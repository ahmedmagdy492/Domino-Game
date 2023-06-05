#include <iostream>
#include <vector>
#include <raylib.h>
#include <string.h>

#include "include/models.h"
#include "include/Util.h"

static const char* cardImages[] = {
		"resources/0_0.png", "resources/1_2.png", "resources/1_5.png",
		"resources/2_2.png", "resources/2_5.png", "resources/3_3.png",
		"resources/3_6.png", "resources/4_5.png", "resources/5_5.png",
		"resources/6_6.png", "resources/1_0.png", "resources/1_3.png",
		"resources/1_6.png", "resources/2_3.png", "resources/2_6.png",
		"resources/3_4.png", "resources/4_0.png", "resources/4_6.png",
		"resources/5_6.png", "resources/1_1.png", "resources/1_4.png",
		"resources/2_0.png", "resources/2_4.png", "resources/3_0.png",
		"resources/3_5.png", "resources/4_4.png", "resources/5_0.png",
		"resources/6_0.png"
};

static int Width = 1024;
static int Height = 768;
static bool isPlayer1Turn;
static std::vector<Player*>* players;
static std::vector<Card*>* cards;
static LinkedList groundCards;
static Positioner positioner;
static bool isPlaying;
static unsigned short winScore;


static void CreateCards() {
	cards = new std::vector<Card*>();
	Card* card = new Card(0, 0, cardImages[0]);
	cards->push_back(card);

	card = new Card(1, 2, cardImages[1]);
	cards->push_back(card);

	card = new Card(1, 5, cardImages[2]);
	cards->push_back(card);

	card = new Card(2, 2, cardImages[3]);
	cards->push_back(card);

	card = new Card(2, 5, cardImages[4]);
	cards->push_back(card);

	card = new Card(3, 3, cardImages[5]);
	cards->push_back(card);

	card = new Card(3, 6, cardImages[6]);
	cards->push_back(card);

	card = new Card(4, 5, cardImages[7]);
	cards->push_back(card);

	card = new Card(5, 5, cardImages[8]);
	cards->push_back(card);

	card = new Card(6, 6, cardImages[9]);
	cards->push_back(card);

	card = new Card(1, 0, cardImages[10]);
	cards->push_back(card);

	card = new Card(1, 3, cardImages[11]);
	cards->push_back(card);

	card = new Card(1, 6, cardImages[12]);
	cards->push_back(card);

	card = new Card(2, 3, cardImages[13]);
	cards->push_back(card);

	card = new Card(2, 6, cardImages[14]);
	cards->push_back(card);

	card = new Card(3, 4, cardImages[15]);
	cards->push_back(card);

	card = new Card(4, 0, cardImages[16]);
	cards->push_back(card);

	card = new Card(4, 6, cardImages[17]);
	cards->push_back(card);

	card = new Card(5, 6, cardImages[18]);
	cards->push_back(card);

	card = new Card(1, 1, cardImages[19]);
	cards->push_back(card);

	card = new Card(1, 4, cardImages[20]);
	cards->push_back(card);

	card = new Card(2, 0, cardImages[21]);
	cards->push_back(card);

	card = new Card(2, 4, cardImages[22]);
	cards->push_back(card);

	card = new Card(3, 0, cardImages[23]);
	cards->push_back(card);

	card = new Card(3, 5, cardImages[24]);
	cards->push_back(card);

	card = new Card(4, 4, cardImages[25]);
	cards->push_back(card);

	card = new Card(5, 0, cardImages[26]);
	cards->push_back(card);

	card = new Card(6, 0, cardImages[27]);
	cards->push_back(card);
}

static void DistributeCards() {
	// player 1
	for(int i = 1; i <= 7; i++) {
		Player* player = *(players->data());
		Card* card = cards->back();
		cards->pop_back();
		player->AddCard(card);
	}

	// computer
	for(int i = 1; i <= 7; i++) {
		Player* player = (*players)[1];
		Card* card = cards->back();
		cards->pop_back();
		player->AddCard(card);
	}
}

static void CreatePlayers() {
	players = new std::vector<Player*>();
	std::string name = std::string("Player1");
	Player *p1 = new Player(name);
	std::string comName = std::string("Computer");
	Player* com = new Player(comName);
	players->push_back(p1);
	players->push_back(com);
}

static void DeterminePlayerTurn() {
	int randomValue = GetRandomValue(1, 11);
	if (randomValue < 5) isPlayer1Turn = true;
	else
		isPlayer1Turn = false;

	// TODO: remove this when done testing
	isPlayer1Turn = true;
}

static void SetupRound() {
	winScore = 100;
	CreatePlayers();
	DeterminePlayerTurn();
	CreateCards();
}

static void StartRound() {
	DistributeCards();
	positioner.InitiateObjectsPositions(Width, Height, players);
	isPlaying = true;
}

static void DestroyAll() {
	//delete players[0].data();
	//delete players[1].data();
	delete players;

	/*for(int i = 0;i < 28; i++) {
		delete cards[i].data();
	}*/

	delete cards;
}


