#pragma once

#include <iostream>

#include "SurfaceTexture.h"
#include "CardDirection.h"
#include "raylib.h"

class Card : public SurfaceTexture
{
	private:
	unsigned short upperValue, lowerValue;
	Card* next;
	Card* prev;
	bool isDisabled;
	bool isHighlighted;
	float rotateAngel;
	CardDirection direction;

	public:
	Card(unsigned short uppValue, unsigned short lowValue, const char* imagePath)
	: SurfaceTexture(imagePath)
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
		isHighlighted = false;
		rotateAngel = 0;
		direction = CardDirection::Left;
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
	void SetIsHighlighted(bool value);
	bool GetIsHighlighted();
	float GetRotatationAngle();
	void SetRotationAngle(float value);
	//void AdaptWithCard(Card *card, bool isHead, int screenWidth, int screenHight);
	void SetDirection(CardDirection direction);
	CardDirection GetDirection();
};
