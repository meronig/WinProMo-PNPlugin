/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPPNPROPERTYWRAPPERS_H_
#define _WPPNPROPERTYWRAPPERS_H_

#include "WPPNPlaceView.h"
#include "../../../WinProMo/src/DiagramEditor/DiagramEditor.h"

BOOL SetPlaceMarking(CDiagramEntity* entity, CDiagramEditor* editor, const UINT& val);
BOOL SetArcWeight(CDiagramEntity* entity, CDiagramEditor* editor, const UINT& val);

#endif //_PNPROPERTYWRAPPERS_H_

