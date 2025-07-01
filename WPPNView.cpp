#include "StdAfx.h"
#include "WPPNView.h"
#include "resource.h"
#include "PNEditor/WPPNPlaceView.h"
#include "PNEditor/WPPNTransView.h"
#include "PNEditor/WPPNArcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPNView

IMPLEMENT_DYNCREATE(CWPPNView, CWinProMoView)

BEGIN_MESSAGE_MAP(CWPPNView, CWinProMoView)
	//{{AFX_MSG_MAP(CWinProMoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_INSERT_PLACE, OnInsertPlace)
	ON_UPDATE_COMMAND_UI(ID_INSERT_PLACE, OnUpdateInsertPlace)
	ON_COMMAND(ID_INSERT_TRANS, OnInsertTrans)
	ON_UPDATE_COMMAND_UI(ID_INSERT_TRANS, OnUpdateInsertTrans)
	ON_COMMAND(ID_INSERT_ARC, OnInsertArc)
	ON_UPDATE_COMMAND_UI(ID_INSERT_ARC, OnUpdateInsertArc)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPNView construction/destruction

CWPPNView::CWPPNView()
{
	
}

CWPPNView::~CWPPNView()
{
	
}

void CWPPNView::CreateEditor()
{
	if (!m_editor) {
		m_editor = new CWPPNEditor;
	}
}

void CWPPNView::OnInsertPlace()
{
	m_editor->UnselectAll();
	CWPPNPlaceView* obj = new CWPPNPlaceView;
	m_editor->StartDrawingObject(obj);

}

void CWPPNView::OnUpdateInsertPlace(CCmdUI* pCmdUI)
{
	if (m_editor->IsDrawing()) {
		CWPPNPlaceView* obj = dynamic_cast<CWPPNPlaceView*>(m_editor->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);

}

void CWPPNView::OnInsertTrans()
{
	m_editor->UnselectAll();
	CWPPNTransView* obj = new CWPPNTransView;
	m_editor->StartDrawingObject(obj);

}

void CWPPNView::OnUpdateInsertTrans(CCmdUI* pCmdUI)
{
	if (m_editor->IsDrawing()) {
		CWPPNTransView* obj = dynamic_cast<CWPPNTransView*>(m_editor->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);

}

void CWPPNView::OnInsertArc()
{
	m_editor->UnselectAll();
	CWPPNArcView* obj = new CWPPNArcView;
	m_editor->StartDrawingObject(obj);
}

void CWPPNView::OnUpdateInsertArc(CCmdUI* pCmdUI)
{
	if (m_editor->IsDrawing()) {
		CWPPNArcView* obj = dynamic_cast<CWPPNArcView*>(m_editor->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);
}