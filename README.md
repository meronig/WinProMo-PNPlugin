# WinProMo-PNPlugin

WinProMo-PNPlugin is a plugin for WinProMo-Editor that allows to model basic Petri Nets

# Compiling

Before compiling this project, make sure that: 

* You cloned both this repository and the one of the WinProMo library (https://github.com/meronig/WinProMo).

* The folders containing the repositories are siblings.

* The folder containing the WinProMo library is named ``WinProMo'' (without quotation marks).

* You already compiled the WinProMo library.

To compile WinProMo-PNPlugin, you will need Microsoft Visual C++, the Microsoft Foundation Classes library, and Microsoft Windows SDK. The freely available Community version of Visual Studio 2022 can satisfy these dependencies.

A Microsoft Visual C++ 2022 project file (WinProMo-App.vcxproj) is included in this repository. For older versions of Microsoft Visual C++, you will have to create your own project file. WinProMo-PNPlugin can be compiled with Microsoft Visual C++ 4.0 onwards (really!). Depending on the version of Microsoft Visual C++ being used, the resulting DLL can run under Microsoft Windows 95/NT 3.51 up to Windows 11, on any supported target architecture. However, WinProMo-PNPlugin has been extensively tested only under Microsoft Windows 10/11 x64.

Note that both WinProMo and WinProMo-PNPlugin must be compiled with the same version of Microsoft Visual C++ for the same target architecture. Otherwise, WinProMo-PNPlugin may crash or malfunction.

# Acknowledgements

Copyright © 2025 Technical University of Denmark

This computer program makes use of the CDiagramEditor public domain souce code by Johan Rosengren, Abstrakt Mekanik AB: http://www.abstraktmekanik.se/freebies.html

Microsoft Visual Studio, Microsoft Visual C++, Microsoft Foundation Classes (MFC) and Microsoft Windows are trademarks of the Microsoft group of companies.