/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _PNVIEW_H_
#define _PNVIEW_H_

#include "..\WinProMo\WinProMoView.h"
#include ".\PNEditor\WPPNEditor.h"
class WPPNPLUGIN_API CWPPNView :
    public CWinProMoView
	
{
protected: // create from serialization only
	DECLARE_DYNCREATE(CWPPNView)

	// Operations
public:
	CWPPNView();
	virtual ~CWPPNView();

protected:
	virtual void CreateEditor();
	//{{AFX_MSG(CWPDemoView)
	// NOTE - the ClassWizard will add and remove member functions here.
	//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnInsertPlace();
	afx_msg void OnUpdateInsertPlace(CCmdUI* pCmdUI);
	afx_msg void OnInsertTrans();
	afx_msg void OnUpdateInsertTrans(CCmdUI* pCmdUI);
	afx_msg void OnInsertArc();
	afx_msg void OnUpdateInsertArc(CCmdUI* pCmdUI);
	//}}AFX_MSG
	//Commands
	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // debug version in WinProMoView.cpp
inline CWinProMoDoc* CPNView::GetDocument()
{
	return (CWinProMoDoc*)m_pDocument;
}
#endif

#endif //_PNVIEW_H_