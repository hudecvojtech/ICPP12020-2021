#include "MovableObject.h"

double MovableObject::GetRotationAngle() {
	return rotationAngle;
}

void MovableObject::SetRotationAngle(double rotationAngle) {
	while (rotationAngle > 2 * M_PI)
		rotationAngle -= 2 * M_PI;

	while (rotationAngle < 0) {
		rotationAngle += 2 * M_PI;
	}

	this->rotationAngle = rotationAngle;
}