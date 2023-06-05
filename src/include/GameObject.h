#pragma once
#include <iostream>

class GameObject
{
	protected:
	float x, y;
	int width, height;
	int id;

	public:
	virtual void Move(float sX, float sY) = 0;

	virtual void Draw() = 0;

	void SetId(int id) {
		this->id = id;
	}

	int GetId() {
		return id;
	}
};
