
// BaronPongDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BaronPong.h"
#include "BaronPongDlg.h"
#include "JPanel.h"
#include "afxdialogex.h"
#include "GameObject.h"
#include "Sprite.h"
#include "CircObject.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBaronPongDlg dialog

CBaronPongDlg::~CBaronPongDlg()
{
	if( mGameView )
		delete mGameView;
}

CBaronPongDlg::CBaronPongDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BARONPONG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBaronPongDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBaronPongDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBaronPongDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBaronPongDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CBaronPongDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON4, &CBaronPongDlg::OnBnClickedButtonUndo)
END_MESSAGE_MAP()


// CBaronPongDlg message handlers

BOOL CBaronPongDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// This trick here is to get around the difficulty of adding a custom panel type to the visual editor
	CWnd *tTarget = GetDlgItem(IDC_PANELTARGET);
	RECT tTargetRect;
	tTarget->GetWindowRect(&tTargetRect);

	JPanel::RegisterClass();
	mGameView = new JPanel;
	mGameView->Create(JPanel::sWindowName, L"", 0, tTargetRect, this, IDC_GAMEPANEL);
	mGameView->ShowWindow(SW_SHOW);
	tTarget->DestroyWindow();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBaronPongDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// In case you need to get to the Dialog from somewhere
//CBaronPongDlg *tDialog = (CBaronPongDlg*)AfxGetMainWnd();

// And in case you need to get to the app
//CBaronPongApp* app = ( CBaronPongApp *)AfxGetApp();

void CBaronPongDlg::Draw(double tInterpolation)
{
	mInterpolation = tInterpolation;

	if( mGameView )
	{
		mGameView->Invalidate();
		Invalidate();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBaronPongDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBaronPongDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	CWnd* dialog = GetDlgItem(IDC_BUTTON1);

	if (isFilled == true) {
		dialog->SetWindowText(_T("Unfill"));
		isFilled = false;
	}
	else {
		dialog->SetWindowTextW(_T("Fill"));
		isFilled = true;
	}
}

void CBaronPongDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	CWnd* dialog = GetDlgItem(IDC_BUTTON2);

	if (shape == "Rectangle") {
		dialog->SetWindowText(_T("Circle"));
		shape = "Circle";
	}
	
	else {
		dialog->SetWindowText(_T("Rectangle"));
		shape = "Rectangle";
	}
}

bool CBaronPongDlg::getFilled() {
	return isFilled;
}

std::string CBaronPongDlg::getShape() {
	return shape;
}




void CBaronPongDlg::OnBnClickedButtonClear()
{
	// TODO: Add your control notification handler code here
	mGameView->clear();
}





void CBaronPongDlg::OnBnClickedButtonUndo()
{
	// TODO: Add your control notification handler code here
	mGameView->undo();
}
