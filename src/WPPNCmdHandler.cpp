#include "stdafx.h"
#include "WPPNCmdHandler.h"
#include "resource.h"
#include "PNEditor/WPPNPlaceView.h"
#include "PNEditor/WPPNTransView.h"
#include "PNEditor/WPPNArcView.h"

CWPPNCmdHandler::CWPPNCmdHandler()
{
	m_editor = new CWPPNEditor;
}

CWPPNCmdHandler::~CWPPNCmdHandler()
{
	delete m_editor;
}

BOOL CWPPNCmdHandler::OnPluginCommand(UINT cmdID)
{
	switch (cmdID)
	{
	case ID_INSERT_PLACE:
		OnInsertPlace();
		return TRUE;

	case ID_INSERT_TRANS:
		OnInsertTrans();
		return TRUE;

	case ID_INSERT_ARC:
		OnInsertArc();
		return TRUE;

	default:
		return FALSE; // not handled
	}
}

BOOL CWPPNCmdHandler::OnPluginUpdateCommandUI(CCmdUI* pCmdUI)
{
	UINT cmdID = pCmdUI->m_nID;

	switch (cmdID)
	{
	case ID_INSERT_PLACE:
		OnUpdateInsertPlace(pCmdUI);
		return TRUE;

	case ID_INSERT_TRANS:
		OnUpdateInsertTrans(pCmdUI);
		return TRUE;

	case ID_INSERT_ARC:
		OnUpdateInsertArc(pCmdUI);
		return TRUE;

	default:
		return FALSE;
	}
}

CProMoEditor* CWPPNCmdHandler::GetEditor()
{
	return m_editor;
}

void CWPPNCmdHandler::OnInsertPlace()
{
	m_editor->UnselectAll();
	CWPPNPlaceView* obj = new CWPPNPlaceView;
	m_editor->StartDrawingObject(obj);

}

void CWPPNCmdHandler::OnUpdateInsertPlace(CCmdUI* pCmdUI)
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

void CWPPNCmdHandler::OnInsertTrans()
{
	m_editor->UnselectAll();
	CWPPNTransView* obj = new CWPPNTransView;
	m_editor->StartDrawingObject(obj);

}

void CWPPNCmdHandler::OnUpdateInsertTrans(CCmdUI* pCmdUI)
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

void CWPPNCmdHandler::OnInsertArc()
{
	m_editor->UnselectAll();
	CWPPNArcView* obj = new CWPPNArcView;
	m_editor->StartDrawingObject(obj);
}

void CWPPNCmdHandler::OnUpdateInsertArc(CCmdUI* pCmdUI)
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