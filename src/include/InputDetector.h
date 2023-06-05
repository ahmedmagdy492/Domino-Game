#pragma once

#include <vector>

#include "raylib.h"

typedef void (*OnInputEventDetected)(Vector2 mousePos);

class InputDetector
{
private:
	std::vector<OnInputEventDetected>* mouseEventsSubscribers;
public:
	InputDetector() {
		mouseEventsSubscribers = new std::vector<OnInputEventDetected>();
	}
	~InputDetector() {
		delete mouseEventsSubscribers;
	}
	void SubscribeToMouseEvents(OnInputEventDetected callback);
	// TODO: consider adding a function to unsubscribe objects
	void StartInputEventsCapture();
};
