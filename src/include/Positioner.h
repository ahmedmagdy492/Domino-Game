#pragma once

#include "Player.h"

#include <vector>

class Positioner {
public:
	void InitiateObjectsPositions(int width, int height, std::vector<Player*>* players) {
		// drawing players cards
		std::vector<Card*> player1Cards = *(*(players->data()))->GetCards();
		unsigned int player1CardsSize = player1Cards.size();
		int xOffset = 0;

		for(int i = 0; i < player1CardsSize; i++) {
			Card* card = player1Cards[i];
			card->SetY(height - card->GetHeight());
			int xPos = ((width - (card->GetWidth() * player1CardsSize)) / 2) + xOffset;
			card->SetX(xPos);
			xOffset += card->GetWidth();
		}

		std::vector<Card*> comCards = *(*players)[1]->GetCards();
		unsigned int comCardsSize = comCards.size();
		xOffset = 0;

		for(int i = 0; i < comCardsSize; i++) {
			Card* card = comCards[i];
			card->SetY(0);
			int xPos = ((width - (card->GetWidth() * comCardsSize)) / 2) + xOffset;
			card->SetX(xPos);
			xOffset += card->GetWidth();
		}
	}

	Card* IsIntersectingWithObjects(Vector2& mousePos, std::vector<Card*>* cards) {

		unsigned int size = cards->size();

		for(int i = 0; i < size; i++) {
			Card *card = (*cards)[i];

			if(
					(mousePos.x >= card->GetX() && mousePos.x <= (card->GetWidth() + card->GetX())) &&
					(mousePos.y >= card->GetY() && mousePos.y <= (card->GetHeight() + card->GetY()))
					) {
				return card;
			}
		}

		return NULL;
	}
};
