#ifndef _WPPNARCVIEW_H_
#define _WPPNARCVIEW_H_

#include "..\..\WinProMo\ProMoEditor\ProMoEdgeView.h"

class AFX_EXT_CLASS CWPPNArcView :
    public CProMoEdgeView
{
public:
    CWPPNArcView();
    virtual ~CWPPNArcView();
    
    // Overrides
    virtual CDiagramEntity* Clone();
    virtual void	Draw(CDC* dc, CRect rect);
    static CDiagramEntity* CreateFromString(const CString& str);

};

#endif //_WPPNARCVIEW_H_

