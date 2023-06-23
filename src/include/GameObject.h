#pragma once
#include <iostream>

#include "Helper.h"

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
		id = GetNextObjectId();
	}
	virtual void Move(float sX, float sY) = 0;

	virtual void Draw() = 0;

	int GetId() {
		return id;
	}
};
