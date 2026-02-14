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

void CWPPNArcView::DrawTail(CDC* dc, CRect rect, double size)
{
	// Do nothing, arcs do not have arrow tail
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

CDiagramEntity* CWPPNArcView::Create(const CString& str)
{
	CWPPNArcView* obj = new CWPPNArcView;
	if (!obj->HasType(str))
	{
		delete obj;
		obj = NULL;
	}
	return obj;
}