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
