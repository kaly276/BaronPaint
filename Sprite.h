
#pragma once

#include "afxwin.h"
class GameObject;
class Sprite
{
public:
	Sprite();
	Sprite(GameObject *tObjectToDraw);
	~Sprite();
	bool cIsFilled = false;

	void Draw(CPaintDC &tContext);

	void setFilled(bool isFilled);
	


private:
	
	float mLastDrawX = 0;// Used for interpolation
	float mLastDrawY = 0;

	GameObject *mMyObject;
};

