#pragma once

#include "GameObject.h"
#include "raylib.h"

class SurfaceTexture : public GameObject {
protected:
	Texture2D texture;
public:
	SurfaceTexture(const char* imagePath) {
		texture = LoadTexture(imagePath);
	}

	void Move(float sX, float sY) {
		this->x = sX;
		this->y = sY;
	}

	void Draw() {
		DrawTexture(texture, x, y, WHITE);
	}

	~SurfaceTexture() {
		UnloadTexture(texture);
	}
};
