/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNPLACEMODEL_H_
#define _WPPNPLACEMODEL_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoBlockModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoLabel.h"

class AFX_EXT_CLASS CWPPNPlaceModel :
    public CProMoBlockModel
{
public:
    CWPPNPlaceModel();
    virtual ~CWPPNPlaceModel();
    
    //Overrides
    virtual CProMoModel* Clone();
    
    virtual BOOL CanBeNestedBy(CProMoBlockModel* block);
    static	CProMoModel* CreateFromString(const CString& str);

protected:
    virtual void CreateProperties();
    virtual void CustomizeLabel(CProMoLabel* label);

};

#endif //_WPPNPLACEMODEL_H_

