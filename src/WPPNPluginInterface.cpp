/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#include "stdafx.h"
#include "WPPNPluginInterface.h"
#include "resource.h"
#include "PNEditor/WPPNControlFactory.h"
#include "WPPNCmdHandler.h"


CObArray* CWPPNPluginInterface::GetElements()
{
    CObArray* commands = new CObArray();
    if (commands) {
        CWinProMoPluginCommand* group1 = new CWinProMoPluginCommand();
        group1->m_commandID = 0;
        group1->m_caption = _T("Node");
        group1->m_icon = NULL;
        group1->m_subCommands = new CObArray;

        CWinProMoPluginCommand* cmd1 = new CWinProMoPluginCommand();
        cmd1->m_commandID = ID_INSERT_PLACE;
        cmd1->m_caption = _T("Place");
        cmd1->m_icon = AfxGetApp()->LoadIcon(IDI_ICON_PLACE);
        cmd1->m_subCommands = NULL;

        CWinProMoPluginCommand* cmd2 = new CWinProMoPluginCommand();
        cmd2->m_commandID = ID_INSERT_TRANS;
        cmd2->m_caption = _T("Transition");
        cmd2->m_icon = AfxGetApp()->LoadIcon(IDI_ICON_TRANS);
        cmd2->m_subCommands = NULL;

        group1->m_subCommands->Add(cmd1);
        group1->m_subCommands->Add(cmd2);

        CWinProMoPluginCommand* group2 = new CWinProMoPluginCommand();
        group2->m_commandID = 0;
        group2->m_caption = _T("Edge");
        group2->m_icon = NULL;
        group2->m_subCommands = new CObArray;

        CWinProMoPluginCommand* cmd3 = new CWinProMoPluginCommand();
        cmd3->m_commandID = ID_INSERT_ARC;
        cmd3->m_caption = _T("Arc");
        cmd3->m_icon = AfxGetApp()->LoadIcon(IDI_ICON_ARC);
        cmd3->m_subCommands = NULL;

        group2->m_subCommands->Add(cmd3);

        commands->Add(group1);
        commands->Add(group2);
    }
    return commands;
}

CObArray* CWPPNPluginInterface::GetCommands()
{
    return NULL;
}

const CString CWPPNPluginInterface::GetDocumentType()
{
    return _T("pnPlugin");
}

const UINT CWPPNPluginInterface::GetDocumentID()
{
    //needed for custom menus
    return IDR_WPPNPLUGIN;
}

const CString CWPPNPluginInterface::GetDocumentDescr()
{
    return CString("Petri Net");
}

void CWPPNPluginInterface::Destroy()
{
    delete this;
}

CProMoCmdHandler* CWPPNPluginInterface::GetCmdHandler()
{
    return new CWPPNCmdHandler;
}

CProMoEntityContainer* CWPPNPluginInterface::GetContainer()
{
    return new CProMoEntityContainer("pnPlugin");
}

CProMoControlFactory* CWPPNPluginInterface::GetControlFactory()
{
    return new CWPPNControlFactory;
}

CProMoRenderer* CWPPNPluginInterface::GetRenderer()
{
    return new CProMoRenderer;
}