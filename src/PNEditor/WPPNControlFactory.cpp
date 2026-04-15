/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPPNControlFactory

	Author :		Giovanni Meroni

	Purpose :		CWPPNControlFactory implements CProMoControlFactory
					for the WinProMo Petri Net Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPPNControlFactory.h"
#include "WPPNArcModel.h"
#include "WPPNArcView.h"
#include "WPPNPlaceModel.h"
#include "WPPNPlaceView.h"
#include "WPPNTransModel.h"
#include "WPPNTransView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWPPNControlFactory

CDiagramEntity* CWPPNControlFactory::CreateViewFromString(const CString& str)
/* ============================================================
	Function :		CWPPNControlFactory::CreateViewFromString
	Description :	The function returns an object from the
					parameter str.

	Return :		CDiagramEntity*		-	The new object, or
											NULL is str is not a
											valid representation.
	Parameters :	const CString& str	-	The string to create
											a new object from

	Usage :			Call this function while reading
					string representations of objects from a
					text file. Note that the caller is
					responsible for the allocated memory.

   ============================================================*/
{
	CDiagramEntity* obj;

	obj = CWPPNPlaceView::CreateFromString(str);

	if (!obj)
		obj = CWPPNTransView::CreateFromString(str);

	if (!obj)
		obj = CWPPNArcView::CreateFromString(str);


	return obj;
}

CDiagramEntity* CWPPNControlFactory::CreateViewFromString(const CString& str, CProMoModel* model)
/* ============================================================
	Function :		CWPPNControlFactory::CreateViewFromString
	Description :	The function returns an object from the
					parameter str.

	Return :		CDiagramEntity*		-	The new object, or
											NULL is str is not a
											valid representation.
	Parameters :	const CString& str	-	The string to create
											a new object from
					CProMoModel* model	-	The model that will
											be linked to the
											created object

	Usage :			Call this static function while reading
					string representations of objects from a
					text file. Note that the caller is
					responsible for the allocated memory of
					the created object only. The created object
					will take ownership of the model being
					passed, which should be created on the heap.

   ============================================================*/
{
	CDiagramEntity* obj;

	obj = CWPPNPlaceView::CreateFromString(str, model);

	if (!obj)
		obj = CWPPNTransView::CreateFromString(str, model);

	if (!obj)
		obj = CWPPNArcView::CreateFromString(str, model);


	return obj;
}

CProMoModel* CWPPNControlFactory::CreateModelFromString(const CString& str)
/* ============================================================
	Function :		CWPPNControlFactory::CreateModelFromString
	Description :	The function returns an object from the
					parameter str.

	Return :		CDiagramEntity*		-	The new object, or
											NULL is str is not a
											valid representation.
	Parameters :	const CString& str	-	The string to create
											a new object from

	Usage :			Call this static function while reading
					string representations of objects from a
					text file. Note that the caller is
					responsible for the allocated memory.

   ============================================================*/
{
	CProMoModel* obj;

	obj = CWPPNPlaceModel::CreateFromString(str);

	if (!obj)
		obj = CWPPNTransModel::CreateFromString(str);

	if (!obj)
		obj = CWPPNArcModel::CreateFromString(str);

	return obj;
}

CDiagramEntity* CWPPNControlFactory::CreateNewEntity(const CString& str)
/* ============================================================
	Function :		CWPPNControlFactory::CreateNewEntity
	Description :	The function returns an object with a type
					corresponding to the parameter str.
	Return :		CDiagramEntity*		-	The new object, or
											NULL if str is not a
											valid object type.
	Parameters :	const CString& str	-	The object type to
											create
	Usage :			Call this static function from the UI or the
					automation interface to create new objects
					of the specified type. Note that the caller
					is responsible for the allocated memory.
   ============================================================*/
{
	CDiagramEntity* obj;

	obj = CWPPNPlaceView::Create(str);

	if (!obj)
		obj = CWPPNTransView::Create(str);

	if (!obj)
		obj = CWPPNArcView::Create(str);

	return obj;
}

void CWPPNControlFactory::GetEntityTypes(CStringArray& typeList)
/* ============================================================
	Function :		CWPPNControlFactory::GetEntityTypes
	Description :	Fills the provided list with the types of
					objects that can be created by this factory.
	Return :		void
	Parameters :	CStringArray& typeList	-	The list to fill
	Usage :			Call this function to get the list of
					available object types for use in the UI
					or the automation interface.
   ============================================================*/
{
	// Clear the list
	typeList.RemoveAll();
	// Add block types
	CDiagramEntity* obj = new CWPPNPlaceView;
	typeList.Add(obj->GetType());
	delete obj;
	// Add edge types
	obj = new CWPPNTransView;
	typeList.Add(obj->GetType());
	delete obj;
	// Add label types
	obj = new CWPPNArcView;
	typeList.Add(obj->GetType());
	delete obj;
}
