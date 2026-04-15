/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNCOMMANDHANDLER_H_
#define _WPPNCOMMANDHANDLER_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoCmdHandler.h"

class AFX_EXT_CLASS CWPPNCmdHandler :
    public CProMoCmdHandler
{
public:
	CWPPNCmdHandler();

	virtual void OnInsertPlace();
	virtual void OnUpdateInsertPlace(CCmdUI* pCmdUI);
	virtual void OnInsertTrans();
	virtual void OnUpdateInsertTrans(CCmdUI* pCmdUI);
	virtual void OnInsertArc();
	virtual void OnUpdateInsertArc(CCmdUI* pCmdUI);


	//implements
	virtual BOOL OnPluginCommand(UINT cmdID);
	virtual BOOL OnPluginUpdateCommandUI(CCmdUI* pCmdUI);

};

#endif //_WPPNCOMMANDHANDLER_H_

