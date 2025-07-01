#include "StdAfx.h"
#include "WPPNTransModel.h"

CWPPNTransModel::CWPPNTransModel()
{
	SetType(_T("pn_trans_model"));
}

CProMoModel* CWPPNTransModel::Clone()
{
	CWPPNTransModel* obj = new CWPPNTransModel;
	return obj;
}

BOOL CWPPNTransModel::CanBeNested(CProMoBlockModel* block)
{
	return FALSE;
}
