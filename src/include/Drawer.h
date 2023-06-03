#pragma once

#include <vector>

#include "raylib.h"
#include "GameObject.h"
#include "Util.h"


class Drawer
{
	public:
	void DrawPlayersCards(std::vector<Card*>* objects);
	void DrawGroundCards(LinkedList& groundCards);
};
