
// BaronPong.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <thread>

// CBaronPongApp:
// See BaronPong.cpp for the implementation of this class
//
class Logic;

class CBaronPongApp : public CWinApp
{
public:
	CBaronPongApp();
	~CBaronPongApp();

// Overrides
public:
	virtual BOOL InitInstance();
	Logic *mMainLogic;
	std::thread *mGameThread;

// Implementation
private:
	void GameLoop();
	bool mRunning = false;
	LARGE_INTEGER mNow = { 0 };
	LARGE_INTEGER mLastUpdateTime = { 0 };
	LARGE_INTEGER mLastDrawTime = { 0 };

	DECLARE_MESSAGE_MAP()
};

extern CBaronPongApp theApp;