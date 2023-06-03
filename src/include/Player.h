#pragma once

#include <iostream>
#include <vector>

#include "Card.h"

class Player {
	private:
	std::string name;
	unsigned short score;
	std::vector<Card*>* cards;

	public:
	Player(std::string &name) {
		this->name = name;
		score = 0;
		cards = new std::vector<Card*>();
	}

	~Player() {
		delete cards;
	}

	void AddCard(Card* card) {
		cards->push_back(card);
	}

	std::vector<Card*>* GetCards() {
		return cards;
	}

	std::string& GetName() {
		return this->name;
	}

	unsigned short GetScore() {
		return this->score;
	}

	void SetScore(unsigned short score) {
		this->score = score;
	}
};
