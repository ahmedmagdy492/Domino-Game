#pragma once

#include <iostream>
#include <vector>

#include "Card.h"
#include "CardDirection.h"

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

	void RemoveCard(Card* card) {
		unsigned int size = cards->size();

		for(int i = 0;i < size; i++) {
			Card* tempCard = (*cards)[i];
			if(card->GetUpValue() == tempCard->GetUpValue() && card->GetLowValue() == tempCard->GetLowValue()) {
				cards->erase(cards->begin()+i);
				break;
			}
		}
	}

	///
	// Summary: convention for checking the cards
	// head: always the up value is available
	// tail: always the low value is available
	///
	void EnableCardsThatAreCombatibleWith(Card* head, Card* tail) {
		unsigned int size = cards->size();

		for(int i = 0; i < size; i++) {
			Card* playerCard = (*cards)[i];
			if(
					head->GetUpValue() == playerCard->GetUpValue() || head->GetUpValue() == playerCard->GetLowValue() ||
					tail->GetLowValue() == playerCard->GetUpValue() || tail->GetLowValue() == playerCard->GetLowValue()
					){
				playerCard->SetIsDisabled(false);
				int y = playerCard->GetY() - 10;
				playerCard->SetY(y);
			}
		}
	}

	void EnableAllCards() {
		unsigned int size = cards->size();

		for(int i = 0; i < size; i++) {
			Card* playerCard = (*cards)[i];
			playerCard->SetIsDisabled(false);
		}
	}

	void SelectCard(Card* card) {
		unsigned int size = cards->size();

		for(int i = 0; i < size; i++) {
			Card* playerCard = (*cards)[i];
			if(card->GetUpValue() == playerCard->GetUpValue() && card->GetLowValue() == playerCard->GetLowValue()) {
				playerCard->SetIsHighlighted(true);
			}
			else {
				playerCard->SetIsDisabled(true);
				playerCard->SetIsHighlighted(false);
			}
		}
	}

	void PlayCard(Card* card) {
		card->SetIsHighlighted(false);

		if(card->GetDirection() == CardDirection::Left) {
			card->SetRotationAngle(-90);
		}
		else if(card->GetDirection() == CardDirection::Right) {
			card->SetRotationAngle(90);
		}
		else if(card->GetDirection() == CardDirection::UP) {
			card->SetRotationAngle(0);
		}
		else if(card->GetDirection() == CardDirection::Down) {
			card->SetRotationAngle(180);
		}

		RemoveCard(card);
	}
};
