#pragma once
class GameObject;;
class Sprite
{
public:
	Sprite(GameObject *tObjectToDraw);
	~Sprite();

	void Draw(CPaintDC &tContext);

private:
	float mLastDrawX = 0;// Used for interpolation
	float mLastDrawY = 0;

	GameObject *mMyObject;
};

