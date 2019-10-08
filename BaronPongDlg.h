
// BaronPongDlg.h : header file
//

#pragma once

class JPanel;
// CBaronPongDlg dialog
class CBaronPongDlg : public CDialogEx
{
// Construction
public:
	CBaronPongDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CBaronPongDlg();

	JPanel *mGameView = nullptr;
	void Draw(double tInterpolation);
	double mInterpolation = 0;

	//afx_msg void OnPaint();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BARONPONG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	bool isFilled = true;
	std::string shape = "Rectangle";

public:
	afx_msg void OnBnClickedButton1();
	
	bool getFilled();

	std::string getShape();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonUndo();
};
