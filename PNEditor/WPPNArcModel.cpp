#include "StdAfx.h"
#include "WPPNArcModel.h"

CWPPNArcModel::CWPPNArcModel()
{
	SetType(_T("pn_arc_model"));

}

CProMoModel* CWPPNArcModel::Clone()
{
	CWPPNArcModel* obj = new CWPPNArcModel;
	return obj;
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
