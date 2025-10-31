/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNPLACEVIEW_H_
#define _WPPNPLACEVIEW_H_

#include "../../../WinProMo/src/ProMoEditor\ProMoBlockView.h"
class AFX_EXT_CLASS CWPPNPlaceView :
    public CProMoBlockView
{
public:
    CWPPNPlaceView();
    virtual ~CWPPNPlaceView();

    // Overrides
    virtual CDiagramEntity* Clone();

public:
    
    static CDiagramEntity* CreateFromString(const CString& str);
    static CDiagramEntity* CreateFromString(const CString& str, CProMoModel* model);

    
};

#endif //_WPPNPLACEVIEW_H_
