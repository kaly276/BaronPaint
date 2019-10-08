
// BaronPong.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "BaronPong.h"
#include "BaronPongDlg.h"
#include "Logic.h"
#include <time.h>
#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBaronPongApp

BEGIN_MESSAGE_MAP(CBaronPongApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CBaronPongApp construction

CBaronPongApp::CBaronPongApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	mMainLogic = new Logic;
}

CBaronPongApp::~CBaronPongApp()
{
	delete mMainLogic;
}

// The one and only CBaronPongApp object

CBaronPongApp theApp;


// CBaronPongApp initialization

BOOL CBaronPongApp::InitInstance()
{
	CWinApp::InitInstance();


	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CBaronPongDlg dlg;
	m_pMainWnd = &dlg;
	mRunning = true;
	mGameThread = new std::thread(&CBaronPongApp::GameLoop, this);

	INT_PTR nResponse = dlg.DoModal();
	if( nResponse == IDOK )
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if( nResponse == IDCANCEL )
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if( nResponse == -1 )
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	mRunning = false;
	mGameThread->join();
	delete mGameThread;

	// Delete the shell manager created above.
	if( pShellManager != NULL )
	{
		delete pShellManager;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

void CBaronPongApp::GameLoop()
{
	static double GAME_HERTZ = 5;
	static double TIME_BETWEEN_UPDATES = 1000000 / GAME_HERTZ;

	static double TARGET_FPS = 60;
	static double TARGET_TIME_BETWEEN_RENDERS = 1000000 / TARGET_FPS;

	while( mRunning )
	{
		LARGE_INTEGER tFreq;
		QueryPerformanceFrequency(&tFreq);
		QueryPerformanceCounter(&mNow);
		mNow.QuadPart *= 1000000;
		mNow.QuadPart /= tFreq.QuadPart;// Now we are microseconds.

		if( mLastUpdateTime.QuadPart == 0 )
		{
			mLastUpdateTime.QuadPart = mNow.QuadPart;
			mLastDrawTime.QuadPart = mNow.QuadPart;
		}

		// Update the game state if needed
		if( mNow.QuadPart - mLastUpdateTime.QuadPart > TIME_BETWEEN_UPDATES )
		{
			mMainLogic->Update(TIME_BETWEEN_UPDATES / (1000000));// Update wants seconds, and I'm tracking microseconds here.
			mLastUpdateTime.QuadPart += TIME_BETWEEN_UPDATES;
		}

		if( mNow.QuadPart - mLastDrawTime.QuadPart > TARGET_TIME_BETWEEN_RENDERS )
		{
			// Draw
			float tInterpolation = min(1.0f, (float)((mNow.QuadPart - mLastUpdateTime.QuadPart) / TIME_BETWEEN_UPDATES));
			((CBaronPongDlg*)m_pMainWnd)->Draw(tInterpolation);
			mLastDrawTime.QuadPart = mNow.QuadPart;
		}

		std::this_thread::yield();
	}
}
