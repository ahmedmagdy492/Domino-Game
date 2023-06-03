#pragma once

#include <vector>

#include "GameObject.h"
#include "Card.h"

class Yard : GameObject
{
	private:
	std::vector<Card>* cards;
	bool isDisabled;

	public:
	Yard() {
		cards = new std::vector<Card>();
		isDisabled = true;
	}

	~Yard() {
		delete cards;
	}

	void SetIsDisabled(bool value);
	bool GetIsDisabled();
	void AddCard(Card* card);
	void RemoveCard(Card* card);
	std::vector<Card>* GetCards();
	void Draw();
	void Move(float sX, float sY);
};
