# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=WPPNPlugin - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to WPPNPlugin - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "WPPNPlugin - Win32 Release" && "$(CFG)" !=\
 "WPPNPlugin - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "WPPNPlugin.mak" CFG="WPPNPlugin - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WPPNPlugin - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "WPPNPlugin - Win32 Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "WPPNPlugin - Win32 Debug"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "WPPNPlugin - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\Release\WPPNPlugin.dll"

CLEAN : 
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\WPPNArcModel.obj"
	-@erase "$(INTDIR)\WPPNArcView.obj"
	-@erase "$(INTDIR)\WPPNControlFactory.obj"
	-@erase "$(INTDIR)\WPPNDoc.obj"
	-@erase "$(INTDIR)\WPPNEditor.obj"
	-@erase "$(INTDIR)\WPPNPlaceModel.obj"
	-@erase "$(INTDIR)\WPPNPlaceView.obj"
	-@erase "$(INTDIR)\WPPNPlugin.obj"
	-@erase "$(INTDIR)\WPPNPlugin.pch"
	-@erase "$(INTDIR)\WPPNPlugin.res"
	-@erase "$(INTDIR)\WPPNPluginInterface.obj"
	-@erase "$(INTDIR)\WPPNPropertyWrappers.obj"
	-@erase "$(INTDIR)\WPPNTransModel.obj"
	-@erase "$(INTDIR)\WPPNTransView.obj"
	-@erase "$(INTDIR)\WPPNView.obj"
	-@erase "$(OUTDIR)\WPPNPlugin.exp"
	-@erase "$(OUTDIR)\WPPNPlugin.lib"
	-@erase "..\Release\WPPNPlugin.dll"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D WPPNPLUGIN_EXPORTS=1 /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GR /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D WPPNPLUGIN_EXPORTS=1\
 /Fp"$(INTDIR)/WPPNPlugin.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/WPPNPlugin.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WPPNPlugin.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 ../WinPromo/Release/WinProMo.lib /nologo /base:0x14000000 /subsystem:windows /dll /machine:I386 /out:"../Release/WPPNPlugin.dll"
# SUBTRACT LINK32 /nodefaultlib
LINK32_FLAGS=../WinPromo/Release/WinProMo.lib /nologo /base:0x14000000\
 /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)/WPPNPlugin.pdb"\
 /machine:I386 /out:"../Release/WPPNPlugin.dll"\
 /implib:"$(OUTDIR)/WPPNPlugin.lib" 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WPPNArcModel.obj" \
	"$(INTDIR)\WPPNArcView.obj" \
	"$(INTDIR)\WPPNControlFactory.obj" \
	"$(INTDIR)\WPPNDoc.obj" \
	"$(INTDIR)\WPPNEditor.obj" \
	"$(INTDIR)\WPPNPlaceModel.obj" \
	"$(INTDIR)\WPPNPlaceView.obj" \
	"$(INTDIR)\WPPNPlugin.obj" \
	"$(INTDIR)\WPPNPlugin.res" \
	"$(INTDIR)\WPPNPluginInterface.obj" \
	"$(INTDIR)\WPPNPropertyWrappers.obj" \
	"$(INTDIR)\WPPNTransModel.obj" \
	"$(INTDIR)\WPPNTransView.obj" \
	"$(INTDIR)\WPPNView.obj"

"..\Release\WPPNPlugin.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WPPNPlugin - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\Debug\WPPNPlugin.dll"

CLEAN : 
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\WPPNArcModel.obj"
	-@erase "$(INTDIR)\WPPNArcView.obj"
	-@erase "$(INTDIR)\WPPNControlFactory.obj"
	-@erase "$(INTDIR)\WPPNDoc.obj"
	-@erase "$(INTDIR)\WPPNEditor.obj"
	-@erase "$(INTDIR)\WPPNPlaceModel.obj"
	-@erase "$(INTDIR)\WPPNPlaceView.obj"
	-@erase "$(INTDIR)\WPPNPlugin.obj"
	-@erase "$(INTDIR)\WPPNPlugin.pch"
	-@erase "$(INTDIR)\WPPNPlugin.res"
	-@erase "$(INTDIR)\WPPNPluginInterface.obj"
	-@erase "$(INTDIR)\WPPNPropertyWrappers.obj"
	-@erase "$(INTDIR)\WPPNTransModel.obj"
	-@erase "$(INTDIR)\WPPNTransView.obj"
	-@erase "$(INTDIR)\WPPNView.obj"
	-@erase "$(OUTDIR)\WPPNPlugin.exp"
	-@erase "$(OUTDIR)\WPPNPlugin.lib"
	-@erase "$(OUTDIR)\WPPNPlugin.pdb"
	-@erase "..\Debug\WPPNPlugin.dll"
	-@erase "..\Debug\WPPNPlugin.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D WPPNPLUGIN_EXPORTS=1 /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GR /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D\
 WPPNPLUGIN_EXPORTS=1 /Fp"$(INTDIR)/WPPNPlugin.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/WPPNPlugin.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WPPNPlugin.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 ../WinPromo/Debug/WinProMo.lib /nologo /base:0x14000000 /subsystem:windows /dll /debug /machine:I386 /out:"../Debug/WPPNPlugin.dll"
