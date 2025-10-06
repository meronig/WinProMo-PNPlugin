/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNTRANSVIEW_H_
#define _WPPNTRANSVIEW_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoBlockView.h"

class AFX_EXT_CLASS CWPPNTransView :
    public CProMoBlockView
{
public:
    CWPPNTransView();
    virtual ~CWPPNTransView();

    // Overrides
    virtual CDiagramEntity* Clone();

    static CDiagramEntity* CreateFromString(const CString& str);
    static CDiagramEntity* CreateFromString(const CString& str, CProMoModel* model);

};

#endif //_WPPNTRANSVIEW_H_

