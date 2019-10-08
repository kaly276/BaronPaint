
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

	std::string getTypeToDraw() const;
	bool getFilled() const;
	COLORREF getColor() const;
	int getWidth() const;
	int getHeight() const;
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

	std::string typeToDraw = "Rect";
	bool isFilled = true;
	int width = 100;
	int height = 100;
	int red = 0;
	int green = 0;
	int blue = 0;
	CSliderCtrl widthCtrl;
	CSliderCtrl heightCtrl;

	CSliderCtrl redCtrl;
	CSliderCtrl greenCtrl;
	CSliderCtrl blueCtrl;

	CBrush mBrush;
public:
	afx_msg void OnBnClickedFill();
	afx_msg void OnBnClickedType();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedUndo();
	afx_msg void OnBnClickedClear();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
