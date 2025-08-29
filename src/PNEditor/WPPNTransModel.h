/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNTRANSMODEL_H_
#define _WPPNTRANSMODEL_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoBlockModel.h"
class AFX_EXT_CLASS CWPPNTransModel :
    public CProMoBlockModel
{
public:
    CWPPNTransModel();
    virtual ~CWPPNTransModel();

    //Overrides
    virtual CProMoModel* Clone();
    virtual BOOL CanBeNestedBy(CProMoBlockModel* block);
    static	CProMoModel* CreateFromString(const CString& str);

};

#endif _WPPNTRANSMODEL_H_

