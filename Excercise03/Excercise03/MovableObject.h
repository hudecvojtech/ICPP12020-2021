#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H
#define _USE_MATH_DEFINES
#include "Object.h"
#include <cmath>

class MovableObject : public Object {
	double rotationAngle;
public:
	MovableObject(int id) : Object(id) { rotationAngle = 0; };
	~MovableObject() { };
	double GetRotationAngle();
	void SetRotationAngle(double rotationAngle);
};

#endif // !MOVABLE_OBJECT_H
