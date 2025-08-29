/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNPLUGININTERFACE_H_
#define _WPPNPLUGININTERFACE_H_

#include "../../WinProMo/src/WinProMoPluginInterface.h"
class CWPPNPluginInterface :
    public CWinProMoPluginInterface
{
	virtual CMultiDocTemplate* RegisterPlugin(CRuntimeClass* pFrameClass, CProMoClipboardHandler* pClip);
	virtual CObArray* GetElements();
	virtual CObArray* GetCommands();
	virtual const CString GetDocumentType();
	virtual const UINT GetDocumentID();
	virtual void Destroy();
};

#endif