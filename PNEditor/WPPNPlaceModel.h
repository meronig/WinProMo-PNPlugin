/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNPLACEMODEL_H_
#define _WPPNPLACEMODEL_H_

#include "..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"
class AFX_EXT_CLASS CWPPNPlaceModel :
    public CProMoBlockModel
{
public:
    CWPPNPlaceModel();
    virtual ~CWPPNPlaceModel();
    virtual UINT GetMarking() const;
    virtual void SetMarking(UINT marking);

    //Overrides
    virtual CProMoModel* Clone();
    virtual void	Copy(CProMoModel* obj);

    virtual BOOL CanBeNested(CProMoBlockModel* block);
    static	CProMoModel* CreateFromString(const CString& str);

protected:
    virtual CString				GetDefaultGetString() const;
    virtual BOOL				GetDefaultFromString(CString& str);


private:
    UINT m_marking;
};

#endif //_WPPNPLACEMODEL_H_

