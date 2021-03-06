#include "Game.h"
#include "StaticObject.h"
#include <math.h>

Game::Game()
{
	objects = new Object* [ARRAY_SIZE];
	arrayOfIds = nullptr;
	arrayOfMovableItems = nullptr;
	arrayOfMovableItemsWithRotation = nullptr;

	arrayCounter = 0;
	staticObjectsCounter = 0;
	movableObjectsCounter = 0;
	movableObjectsWithRotationCounter = 0;
}

void Game::InsertObject(Object* o)
{
	if (arrayCounter >= ARRAY_SIZE)
		throw "Not enough space in array.";

		objects[arrayCounter++] = o;
}

int* Game::FindIdsOfStaticObjects(double xmin, double xmax, double ymin, double ymax)
{
	staticObjectsCounter = 0;
	arrayOfIds = new int[arrayCounter];
	for (int i = 0; i < arrayCounter; i++) {
		if (dynamic_cast<StaticObject*>(objects[i]) == nullptr)
			continue;

		if (objects[i]->GetX() > xmin && objects[i]->GetX() < xmax &&
			objects[i]->GetY() > ymin && objects[i]->GetY() < ymax) {
			arrayOfIds[staticObjectsCounter++] = objects[i]->GetId();
		}
	}

	return arrayOfIds;
}

MovableObject** Game::FindMovableObjectsInArea(double x, double y, double r)
{
	movableObjectsCounter = 0;
	arrayOfMovableItems = new MovableObject* [arrayCounter];
	for (int i = 0; i < arrayCounter; i++) {
		if (dynamic_cast<MovableObject*>(objects[i]) == nullptr)
			continue;

		if (sqrt(pow(abs(objects[i]->GetX() - x), 2.0) + pow(abs(objects[i]->GetY() - y), 2.0)) < r) {
			arrayOfMovableItems[movableObjectsCounter++] = (MovableObject*)objects[i];
		}
	}

	return arrayOfMovableItems;
}

MovableObject** Game::FindMovableObjectsInArea(double x, double y, double r, double umin, double umax)
{
	movableObjectsWithRotationCounter = 0;
	MovableObject** arrayInDimensions = FindMovableObjectsInArea(x, y, r);
	arrayOfMovableItemsWithRotation = new MovableObject* [arrayCounter];

	for (int i = 0; i < GetMovableObjectsCounter(); i++) {
		if (arrayInDimensions[i]->GetRotationAngle() < umax && arrayInDimensions[i]->GetRotationAngle() > umin) {
			arrayOfMovableItemsWithRotation[movableObjectsWithRotationCounter++] = arrayInDimensions[i];
		}
	}

	return arrayOfMovableItemsWithRotation;

}

Game::~Game() {
	delete[] objects;
	delete[] arrayOfIds;
	delete[] arrayOfMovableItems;
	delete[] arrayOfMovableItemsWithRotation;
}

int Game::GetStaticObjectsCounter()
{
	return staticObjectsCounter;
}

int Game::GetMovableObjectsCounter()
{
	return movableObjectsCounter;
}

int Game::GetMovableObjectsWithRotationCounter() {
	return movableObjectsWithRotationCounter;
}
