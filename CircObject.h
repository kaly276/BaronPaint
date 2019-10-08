#pragma once
#include "GameObject.h"

class CircObject : public GameObject
{
public:
	CircObject();
	CircObject(float x, float y);
	~CircObject();

	std::string getShape();

private: 
	std::string shape = "Circle";
};

