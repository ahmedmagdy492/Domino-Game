#pragma once

// this is just a data holder and we're not breaking the encpsulation of the class
class CardInfo {
public:
	bool isHead;
	Card* card; // will be null if no cards are compatible
};
