#pragma once

#include "Renderer.h"

class CompatiblityResult {
private:
	Card* card;
	CardDirection direction;
	int rotateAngle;
public:
	Card* GetCard() {
		return card;
	}

	void SetCard(Card* card) {
		this->card = card;
	}

	void SetDirection(CardDirection dir) {
		direction = dir;
	}

	CardDirection GetDirection() {
		return direction;
	}

	void SetRotateAngle(int angle) {
		rotateAngle = angle;
	}

	int GetRotateAngle() {
		return rotateAngle;
	}
};

class CompatabilityChecker {
public:
	std::vector<CompatiblityResult*>* CheckCardCompatiblity(Card* card, LinkedList* groundCards) {
		std::vector<CompatiblityResult*>* comResults = new std::vector<CompatiblityResult*>();
		Card* head = groundCards->GetHead();
		Card* tail = groundCards->GetTail();

		if(head->GetDirection() == CardDirection::Left) {
			if(card->GetUpValue() == head->GetUpValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(head);
				comResult->SetRotateAngle(90);
				comResult->SetDirection(CardDirection::Right);
				comResults->push_back(comResult);
			}
			else if(card->GetLowValue() == head->GetUpValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(head);
				comResult->SetRotateAngle(-90);
				comResult->SetDirection(CardDirection::Left);
				comResults->push_back(comResult);
			}
		}
		else if(head->GetDirection() == CardDirection::Right) {
			if(card->GetUpValue() == head->GetLowValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(head);
				comResult->SetRotateAngle(90);
				comResult->SetDirection(CardDirection::Right);
				comResults->push_back(comResult);
			}
			else if(card->GetLowValue() == head->GetLowValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(head);
				comResult->SetRotateAngle(-90);
				comResult->SetDirection(CardDirection::Left);
				comResults->push_back(comResult);
			}
		}
		else if(head->GetDirection() == CardDirection::UP) {
			if(card->GetUpValue() == head->GetLowValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(head);
				comResult->SetRotateAngle(0);
				comResult->SetDirection(CardDirection::UP);
				comResults->push_back(comResult);
			}
			else if(card->GetLowValue() == head->GetLowValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(head);
				comResult->SetRotateAngle(180);
				comResult->SetDirection(CardDirection::Down);
				comResults->push_back(comResult);
			}
		}
		else if(head->GetDirection() == CardDirection::Down) {
			if(card->GetUpValue() == head->GetUpValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(head);
				comResult->SetRotateAngle(0);
				comResult->SetDirection(CardDirection::UP);
				comResults->push_back(comResult);
			}
			else if(card->GetLowValue() == head->GetUpValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(head);
				comResult->SetRotateAngle(180);
				comResult->SetDirection(CardDirection::Down);
				comResults->push_back(comResult);
			}
		}

		if(tail->GetDirection() == CardDirection::Left) {
			if(card->GetUpValue() == tail->GetLowValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(tail);
				comResult->SetRotateAngle(-90);
				comResult->SetDirection(CardDirection::Left);
				comResults->push_back(comResult);
			}
			else if(card->GetLowValue() == tail->GetLowValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(tail);
				comResult->SetRotateAngle(90);
				comResult->SetDirection(CardDirection::Right);
				comResults->push_back(comResult);
			}
		}
		else if(tail->GetDirection() == CardDirection::Right) {
			if(card->GetUpValue() == tail->GetUpValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(tail);
				comResult->SetRotateAngle(-90);
				comResult->SetDirection(CardDirection::Left);
				comResults->push_back(comResult);
			}
			else if(card->GetLowValue() == tail->GetUpValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(tail);
				comResult->SetRotateAngle(90);
				comResult->SetDirection(CardDirection::Right);
				comResults->push_back(comResult);
			}
		}
		else if(tail->GetDirection() == CardDirection::UP) {
			if(card->GetUpValue() == tail->GetLowValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(tail);
				comResult->SetRotateAngle(0);
				comResult->SetDirection(CardDirection::UP);
				comResults->push_back(comResult);
			}
			else if(card->GetLowValue() == tail->GetLowValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(tail);
				comResult->SetRotateAngle(180);
				comResult->SetDirection(CardDirection::Down);
				comResults->push_back(comResult);
			}
		}
		else if(tail->GetDirection() == CardDirection::Down) {
			if(card->GetUpValue() == tail->GetUpValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(tail);
				comResult->SetDirection(CardDirection::UP);
				comResult->SetRotateAngle(0);
				comResults->push_back(comResult);
			}
			else if(card->GetLowValue() == tail->GetUpValue()) {
				CompatiblityResult* comResult = new CompatiblityResult();
				comResult->SetCard(tail);
				comResult->SetRotateAngle(180);
				comResult->SetDirection(CardDirection::Down);
				comResults->push_back(comResult);
			}
		}

		return comResults;
	}
};
