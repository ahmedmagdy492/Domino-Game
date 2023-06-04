#include "../include/Card.h"

#include <cmath>

void Card::SetX(float x) 
{
	this->x = x;
}

void Card::SetY(float y)
{
	this->y = y;
}

float Card::GetX() {
	return x;
}

float Card::GetY() {
	return y;
}

unsigned short Card::GetUpValue() {
	return upperValue;
}

unsigned short Card::GetLowValue() {
	return lowerValue;
}

void Card::setNext(Card* card) {
	this->next = card;
}

void Card::setPrev(Card* card) {
	this->prev = card;
}

Card* Card::getNext() {
	return this->next;
}

Card* Card::getPrev() {
	return this->prev;
}

void Card::Draw()
{
	//DrawTextureEx(texture, (Vector2){x, y}, rotateAngel, 1, WHITE);
	DrawTexture(texture, x, y,WHITE);
}

void Card::Move(float sX, float sY) {
	this->x = sX;
	this->y = sY;
}

void Card::SetIsDisabled(bool value) {
	this->isDisabled = value;
}

bool Card::GetIsDisabled() {
	return this->isDisabled;
}

int Card::GetWidth() {
	return this->width;
}

int Card::GetHeight() {
	return this->height;
}

void Card::SetIsHighlighted(bool value) {
	this->isHighlighted = value;
}

bool Card::GetIsHighlighted() {
	return isHighlighted;
}

float Card::GetRotatationAngle() {
	return this->rotateAngel;
}

void Card::SetRotationAngle(float value) {
	rotateAngel = value;
}

void Card::SetDirection(CardDirection direction) {
	this->direction = direction;
}

CardDirection Card::GetDirection() {
	return this->direction;
}

void Card::AdaptWithCard(Card *card, bool isHead, int screenWidth, int screenHight) {
	if(card->direction != CardDirection::UP && card->direction != CardDirection::Down) {
		if(isHead) {
			if(this->direction == CardDirection::Right) {
				// right direction
				int newXPos = card->GetX() - this->GetWidth();
				int newYPos = (screenHight - card->GetHeight()) / 2;
				this->SetX(newXPos);
				this->SetY(newYPos);
			}
			else {
				// left direction
				int newXPos = card->GetX() - this->GetWidth();
				int newYPos = (screenHight - this->GetHeight()) / 2;
				this->SetX(newXPos);
				this->SetY(newYPos);
			}
		}
		else {
			if(this->direction == CardDirection::Left) {
				int newXPos = card->GetX() + this->GetHeight();
				int newYPos = (screenHight - this->GetHeight()) / 2;
				this->SetX(newXPos);
				this->SetY(newYPos);
			}
			else {
				int newXPos = card->GetX();
				int newYPos = (screenHight - this->GetHeight()) / 2;
				this->SetX(newXPos);
				this->SetY(newYPos);
			}
		}
	}
}
