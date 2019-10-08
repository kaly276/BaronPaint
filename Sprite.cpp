#include "stdafx.h"
#include "Sprite.h"
#include "GameObject.h"

void Sprite::Draw(CPaintDC &tContext)
{
	CRect rect(mMyObject->getXPosition(), mMyObject->getYPosition(), mMyObject->getFinalXPosition(), mMyObject->getFinalYPosition());
	COLORREF color = mMyObject->getColor();
	CBrush brush(color);
	CPen penBlack(PS_SOLID, 0, color);
	CPen* pOldPen = tContext.SelectObject(&penBlack);
	
	if (mMyObject->getFill())
	{
		CBrush* pOldBrush = tContext.SelectObject(&brush);
	}
	else
	{
		tContext.SelectStockObject(NULL_BRUSH);
	}
	
	if (mMyObject->getShape() == "Rect")
	{
		tContext.Rectangle(rect);
	}
	else
	{
		tContext.Ellipse(rect);
	}

}

Sprite::Sprite(GameObject *tObjectToDraw)
{
	mMyObject = tObjectToDraw;
}


Sprite::~Sprite()
{

}
