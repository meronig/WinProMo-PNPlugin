/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPPNPlaceModel

	Author :		Giovanni Meroni

	Purpose :		CWPPNPlaceModel represents the model of a place in a Petri 
					Net and implements CProMoBlockModel	for the WinProMo Petri 
					Net Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPPNPlaceModel.h"
#include "../../../WinProMo/src/DiagramEditor/Tokenizer.h"
#include "../../../WinProMo/src/FileUtils/FileParser.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoProperty.h"

CWPPNPlaceModel::CWPPNPlaceModel()
/* ============================================================
	Function :		CWPPNPlaceModel::CWPPNPlaceModel
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Override to set the type of the model element to a
					unique string, (e.g., "my_block_model") and call
					CreateProperties to add additional properties to 
					the model.
============================================================*/
{
	SetType(_T("pn_place_model"));
	CreateProperties();
}

CWPPNPlaceModel::~CWPPNPlaceModel()
/* ============================================================
	Function :		CWPPNPlaceModel::~CWPPNPlaceModel
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

============================================================*/
{
}

CProMoModel* CWPPNPlaceModel::Clone()
/* ============================================================
	Function :		CWPPNPlaceModel::Clone
	Description :	Clones this object and returns a new one.
	Access :		Public

	Return :		CProMoModel*	-	The resulting clone
	Parameters :	none

	Usage :			Call to clone the current object.

============================================================*/
{
	CWPPNPlaceModel* obj = new CWPPNPlaceModel;
	return obj;
}

BOOL CWPPNPlaceModel::CanBeSubBlockOf(CProMoBlockModel* block) const
/* ============================================================
	Function :		CWPPNPlaceModel::CanBeSubBlockOf
	Description :	Returns if this block can be a subblock of the
					block being passed as input	parameter.
	Access :		Public

	Return :		BOOL					-	"TRUE" if the
												block can be
												nested
	Parameters :	CProMoBlockModel* block	-	the block that
												should nest
												this block
	Usage:			Override to implement diagram-specific logic.
					By default, places cannot be nested.

   ============================================================*/
{
	return FALSE;
}

BOOL CWPPNPlaceModel::CanBeBoundaryOf(CProMoBlockModel* block, unsigned int alignment) const
/* ============================================================
	Function :		CWPPNPlaceModel::CanBeBoundaryOf
	Description :	Returns if this block can be a boundary
					block of the block being passed as input
					parameter.
	Access :		Public

	Return :		BOOL					-	"TRUE" if the
												block can be
												a boundary
												block
	Parameters :	CProMoBlockModel* block	-	the block that
												should have
												this block as
												boundary
					unsigned int alignment	-	the type of
												attachment for
												the boundary
												block
	Usage:			Override to implement diagram-specific logic.
					By default, places cannot be boundary blocks.

   ============================================================*/
{
	return FALSE;
}

CProMoModel* CWPPNPlaceModel::CreateFromString(const CString& str)
/* ============================================================
	Function :		CWPPNPlaceModel::CreateFromString
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

	CWPPNPlaceModel* obj = new CWPPNPlaceModel;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

void CWPPNPlaceModel::CreateProperties()
/* ============================================================
	Function :		CWPPNPlaceModel::CreateProperties
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
	
	// To represent the marking of the place, we add an integer property 
	// called "Marking". 
	CVariantWrapper wrapper;
	wrapper.SetInt(1);
	AddProperty(new CProMoProperty(_T("Marking"), PROPTYPE_INT, wrapper, FALSE, TRUE, TRUE, this));
}

void CWPPNPlaceModel::CustomizeLabel(CProMoLabel* label)
/* ============================================================
	Function :		CWPPNPlaceModel::CustomizeLabel
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
		if (label->GetPropertyName() == CString("Marking")) {
			// Make the label automatically fit the text and the view, and reposition the label to the center of the block
			label->SetFitView(TRUE);
			label->SetViewAnchorPoint(DEHT_CENTER);
			label->SetLabelAnchorPoint(DEHT_CENTER);
			label->SetLock(LOCK_REPOSITIONING);
		}
		if (label->GetPropertyName() == CString("Title")) {
			// Make the label bounding box as large as the block, and reposition the label to the bottom middle of the block
			label->SetViewAnchorPoint(DEHT_BOTTOMMIDDLE);
			label->SetLabelAnchorPoint(DEHT_TOPMIDDLE);
		}
	}

	CProMoModel::CustomizeLabel(label);
}