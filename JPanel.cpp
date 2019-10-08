// JPanel.cpp : implementation file
//

#include "stdafx.h"
#include "BaronPong.h"
#include "JPanel.h"
#include "Sprite.h"
#include "Rect.h"
#include "BaronPongDlg.h"
#include "Eclipse.h"


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
	
	float x = point.x;
	float y = point.y;
	GameObject* shape;

	if (tDialog->getTypeToDraw() == "Rect")
	{
		shape = new Rect(x, y);
	}
	else
	{
		shape = new Eclipse(x, y);
	}

	if (tDialog->getFilled())
	{
		shape->setFill(true);
	}
	else
	{
		shape->setFill(false);
	}
	shape->setXScale(tDialog->getWidth());
	shape->setYScale(tDialog->getHeight());
	shape->setColor(tDialog->getColor());
	Sprite* sprite = new Sprite(shape);

	this->mAllSprites.push_back(sprite);
}

void JPanel::undo()
{
	mAllSprites.pop_back();
}

void JPanel::clear()
{
	while (!mAllSprites.empty())
	{
		mAllSprites.pop_back();
	}
}

// JPanel message handlers




void JPanel::OnPaint()
{
	//https://msdn.microsoft.com/en-us/library/fxhhde73.aspx
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CWnd::OnPaint() for painting messages

	// This code here is just to show you where the JPanel is.  Makes it blue.
	CBrush brushWhite(RGB(255, 255, 255));
	CBrush* pOldBrush = dc.SelectObject(&brushWhite);

	CRect rect;
	GetClientRect(rect);
	dc.Rectangle(rect);

	dc.SelectObject(pOldBrush);

	// Ask our dialog for the current interpolation percentage (if doing interploation)
	// Loop through all of our sprites and tell them to draw by passing the dc in..
	for (std::list<Sprite*>::iterator sprite = mAllSprites.begin(); sprite != mAllSprites.end(); ++sprite) 
	{
		Sprite* current = *sprite;
		current->Draw(dc);
	}
}

