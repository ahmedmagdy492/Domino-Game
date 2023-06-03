#include "../include/Yard.h"

void Yard::SetIsDisabled(bool value) {
	this->isDisabled = value;
}

bool Yard::GetIsDisabled() {
	return this->isDisabled;
}

void Yard::AddCard(Card* card) {
	cards->push_back(*card);
}

void Yard::RemoveCard(Card* card) {

}

std::vector<Card>* Yard::GetCards() {
	return this->cards;
}

void Yard::Draw() {

}

void Yard::Move(float sX, float sY) {
	this->x = sX;
	this->y = sY;
}
