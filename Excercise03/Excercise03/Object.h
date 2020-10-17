#ifndef OBJECT_H
#define OBJECT_H

class Object {
	int id;
	double x;
	double y;
public:
	Object() = delete;
	Object(int id);
	virtual ~Object() { };
	int GetId();
	double GetX();
	double GetY();
	void SetX(double x);
	void SetY(double y);
};

#endif // !OBJECT_H

