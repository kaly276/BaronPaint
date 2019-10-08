#pragma once

#include "GameObject.h"

class RectObject : public GameObject
{
public:
	RectObject();
	RectObject(float x, float y);
	~RectObject();

	std::string getShape();
	

private: 
	std::string shape = "Rectangle";
	

};

