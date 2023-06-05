#pragma once
#include <iostream>

class GameObject
{
	protected:
	float x, y;
	int width, height;
	int id;

	public:
	GameObject() {
		x = y = 0;
		width = height = 0;
		id = 0;
	}
	virtual void Move(float sX, float sY) = 0;

	virtual void Draw() = 0;

	int GetId() {
		return id;
	}
};
