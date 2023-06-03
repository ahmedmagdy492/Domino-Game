#pragma once

#include "Card.h"

class LinkedList
{
	private:
	Card* head;
	Card* tail;

	public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void Append(Card* card);
	void Prepend(Card* card);
	Card* GetHead();
	Card* GetTail();
};
