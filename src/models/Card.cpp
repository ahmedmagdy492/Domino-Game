#include "../include/Card.h"

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
	DrawTexture(texture, x, y, WHITE);
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
