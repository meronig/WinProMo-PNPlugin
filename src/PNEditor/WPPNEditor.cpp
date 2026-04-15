/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPPNEditor

	Author :		Giovanni Meroni

	Purpose :		CWPPNEditor implements the editor class for the WinProMo
					Petri Net Plugin.
					Derive from CProMoEditor and override the constructor to 
					customize the appearance of the editor (e.g., background 
					color) and to set up any additional logic.

   ========================================================================*/
#include "StdAfx.h"
#include "WPPNEditor.h"

CWPPNEditor::CWPPNEditor()
{
	SetBackgroundColor(RGB(200, 250, 250));
}

CWPPNEditor::~CWPPNEditor()
{
}