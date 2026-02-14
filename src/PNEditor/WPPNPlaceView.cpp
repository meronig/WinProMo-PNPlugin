/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNPlaceView.h"
#include "WPPNPlaceModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"
#include <math.h>
#include "../../../WinProMo/src/GeometryUtils/DoublePoint.h"
#include "../../../WinProMo/src/GeometryUtils/IntersectionHelper.h"

CWPPNPlaceView::CWPPNPlaceView()
{
	SetConstraints(CSize(32, 32), CSize(-1, -1));
	SetType(_T("pn_place_view"));
	SetModel(new CWPPNPlaceModel());
    SetLockedProportions(TRUE);
    SetShape(SHAPE_ELLIPSE);
}

CWPPNPlaceView::~CWPPNPlaceView()
{
}

CDiagramEntity* CWPPNPlaceView::Clone()
{
	CWPPNPlaceView* obj = new CWPPNPlaceView;
	obj->Copy(this);
	obj->SetName(CProMoNameFactory::GetID());
	return obj;
}

CDiagramEntity* CWPPNPlaceView::CreateFromString(const CString& str)
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
{
    CWPPNPlaceView* obj = new CWPPNPlaceView;
    if (!obj->HasType(str))
    {
        delete obj;
        obj = NULL;
    }
    return obj;
}