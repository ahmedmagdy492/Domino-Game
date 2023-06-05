#pragma once

#include "Util.h"
#include "raylib.h"

class CardPositioner {
private:
	LinkedList* cards;

public:
	CardPositioner(LinkedList* cards) {
		this->cards = cards;
	}

	void HighlightPosition(bool isHead) {
		if(isHead == true) {
			Card* head = cards->GetHead();
			head->SetIsHighlighted(true);
		}
		else {
			Card* tail = cards->GetTail();
			tail->SetIsHighlighted(true);
		}
	}

	void UnHighlightPosition(bool isHead) {
		if(isHead == true) {
			Card* head = cards->GetHead();
			head->SetIsHighlighted(false);
		}
		else {
			Card* tail = cards->GetTail();
			tail->SetIsHighlighted(true);
		}
	}

	void AddCardToEnd(Card* card) {
		Card* tail = cards->GetTail();
		tail->SetDirection(card->GetDirection());
		tail->Set
	}

	void AddCardToBegin(Card* card) {
		cards->Prepend(card);
	}
};
