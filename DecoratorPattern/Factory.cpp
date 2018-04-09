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

//Opmerking: gemaakt met hulp en tips van Frans, ik liep hierop stuk. Samen hebben we naar mijn code gekeken en heeft hij me uitgelegd wat er anders moest/waar ik fouten maakte


Factory::Factory()
{
}

void Factory::Input()//get user input on class, race and name
{
	int Class;
	int Race;
	string Name;

	cout << "~CHARACTER CREATION~" << endl;
	cout << "-----------------" << endl << endl << endl;
	cout << " Insert Race (0 = Elf race, 1 = Orc race) " << endl;
	cin >> Race;
	cout << " Insert Class  (0 = Farmer, 1 = Shaman, 2 = Soldier) " << endl;
	cin >> Class;
	cout << " Insert Name " << endl;
	cin >> Name;

	Create(Class, Race, Name);

}


void Factory::Create(int Class, int Race, string Name)//Create characters with all classes and races
{
	NPC *newCharacter;

	switch (Class)
	{
	case 0: 
		switch (Race)
		{
		case 0: 
			newCharacter = new FarmerDecorator(new Elves(Name));
			break;
		case 1:
			newCharacter = new FarmerDecorator(new Orcs(Name));
			break;
		}
		break;

	case 1:
		switch (Race)
		{
		case 0: 
			newCharacter = new ShamanDecorator(new Elves(Name));
			break;
		case 1: 
			break;
			newCharacter = new ShamanDecorator(new Orcs(Name));
		}
		break;

	case 2:
		switch (Race)
		{
		case 0:
			newCharacter = new SoldierDecorator(new Elves(Name));
			break;
		case 1:
			newCharacter = new SoldierDecorator(new Orcs(Name));
			break;
		}
		break;
	}
	FactoryObject.push_back(newCharacter);
}


void Factory::DisplayObjects() //cout the vector
{
	cout << endl << endl;
	cout << "Every character created through the factory:" << endl;

	vector<NPC*>::iterator it = FactoryObject.begin();
	while (it != FactoryObject.end()) {
		(*it)->Render();
		it++;
	}
	cout << endl;
}