# SUBTRACT LINK32 /nodefaultlib
LINK32_FLAGS=../WinPromo/Debug/WinProMo.lib /nologo /base:0x14000000\
 /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)/WPPNPlugin.pdb" /debug\
 /machine:I386 /out:"../Debug/WPPNPlugin.dll" /implib:"$(OUTDIR)/WPPNPlugin.lib"\
 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WPPNArcModel.obj" \
	"$(INTDIR)\WPPNArcView.obj" \
	"$(INTDIR)\WPPNControlFactory.obj" \
	"$(INTDIR)\WPPNDoc.obj" \
	"$(INTDIR)\WPPNEditor.obj" \
	"$(INTDIR)\WPPNPlaceModel.obj" \
	"$(INTDIR)\WPPNPlaceView.obj" \
	"$(INTDIR)\WPPNPlugin.obj" \
	"$(INTDIR)\WPPNPlugin.res" \
	"$(INTDIR)\WPPNPluginInterface.obj" \
	"$(INTDIR)\WPPNPropertyWrappers.obj" \
	"$(INTDIR)\WPPNTransModel.obj" \
	"$(INTDIR)\WPPNTransView.obj" \
	"$(INTDIR)\WPPNView.obj"

"..\Debug\WPPNPlugin.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "WPPNPlugin - Win32 Release"
# Name "WPPNPlugin - Win32 Debug"

!IF  "$(CFG)" == "WPPNPlugin - Win32 Release"

!ELSEIF  "$(CFG)" == "WPPNPlugin - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "WPPNPlugin - Win32 Release"

!ELSEIF  "$(CFG)" == "WPPNPlugin - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPPNPlugin.cpp
DEP_CPP_WPPNP=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\StdAfx.h"\
	"..\WinProMo\WinProMoPluginInterface.h"\
	".\StdAfx.h"\
	".\WPPNPluginInterface.h"\
	

"$(INTDIR)\WPPNPlugin.obj" : $(SOURCE) $(DEP_CPP_WPPNP) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "WPPNPlugin - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GR /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D WPPNPLUGIN_EXPORTS=1\
 /Fp"$(INTDIR)/WPPNPlugin.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\WPPNPlugin.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "WPPNPlugin - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D\
 WPPNPLUGIN_EXPORTS=1 /Fp"$(INTDIR)/WPPNPlugin.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\WPPNPlugin.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPPNPlugin.rc
DEP_RSC_WPPNPL=\
	".\res\WPPNPlugin.rc2"\
	

"$(INTDIR)\WPPNPlugin.res" : $(SOURCE) $(DEP_RSC_WPPNPL) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPPNView.cpp
DEP_CPP_WPPNV=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEditor.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramMenu.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoEntityContainer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	"..\WinProMo\WinProMoDoc.h"\
	"..\WinProMo\WinProMoView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEditor.h"\
	".\PNEditor\WPPNArcView.h"\
	".\PNEditor\WPPNEditor.h"\
	".\PNEditor\WPPNPlaceView.h"\
	".\PNEditor\WPPNTransView.h"\
	".\StdAfx.h"\
	".\WPPNView.h"\
	

"$(INTDIR)\WPPNView.obj" : $(SOURCE) $(DEP_CPP_WPPNV) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPPNPluginInterface.cpp
DEP_CPP_WPPNPLU=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEditor.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramMenu.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoEntityContainer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	"..\WinProMo\WinProMoDoc.h"\
	"..\WinProMo\WinProMoDocTemplate.h"\
	"..\WinProMo\WinProMoPluginInterface.h"\
	"..\WinProMo\WinProMoView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEditor.h"\
	".\PNEditor\WPPNEditor.h"\
	".\StdAfx.h"\
	".\WPPNDoc.h"\
	".\WPPNPluginInterface.h"\
	".\WPPNView.h"\
	

"$(INTDIR)\WPPNPluginInterface.obj" : $(SOURCE) $(DEP_CPP_WPPNPLU) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPPNDoc.cpp
DEP_CPP_WPPND=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoEntityContainer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	"..\WinProMo\WinProMoDoc.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\WPPNControlFactory.h"\
	".\StdAfx.h"\
	".\WPPNDoc.h"\
	

"$(INTDIR)\WPPNDoc.obj" : $(SOURCE) $(DEP_CPP_WPPND) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PNEditor\WPPNTransView.cpp
DEP_CPP_WPPNT=\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\ProMoNameFactory.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\WPPNTransModel.h"\
	".\PNEditor\WPPNTransView.h"\
	
