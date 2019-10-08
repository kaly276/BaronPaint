#pragma once
#include <string>
class GameObject
{
public:
	GameObject();
	GameObject(float x, float y);
	~GameObject();

	void Update(double tDeltaTime);

	void setPosition(float x, float y);
	
	void setXScale(int xScale);
	void setYScale(int yScale);

	void setShape(std::string shape);

	void setFill(bool isFill);

	void setColor(COLORREF color);

	float getXPosition() const;
	float getYPosition() const;
	float getFinalXPosition() const;
	float getFinalYPosition() const;
	
	std::string getShape() const;

	bool getFill() const;

	COLORREF getColor() const;
private:

	float mXPosition = 0;
	float mYPosition = 0;

	float mFinalXPosition = 0;
	float mFinalYPosition = 0;

	std::string mShape;

	int mXScale = 100;
	int mYScale = 100;

	bool isFilled = true;

	COLORREF mColor = RGB(0, 0, 0);
};

