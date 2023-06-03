#include "../include/LinkedList.h"

void LinkedList::Append(Card* card) {
	if(head == NULL) {
		head = card;
		tail = card;
	}
	else if(head->getNext() == NULL) {
		head->setNext(card);
		card->setPrev(head);
		tail = card;
	}
	else {
		tail->setNext(card);
		card->setPrev(tail);
		tail = card;
	}
}

void LinkedList::Prepend(Card* card) {
	if(head == NULL) {
		head = card;
		tail = card;
	}
	else {
		head->setPrev(card);
		card->setNext(head);
		head = card;
	}
}

Card* LinkedList::GetHead() {
	return this->head;
}

Card* LinkedList::GetTail() {
	return this->tail;
}
