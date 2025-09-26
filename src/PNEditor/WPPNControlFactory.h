/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNCONTROLFACTORY_H_
#define _WPPNCONTROLFACTORY_H_

#include "../../../WinProMo/src/DiagramEditor/DiagramEntity.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoModel.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoControlFactory.h"

class AFX_EXT_CLASS CWPPNControlFactory :
public CProMoControlFactory {

public:
	// Implementation
	virtual CDiagramEntity* CreateViewFromString(const CString& str);
	virtual CDiagramEntity* CreateViewFromString(const CString& str, CProMoModel* model);
	virtual CProMoModel* CreateModelFromString(const CString& str);

};

#endif // _WPPNCONTROLFACTORY_H_

