#include "StaticObject.h"

StaticObject::StaticObject(int id, ObstacleType obstacleType) : Object(id) {
	this->obstacleType = obstacleType;
}

ObstacleType StaticObject::GetObstacleType() {
	return obstacleType;
}