#include "StdAfx.h"
#include "WPPNEditor.h"
#include "../../WinProMo/PropertyItem/TypedPropertyItem.h"
#include "WPPNPropertyWrappers.h"
#include "WPPNPlaceView.h"
#include "WPPNPlaceModel.h"
#include "WPPNArcView.h"
#include "WPPNArcModel.h"

CWPPNEditor::CWPPNEditor()
{
	SetBackgroundColor(RGB(200, 250, 250));
}

CWPPNEditor::~CWPPNEditor()
{
}

CObArray* CWPPNEditor::GetProperties(CDiagramEntity* element) 
{
	CObArray* pProps = CProMoEditor::GetProperties(element);
	if (pProps) {
		CWPPNPlaceView* placeView = dynamic_cast<CWPPNPlaceView*>(element);
		if (placeView) {
			CWPPNPlaceModel* placeModel = dynamic_cast<CWPPNPlaceModel*>(placeView->GetModel());
			if (placeModel) {
				// Create a property item for "Marking"
				CTypedPropertyItem<UINT>* pMarking = new CTypedPropertyItem<UINT>(_T("Marking"), placeView, this, &SetPlaceMarking, placeModel->GetMarking());
				pProps->Add(pMarking);
			}
		}
		CWPPNArcView* arcView = dynamic_cast<CWPPNArcView*>(element);
		if (arcView) {
			CWPPNArcModel* arcModel = dynamic_cast<CWPPNArcModel*>(arcView->GetModel());
			if (arcModel) {
				// Create a property item for "Weight"
				CTypedPropertyItem<UINT>* pWeight = new CTypedPropertyItem<UINT>(_T("Weight"), arcView, this, &SetArcWeight, arcModel->GetWeight());
				pProps->Add(pWeight);
			}
		}
	}
	return pProps;
}
