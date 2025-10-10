/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNARCMODEL_H_
#define _WPPNARCMODEL_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoEdgeModel.h"

class AFX_EXT_CLASS CWPPNArcModel :
    public CProMoEdgeModel
{
public: 
    CWPPNArcModel();
    virtual ~CWPPNArcModel();
    
    //Overrides
    virtual CProMoModel* Clone();
    
    virtual BOOL CanConnectSource(CProMoBlockModel* source);
    virtual BOOL CanConnectDestination(CProMoBlockModel* destination);
    static	CProMoModel* CreateFromString(const CString& str);

protected:
    virtual void CreateProperties();

};

#endif //_WPPNARCMODEL_H_

