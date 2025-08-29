/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _PNDOC_H_
#define _PNDOC_H_

#include "../../WinProMo/src/WinProMoDoc.h"
class WPPNPLUGIN_API CWPPNDoc :
    public CWinProMoDoc
{
protected: // create from serialization only
    DECLARE_DYNCREATE(CWPPNDoc)

    // Operations
public:
    CWPPNDoc();
    virtual ~CWPPNDoc();

    virtual void CreateControlFactory();
    virtual void CreateContainer();


};

#endif
