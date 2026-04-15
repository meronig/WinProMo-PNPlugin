/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPPNArcView

	Author :		Giovanni Meroni

	Purpose :		CWPPNArcView represents the view of an arc in a
					Petri Net and implements CProMoEdgeView for the WinProMo
					Petri Net Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPPNArcView.h"
#include "WPPNArcModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"

CWPPNArcView::CWPPNArcView()
/* ============================================================
	Function :		CWPPNArcView::CWPPNArcView
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Override to set the type of the view element to a
					unique string, (e.g., "my_edge_view") and call
					SetModel to associate a model (derived from
					CProMoEdgeModel) to the view. Implement here
					the logic to customize the default visual
					appearance of the edge view.

============================================================*/
{
	SetType(_T("pn_arc_view"));
	SetModel(new CWPPNArcModel());
}

CWPPNArcView::~CWPPNArcView()
/* ============================================================
	Function :		CWPPNArcView::~CWPPNArcView
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

============================================================*/
{
}

CDiagramEntity* CWPPNArcView::Clone()
/* ============================================================
	Function :		CWPPNArcView::Clone
	Description :	Clones this object and returns a new one.
	Access :		Public

	Return :		CProMoModel*	-	The resulting clone
	Parameters :	none

	Usage :			Call to clone the current object.

============================================================*/
{
	CWPPNArcView* obj = new CWPPNArcView;
	obj->Copy(this);
	obj->SetName(CProMoNameFactory::GetID());
	return obj;
}

void CWPPNArcView::DrawTail(CDC* dc, CRect rect, double size)
/* ============================================================
	Function :		CWPPNArcView::DrawTail
	Description :	Draws the tail of the edge.
	Access :		Protected

	Return :		void
	Parameters :	CDC* dc		-	The CDC to draw to.
					CRect rect	-	The real rectangle of the
									object.
					double size	-	The size of the tail

	Usage :			The default implementation draws a solid
					circle for the tail of the edge.
					Overridden to an empty implementation since 
					arcs in Petri Nets do not have an arrow tail.

   ============================================================*/
{
	// Do nothing, arcs do not have arrow tail
}

CDiagramEntity* CWPPNArcView::CreateFromString(const CString& str)
/* ============================================================
	Function :		CWPPNArcView::CreateFromString
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

	CWPPNArcView* obj = new CWPPNArcView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

CDiagramEntity* CWPPNArcView::CreateFromString(const CString& str, CProMoModel* model)
/* ============================================================
	Function :		CWPPNArcView::CreateFromString
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

	CWPPNArcView* obj = new CWPPNArcView;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}
	else {
		CWPPNArcModel* blockModel = dynamic_cast<CWPPNArcModel*>(model);

		if (blockModel) {
			obj->SetModel(blockModel);
		}
	}

	return obj;

}

CDiagramEntity* CWPPNArcView::Create(const CString& str)
/* ============================================================
	Function :		CWPPNArcView::Create
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
	CWPPNArcView* obj = new CWPPNArcView;
	if (!obj->HasType(str))
	{
		delete obj;
		obj = NULL;
	}
	return obj;
}