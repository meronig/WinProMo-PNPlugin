/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNARCMODEL_H_
#define _WPPNARCMODEL_H_

#include "..\..\WinProMo\ProMoEditor\ProMoEdgeModel.h"

class AFX_EXT_CLASS CWPPNArcModel :
    public CProMoEdgeModel
{
public: 
    CWPPNArcModel();
    virtual ~CWPPNArcModel();
    virtual UINT GetWeight() const;
    virtual void SetWeight(UINT weight);

    //Overrides
    virtual CProMoModel* Clone();
    virtual void	Copy(CProMoModel* obj);

    virtual BOOL CanConnectSource(CProMoModel* source);
    virtual BOOL CanConnectDestination(CProMoModel* destination);
    static	CProMoModel* CreateFromString(const CString& str);

protected:
    virtual CString				GetDefaultGetString() const;
    virtual BOOL				GetDefaultFromString(CString& str);


private:
    UINT m_weight;
};

#endif //_WPPNARCMODEL_H_

