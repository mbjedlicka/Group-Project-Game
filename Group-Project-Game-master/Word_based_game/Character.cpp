#include "Character.h"


//Constructor
Character::Character()
{
	name = "";
	current = charLocation;
}

//destructor
Character::~Character()
{
}

//Prints the characters inventory to the screen
void Character::printInventory()
{
	cout << "===Current Inventory===" << endl;
	if (inventory[0]->inventoryExists == true)
		cout << inventory[0]->name << endl;
}
void Character::move()
{

}
void Character::action()
{

}

Character * character;
