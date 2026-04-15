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
public:
	CWPPNPluginInterface();
	virtual CObArray* GetElements();
	virtual CObArray* GetCommands();
	virtual CProMoCmdHandler* GetCmdHandler();
};

#endif