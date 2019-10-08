#include "stdafx.h"
#include "GameObject.h"

void GameObject::Update(double tDeltaTime)
{
	// Our acceleration changes our velocity, then our velocity changes our position
	// Both are scaled by the delta time - it gives us pixels per update instead of pixels per second
}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

GameObject::GameObject(float x, float y)
{
	mXPosition = x;
	mYPosition = y;
}

void GameObject::setPosition(float x, float y)
{
	mXPosition = x;
	mYPosition = y;
}

void GameObject::setXScale(int xScale)
{
	mXScale = xScale;
	mXPosition -= mXScale / 2.0;
}

void GameObject::setYScale(int yScale)
{
	mYScale = yScale;
	mYPosition -= mYScale / 2.0;
}

float GameObject::getXPosition() const
{
	return mXPosition;
}

float GameObject::getYPosition() const
{
	return mYPosition;
}

float GameObject::getFinalXPosition() const
{
	return mXPosition + mXScale;
}

float GameObject::getFinalYPosition() const
{
	return mYPosition + mYScale;
}

std::string GameObject::getShape() const
{
	return mShape;
}

bool GameObject::getFill() const
{
	return isFilled;
}

COLORREF GameObject::getColor() const
{
	return mColor;
}

void GameObject::setShape(std::string shape)
{
	mShape = shape;
}

void GameObject::setFill(bool isFill)
{
	isFilled = isFill;
}

void GameObject::setColor(COLORREF color)
{
	mColor = color;
}
