#include "stdafx.h"
#include "CircObject.h"


CircObject::CircObject()
{
}


CircObject::CircObject(float x, float y) : GameObject(x, y)
{

}

CircObject::~CircObject()
{
}

std::string CircObject::getShape() {
	return shape;
}