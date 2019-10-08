// JPanel.cpp : implementation file
//

#include "stdafx.h"
#include "BaronPong.h"
#include "JPanel.h"
#include "BaronPongDlg.h"
#include "Sprite.h"
#include "GameObject.h"
#include "RectObject.h"
#include "CircObject.h"


// JPanel

IMPLEMENT_DYNAMIC(JPanel, CWnd)

JPanel::JPanel()
{

}

JPanel::~JPanel()
{
}

CString JPanel::sWindowName;
void JPanel::RegisterClass()
{
	sWindowName = AfxRegisterWndClass(0);
}


BEGIN_MESSAGE_MAP(JPanel, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// In case you need to get to the Dialog from somewhere
//CBaronPongDlg *tDialog = (CBaronPongDlg*)AfxGetMainWnd();

// And in case you need to get to the app
//CBaronPongApp* app = ( CBaronPongApp *)AfxGetApp();

// A click upon us!  Execute this code and be merry.
void JPanel::OnLButtonDown(UINT nFlags, CPoint point)
{
	CBaronPongDlg *tDialog = (CBaronPongDlg*)AfxGetMainWnd();
	
	// Create object where click.
	float x = point.x;
	float y = point.y;

	GameObject* obj;
	

	if (tDialog->getShape() == "Circle") {
		obj = new CircObject(x, y);
	}
	else {
		obj = new RectObject(x, y);
	}






	if (tDialog->getFilled() == true) {
		obj->setFilled(true);
	}
	else {
		obj->setFilled(false);
	}
	
	
	
	Sprite* sprite = new Sprite(obj);
	this->mAllSprites.push_back(sprite);


	CWnd::OnLButtonDown(nFlags, point);

}

// JPanel message handlers




void JPanel::OnPaint()
{
	//https://msdn.microsoft.com/en-us/library/fxhhde73.aspx
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CWnd::OnPaint() for painting messages

	// This code here is just to show you where the JPanel is.  Makes it blue.
	CBrush brush(RGB(255, 255, 255));
	CBrush* pOldBrush = dc.SelectObject(&brush);

	CRect rect;
	GetClientRect(rect);
	dc.Rectangle(rect); //BLUE RECTANGLE IN BACKGROUND

	dc.SelectObject(pOldBrush);

	// Ask our dialog for the current interpolation percentage (if doing interploation)
	// Loop through all of our sprites and tell them to draw by passing the dc in..

	//dc.Rectangle(0, 0, 40, 20); //WHITE SMALL RECTANGLE
	//std::list<Sprite*> mAllSprites;

	for (std::list<Sprite*>::iterator it1 = mAllSprites.begin(); it1 != mAllSprites.end(); ++it1) {
		Sprite* sprite = *it1;
		sprite->Draw(dc);
	}

}

void JPanel::undo() {
	mAllSprites.pop_back();
}

void JPanel::clear() {
	while (!mAllSprites.empty()) {
		mAllSprites.pop_back();
	}
}
