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
    static CDiagramEntity* Create(const CString& str);


protected:
    virtual void DrawTail(CDC* dc, CRect rect, double size);

};

#endif //_WPPNARCVIEW_H_

