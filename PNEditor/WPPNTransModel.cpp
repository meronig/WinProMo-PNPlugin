#include "StdAfx.h"
#include "WPPNTransModel.h"

CWPPNTransModel::CWPPNTransModel()
{
	SetType(_T("pn_trans_model"));
}

CWPPNTransModel::~CWPPNTransModel()
{
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

CProMoModel* CWPPNTransModel::CreateFromString(const CString& str)
{

	CWPPNTransModel* obj = new CWPPNTransModel;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}