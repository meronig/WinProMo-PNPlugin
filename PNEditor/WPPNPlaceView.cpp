#include "StdAfx.h"
#include "WPPNPlaceView.h"
#include "WPPNPlaceModel.h"
#include "../../WinProMo/ProMoEditor/ProMoNameFactory.h"
#include <math.h>

CWPPNPlaceView::CWPPNPlaceView()
{
	SetConstraints(CSize(32, 32), CSize(-1, -1));
	SetType(_T("pn_place_view"));
	SetModel(new CWPPNPlaceModel());
    SetLockedProportions(TRUE);
}

CWPPNPlaceView::~CWPPNPlaceView()
{
}

CDiagramEntity* CWPPNPlaceView::Clone()
{
	CWPPNPlaceView* obj = new CWPPNPlaceView;
	obj->Copy(this);
	obj->SetName(CProMoNameFactory::GetID());
	return obj;
}

void CWPPNPlaceView::Draw(CDC* dc, CRect rect)
{
	ASSERT_VALID(this->GetModel());

	dc->SelectStockObject(BLACK_PEN);
	dc->SelectStockObject(WHITE_BRUSH);

	if (IsTarget()) {
		CPen p;
		p.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		CPen* pOldPen = dc->SelectObject(&p);
		dc->Ellipse(rect);
	}
	else {
		dc->Ellipse(rect);
	}

	CFont font;
	CString str;
	/* uncomment line below for debug */
	//str.Format(_T("%d,%d"), getModel()->getIncomingEdges()->GetSize(), getModel()->getOutgoingEdges()->GetSize());
	str = GetTitle();
	font.CreateFont(-round(12.0 * GetZoom()), 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, _T("Courier New"));
	dc->SelectObject(&font);
	int mode = dc->SetBkMode(TRANSPARENT);

    CRect textBounds = ComputeTextRect(str, font);
    
    CRect titleRect;
    double textWidth = textBounds.Width();
    double textHeight = textBounds.Height();
    int ellipseCenterX = rect.left + rect.Width() / 2;

    titleRect.left = ellipseCenterX - textWidth / 2;
    titleRect.right = ellipseCenterX + textWidth / 2;
    titleRect.top = rect.bottom + 2;  // Add vertical spacing
    titleRect.bottom = titleRect.top + textHeight;

    dc->DrawText(str, &titleRect, DT_NOPREFIX | DT_SINGLELINE | DT_TOP);

    UINT marking = GetMarking();
    
    if (marking > 0) {

        str.Format(_T("%u"), marking);
        dc->DrawText(str, rect, DT_NOPREFIX | DT_SINGLELINE | DT_VCENTER | DT_CENTER);

    }

	dc->SelectStockObject(DEFAULT_GUI_FONT);
	dc->SetBkMode(mode);
}

