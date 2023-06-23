#pragma once

#include "Player.h"
#include "raylib.h"

#include <vector>
#include <iostream>
#include <queue>

struct CardPos {
	Vector2 pos;
	bool isBusy = false;
	CardPos* next;
	CardPos* prev;
};

class LinkedNodes {
private:
CardPos* head;
CardPos* tail;

public:
void Append(CardPos* card) {
	if(head == NULL) {
		head = card;
		tail = card;
	}
	else if(head->next == NULL) {
		head->next = card;
		card->prev = head;
		tail = card;
	}
	else {
		tail->next = card;
		card->prev = tail;
		tail = card;
	}
}

void Prepend(CardPos* card) {
	if(head == NULL) {
		head = card;
		tail = card;
	}
	else {
		head->prev = card;
		card->next = head;
		head = card;
	}
}

CardPos* GetHead() {
	return this->head;
}

CardPos* GetTail() {
	return this->tail;
}
};


class Positioner {
private:
	int cH = 100;
	int cW = 50;
	int width;
	int height;
	std::queue<CardPos> *headPositions;
	std::queue<CardPos> *tailPositions;

	void CreatePositions() {
		tailPositions = new std::queue<CardPos>();
		headPositions = new std::queue<CardPos>();
		auto pos1 = CardPos{Vector2({(width-cH)/2, cH+30})};
		headPositions->push(pos1);

		// tail posiitions
		auto pos42 = CardPos{Vector2({pos1.pos.x + cH, pos1.pos.y})};
		tailPositions->push(pos42);

		auto pos43 = CardPos{Vector2({pos42.pos.x + cH, pos42.pos.y})};
		tailPositions->push(pos43);

		auto pos44 = CardPos{Vector2({pos43.pos.x + cH, pos43.pos.y})};
		tailPositions->push(pos44);

		auto pos45 = CardPos{Vector2({pos44.pos.x + cH, pos44.pos.y})};
		tailPositions->push(pos45);

		auto pos46 = CardPos{Vector2({pos45.pos.x + cH, pos45.pos.y})};
		tailPositions->push(pos46);

		auto pos47 = CardPos{Vector2({pos46.pos.x + cH, pos46.pos.y})};
		tailPositions->push(pos47);

		auto pos48 = CardPos{Vector2({pos47.pos.x + cH, pos47.pos.y})};
		tailPositions->push(pos48);

		auto pos49 = CardPos{Vector2({pos48.pos.x + cH, pos48.pos.y})};
		tailPositions->push(pos49);

		// right vertical
		auto pos50 = CardPos{Vector2({pos49.pos.x, pos49.pos.y+cW})};
		tailPositions->push(pos50);

		auto pos51 = CardPos{Vector2({pos50.pos.x, pos50.pos.y+cH})};
		tailPositions->push(pos51);

		auto pos52 = CardPos{Vector2({pos51.pos.x, pos51.pos.y+cH})};
		tailPositions->push(pos52);

		auto pos53 = CardPos{Vector2({pos52.pos.x, pos52.pos.y+cH})};
		tailPositions->push(pos53);

		auto pos54 = CardPos{Vector2({pos53.pos.x, pos53.pos.y+cH})};
		tailPositions->push(pos54);

		auto pos55 = CardPos{Vector2({pos54.pos.x, pos54.pos.y+cH})};
		tailPositions->push(pos55);

		auto pos56 = CardPos{Vector2({pos55.pos.x, pos55.pos.y+cH})};
		tailPositions->push(pos56);

		auto pos57 = CardPos{Vector2({pos56.pos.x, pos56.pos.y+cH})};
		tailPositions->push(pos57);

		// horizental bottom
		auto pos58 = CardPos{Vector2({pos57.pos.x, pos57.pos.y+cH})};
		tailPositions->push(pos58);

		auto pos59 = CardPos{Vector2({pos58.pos.x-cH, pos58.pos.y})};
		tailPositions->push(pos59);

		auto pos60 = CardPos{Vector2({pos59.pos.x-cH, pos59.pos.y})};
		tailPositions->push(pos60);

		auto pos61 = CardPos{Vector2({pos60.pos.x-cH, pos60.pos.y})};
		tailPositions->push(pos61);

		auto pos62 = CardPos{Vector2({pos61.pos.x-cH, pos61.pos.y})};
		tailPositions->push(pos62);

		auto pos63 = CardPos{Vector2({pos62.pos.x-cH, pos62.pos.y})};
		tailPositions->push(pos63);

		auto pos64 = CardPos{Vector2({pos63.pos.x-cH, pos63.pos.y})};
		tailPositions->push(pos64);

		auto pos65 = CardPos{Vector2({pos64.pos.x-cH, pos64.pos.y})};
		tailPositions->push(pos65);

		auto pos66 = CardPos{Vector2({pos65.pos.x-cH, pos65.pos.y})};
		tailPositions->push(pos66);

		auto pos67 = CardPos{Vector2({pos66.pos.x-cH, pos66.pos.y})};
		tailPositions->push(pos67);

		auto pos68 = CardPos{Vector2({pos67.pos.x-cH, pos67.pos.y})};
		tailPositions->push(pos68);

		auto pos69 = CardPos{Vector2({pos68.pos.x-cH, pos68.pos.y})};
		tailPositions->push(pos69);

		auto pos70 = CardPos{Vector2({pos69.pos.x-cH, pos69.pos.y})};
		tailPositions->push(pos70);

		auto pos71 = CardPos{Vector2({pos70.pos.x-cH, pos70.pos.y})};
		tailPositions->push(pos71);

		auto pos72 = CardPos{Vector2({pos71.pos.x-cH, pos71.pos.y})};
		tailPositions->push(pos72);

		auto pos73 = CardPos{Vector2({pos72.pos.x-cH, pos72.pos.y})};
		tailPositions->push(pos73);

		// head positions
		// up horizontal
		auto pos2 = CardPos{Vector2({pos1.pos.x-cH, pos1.pos.y})};
		headPositions->push(pos2);

		auto pos3 = CardPos{Vector2({pos2.pos.x-cH, pos2.pos.y})};
		headPositions->push(pos3);

		auto pos4 = CardPos{Vector2({pos3.pos.x-cH, pos3.pos.y})};
		headPositions->push(pos4);

		auto pos5 = CardPos{Vector2({pos4.pos.x-cH, pos4.pos.y})};
		headPositions->push(pos5);

		auto pos6 = CardPos{Vector2({pos5.pos.x-cH, pos5.pos.y})};
		headPositions->push(pos6);

		auto pos7 = CardPos{Vector2({pos6.pos.x-cH, pos6.pos.y})};
		headPositions->push(pos7);

		auto pos8 = CardPos{Vector2({pos7.pos.x-cH, pos7.pos.y})};
		headPositions->push(pos8);

		auto pos9 = CardPos{Vector2({pos8.pos.x-cH, pos8.pos.y})};
		headPositions->push(pos9);

		// vertical left
		auto pos10 = CardPos{Vector2({pos9.pos.x, pos9.pos.y+cW})};
		headPositions->push(pos10);

		auto pos11 = CardPos{Vector2({pos10.pos.x, pos10.pos.y+cH})};
		headPositions->push(pos11);

		auto pos12 = CardPos{Vector2({pos11.pos.x, pos11.pos.y+cH})};
		headPositions->push(pos12);

		auto pos13 = CardPos{Vector2({pos12.pos.x, pos12.pos.y+cH})};
		headPositions->push(pos13);

		auto pos14 = CardPos{Vector2({pos13.pos.x, pos13.pos.y+cH})};
		headPositions->push(pos14);

		auto pos15 = CardPos{Vector2({pos14.pos.x, pos14.pos.y+cH})};
		headPositions->push(pos15);

		auto pos16 = CardPos{Vector2({pos15.pos.x, pos15.pos.y+cH})};
		headPositions->push(pos16);

		// bottom horizental

		auto pos17 = CardPos{Vector2({pos16.pos.x + cW, pos16.pos.y})};
		headPositions->push(pos17);

		auto pos18 = CardPos{Vector2({pos17.pos.x + cH, pos17.pos.y})};
		headPositions->push(pos18);

		auto pos19 = CardPos{Vector2({pos18.pos.x + cH, pos18.pos.y})};
		headPositions->push(pos19);

		auto pos20 = CardPos{Vector2({pos19.pos.x + cH, pos19.pos.y})};
		headPositions->push(pos20);

		auto pos21 = CardPos{Vector2({pos20.pos.x + cH, pos20.pos.y})};
		headPositions->push(pos21);

		auto pos22 = CardPos{Vector2({pos21.pos.x + cH, pos21.pos.y})};
		headPositions->push(pos22);

		auto pos23 = CardPos{Vector2({pos22.pos.x + cH, pos22.pos.y})};
		headPositions->push(pos23);

		auto pos24 = CardPos{Vector2({pos23.pos.x + cH, pos23.pos.y})};
		headPositions->push(pos24);

		auto pos25 = CardPos{Vector2({pos24.pos.x + cH, pos24.pos.y})};
		headPositions->push(pos25);

		auto pos26 = CardPos{Vector2({pos25.pos.x + cH, pos25.pos.y})};
		headPositions->push(pos26);

		auto pos27 = CardPos{Vector2({pos26.pos.x + cH, pos26.pos.y})};
		headPositions->push(pos27);

		auto pos28 = CardPos{Vector2({pos27.pos.x + cH, pos27.pos.y})};
		headPositions->push(pos28);

		auto pos29 = CardPos{Vector2({pos28.pos.x + cH, pos28.pos.y})};
		headPositions->push(pos29);

		auto pos30 = CardPos{Vector2({pos29.pos.x + cH, pos29.pos.y})};
		headPositions->push(pos30);

		auto pos31 = CardPos{Vector2({pos30.pos.x + cH, pos30.pos.y})};
		headPositions->push(pos31);

		auto pos32 = CardPos{Vector2({pos31.pos.x + cH, pos31.pos.y})};
		headPositions->push(pos32);

		auto pos33 = CardPos{Vector2({pos32.pos.x + cH, pos32.pos.y})};
		headPositions->push(pos33);

		// vertical right
		auto pos34 = CardPos{Vector2({pos33.pos.x+cH/2, pos33.pos.y-cW})};
		headPositions->push(pos34);

		auto pos35 = CardPos{Vector2({pos34.pos.x, pos34.pos.y-cH})};
		headPositions->push(pos35);

		auto pos36 = CardPos{Vector2({pos35.pos.x, pos35.pos.y-cH})};
		headPositions->push(pos36);

		auto pos37 = CardPos{Vector2({pos36.pos.x, pos36.pos.y-cH})};
		headPositions->push(pos37);

		auto pos38 = CardPos{Vector2({pos37.pos.x, pos37.pos.y-cH})};
		headPositions->push(pos38);

		auto pos39 = CardPos{Vector2({pos38.pos.x, pos38.pos.y-cH})};
		headPositions->push(pos39);

		auto pos40 = CardPos{Vector2({pos39.pos.x, pos39.pos.y-cH})};
		headPositions->push(pos40);
	}
public:
	Positioner(int width, int height) {
		this->width = width;
		this->height = height;
		CreatePositions();
	}

	~Positioner() {
		delete headPositions;
		delete tailPositions;
	}

	void InitiateObjectsPositions(std::vector<Player*>* players) {
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

	void SelectPosition(Card* card, bool isHead, Vector2* vec) {
		if(card == NULL) {
			CardPos firstEl = headPositions->front();
			vec->x = firstEl.pos.x;
			vec->y = firstEl.pos.y;
			headPositions->pop();
			tailPositions->pop();
		}
		else {
			if(isHead) {
				vec->x = headPositions->front().pos.x;
				vec->y = headPositions->front().pos.y;
				headPositions->pop();
			}
			else {
				vec->x = tailPositions->front().pos.x;
				vec->y = tailPositions->front().pos.y;
				tailPositions->pop();
			}
		}
	}
};
