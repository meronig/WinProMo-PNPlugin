/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

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
