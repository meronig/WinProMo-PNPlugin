/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPPNTransModel

	Author :		Giovanni Meroni

	Purpose :		CWPPNTransModel represents the model of a transition in a 
					Petri Net and implements CProMoBlockModel for the WinProMo
					Petri Net Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPPNTransModel.h"
#include "../../../WinProMo/src/DiagramEditor/Tokenizer.h"

CWPPNTransModel::CWPPNTransModel()
/* ============================================================
	Function :		CWPPNTransModel::CWPPNTransModel
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
	SetType(_T("pn_trans_model"));
}

CWPPNTransModel::~CWPPNTransModel()
/* ============================================================
	Function :		CWPPNTransModel::~CWPPNTransModel
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

============================================================*/
{
}

CProMoModel* CWPPNTransModel::Clone()
/* ============================================================
	Function :		CWPPNTransModel::Clone
	Description :	Clones this object and returns a new one.
	Access :		Public

	Return :		CProMoModel*	-	The resulting clone
	Parameters :	none

	Usage :			Call to clone the current object.

============================================================*/
{
	CWPPNTransModel* obj = new CWPPNTransModel;
	return obj;
}

BOOL CWPPNTransModel::CanBeSubBlockOf(CProMoBlockModel* block) const
/* ============================================================
	Function :		CWPPNTransModel::CanBeSubBlockOf
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
					By default, transitions cannot be nested.

   ============================================================*/
{
	return FALSE;
}

BOOL CWPPNTransModel::CanBeBoundaryOf(CProMoBlockModel* block, unsigned int alignment) const
/* ============================================================
	Function :		CWPPNTransModel::CanBeBoundaryOf
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
					By default, transitions cannot be boundary blocks.

   ============================================================*/
{
	return FALSE;
}

CProMoModel* CWPPNTransModel::CreateFromString(const CString& str)
/* ============================================================
	Function :		CWPPNTransModel::CreateFromString
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

	CWPPNTransModel* obj = new CWPPNTransModel;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}