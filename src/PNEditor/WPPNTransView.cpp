/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNTransView.h"
#include "WPPNTransModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"

CWPPNTransView::CWPPNTransView()
{
	SetConstraints(CSize(32, 32), CSize(-1, -1));
	SetType(_T("pn_trans_view"));
	SetModel(new CWPPNTransModel());
	SetLockedProportions(FALSE);
	SetFitTitle(TRUE);
	SetShape(SHAPE_RECTANGLE);
}

CWPPNTransView::~CWPPNTransView()
{
}

CDiagramEntity* CWPPNTransView::Clone()
{
	CWPPNTransView* obj = new CWPPNTransView;
	obj->Copy(this);
	obj->SetName(CProMoNameFactory::GetID());
	return obj;
}

CDiagramEntity* CWPPNTransView::CreateFromString(const CString& str)
{

	CWPPNTransView* obj = new CWPPNTransView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

CDiagramEntity* CWPPNTransView::CreateFromString(const CString& str, CProMoModel* model)
{

	CWPPNTransView* obj = new CWPPNTransView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}
	else {
		CWPPNTransModel* blockModel = dynamic_cast<CWPPNTransModel*>(model);

		if (blockModel) {
			obj->SetModel(blockModel);
		}
	}

	return obj;

}