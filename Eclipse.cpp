#include "stdafx.h"
#include "Eclipse.h"

Eclipse::Eclipse()
{
}

Eclipse::Eclipse(float x, float y) : GameObject(x, y)
{
	this->setShape("Eclipse");
}

Eclipse::~Eclipse()
{
}