int main() {

	InputDetector inputDetector;

	// register all event handlers

	Renderer renderer(Width, Height, &inputDetector);

	renderer.InitDrawing();

	// load textures
	SurfaceTexture background("resources/bg.png");
	renderer.AddObjectToDraw(&background);

	SetupRound();

	StartRound();

	// adding objects
	std::vector<Card*>* player1Cards = (*(players->data()))->GetCards();
	unsigned int player1CardsSize = player1Cards->size();
	std::vector<Card*>* computerCards = (*players)[1]->GetCards();
	unsigned int computerCardsSize = computerCards->size();

	for(int i = 0; i < player1CardsSize; i++) {
		renderer.AddObjectToDraw((*player1Cards)[i]);
	}

	for(int i = 0; i < computerCardsSize; i++) {
		renderer.AddObjectToDraw((*computerCards)[i]);
	}

	renderer.StartRendering();

	DestroyAll();

	return 0;
}


/*
static CardInfo IsCardCombitableWith(Card* card) {
	CardInfo cardInfo;
	cardInfo.card1 = NULL;
	cardInfo.card2 = NULL;
	int headUpValue = groundCards.GetHead()->GetUpValue();
	int tailLowValue = groundCards.GetTail()->GetLowValue();

	// TODO: do the checks for UP And Down Directions as well
	// TODO: if there is more than one match ask the user which card to attach to

	// head checks
	if(groundCards.GetHead()->GetDirection() == CardDirection::Left) {
		if(headUpValue == card->GetUpValue()) {
			cardInfo.card1 = groundCards.GetHead();
			cardInfo.isHead = true;
			card->SetDirection(CardDirection::Right);
		}
		else if(headUpValue == card->GetLowValue()) {
			cardInfo.card1 = groundCards.GetHead();
			cardInfo.isHead = true;
			card->SetDirection(CardDirection::Left);
		}
	}
	else if(groundCards.GetHead()->GetDirection() == CardDirection::Right) {
		int headLowValue = groundCards.GetHead()->GetLowValue();
		if(headLowValue == card->GetUpValue()) {
			cardInfo.card1 = groundCards.GetHead();
			cardInfo.isHead = true;
			card->SetDirection(CardDirection::Right);
		}
		else if(headLowValue == card->GetLowValue()) {
			cardInfo.card1 = groundCards.GetHead();
			cardInfo.isHead = true;
			card->SetDirection(CardDirection::Left);
		}
	}

	// tail checks
	if(groundCards.GetTail()->GetDirection() == CardDirection::Left) {
		if(tailLowValue == card->GetUpValue()) {
			cardInfo.card2 = groundCards.GetTail();
			cardInfo.isHead = false;
			card->SetDirection(CardDirection::Left);
		}
		else if(tailLowValue == card->GetLowValue()) {
			cardInfo.card2 = groundCards.GetTail();
			cardInfo.isHead = false;
			card->SetDirection(CardDirection::Right);
		}
	}
	else if(groundCards.GetTail()->GetDirection() == CardDirection::Right) {
		int tailUpValue = groundCards.GetTail()->GetUpValue();
		if(tailUpValue == card->GetUpValue()) {
			cardInfo.card2 = groundCards.GetTail();
			cardInfo.isHead = false;
			card->SetDirection(CardDirection::Left);
		}
		else if(tailUpValue == card->GetLowValue()) {
			cardInfo.card2 = groundCards.GetTail();
			cardInfo.isHead = false;
			card->SetDirection(CardDirection::Right);
		}
	}

	return cardInfo;
}
/*
void OnMouseClickDetected(Vector2 mousePos) {
	if(isPlayer1Turn) {
		Card* card = IsIntersectingWithObjects(mousePos, (*(players->data()))->GetCards());
		if(card != NULL) {
			if(card->GetIsHighlighted()) {
				if(groundCards.GetHead() == NULL) {
					// when no cards are on the ground
					int cardXPos = (Width - card->GetWidth()) / 2;
					int cardYPos = (Height - card->GetHeight()) / 2;
					card->SetX(cardXPos);
					card->SetY(cardYPos);
					groundCards.Append(card);
					(*players)[0]->PlayCard(card);
				}
				else {
					// ground contains cards
					CardInfo cardInfo = IsCardCombitableWith(card);

					if(cardInfo.card1 != NULL && cardInfo.card2 != NULL) {
						// tail and head both matches the card to be played

					}

					if(cardInfo.card1 != NULL) {
						(*players)[0]->PlayCard(card);

						if(cardInfo.isHead) {
							std::cout << "Card to be played: " << card->GetUpValue() << "|" << card->GetLowValue() <<
																", head card: " << groundCards.GetHead()->GetUpValue() << "|" <<
																groundCards.GetHead()->GetLowValue()
																<< std::endl;
							// attach to head
							card->AdaptWithCard(cardInfo.card1, cardInfo.isHead, Width, Height);
							groundCards.Prepend(card);
						}
						else {
							// attach to tail
							card->AdaptWithCard(cardInfo.card1, cardInfo.isHead, Width, Height);
							groundCards.Append(card);
						}
					}
					else {
						std::cout << "No Cards are Compatible with " << card->GetUpValue() << "|" << card->GetLowValue() << std::endl;
					}
				}
			}
			else {
				(*players)[0]->SelectCard(card);
			}
		}
	}
}
*/
