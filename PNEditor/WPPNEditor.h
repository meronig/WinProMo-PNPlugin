/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _PNEDITOR_H_
#define _PNEDITOR_H_

#include "..\..\WinProMo\ProMoEditor\ProMoEditor.h"
class AFX_EXT_CLASS CWPPNEditor :
    public CProMoEditor
{
public:
	// Construction/initialization/destruction
	CWPPNEditor();
	virtual ~CWPPNEditor();

// Overrides
protected:
	virtual CObArray* GetProperties(CDiagramEntity* element);
};

#endif

