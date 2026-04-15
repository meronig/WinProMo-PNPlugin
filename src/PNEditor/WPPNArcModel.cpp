/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPPNArcModel

	Author :		Giovanni Meroni

	Purpose :		CWPPNArcModel represents the model of an arc in a
					Petri Net and implements CProMoEdgeModel for the WinProMo
					Petri Net Plugin.

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNArcModel.h"
#include "../../../WinProMo/src/DiagramEditor/Tokenizer.h"
#include "../../../WinProMo/src/FileUtils/FileParser.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoProperty.h"

CWPPNArcModel::CWPPNArcModel()
/* ============================================================
	Function :		CWPPNArcModel::CWPPNArcModel
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Override to set the type of the model element to a
					unique string, (e.g., "my_edge_model") and call
					CreateProperties to add additional properties to
					the model.

============================================================*/
{
	SetType(_T("pn_arc_model"));
	CreateProperties();
}

CWPPNArcModel::~CWPPNArcModel()
/* ============================================================
	Function :		CWPPNArcModel::~CWPPNArcModel
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

============================================================*/
{
}

CProMoModel* CWPPNArcModel::Clone()
/* ============================================================
	Function :		CWPPNArcModel::Clone
	Description :	Clones this object and returns a new one.
	Access :		Public

	Return :		CProMoModel*	-	The resulting clone
	Parameters :	none

	Usage :			Call to clone the current object.

============================================================*/
{
	CWPPNArcModel* obj = new CWPPNArcModel;
	return obj;
}

BOOL CWPPNArcModel::CanConnectSource(CProMoBlockModel* source) const
/* ============================================================
	Function :		CWPPNArcModel::CanConnectSource
	Description :	Returns if the object being passed as input
					parameter can be a source object.
	Access :		Public

	Return :		BOOL						-	"TRUE" if the
													object can be
													a source
	Parameters :	CProMoBlockModel* source	-	the object
													that should
													be the source
	Usage:			Override to implement diagram-specific logic.
					By default, an arc cannot connect to a source 
					of the same type as the destination (i.e., 
					a place cannot connect to another place). 
   ============================================================*/
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
/* ============================================================
	Function :		CWPPNArcModel::CanConnectDestination
	Description :	Returns if the object being passed as input
					parameter can be a destination object.
	Access :		Public

	Return :		BOOL							-	"TRUE" if
														the object
														can be a
														destination
	Parameters :	CProMoBlockModel* destination	-	the
														object
														that
														should
														be the
														destination
	Usage:			Override to implement diagram-specific logic.
					By default, an arc cannot connect to a destination
					of the same type as the source (i.e.,
					a place cannot connect to another place).
   ============================================================*/
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
/* ============================================================
	Function :		CWPPNArcModel::CreateFromString
	Description :	Static factory function that creates and
					returns an instance of this class if "str"
					is a valid representation.
	Access :		Public

	Return :		CProMoModel*		-	The object, or "NULL"
											if "str" is not a
											representation of
											this type.
	Parameters :	const CString& str	-	The string to create
											from.

	Usage :			Can be used as a factory for text file loads.
					Each object type should have its own
					version - the default one is a model
					implementation.

   ============================================================*/
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
/* ============================================================
	Function :		CWPPNArcModel::CreateProperties
	Description :	Creates the properties for this object.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Override to add properties to the model. Call
					the base class version to add the Title property
					(e.g., "Name") and then add the	custom ones using
					AddProperty.

   ============================================================*/
{
	CProMoModel::CreateProperties();

	// To represent the weight of the arc, we add an integer property 
	// called "Weight". 
	CVariantWrapper wrapper;
	wrapper.SetInt(1);
	AddProperty(new CProMoProperty(_T("Weight"), PROPTYPE_INT, wrapper, FALSE, TRUE, TRUE, this));
}

void CWPPNArcModel::CustomizeLabel(CProMoLabel* label)
/* ============================================================
	Function :		CWPPNArcModel::CustomizeLabel
	Description :	Customizes the input label.
	Access :		Public

	Return :		void
	Parameters :	CProMoLabel*		-	A pointer to the
											label to customize
	Usage :			Override to customize the appearance of the
					labels linked to this model. Must call the base
					class version to reposition the label.

   ============================================================*/
{
	if (label) {
		if (label->GetPropertyName() == CString("Weight")) {
			// For the weight label, we set it to be below the arc and centered.
			label->SetViewAnchorPoint(DEHT_CENTER);
			label->SetLabelAnchorPoint(DEHT_TOPMIDDLE);

			// If the weight is 1, we hide the label and lock it to prevent selection, otherwise we show it and unlock it.
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
			// For the title label, we set it to be above the arc and centered.
			label->SetViewAnchorPoint(DEHT_CENTER);
			label->SetLabelAnchorPoint(DEHT_BOTTOMMIDDLE);
		}
	}

	CProMoModel::CustomizeLabel(label);
}

void CWPPNArcModel::OnPropertyChanged(CProMoProperty* prop)
/* ============================================================
	Function :		CWPPNArcModel::OnPropertyChanged
	Description :	Notification that a property has changed.
	Access :		Public

	Return :		void
	Parameters :	CProMoProperty* prop	-	Property that
												changed.

	Usage :			Can be called by a property to notify the
					model that it changed, and to trigger UI
					updates. Must call the base class version to
					update the label text, and then add custom logic.

   ============================================================*/
{
	CProMoModel::OnPropertyChanged(prop);

	CustomizeLabel(GetLabel(prop->GetFullName()));

}