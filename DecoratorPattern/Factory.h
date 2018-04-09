#pragma once
//include our decorators
#include "FarmerDecorator.h"
#include "ShamanDecorator.h"
#include "SoldierDecorator.h"
#include "Orcs.h"
#include "Elves.h"
#include "Factory.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Factory
{

public:
	Factory();
	void Input();
	void Create(int Role, int Race, std::string Name);
	void DisplayObjects();
	vector<NPC*> FactoryObject;
};