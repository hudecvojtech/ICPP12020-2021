#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "Object.h"

enum ObstacleType { Rock, SmallPlant, BigPlant };

class StaticObject : public Object {
	ObstacleType obstacleType;	
public:
	StaticObject(int id, ObstacleType obstacleType);
	~StaticObject() { };
	ObstacleType GetObstacleType();
};

#endif // !STATIC_OBJECT_H
