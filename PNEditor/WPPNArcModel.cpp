#include "StdAfx.h"
#include "WPPNArcModel.h"

CWPPNArcModel::CWPPNArcModel()
{
	SetType(_T("pn_arc_model"));
	m_weight = 1;
}

CWPPNArcModel::~CWPPNArcModel()
{
}

UINT CWPPNArcModel::GetWeight()
{
	return m_weight;
}

void CWPPNArcModel::SetWeight(UINT weight)
{
	m_weight = weight;
}

CProMoModel* CWPPNArcModel::Clone()
{
	CWPPNArcModel* obj = new CWPPNArcModel;
	return obj;
}

void CWPPNArcModel::Copy(CProMoModel* obj)
{
	CProMoEdgeModel::Copy(obj);
	CWPPNArcModel* objModel = dynamic_cast<CWPPNArcModel*>(obj);
	if (objModel) {
		SetWeight(objModel->GetWeight());
	}
}

BOOL CWPPNArcModel::CanConnectSource(CProMoModel* source)
{
	if (m_dest) {
		int a = 1;
		if (m_dest->GetType() == source->GetType()) {
			return FALSE;
		}
	}
	
	return TRUE;
}


BOOL CWPPNArcModel::CanConnectDestination(CProMoModel* destination)
{
	if (m_source) {
		int a = 1;
		if (m_source->GetType() == destination->GetType()) {
			return FALSE;
		}
	}

	return TRUE;
}

CProMoModel* CWPPNArcModel::CreateFromString(const CString& str)
{

	CWPPNArcModel* obj = new CWPPNArcModel;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}