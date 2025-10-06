/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNArcModel.h"
#include "../../../WinProMo/src/DiagramEditor/Tokenizer.h"
#include "../../../WinProMo/src/FileUtils/FileParser.h"

CWPPNArcModel::CWPPNArcModel()
{
	SetType(_T("pn_arc_model"));
	m_weight = 1;
}

CWPPNArcModel::~CWPPNArcModel()
{
}

UINT CWPPNArcModel::GetWeight() const
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

BOOL CWPPNArcModel::CanConnectSource(CProMoBlockModel* source)
{
	if (m_dest) {
		int a = 1;
		if (m_dest->GetType() == source->GetType()) {
			return FALSE;
		}
	}
	
	return TRUE;
}


BOOL CWPPNArcModel::CanConnectDestination(CProMoBlockModel* destination)
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

CString CWPPNArcModel::GetDefaultGetString() const
{
	CString result = CProMoEdgeModel::GetDefaultGetString();

	CString str;

	str.Format(_T(",%u"), GetWeight());

	return result + str;
}

BOOL CWPPNArcModel::GetDefaultFromString(CString& str)
{
	BOOL result = CProMoEdgeModel::GetDefaultFromString(str);
	if (result) {
		result = FALSE;
		
		CTokenizer* tok = CFileParser::Tokenize(str);
		int size = tok->GetSize();
		if (size >= 4)
		{
			int weight;
			int count = 3;

			tok->GetAt(count++, weight);

			SetWeight(weight);

			result = TRUE;
		}
		delete tok;
	}
	return result;

}