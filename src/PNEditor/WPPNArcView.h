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

    virtual UINT GetWeight() const;
    virtual void SetWeight(UINT weight);

    
    // Overrides
    virtual CDiagramEntity* Clone();
    virtual void	Draw(CDC* dc, CRect rect);
    static CDiagramEntity* CreateFromString(const CString& str);

};

#endif //_WPPNARCVIEW_H_

