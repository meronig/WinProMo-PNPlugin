#ifndef _WPPNPLACEVIEW_H_
#define _WPPNPLACEVIEW_H_

#include "..\..\WinProMo\ProMoEditor\ProMoBlockView.h"
class AFX_EXT_CLASS CWPPNPlaceView :
    public CProMoBlockView
{
public:
    CWPPNPlaceView();

    // Overrides
    virtual CDiagramEntity* Clone();
    virtual void Draw(CDC* dc, CRect rect);
    
protected:
    virtual CPoint GetIntersection(CPoint innerPoint, CPoint outerPoint);

};

#endif //_WPPNPLACEVIEW_H_
