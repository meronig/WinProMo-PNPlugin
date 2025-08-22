/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNPropertyWrappers.h"
#include "WPPNPlaceModel.h"
#include "WPPNEditor.h"
#include "WPPNArcView.h"
#include "WPPNArcModel.h"

BOOL SetPlaceMarking(CDiagramEntity* entity, CDiagramEditor* editor, const UINT& val)
{
	CWPPNPlaceView* view = dynamic_cast<CWPPNPlaceView*>(entity);
	if (view) {
		view->SetMarking(val);
		return TRUE;
	}
	return FALSE;
}

BOOL SetArcWeight(CDiagramEntity* entity, CDiagramEditor* editor, const UINT& val)
{
	CWPPNArcView* view = dynamic_cast<CWPPNArcView*>(entity);
	if (view && val > 0) {
		CWPPNArcModel* model = dynamic_cast<CWPPNArcModel*>(view->GetModel());
		if (model) {
			model->SetWeight(val);
			return TRUE;
		}
	}
	return FALSE;
}
