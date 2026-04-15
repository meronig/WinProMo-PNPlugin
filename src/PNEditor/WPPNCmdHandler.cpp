/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPPNCmdHandler

	Author :		Giovanni Meroni

	Purpose :		CWPPNCmdHandler implements CWinProMoCmdHandler
					for the WinProMo Petri Net Plugin.

   ========================================================================*/
#include "stdafx.h"
#include "WPPNCmdHandler.h"
#include "../resource.h"
#include "WPPNPlaceView.h"
#include "WPPNTransView.h"
#include "WPPNArcView.h"
#include "WPPNEditor.h"

CWPPNCmdHandler::CWPPNCmdHandler()
	: CProMoCmdHandler(new CWPPNEditor)
/* =========================================================================
	Function :		CWPPNCmdHandler::CWPPNCmdHandler
	Description :	Constructor
	Access :		Public
	Return :    	void
	Parameters :	none
	Notes :			Customize the parameters passed to the base constructor to
					set the editor of your plugin. The editor is responsible
					for managing the diagram and its elements, and provides
					methods to manipulate them. You can create a custom
					editor deriving from CProMoEditor and overriding
					its methods.
* ========================================================================*/
{
}

BOOL CWPPNCmdHandler::OnPluginCommand(UINT cmdID)
/* =========================================================================
	Function :		CWPPNCmdHandler::OnPluginCommand
	Description :	Handles the commands of the plugin. This method is called
					when a command of the plugin is selected (e.g., from the
					Insert menu or the tool palette). The cmdID parameter is
					the ID of the command that was selected, which should match
					the ID of the command defined in the GetElements method of
					the plugin interface. You should handle each command by its ID
					and perform the appropriate action (e.g., insert a new element,
					modify the diagram, etc.). Return TRUE if the command was handled,
					or FALSE if it was not handled (in which case it will be routed to
					the next handler).
	Access :		Public
	Return :    	BOOL		-   "TRUE" if the command was handled, "FALSE"
									otherwise
	Parameters :	UINT cmdID  -   ID of the command that was selected
	Notes :			Customize this method to handle the commands of your plugin.
					Make sure to handle each command by its ID and perform the
					appropriate action. You can use the GetEditor() method to
					access the editor of the plugin and manipulate the diagram
					and its elements.
* ========================================================================*/
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
/* =========================================================================
	Function :		CWPPNCmdHandler::OnPluginUpdateCommandUI
	Description :	Updates the UI of the plugin commands. This method is called
					when the UI of the plugin needs to be updated (e.g., to check
					or uncheck a menu item or toolbar button). The pCmdUI parameter
					is a pointer to a CCmdUI object that represents the UI element
					to be updated. You should update the UI element based on the
					current state of the plugin (e.g., whether a command is active
					or not). Return TRUE if the UI was updated, or FALSE if it was
					not updated (in which case it will be routed to the next handler).
	Access :		Public
	Return :    	BOOL			-   "TRUE" if the UI was updated, "FALSE"
										otherwise
	Parameters :	CCmdUI* pCmdUI  -   pointer to the UI element to be updated
	Notes :			Customize this method to update the UI of your plugin commands.
					Make sure to update each UI element based on the current state
					of the plugin. You can use the GetEditor() method to access
					the editor of the plugin and manipulate the diagram and its elements.
* ========================================================================*/
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

void CWPPNCmdHandler::OnInsertPlace()
{
	GetEditor()->UnselectAll();
	CWPPNPlaceView* obj = new CWPPNPlaceView;
	GetEditor()->StartDrawingObject(obj);

}

void CWPPNCmdHandler::OnUpdateInsertPlace(CCmdUI* pCmdUI)
{
	if (GetEditor()->IsDrawing()) {
		CWPPNPlaceView* obj = dynamic_cast<CWPPNPlaceView*>(GetEditor()->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);

}

void CWPPNCmdHandler::OnInsertTrans()
{
	GetEditor()->UnselectAll();
	CWPPNTransView* obj = new CWPPNTransView;
	GetEditor()->StartDrawingObject(obj);

}

void CWPPNCmdHandler::OnUpdateInsertTrans(CCmdUI* pCmdUI)
{
	if (GetEditor()->IsDrawing()) {
		CWPPNTransView* obj = dynamic_cast<CWPPNTransView*>(GetEditor()->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);

}

void CWPPNCmdHandler::OnInsertArc()
{
	GetEditor()->UnselectAll();
	CWPPNArcView* obj = new CWPPNArcView;
	GetEditor()->StartDrawingObject(obj);
}

void CWPPNCmdHandler::OnUpdateInsertArc(CCmdUI* pCmdUI)
{
	if (GetEditor()->IsDrawing()) {
		CWPPNArcView* obj = dynamic_cast<CWPPNArcView*>(GetEditor()->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);
}