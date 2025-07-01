#include "StdAfx.h"
#include "WPPNPlaceModel.h"

CWPPNPlaceModel::CWPPNPlaceModel()
{
	SetType(_T("pn_place_model"));
}

UINT CWPPNPlaceModel::GetMarking()
{
	return m_marking;
}

void CWPPNPlaceModel::SetMarking(UINT marking)
{
	m_marking = marking;
}

CProMoModel* CWPPNPlaceModel::Clone()
{
	CWPPNPlaceModel* obj = new CWPPNPlaceModel;
	return obj;
}

BOOL CWPPNPlaceModel::CanBeNested(CProMoBlockModel* block)
{
	return FALSE;
}

CProMoModel* CWPPNPlaceModel::CreateFromString(const CString& str)
{

	CWPPNPlaceModel* obj = new CWPPNPlaceModel;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}