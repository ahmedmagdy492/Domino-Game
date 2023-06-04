#include "../include/Drawer.h"
#include "../include/Util.h"

void Drawer::DrawPlayersCards(std::vector<Card*>* objects) {
	unsigned int size = objects->size();
	for(int i = 0; i < size; i++) {
		(*objects)[i]->Draw();
		if((*objects)[i]->GetIsHighlighted()) {
			DrawRectangleLines((*objects)[i]->GetX(), (*objects)[i]->GetY(), (*objects)[i]->GetWidth(), (*objects)[i]->GetHeight(), RED);
		}
	}
}

void Drawer::DrawGroundCards(LinkedList& groundCards) {
	Card* ptr = groundCards.GetHead();

	while(ptr != NULL) {
		ptr->Draw();
		ptr = ptr->getNext();
	}
}
