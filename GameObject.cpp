#include "stdafx.h"
#include "GameObject.h"

void GameObject::Update(double tDeltaTime)
{
	// Our acceleration changes our velocity, then our velocity changes our position
	// Both are scaled by the delta time - it gives us pixels per update instead of pixels per second
}

GameObject::GameObject(float x, float y) {
	mXPosition = x - 50;
	mYPosition = y - 50;

	finalXPosition = mXPosition + 100;
	finalYPosition = mYPosition + 100;

}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

float GameObject::getXPosition() {
	return mXPosition;
}

float GameObject::getYPosition() {
	return mYPosition;
}

float GameObject::getFinalXPosition() {
	return finalXPosition;

}

float GameObject::getFinalYPosition() {
	return finalYPosition;
}

std::string GameObject::getShape() {
	return cShape;
}

void GameObject::setShape(std::string shape) {
	cShape = shape;
}

bool GameObject::getFilled() {
	return cIsFilled;
}

void GameObject::setFilled(bool isFilled) {
	cIsFilled = isFilled;
}