NODEP_CPP_WPPNT=\
	".\PNEditor\StdAfx.h"\
	

"$(INTDIR)\WPPNTransView.obj" : $(SOURCE) $(DEP_CPP_WPPNT) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PNEditor\WPPNArcView.cpp
DEP_CPP_WPPNA=\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\ProMoNameFactory.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	".\PNEditor\WPPNArcModel.h"\
	".\PNEditor\WPPNArcView.h"\
	
NODEP_CPP_WPPNA=\
	".\PNEditor\StdAfx.h"\
	

"$(INTDIR)\WPPNArcView.obj" : $(SOURCE) $(DEP_CPP_WPPNA) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PNEditor\WPPNEditor.cpp
DEP_CPP_WPPNE=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEditor.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramMenu.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\PropertyItem\PropertyItem.h"\
	"..\WinProMo\PropertyItem\TypedPropertyItem.h"\
	"..\WinProMo\PropertyItem\TypedPropertyItem.hxx"\
	"..\WinProMo\StdAfx.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEditor.h"\
	".\PNEditor\WPPNArcModel.h"\
	".\PNEditor\WPPNArcView.h"\
	".\PNEditor\WPPNEditor.h"\
	".\PNEditor\WPPNPlaceModel.h"\
	".\PNEditor\WPPNPlaceView.h"\
	".\PNEditor\WPPNPropertyWrappers.h"\
	
NODEP_CPP_WPPNE=\
	".\PNEditor\StdAfx.h"\
	

"$(INTDIR)\WPPNEditor.obj" : $(SOURCE) $(DEP_CPP_WPPNE) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PNEditor\WPPNPlaceModel.cpp
DEP_CPP_WPPNPLA=\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\StdAfx.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\WPPNPlaceModel.h"\
	
NODEP_CPP_WPPNPLA=\
	".\PNEditor\StdAfx.h"\
	

"$(INTDIR)\WPPNPlaceModel.obj" : $(SOURCE) $(DEP_CPP_WPPNPLA) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PNEditor\WPPNPlaceView.cpp
DEP_CPP_WPPNPLAC=\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\ProMoNameFactory.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\WPPNPlaceModel.h"\
	".\PNEditor\WPPNPlaceView.h"\
	
NODEP_CPP_WPPNPLAC=\
	".\PNEditor\StdAfx.h"\
	

"$(INTDIR)\WPPNPlaceView.obj" : $(SOURCE) $(DEP_CPP_WPPNPLAC) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PNEditor\WPPNTransModel.cpp
DEP_CPP_WPPNTR=\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\StdAfx.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\WPPNTransModel.h"\
	
NODEP_CPP_WPPNTR=\
	".\PNEditor\StdAfx.h"\
	

"$(INTDIR)\WPPNTransModel.obj" : $(SOURCE) $(DEP_CPP_WPPNTR) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PNEditor\WPPNArcModel.cpp
DEP_CPP_WPPNAR=\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	".\PNEditor\WPPNArcModel.h"\
	
NODEP_CPP_WPPNAR=\
	".\PNEditor\StdAfx.h"\
	

"$(INTDIR)\WPPNArcModel.obj" : $(SOURCE) $(DEP_CPP_WPPNAR) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PNEditor\WPPNControlFactory.cpp
DEP_CPP_WPPNC=\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	".\PNEditor\WPPNArcModel.h"\
	".\PNEditor\WPPNArcView.h"\
	".\PNEditor\WPPNControlFactory.h"\
	".\PNEditor\WPPNPlaceModel.h"\
	".\PNEditor\WPPNPlaceView.h"\
	".\PNEditor\WPPNTransModel.h"\
	".\PNEditor\WPPNTransView.h"\
	
NODEP_CPP_WPPNC=\
	".\PNEditor\StdAfx.h"\
	

"$(INTDIR)\WPPNControlFactory.obj" : $(SOURCE) $(DEP_CPP_WPPNC) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PNEditor\WPPNPropertyWrappers.cpp
DEP_CPP_WPPNPR=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEditor.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramMenu.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\StdAfx.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeModel.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	".\PNEditor\..\..\WinProMo\ProMoEditor\ProMoEditor.h"\
	".\PNEditor\WPPNArcModel.h"\
	".\PNEditor\WPPNArcView.h"\
	".\PNEditor\WPPNEditor.h"\
	".\PNEditor\WPPNPlaceModel.h"\
	".\PNEditor\WPPNPlaceView.h"\
	".\PNEditor\WPPNPropertyWrappers.h"\
	
NODEP_CPP_WPPNPR=\
	".\PNEditor\StdAfx.h"\
	

"$(INTDIR)\WPPNPropertyWrappers.obj" : $(SOURCE) $(DEP_CPP_WPPNPR) "$(INTDIR)"\
 "$(INTDIR)\WPPNPlugin.pch"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
