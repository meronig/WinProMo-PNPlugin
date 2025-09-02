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

    virtual UINT GetMarking();
    virtual void SetMarking(UINT marking);

    // Overrides
    virtual CDiagramEntity* Clone();
    virtual void Draw(CDC* dc, CRect rect);
    virtual void SetModel(CProMoBlockModel* model);

    
    virtual void	SetRect(CRect rect);
    virtual void	SetRect(double left, double top, double right, double bottom);
    static CDiagramEntity* CreateFromString(const CString& str);


protected:    
    virtual CPoint GetIntersection(CPoint innerPoint, CPoint outerPoint);

private:
    virtual void ComputeMarkingRect(const UINT& text);

    CRect m_markingRect;
};

#endif //_WPPNPLACEVIEW_H_
