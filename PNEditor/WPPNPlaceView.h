/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNPLACEVIEW_H_
#define _WPPNPLACEVIEW_H_

#include "..\..\WinProMo\ProMoEditor\ProMoBlockView.h"
class AFX_EXT_CLASS CWPPNPlaceView :
    public CProMoBlockView
{
public:
    CWPPNPlaceView();
    virtual ~CWPPNPlaceView();

    virtual UINT GetMarking();
    virtual void SetMarking(UINT marking);

    // Overrides
    virtual CDiagramEntity* Clone();
    virtual void Draw(CDC* dc, CRect rect);
    virtual void SetModel(CProMoBlockModel* model);
    
    static CDiagramEntity* CreateFromString(const CString& str);

protected:    
    virtual CPoint GetIntersection(CPoint innerPoint, CPoint outerPoint);
    virtual void ComputeMinimumSize();
};

#endif //_WPPNPLACEVIEW_H_
