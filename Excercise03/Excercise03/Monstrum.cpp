#include "Monstrum.h"

int Monstrum::GetHp() {
	return hp;
}

int Monstrum::GetMaxHp() {
	return maxhp;
}

void Monstrum::SetHp(int hp) {
	this->hp = hp;
}

void Monstrum::SetMaxHp(int maxhp) {
	this->maxhp = maxhp;
}