#include "./include/InputDetector.h"

#include <iostream>

#include "./include/raylib.h"

void InputDetector::SubscribeToMouseEvents(OnInputEventDetected callback) {
	mouseEventsSubscribers->push_back(callback);
}

void InputDetector::StartInputEventsCapture() {
	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		unsigned int size = mouseEventsSubscribers->size();

		for(int i = 0;i < size; i++) {
			(*mouseEventsSubscribers)[i](GetMousePosition());
		}
	}
}
