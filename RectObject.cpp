#include "stdafx.h"
#include "RectObject.h"
#include "JPanel.h"
#include "afxwin.h"
#include "Sprite.h"


RectObject::RectObject()
{

}

RectObject::RectObject(float x, float y) : GameObject(x, y)
{

}


RectObject::~RectObject()
{
}

std::string RectObject::getShape() {
	return shape;
}

