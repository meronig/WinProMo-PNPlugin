/* ==========================================================================

    Copyright © 2025-26 Technical University of Denmark

    CWPPNPlaceView

    Author :		Giovanni Meroni

    Purpose :		CWPPNPlaceView represents the view of a place in a
                    Petri Net and implements CProMoBlockView for the WinProMo
                    Petri Net Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPPNPlaceView.h"
#include "WPPNPlaceModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"
#include <math.h>
#include "../../../WinProMo/src/GeometryUtils/DoublePoint.h"
#include "../../../WinProMo/src/GeometryUtils/IntersectionHelper.h"

CWPPNPlaceView::CWPPNPlaceView()
/* ============================================================
    Function :		CWPPNPlaceView::CWPPNPlaceView
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
	// Set the minimum and maximum size of the place view to be square.
    SetConstraints(CSize(32, 32), CSize(-1, -1));

	SetType(_T("pn_place_view"));
	SetModel(new CWPPNPlaceModel());

	// Lock the proportions of the place view to maintain a circular shape
    SetLockedProportions(TRUE);
	
    // Set the shape of the place view to an ellipse to make it circular.
    // The shape being specifed by SetShape will also determine the
    // logic for hit testing and intersection computations.
    SetShape(SHAPE_ELLIPSE);
}

CWPPNPlaceView::~CWPPNPlaceView()
/* ============================================================
    Function :		CWPPNPlaceView::~CWPPNPlaceView
    Description :	Destructor
    Access :		Public

    Return :		void
    Parameters :	none

============================================================*/
{
}

CDiagramEntity* CWPPNPlaceView::Clone()
/* ============================================================
    Function :		CWPPNPlaceView::Clone
    Description :	Clones this object and returns a new one.
    Access :		Public

    Return :		CProMoModel*	-	The resulting clone
    Parameters :	none

    Usage :			Call to clone the current object.

============================================================*/
{
	CWPPNPlaceView* obj = new CWPPNPlaceView;
	obj->Copy(this);
	obj->SetName(CProMoNameFactory::GetID());
	return obj;
}

CDiagramEntity* CWPPNPlaceView::CreateFromString(const CString& str)
/* ============================================================
    Function :		CWPPNPlaceView::CreateFromString
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

    CWPPNPlaceView* obj = new CWPPNPlaceView;
    if (!obj->FromString(str))
    {
        delete obj;
        obj = NULL;
    }

    return obj;

}

CDiagramEntity* CWPPNPlaceView::CreateFromString(const CString& str, CProMoModel* model)
/* ============================================================
    Function :		CWPPNPlaceView::CreateFromString
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

    CWPPNPlaceView* obj = new CWPPNPlaceView;
    if (!obj->FromString(str))
    {
        delete obj;
        obj = NULL;
    }
    else {
        CWPPNPlaceModel* blockModel = dynamic_cast<CWPPNPlaceModel* > (model);

        if (blockModel) {
            obj->SetModel(blockModel);
        }
    }

    return obj;

}

CDiagramEntity* CWPPNPlaceView::Create(const CString& str)
/* ============================================================
    Function :		CWPPNPlaceView::Create
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
    CWPPNPlaceView* obj = new CWPPNPlaceView;
    if (!obj->HasType(str))
    {
        delete obj;
        obj = NULL;
    }
    return obj;
}