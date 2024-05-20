// WorldEmu.cpp : Defines the class behaviors for the application.
//

#include "petitiond/stdafx.h"
#include "petitiond/WorldEmu.h"
#include "petitiond/WorldEmuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorldEmuApp

BEGIN_MESSAGE_MAP(CWorldEmuApp, CWinApp)
    //{{AFX_MSG_MAP(CWorldEmuApp)
        // NOTE - the ClassWizard will add and remove mapping macros here.
        //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG
    ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorldEmuApp construction

CWorldEmuApp::CWorldEmuApp()
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWorldEmuApp object

CWorldEmuApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CWorldEmuApp initialization

BOOL CWorldEmuApp::InitInstance()
{
    // CG: The following block was added by the Windows Sockets component.
    {
        if (!AfxSocketInit())
        {
            AfxMessageBox(CG_IDS_SOCKETS_INIT_FAILED);
            return FALSE;
        }

    }
    AfxEnableControlContainer();

    SetRegistryKey( _T("NCSoft") );

    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.

#ifdef _AFXDLL
    Enable3dControls();			// Call this when using MFC in a shared DLL
#else
    Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

    CWorldEmuDlg dlg;
    m_pMainWnd = &dlg;
    int nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with OK
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with Cancel
    }

    // Since the dialog has been closed, return FALSE so that we exit the
    //  application, rather than start the application's message pump.
    return FALSE;
}
