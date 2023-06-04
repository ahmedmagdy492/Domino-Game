#include "./include/InputDetector.h"

#include "./include/raylib.h"

void InputDetector::StartInputEventsCapture(OnInputEventDetected callback) {
	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		callback(GetMousePosition());
	}
}
