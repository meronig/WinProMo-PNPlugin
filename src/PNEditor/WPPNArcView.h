/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNARCVIEW_H_
#define _WPPNARCVIEW_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoEdgeView.h"

class AFX_EXT_CLASS CWPPNArcView :
    public CProMoEdgeView
{
public:
    CWPPNArcView();
    virtual ~CWPPNArcView();

    // Overrides
    virtual CDiagramEntity* Clone();
    static CDiagramEntity* CreateFromString(const CString& str);
    static	CDiagramEntity* CreateFromString(const CString& str, CProMoModel* model);

protected:
    virtual void DrawLine(CDC* dc, CRect rect);

};

#endif //_WPPNARCVIEW_H_

