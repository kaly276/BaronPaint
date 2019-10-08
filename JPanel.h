#pragma once
#include <list>

// JPanel
class Sprite;
class JPanel : public CWnd
{
	DECLARE_DYNAMIC(JPanel)

public:
	JPanel();
	virtual ~JPanel();

	static CString sWindowName;
	static void RegisterClass();

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); 

	void undo();
	void clear();
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();

private:
	std::list<Sprite*> mAllSprites;
};


