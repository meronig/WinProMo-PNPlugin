/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNArcView.h"
#include "WPPNArcModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"

CWPPNArcView::CWPPNArcView()
{
	SetType(_T("pn_arc_view"));
	SetModel(new CWPPNArcModel());
}

CWPPNArcView::~CWPPNArcView()
{
}

CDiagramEntity* CWPPNArcView::Clone()
{
	CWPPNArcView* obj = new CWPPNArcView;
	obj->Copy(this);
	obj->SetName(CProMoNameFactory::GetID());
	return obj;
}

void CWPPNArcView::Draw(CDC* dc, CRect rect)
{
	CProMoEdgeView::Draw(dc, rect);

	CString str;
	UINT weight = GetWeight();
	if (weight > 1 && IsFirstSegment()) {
		CFont font;
		str.Format(_T("%u"), weight);
		font.CreateFont(-round(12.0 * GetZoom()), 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, _T("Courier New"));
		dc->SelectObject(&font);
		int mode = dc->SetBkMode(TRANSPARENT);

		CRect rectTemp(rect);
		rectTemp.NormalizeRect();
		int cy = round(14.0 * GetZoom());
		int cut = round((double)GetMarkerSize().cx * GetZoom() / 2);
		CRect r(rect.right - cut, rect.top, rect.right - (rectTemp.Width() + cut), rect.bottom);
		if (rect.top == rect.bottom)
		{
			CRect r(rect.left, rect.top + (cy + cut), rect.right, rect.bottom);
			r.NormalizeRect();
			dc->DrawText(str, r, DT_NOPREFIX | DT_SINGLELINE | DT_VCENTER | DT_CENTER);
		}
		else
		{
			CRect r(rect.left + cut, rect.top, rect.left + (cy * str.GetLength() + cut), rect.bottom);
			r.NormalizeRect();
			dc->DrawText(str, r, DT_NOPREFIX | DT_SINGLELINE | DT_VCENTER | DT_RIGHT);
		}

		dc->SelectStockObject(DEFAULT_GUI_FONT);
		dc->SetBkMode(mode);
	}

}

void CWPPNArcView::DrawLine(CDC* dc, CRect rect)
{
	dc->SelectStockObject(BLACK_PEN);

	dc->MoveTo(rect.TopLeft());
	dc->LineTo(rect.BottomRight());

	//draw the tip only if it is the last segment
	if (m_dest == NULL) {
		DrawHead(dc, rect, 10 * GetZoom());
	}

}

CDiagramEntity* CWPPNArcView::CreateFromString(const CString& str)
{

	CWPPNArcView* obj = new CWPPNArcView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

CDiagramEntity* CWPPNArcView::CreateFromString(const CString& str, CProMoModel* model)
{

	CWPPNArcView* obj = new CWPPNArcView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}
	else {
		CWPPNArcModel* blockModel = dynamic_cast<CWPPNArcModel*>(model);

		if (blockModel) {
			obj->SetModel(blockModel);
		}
	}

	return obj;

}

UINT CWPPNArcView::GetWeight() const
{
	CWPPNArcModel* model = dynamic_cast<CWPPNArcModel*>(GetModel());
	if (model) {
		return model->GetWeight();
	}
	return 1;
}

void CWPPNArcView::SetWeight(UINT weight)
{
	CWPPNArcModel* model = dynamic_cast<CWPPNArcModel*>(GetModel());
	if (model) {
		model->SetWeight(weight);
	}
}
