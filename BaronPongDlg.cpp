
// BaronPongDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BaronPong.h"
#include "BaronPongDlg.h"
#include "JPanel.h"
#include "afxdialogex.h"

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
	DDX_Control(pDX, IDC_WIDTH, widthCtrl);
	DDX_Control(pDX, IDC_HEIGHT, heightCtrl);
	DDX_Control(pDX, IDC_RED, redCtrl);
	DDX_Control(pDX, IDC_GREEN, greenCtrl);
	DDX_Control(pDX, IDC_BLUE, blueCtrl);
}

BEGIN_MESSAGE_MAP(CBaronPongDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FILL, &CBaronPongDlg::OnBnClickedFill)
	ON_BN_CLICKED(IDC_TYPE, &CBaronPongDlg::OnBnClickedType)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_UNDO, &CBaronPongDlg::OnBnClickedUndo)
	ON_BN_CLICKED(IDC_CLEAR, &CBaronPongDlg::OnBnClickedClear)
	ON_WM_CTLCOLOR()
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
	widthCtrl.SetRange(50, 150, TRUE);
	widthCtrl.SetPos(100);
	heightCtrl.SetRange(50, 150, TRUE);
	heightCtrl.SetPos(100);
	redCtrl.SetRange(0, 255, TRUE);
	redCtrl.SetPos(0);
	greenCtrl.SetRange(0, 255, TRUE);
	greenCtrl.SetPos(0);
	blueCtrl.SetRange(0, 255, TRUE);
	blueCtrl.SetPos(0);

	CWnd *tTarget;
	CString str;

	tTarget = GetDlgItem(IDC_WIDTH_VALUE);
	str.Format(_T("%d px"), width);
	tTarget->SetWindowText(str);

	tTarget = GetDlgItem(IDC_HEIGHT_VALUE);
	str.Format(_T("%d px"), height);
	tTarget->SetWindowText(str);
	// This trick here is to get around the difficulty of adding a custom panel type to the visual editor

	tTarget = GetDlgItem(IDC_PANELTARGET);
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

std::string CBaronPongDlg::getTypeToDraw() const
{
	return typeToDraw;
}

bool CBaronPongDlg::getFilled() const
{
	return isFilled;
}

COLORREF CBaronPongDlg::getColor() const
{
	return RGB(red, green, blue);
}

int CBaronPongDlg::getWidth() const
{
	return width;
}

int CBaronPongDlg::getHeight() const
{
	return height;
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBaronPongDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBaronPongDlg::OnBnClickedFill()
{
	CWnd *tTarget = GetDlgItem(IDC_FILL); 
	if (isFilled)
	{
		tTarget->SetWindowText(_T("Hollow"));
		isFilled = false;
	}
	else
	{
		tTarget->SetWindowText(_T("Filled"));
		isFilled = true;
	}
}


void CBaronPongDlg::OnBnClickedType()
{
	CWnd *tTarget = GetDlgItem(IDC_TYPE);
	if (typeToDraw == "Rect")
	{
		tTarget->SetWindowText(_T("Eclipse"));
		typeToDraw = "Eclipse";
	}
	else
	{
		tTarget->SetWindowText(_T("Rectangle"));
		typeToDraw = "Rect";
	}
}

void CBaronPongDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CWnd *tTarget; 
	CString str;
	
	if (pScrollBar == (CScrollBar *)&widthCtrl)
	{
		width = widthCtrl.GetPos();
		tTarget = GetDlgItem(IDC_WIDTH_VALUE);
		str.Format(_T("%d px"), width);
		tTarget->SetWindowText(str);
		UpdateData(FALSE);
	}
	else if (pScrollBar == (CScrollBar *)&heightCtrl)
	{
		height = heightCtrl.GetPos();
		tTarget = GetDlgItem(IDC_HEIGHT_VALUE);
		str.Format(_T("%d px"), height);
		tTarget->SetWindowText(str);
		UpdateData(FALSE);
	}
	else if (pScrollBar == (CScrollBar *)&redCtrl)
	{
		red = redCtrl.GetPos();
		tTarget = GetDlgItem(IDC_RED_VALUE);
		str.Format(_T("%d"), red);
		tTarget->SetWindowText(str);
		UpdateData(FALSE);
	}
	else if (pScrollBar == (CScrollBar *)&greenCtrl)
	{
		green = greenCtrl.GetPos();
		tTarget = GetDlgItem(IDC_GREEN_VALUE);
		str.Format(_T("%d"), green);
		tTarget->SetWindowText(str);
		UpdateData(FALSE);
	}
	else if (pScrollBar == (CScrollBar *)&blueCtrl)
	{
		blue = blueCtrl.GetPos();
		tTarget = GetDlgItem(IDC_BLUE_VALUE);
		str.Format(_T("%d"), blue);
		tTarget->SetWindowText(str);
		UpdateData(FALSE);
	}
	else
	{
		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	
}


void CBaronPongDlg::OnBnClickedUndo()
{
	mGameView->undo();
}




void CBaronPongDlg::OnBnClickedClear()
{
	mGameView->clear();
}

HBRUSH CBaronPongDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	// Call the base class implementation first! Otherwise, it may
	// undo what we're trying to accomplish here.
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// Are we painting the IDC_MYSTATIC control? We can use
	// CWnd::GetDlgCtrlID() to perform the most efficient test.
	if (pWnd->GetDlgCtrlID() == IDC_PREVIEW)
	{
		// Set the text color to red
		mBrush.DeleteObject();
		mBrush.CreateSolidBrush(getColor());
		pDC->SetBkColor(getColor());

		// Return handle to our CBrush object
		hbr = mBrush;
	}

	return hbr;
}
