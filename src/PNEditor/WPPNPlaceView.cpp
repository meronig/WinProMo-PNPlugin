/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNPlaceView.h"
#include "WPPNPlaceModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"
#include <math.h>
#include "../../../WinProMo/src/GeometryUtils/DoublePoint.h"
#include "../../../WinProMo/src/GeometryUtils/IntersectionHelper.h"

CWPPNPlaceView::CWPPNPlaceView()
{
	SetConstraints(CSize(32, 32), CSize(-1, -1));
    m_markingRect = CRect(CPoint(0, 0), GetMinimumSize());
	SetType(_T("pn_place_view"));
	SetModel(new CWPPNPlaceModel());
    SetLockedProportions(TRUE);
    SetShape(SHAPE_ELLIPSE);
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

    dc->DrawText(str, &titleRect, DT_NOPREFIX | DT_SINGLELINE | DT_TOP | DT_CENTER);

    UINT marking = GetMarking();
    
    if (marking > 0) {

        str.Format(_T("%u"), marking);
        dc->DrawText(str, rect, DT_NOPREFIX | DT_SINGLELINE | DT_VCENTER | DT_CENTER);

    }

	dc->SelectStockObject(DEFAULT_GUI_FONT);
	dc->SetBkMode(mode);
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
        ComputeMarkingRect(marking);
        CDiagramEntity::SetRect(GetRect());
    }
}

void CWPPNPlaceView::SetModel(CProMoBlockModel* model) {
    CWPPNPlaceModel* placeModel = dynamic_cast<CWPPNPlaceModel*>(model);
    if (placeModel) {
        CProMoBlockView::SetModel(model);
        ComputeMarkingRect(placeModel->GetMarking());
        CDiagramEntity::SetRect(GetRect());
    }
}

void CWPPNPlaceView::ComputeMarkingRect(const UINT& marking) {
    CFont font;
    CString str;
    double zoom = GetZoom();
    if (zoom == 0) {
        zoom = 1.0;
    }
    font.CreateFont(-round(12.0 * zoom), 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, _T("Courier New"));
    str.Format(_T("%i"), marking);
    m_markingRect = ComputeTextRect(str, font);
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

CDiagramEntity* CWPPNPlaceView::CreateFromString(const CString& str, CProMoModel* model)
{

    CWPPNPlaceView* obj = new CWPPNPlaceView;
    if (!obj->FromString(str))
    {
        delete obj;
        obj = NULL;
    }
    else {
        CWPPNPlaceModel* blockModel = dynamic_cast<CWPPNPlaceModel* > (model);

        if (blockModel) {
            obj->SetModel(blockModel);
        }
    }

    return obj;

}

void CWPPNPlaceView::SetRect(CRect rect)
{
    // DO NOT DELETE, it is needed for derived classes
    CProMoBlockView::SetRect(rect);
}


void CWPPNPlaceView::SetRect(double left, double top, double right, double bottom) {
    if (m_markingRect.Width() > right - left) {
        if (GetLeft() - left != 0) {
            left = (right - m_markingRect.Width());
        }
        else {
            right = (left + m_markingRect.Width());
        }
    }

    if (m_markingRect.Height() > bottom - top) {
        if (GetTop() - top != 0) {
            top = (bottom - m_markingRect.Height());
        }
        else {
            bottom = (top + m_markingRect.Height());
        }
    }

    CProMoBlockView::SetRect(left, top, right, bottom);
}