CPoint CWPPNPlaceView::GetIntersection(CPoint innerPoint, CPoint outerPoint)
{
	double ipx = innerPoint.x;
	double ipy = innerPoint.y;
    double opx = outerPoint.x;
    double opy = outerPoint.y;

    // 1. Normalize ellipse bounds
    double left = min(GetLeft(), GetRight());
    double right = max(GetLeft(), GetRight());
    double top = min(GetTop(), GetBottom());
    double bottom = max(GetTop(), GetBottom());

    // 2. Center and radii
    double cx = (left + right) / 2.0;
    double cy = (top + bottom) / 2.0;
    double a = (right - left) / 2.0;
    double b = (bottom - top) / 2.0;

    if (a < 1e-6 || b < 1e-6)
        return CPoint(-1, -1); // Avoid divide-by-zero

    
    // 3. Translate points to ellipse-centered coordinate system
    double x1 = (opx - cx) / a;
    double y1 = (opy - cy) / b;
    double x2 = (ipx - cx) / a;
    double y2 = (ipy - cy) / b;

    // Parametrize the segment: P(t) = (x1, y1) + t * (dx, dy)
    double dx = x2 - x1;
    double dy = y2 - y1;

    const double pushOut = 1.5;
    double len = sqrt(dx * dx + dy * dy);
    if (len > 1e-6) {
        double scale = (len + pushOut / max(a, b)) / len;
        x2 = x1 + dx * scale;
        y2 = y1 + dy * scale;
        dx = x2 - x1;
        dy = y2 - y1;
    }

    // 4. Solve for intersection with unit circle (x² + y² = 1)
    double A = dx * dx + dy * dy;
    double B = 2.0 * (x1 * dx + y1 * dy);
    double C = x1 * x1 + y1 * y1 - 1.0;

    const double EPS = 1e-9;
    double discriminant = B * B - 4.0 * A * C;

    if (discriminant < 0.0) {
        if (discriminant > -EPS) {
            // Treat as tangent
            discriminant = 0.0;
        }
        else {
            // Truly no intersection
            return CPoint(-1, -1);
        }
    }
    
    double sqrtD = sqrt(discriminant);
    double t1 = (-B - sqrtD) / (2.0 * A);
    double t2 = (-B + sqrtD) / (2.0 * A);

    // 5. Select the valid t  [0, 1] closest to innerPoint
    double t = (fabs(t1) < fabs(t2)) ? t1 : t2;
    t = max(0.0, min(1.0, t));  // Clamp to segment range

    // 5. Transform back to original space
    double xi = (x1 + t * dx) * a + cx;
    double yi = (y1 + t * dy) * b + cy;

    // Optional: snap exactly on ellipse (helps long-term stability)
    double ex = (xi - cx) / a;
    double ey = (yi - cy) / b;
    double norm = sqrt(ex * ex + ey * ey);
    if (norm > 1e-6) {
        ex /= norm;
        ey /= norm;
        xi = cx + ex * a;
        yi = cy + ey * b;
    }

    return CPoint(static_cast<int>(xi + 0.5), static_cast<int>(yi + 0.5));
}

void CWPPNPlaceView::ComputeMinimumSize()
{
    UINT marking = GetMarking();

    if (marking > 0) {

        CString str;
        str.Format(_T("%u"), GetMarking());

        CFont font;
        font.CreateFont(-round(12.0 * GetZoom()), 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, _T("Courier New"));
        CRect textBounds = ComputeTextRect(str, font);

        CSize minSize = GetMinimumSize();

        double oldWidth = GetRect().Width();
        double oldHeight = GetRect().Height();
        double textWidth = textBounds.Width();
        double textHeight = textBounds.Height();

        double deltaX;
        double deltaY;

        if (HasLockedProportions()) {
            double oldRatio = oldHeight / oldWidth;
            deltaX = (textWidth + 4 - oldWidth) * oldRatio;
            deltaY = (textHeight + 4 - oldHeight) / oldRatio;

            if (deltaX > deltaY) {
                deltaY = deltaX / oldRatio;
            }
            else {
                deltaX = deltaY * oldRatio;
            }
        }
        else {
            deltaX = textWidth + 4 - oldWidth;
            deltaY = textHeight + 4 - oldHeight;
        }

        if (deltaX > 0) {
            SetRight(GetLeft() + oldWidth + deltaX);
        }

        if (deltaY > 0) {
            SetBottom(GetTop() + oldHeight + deltaY);
        }

        minSize.cx = max(32, oldWidth + deltaX);
        minSize.cy = max(32, oldHeight + deltaX);

        SetMinimumSize(minSize);

    }
}

UINT CWPPNPlaceView::GetMarking() 
{
    CWPPNPlaceModel* model = dynamic_cast<CWPPNPlaceModel*>(GetModel());
    if (model) {
        return model->GetMarking();
    }
    return 0;
}

void CWPPNPlaceView::SetMarking(UINT marking) 
{
    CWPPNPlaceModel* model = dynamic_cast<CWPPNPlaceModel*>(GetModel());
    if (model) {
        model->SetMarking(marking);
        ComputeMinimumSize();
    }
}

void CWPPNPlaceView::SetModel(CProMoBlockModel* model) {
    CProMoBlockView::SetModel(model);
    ComputeMinimumSize();
}

CDiagramEntity* CWPPNPlaceView::CreateFromString(const CString& str)
{

    CWPPNPlaceView* obj = new CWPPNPlaceView;
    if (!obj->FromString(str))
    {
        delete obj;
        obj = NULL;
    }

    return obj;

}