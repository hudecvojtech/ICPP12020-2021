#ifndef MONSTRUM_H
#define MONSTRUM_H
#include "MovableObject.h"

class Monstrum : public MovableObject {
	int hp;
	int maxhp;	
public:
	Monstrum(int id) : MovableObject(id) { hp = maxhp = 0; };
	~Monstrum() { };
	int GetHp();
	int GetMaxHp();
	void SetHp(int hp);
	void SetMaxHp(int maxhp);
};

#endif // !MONSTRUM_H

