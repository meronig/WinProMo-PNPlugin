/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNTransView.h"
#include "WPPNTransModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoNameFactory.h"

CWPPNTransView::CWPPNTransView()
{
	SetConstraints(CSize(32, 32), CSize(-1, -1));
	SetType(_T("pn_trans_view"));
	SetModel(new CWPPNTransModel());
	SetLockedProportions(FALSE);
	SetFitTitle(TRUE);
	SetShape(SHAPE_RECTANGLE);
}

CWPPNTransView::~CWPPNTransView()
{
}

CDiagramEntity* CWPPNTransView::Clone()
{
	CWPPNTransView* obj = new CWPPNTransView;
	obj->Copy(this);
	obj->SetName(CProMoNameFactory::GetID());
	return obj;
}

void CWPPNTransView::Draw(CDC* dc, CRect rect)
{
	ASSERT_VALID(this->GetModel());

	DrawShape(dc, rect);
	Highlight(dc, rect);

	CFont font;
	CString str;
	/* uncomment line below for debug */
	//str.Format(_T("%d,%d"), getModel()->getIncomingEdges()->GetSize(), getModel()->getOutgoingEdges()->GetSize());
	str = GetTitle();
	font.CreateFont(-round(12.0 * GetZoom()), 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, _T("Courier New"));
	dc->SelectObject(&font);
	int mode = dc->SetBkMode(TRANSPARENT);

	CRect textBounds(0, 0, 0, 0);
	dc->DrawText(str, &textBounds, DT_NOPREFIX | DT_SINGLELINE | DT_TOP | DT_CALCRECT);

	dc->DrawText(str, rect, DT_NOPREFIX | DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	
	dc->SelectStockObject(DEFAULT_GUI_FONT);
	dc->SetBkMode(mode);
}

CDiagramEntity* CWPPNTransView::CreateFromString(const CString& str)
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