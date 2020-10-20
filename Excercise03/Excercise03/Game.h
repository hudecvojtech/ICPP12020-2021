#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovableObject.h"

#define ARRAY_SIZE 100

class Game {
	Object** objects;
	int* arrayOfIds;
	MovableObject** arrayOfMovableItems;
	MovableObject** arrayOfMovableItemsWithRotation;

	int arrayCounter;
	int staticObjectsCounter;
	int movableObjectsCounter;
	int movableObjectsWithRotationCounter;
public:
	Game();
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

