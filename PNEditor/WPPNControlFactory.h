#ifndef _WPPNCONTROLFACTORY_H_
#define _WPPNCONTROLFACTORY_H_

#include "../../WinProMo/DiagramEditor/DiagramEntity.h"
#include "../../WinProMo/ProMoEditor/ProMoModel.h"
#include "../../WinProMo/ProMoEditor/ProMoControlFactory.h"

class AFX_EXT_CLASS CWPPNControlFactory :
public CProMoControlFactory {

public:
	// Implementation
	virtual CDiagramEntity* CreateViewFromString(const CString& str);
	virtual CProMoModel* CreateModelFromString(const CString& str);

};

#endif // _WPPNCONTROLFACTORY_H_

