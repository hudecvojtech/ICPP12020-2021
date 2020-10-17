#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovableObject.h"

class Game {
	Object** objects = new Object*[10];
	int* arrayOfIds = new int[100];
	MovableObject** arrayOfMovableItems = new MovableObject*[100];
	MovableObject** arrayOfMovableItemsWithRotation = new MovableObject*[100];

	int arrayCounter = 0;
	int staticObjectsCounter = 0;
	int movableObjectsCounter = 0;
	int movableObjectsWithRotationCounter = 0;
public:
	~Game();
	void InsertObject(Object* o);
	int* FindIdsOfStaticObjects(double xmin, double xmax, double ymin, double ymax);
	MovableObject** FindMovableObjectsInArea(double x, double y, double r);
	MovableObject** FindMovableObjectsInArea(double x, double y, double r, double umin, double umax);
	int GetStaticObjectsCounter();
	int GetMovableObjectsCounter();
	int GetMovableObjectsWithRotationCounter();
};

#endif // !GAME_H

