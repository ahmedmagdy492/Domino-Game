#pragma once

#include <iostream>

#include "GameObject.h"
#include "raylib.h"

class Card : GameObject
{
	private:
	unsigned short upperValue, lowerValue;
	Card* next;
	Card* prev;
	bool isDisabled;
	Texture2D texture;

	public:
	Card(unsigned short uppValue, unsigned short lowValue, const char* imagePath)
	{
		width = 50;
		height = 100;
		x = 0;
		y = 0;
		next = NULL;
		prev = NULL;
		upperValue = uppValue;
		lowerValue = lowValue;
		isDisabled = true;
		texture = LoadTexture(imagePath);
	}

	~Card() {
		UnloadTexture(texture);
	}

	int GetWidth();
	int GetHeight();
	void SetX(float x);
	void SetY(float y);
	float GetX();
	float GetY();
	unsigned short GetUpValue();
	unsigned short GetLowValue();
	void setNext(Card* card);
	void setPrev(Card* card);
	Card* getNext();
	Card* getPrev();
	void Move(float sX, float sY);
	void Draw();
	void SetIsDisabled(bool value);
	bool GetIsDisabled();
};
