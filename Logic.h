#pragma once
#include <list>

class GameObject;

class Logic
{
public:
	Logic();
	~Logic();

	void Update(double tDeltaTime);

private:
	std::list<GameObject*> mAllObjects;
};

