#include "Object.h"

Object::Object(int id) {
	this->id = id;
	x = 0;
	y = 0;
}

int Object::GetId() {
	return id;
}

double Object::GetX() {
	return x;
}

double Object::GetY() {
	return y;
}

void Object::SetX(double x) {
	this->x = x;
}

void Object::SetY(double y) {
	this->y = y;
}