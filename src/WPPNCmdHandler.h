#ifndef _WPPNCOMMANDHANDLER_H_
#define _WPPNCOMMANDHANDLER_H_

#include "../../WinProMo/src/WinProMoCmdHandler.h"
#include "PNEditor/WPPNEditor.h"

class AFX_EXT_CLASS CWPPNCmdHandler :
    public CWinProMoCmdHandler
{
public:
	CWPPNCmdHandler();
    virtual ~CWPPNCmdHandler();

	virtual void OnInsertPlace();
	virtual void OnUpdateInsertPlace(CCmdUI* pCmdUI);
	virtual void OnInsertTrans();
	virtual void OnUpdateInsertTrans(CCmdUI* pCmdUI);
	virtual void OnInsertArc();
	virtual void OnUpdateInsertArc(CCmdUI* pCmdUI);


	//overrides
	virtual BOOL OnPluginCommand(UINT cmdID);
	virtual BOOL OnPluginUpdateCommandUI(CCmdUI* pCmdUI);
	virtual CProMoEditor* GetEditor();

private:
	CWPPNEditor* m_editor;

};

#endif //_WPPNCOMMANDHANDLER_H_

