/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPPNTransView

	Author :		Giovanni Meroni

	Purpose :		CWPPNTransView represents the view of a transition in a
					Petri Net and implements CProMoBlockView for the WinProMo
					Petri Net Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPPNTransView.h"
#include "WPPNTransModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"

CWPPNTransView::CWPPNTransView()
/* ============================================================
	Function :		CWPPNTransView::CWPPNTransView
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Override to set the type of the view element to a
					unique string, (e.g., "my_block_view") and call
					SetModel to associate a model (derived from
					CProMoBlockModel) to the view. Implement here 
					the logic to customize the shape of the block view.

============================================================*/
{
	// set the minimum and maximum size of the block view. 
	// The default is (0, 0) for minimum and (-1, -1) for maximum, 
	// which means that there are no constraints.
	SetConstraints(CSize(32, 32), CSize(-1, -1));

	SetType(_T("pn_trans_view"));
	SetModel(new CWPPNTransModel());
	
	// Unlock the proportions of the transition view to allow it to be resized freely.
	SetLockedProportions(FALSE);
	
	// Set the shape of the transition view to a rectangle.
	// The shape being specifed by SetShape will also determine the
	// logic for hit testing and intersection computations.
	SetShape(SHAPE_RECTANGLE);
}

CWPPNTransView::~CWPPNTransView()
/* ============================================================
	Function :		CWPPNTransView::~CWPPNTransView
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

============================================================*/
{
}

CDiagramEntity* CWPPNTransView::Clone()
/* ============================================================
	Function :		CWPPNTransView::Clone
	Description :	Clones this object and returns a new one.
	Access :		Public

	Return :		CProMoModel*	-	The resulting clone
	Parameters :	none

	Usage :			Call to clone the current object.

============================================================*/
{
	CWPPNTransView* obj = new CWPPNTransView;
	obj->Copy(this);
	obj->SetName(CProMoNameFactory::GetID());
	return obj;
}

CDiagramEntity* CWPPNTransView::CreateFromString(const CString& str)
/* ============================================================
	Function :		CWPPNTransView::CreateFromString
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

	CWPPNTransView* obj = new CWPPNTransView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

CDiagramEntity* CWPPNTransView::CreateFromString(const CString& str, CProMoModel* model)
/* ============================================================
	Function :		CWPPNTransView::CreateFromString
	Description :	Static factory function that creates and
					returns an instance of this class if "str"
					is a valid representation.

	Return :		CDiagramEntity*		-	The object, or NULL
											if "str" is not a
											representation of
											this type.
	Parameters :	const CString& str	-	The string to create
											from.
					CProMoModel* model	-	A model to be
											associated to the
											object being created.

	Usage :			Can be used as a factory for text file loads.
					Each object type should have its own
					version - the default one is a model
					implementation.

   ============================================================*/
{

	CWPPNTransView* obj = new CWPPNTransView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}
	else {
		CWPPNTransModel* blockModel = dynamic_cast<CWPPNTransModel*>(model);

		if (blockModel) {
			obj->SetModel(blockModel);
		}
	}

	return obj;

}

CDiagramEntity* CWPPNTransView::Create(const CString& str)
/* ============================================================
	Function :		CWPPNTransView::Create
	Description :	Creates an object of this type if the type
					matches.
	Return :		CDiagramEntity*	-	The created object, or
										NULL if the type did
										not match.
	Parameters :	const CString& str	-	The type to create.
	Usage :			Static function used by the
					"CProMoControlFactory" to create objects
					of this type.
   ============================================================*/
{
	CWPPNTransView* obj = new CWPPNTransView;
	if (!obj->HasType(str))
	{
		delete obj;
		obj = NULL;
	}
	return obj;
}