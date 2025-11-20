/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNArcModel.h"
#include "../../../WinProMo/src/DiagramEditor/Tokenizer.h"
#include "../../../WinProMo/src/FileUtils/FileParser.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoProperty.h"

CWPPNArcModel::CWPPNArcModel()
{
	SetType(_T("pn_arc_model"));
	CreateProperties();
}

CWPPNArcModel::~CWPPNArcModel()
{
}

CProMoModel* CWPPNArcModel::Clone()
{
	CWPPNArcModel* obj = new CWPPNArcModel;
	return obj;
}

BOOL CWPPNArcModel::CanConnectSource(CProMoBlockModel* source) const
{
	if (m_dest) {
		int a = 1;
		if (m_dest->GetType() == source->GetType()) {
			return FALSE;
		}
	}
	
	return TRUE;
}


BOOL CWPPNArcModel::CanConnectDestination(CProMoBlockModel* destination) const
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

void CWPPNArcModel::CreateProperties()
{
	CProMoModel::CreateProperties();
	CVariantWrapper wrapper;
	wrapper.SetInt(1);
	AddProperty(new CProMoProperty(_T("Weight"), PROPTYPE_INT, wrapper, FALSE, TRUE, TRUE, this));
}

void CWPPNArcModel::CustomizeLabel(CProMoLabel* label)
{
	if (label) {
		if (label->GetPropertyName() == CString("Weight")) {
			label->SetViewAnchorPoint(DEHT_CENTER);
			label->SetLabelAnchorPoint(DEHT_TOPMIDDLE);
			if (GetPropertyValue("Weight").GetInt() == 1) {
				label->SetVisible(FALSE);
				label->SetLock(label->GetLock() | LOCK_SELECTION);
			}
			else {
				label->SetVisible(TRUE);
				label->SetLock(label->GetLock() &~ LOCK_SELECTION);
			}
		}
		if (label->GetPropertyName() == CString("Title")) {
			label->SetViewAnchorPoint(DEHT_CENTER);
			label->SetLabelAnchorPoint(DEHT_BOTTOMMIDDLE);
		}
	}

	CProMoModel::CustomizeLabel(label);
}

void CWPPNArcModel::OnPropertyChanged(CProMoProperty* prop)
{
	CProMoModel::OnPropertyChanged(prop);

	if (prop->GetFullName() == CString("Weight")) {

		CProMoLabel* label = GetLabel(prop->GetFullName());
		if (label) {
			if (prop->GetValue().GetInt() == 1) {
				label->SetVisible(FALSE);
				label->SetLock(label->GetLock() | LOCK_SELECTION);
			}
			else {
				label->SetVisible(TRUE);
				label->SetLock(label->GetLock() & ~LOCK_SELECTION);
			}
		}
	}
}