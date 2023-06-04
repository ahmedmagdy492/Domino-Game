#pragma once

#include "raylib.h"

typedef void (*OnInputEventDetected)(Vector2 mousePos);

class InputDetector
{
public:
	void StartInputEventsCapture(OnInputEventDetected callback);
};
