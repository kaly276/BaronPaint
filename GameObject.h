#pragma once
#include <string>

class GameObject 
{
public:
	GameObject();
	GameObject(float x, float y);
	~GameObject();

	void Update(double tDeltaTime);


	float getXPosition();
	float getYPosition();
	
	float getFinalXPosition();
	float getFinalYPosition();

	void setShape(std::string shape);
	virtual std::string getShape() = 0;

	
	void setFilled(bool isFilled);
	bool getFilled();

	

	bool cIsFilled;
private:
	std::string cShape;
	
	
	COLORREF cColor = RGB(0, 0, 0);

	float mXPosition = 0;
	float mYPosition = 0;

	float finalXPosition;
	float finalYPosition;

	float mXVelocity = 0;
	float mYVelocity = 0;

	float mXAcceleration = 0;
	float mYAcceleration = 0;
};

