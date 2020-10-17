#include "Game.h"
#include "StaticObject.h"
#include "MovableObject.h"
#include "Monstrum.h"
#include <iostream>

int main() {
	Game game;
	StaticObject* smallPlant = new StaticObject(1, SmallPlant);
	smallPlant->SetX(5);
	smallPlant->SetY(5);

	StaticObject* bigPlant = new StaticObject(10, BigPlant);
	bigPlant->SetX(7);
	bigPlant->SetY(7);

	StaticObject* rock = new StaticObject(100, Rock);
	rock->SetX(9);
	rock->SetY(9);

	MovableObject* movable = new MovableObject(2);
	movable->SetX(3);
	movable->SetY(3);
	movable->SetRotationAngle(5);

	Monstrum* monstrum = new Monstrum(3);
	monstrum->SetX(2);
	monstrum->SetY(2);
	monstrum->SetHp(3);
	monstrum->SetMaxHp(3);
	monstrum->SetRotationAngle(3);

	game.InsertObject(smallPlant);
	game.InsertObject(bigPlant);
	game.InsertObject(rock);
	game.InsertObject(movable);
	game.InsertObject(monstrum);

	int* staticIds = game.FindIdsOfStaticObjects(-100, 100, -100, 100);
	
	std::cout << "Static objects: " << std::endl;
	for (int i = 0; i < game.GetStaticObjectsCounter(); i++) {
		std::cout << staticIds[i] << " ";
	}
	std::cout << std::endl;

	MovableObject** movableObjects = game.FindMovableObjectsInArea(0, 0, 200, 0, 6);

	std::cout << "Movable objects: " << std::endl;
	for (int i = 0; i < game.GetMovableObjectsWithRotationCounter(); i++) {
		std::cout << movableObjects[i]->GetId() << " ";
	}
	std::cout << std::endl;

	delete smallPlant, bigPlant, rock, movable, monstrum;
	
	return 0;
}