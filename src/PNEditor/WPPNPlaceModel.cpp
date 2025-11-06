/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNPlaceModel.h"
#include "../../../WinProMo/src/DiagramEditor/Tokenizer.h"
#include "../../../WinProMo/src/FileUtils/FileParser.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoProperty.h"

CWPPNPlaceModel::CWPPNPlaceModel()
{
	SetType(_T("pn_place_model"));
	CreateProperties();
}

CWPPNPlaceModel::~CWPPNPlaceModel()
{
}

CProMoModel* CWPPNPlaceModel::Clone()
{
	CWPPNPlaceModel* obj = new CWPPNPlaceModel;
	return obj;
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

void CWPPNPlaceModel::CreateProperties()
{
	CProMoModel::CreateProperties();
	CVariantWrapper wrapper;
	wrapper.SetInt(1);
	AddProperty(new CProMoProperty(_T("Marking"), PROPTYPE_INT, wrapper, FALSE, TRUE, TRUE, this));
}

void CWPPNPlaceModel::CustomizeLabel(CProMoLabel* label)
{
	if (label) {
		if (label->GetProperty() == CString("Marking")) {
			label->SetFitView(TRUE);
			label->SetViewAnchorPoint(DEHT_CENTER);
			label->SetLabelAnchorPoint(DEHT_CENTER);
			label->SetLock(LOCK_REPOSITIONING);
		}
		if (label->GetProperty() == CString("Title")) {
			label->SetViewAnchorPoint(DEHT_BOTTOMMIDDLE);
			label->SetLabelAnchorPoint(DEHT_TOPMIDDLE);
		}
	}

	CProMoModel::CustomizeLabel(label);
}