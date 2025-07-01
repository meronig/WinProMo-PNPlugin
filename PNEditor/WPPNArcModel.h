#ifndef _WPPNARCMODEL_H_
#define _WPPNARCMODEL_H_

#include "..\..\WinProMo\ProMoEditor\ProMoEdgeModel.h"

class AFX_EXT_CLASS CWPPNArcModel :
    public CProMoEdgeModel
{
public: 
    CWPPNArcModel();

    //Overrides
    virtual CProMoModel* Clone();
    virtual BOOL CanConnectSource(CProMoModel* source);
    virtual BOOL CanConnectDestination(CProMoModel* destination);
};

#endif //_WPPNARCMODEL_H_

