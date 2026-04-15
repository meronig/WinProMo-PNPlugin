/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	Author :		Giovanni Meroni

	Purpose :		WinProMo demo plugin DLL initialization routines

   ========================================================================*/

#include "stdafx.h"
#include <afxdllx.h>
#include "WPPNPluginInterface.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static AFX_EXTENSION_MODULE WPPNPluginDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
/* =========================================================================
	Function :		DllMain
	Description :	DLL entry point
	Access :		Public

	Return :    	BOOL (non-zero is OK)
	Parameters :	HINSTANCE hInstance	-	handle to the DLL module
					DWORD dwReason		-	reason for calling function
					LPVOID lpReserved	-	reserved
   ========================================================================*/
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("WPPNPLUGIN.DLL Initializing!\n");

		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(WPPNPluginDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.
		// 
		// Insert this DLL into the resource chain
		new CDynLinkLibrary(WPPNPluginDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("WPPNPLUGIN.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(WPPNPluginDLL);
	}
	return 1;   // ok
}

extern "C" WPPNPLUGIN_API CWPPNPluginInterface * CreatePluginInstance() 
/* =========================================================================
	Function :		CreatePluginInstance
	Description :	Creates an instance of the plugin interface and returns
					a pointer to it.
	Access :		Public

	Return :    	CWPDemoPluginInterface*	-	pointer to the created plugin
												interface instance
	Parameters :	none
	Notes :			Customize this function to return a new instance of your
					plugin interface class. The returned class must implement
					the plugin interface (CWinProMoPluginInterface) and provide
					the necessary information and functionality for WinProMo to
					use the plugin.
   ========================================================================*/
{
	return new CWPPNPluginInterface;
}
