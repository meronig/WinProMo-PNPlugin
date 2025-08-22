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
