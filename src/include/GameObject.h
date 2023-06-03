#pragma once
#include <iostream>

class GameObject
{
	protected:
	float x, y;
	std::string imagePath;
	int width, height;

	public:
	virtual void Move(float sX, float sY) = 0;

	virtual void Draw() = 0;
};
