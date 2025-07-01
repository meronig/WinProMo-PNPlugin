#ifndef _WPPNPLACEMODEL_H_
#define _WPPNPLACEMODEL_H_

#include "..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"
class AFX_EXT_CLASS CWPPNPlaceModel :
    public CProMoBlockModel
{
public:
    CWPPNPlaceModel();
    virtual UINT GetMarking();
    virtual void SetMarking(UINT marking);

    //Overrides
    virtual CProMoModel* Clone();
    virtual BOOL CanBeNested(CProMoBlockModel* block);
    static	CProMoModel* CreateFromString(const CString& str);

private:
    UINT m_marking;
};

#endif //_WPPNPLACEMODEL_H_

