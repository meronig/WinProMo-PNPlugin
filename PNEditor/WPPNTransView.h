#ifndef _WPPNTRANSVIEW_H_
#define _WPPNTRANSVIEW_H_

#include "..\..\WinProMo\ProMoEditor\ProMoBlockView.h"
class AFX_EXT_CLASS CWPPNTransView :
    public CProMoBlockView
{
public:
    CWPPNTransView();

    // Overrides
    virtual CDiagramEntity* Clone();

    virtual void Draw(CDC* dc, CRect rect);

};

#endif //_WPPNTRANSVIEW_H_

