#include "stdafx.h"
#include "Rect.h"


Rect::Rect()
{
}

Rect::Rect(float x, float y) : GameObject(x, y)
{
	this->setShape("Rect");
}
Rect::~Rect()
{
}
