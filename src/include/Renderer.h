#pragma once

#include "GameObject.h"
#include "raylib.h"
#include "InputDetector.h"
#include <vector>

class Renderer
{
private:
	int width;
	int height;
	InputDetector* inputDetector;
	std::vector<GameObject*>* objectsToRender;
public:
	Renderer(int width, int height, InputDetector* inputDetector)
	: inputDetector(inputDetector) {
		this->width = width;
		this->height = height;
		objectsToRender = new std::vector<GameObject*>();
	}

	~Renderer() {
		delete objectsToRender;
	}

	void AddObjectToDraw(GameObject* gameObject) {
		this->objectsToRender->push_back(gameObject);
	}

	void RemoveObjectById(int id) {
		unsigned int size = objectsToRender->size();

		for(int i = 0; i < size; i++) {
			GameObject* gameObj = *objectsToRender[i].data();
			if(gameObj->GetId() == id) {
				objectsToRender->erase(objectsToRender->begin() + i);
			}
		}
	}

	void InitDrawing() {
		InitWindow(width, height, "Domino");
		SetTargetFPS(60);
	}

	void StartRendering() {
		unsigned int size = objectsToRender->size();

		while(!WindowShouldClose()) {
			BeginDrawing();

			ClearBackground(RAYWHITE);

			inputDetector->StartInputEventsCapture();

			for(int i = 0; i < size; i++) {
				GameObject* gameObj = (*objectsToRender)[i];
				gameObj->Draw();
			}

			EndDrawing();
		}

		CloseWindow();
	}
};
