#include "stdafx.h"
#include "afxwin.h"
#include "Sprite.h"
#include "GameObject.h"
#include <list>

void Sprite::Draw(CPaintDC &tContext) {
	// Just look at our object and draw something to the DC
	// Now we have address of Jpanel dc.

	CRect rect(mMyObject->getXPosition(), mMyObject->getYPosition(), mMyObject->getFinalXPosition(), mMyObject->getFinalYPosition());
	CBrush brush(RGB(0, 0, 0));

	if (mMyObject->getFilled() == true) {
			CBrush* pOldBrush = tContext.SelectObject(&brush);
		
	}
	else {
			tContext.SelectStockObject(NULL_BRUSH);
	}
	

	if (mMyObject->getShape() == "Circle") {
		tContext.Ellipse(rect);
	}
	else {
		tContext.Rectangle(rect);
	}
	
	

}

void Sprite::setFilled(bool isFilled) {
	cIsFilled = isFilled;
}


Sprite::Sprite(GameObject *tObjectToDraw)
{
	mMyObject = tObjectToDraw;
	
}

Sprite::Sprite() {

}

Sprite::~Sprite()
{

}
