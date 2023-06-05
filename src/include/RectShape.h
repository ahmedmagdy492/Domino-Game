#pragma once

#include "GameObject.h"
#include "raylib.h"

class RectShape : public GameObject {
private:
	bool isOutlined;
	Color color;
public:
	RectShape(bool isOutlined, int width, int height, Color color)
	: isOutlined(isOutlined), color(color) {
		this->width = width;
		this->height = height;
	}

	void Move(float sX, float sY) {
		this->x = sX;
		this->y = sY;
	}

	void Draw() {
		if(isOutlined) {
			DrawRectangleLines(x, y, width, height, color);
		}
		else {
			DrawRectangle(x, y, width, height, color);
		}
	}
};
