#include "../include/Drawer.h"
#include "../include/Util.h"

void Drawer::DrawPlayersCards(std::vector<Card*>* objects) {
	unsigned int size = objects->size();
	for(int i = 0; i < size; i++) {
		(*objects)[i]->Draw();
	}
}

void Drawer::DrawGroundCards(LinkedList& groundCards) {
	Card* ptr = groundCards.GetHead();

	while(ptr != NULL) {
		ptr->Draw();
		ptr = ptr->getNext();
	}
}
