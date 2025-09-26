/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNPlaceModel.h"
#include "../../../WinProMo/src/DiagramEditor/Tokenizer.h"
#include "../../../WinProMo/src/FileUtils/FileParser.h"

CWPPNPlaceModel::CWPPNPlaceModel()
{
	SetType(_T("pn_place_model"));
	m_marking = 0;
}

CWPPNPlaceModel::~CWPPNPlaceModel()
{
}

UINT CWPPNPlaceModel::GetMarking() const
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

void CWPPNPlaceModel::Copy(CProMoModel* obj) 
{
	CProMoBlockModel::Copy(obj);
	CWPPNPlaceModel* objModel = dynamic_cast<CWPPNPlaceModel*>(obj);
	if (objModel) {
		SetMarking(objModel->GetMarking());
	}
	
}

BOOL CWPPNPlaceModel::CanBeNestedBy(CProMoBlockModel* block)
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

CString CWPPNPlaceModel::GetDefaultGetString() const
{
	CString result = CProMoBlockModel::GetDefaultGetString();

	CString str;

	str.Format(_T(",%u"), GetMarking());

	return result + str;

}

BOOL CWPPNPlaceModel::GetDefaultFromString(CString& str)
{
	BOOL result = CProMoBlockModel::GetDefaultFromString(str);
	if (result) {
		result = FALSE;
		
		CTokenizer* tok = CFileParser::Tokenize(str);
		int size = tok->GetSize();
		if (size >= 3)
		{
			CString name;
			int marking;
			int count = 2;

			tok->GetAt(count++, marking);

			SetMarking(marking);

			result = TRUE;
		}
		delete tok;
	}
	return result;

}