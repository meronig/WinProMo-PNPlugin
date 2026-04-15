/* ==========================================================================

    Copyright © 2025-26 Technical University of Denmark

    CWPDemoPluginInterface

    Author :		Giovanni Meroni

    Purpose :		CWPPNPluginInterface implements CWinProMoPluginInterface
                    for the WinProMo Petri Net Plugin.

   ========================================================================*/
#include "stdafx.h"
#include "WPPNPluginInterface.h"
#include "resource.h"
#include "PNEditor/WPPNControlFactory.h"
#include "PNEditor/WPPNCmdHandler.h"

CWPPNPluginInterface::CWPPNPluginInterface()
    : CWinProMoPluginInterface(IDR_WPPNPLUGIN, _T("pnPlugin"), _T("WinProMo Petri Net Plugin Diagram"), new CWPPNControlFactory())
    /* =========================================================================
        Function :		CWPPNPluginInterface::CWPDemoPluginInterface
        Description :	Constructor
        Access :		Public
        Return :    	void
        Parameters :	none
        Notes :			Customize the parameters passed to the base constructor to
                        set the document ID, type, description, and control factory
                        of your plugin. The document ID should be a unique integer
                        (e.g., 1234) that identifies the type of documents created by
                        the plugin. The document type should be a unique string (e.g.,
                        "demoPlugin") that identifies the type of documents created by
                        the plugin. The document description is a string that describes
                        the type of documents created by the plugin and is shown in the
                        "New" dialog when creating a new document. The control factory is
                        responsible for creating the controls of the diagram (e.g., nodes,
                        edges, labels, etc.) and their properties. You can create a custom
                        control factory by deriving from CProMoControlFactory and overriding
                        its methods to create your custom controls.
    * ========================================================================*/
{
}

CObArray* CWPPNPluginInterface::GetElements()
/* =========================================================================
    Function :		CWPPNPluginInterface::GetElements
    Description :	Returns the list of elements to be added to the Insert
                    menu and the tool palette. Each element is represented by
                    a CWinProMoPluginCommand object. To display a separator,
                    add a command with ID=0 and caption="-". To group commands
                    in a submenu, add a command with subcommands (m_subCommands)
                    containing the submenu commands.
    Access :		Public
    Return :    	CObArray* : list of CWinProMoPluginCommand objects
    Parameters :	none
    Notes :			Customize this method to add the elements of your diagram.
                    The command ID of each element will be passed to the
                    command handler (GetCmdHandler) when the element is
                    selected, so make sure to set it to a unique value and
                    handle it in the command handler.
* ========================================================================*/
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
/* =========================================================================
    Function :		CWPPNPluginInterface::GetCommands
    Description :	Returns the list of elements to be added as additional
                    menu entries (after the x menu) and toolbars. Each element
                    is represented by a CWinProMoPluginCommand object. To
                    display a separator, add a command with ID=0 and
                    caption="-". To group commands in a submenu, add a
                    command with subcommands (m_subCommands) containing the
                    submenu commands.
    Access :		Public
    Return :    	CObArray* : list of CWinProMoPluginCommand objects
    Parameters :	none
    Notes :			Customize this method if you need any plugin-specific
                    functionality (e.g., model checking) to be accessible
                    to the end-user.
* ========================================================================*/
{
    return NULL;
}

CProMoCmdHandler* CWPPNPluginInterface::GetCmdHandler()
/* =========================================================================
    Function :		CWPPNPluginInterface::GetCmdHandler
    Description :	Returns a pointer to the command handler of the plugin. The
                    command handler is responsible for handling the commands
                    defined in GetElements and GetCommands.
    Access :		Public
    Return :    	CProMoCmdHandler* : pointer to the command handler
    Parameters :	none
    Notes :			Customize this method to return an instance of your plugin's
                    command handler. Make sure that the command handler properly
                    handles all the commands defined in GetElements and GetCommands.
* ========================================================================*/
{
    return new CWPPNCmdHandler;
}