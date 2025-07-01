#ifndef _WPPNARCVIEW_H_
#define _WPPNARCVIEW_H_

#include "..\..\WinProMo\ProMoEditor\ProMoEdgeView.h"

class AFX_EXT_CLASS CWPPNArcView :
    public CProMoEdgeView
{
public:
    CWPPNArcView();
    
    // Overrides
    virtual CDiagramEntity* Clone();
    virtual void	Draw(CDC* dc, CRect rect);

};

#endif //_WPPNARCVIEW_H_

