#include "Locations.h"

//constructor
Locations::Locations()
{
	name = "";
	description = "";
	inventory[0] = flashDrive;
	inventory[1] = flashLight;
	inventory[2] = mainKey;
	inventory[3] = chemKey;
	inventory[4] = acidBottle;
}

//destructor
Locations::~Locations()
{

}

Locations *charLocation, *entrance, *maintenanceCloset, *cafeteria, *chemLab, *compLab, *chemCloset;


// entrance constructor
Entrance::Entrance()
{
	name = "Entrance";
	description = "You are at the entrance of the school. The front doors are locked and you still aren't sure how you ended up here.\nYou take a look through the windows but see nothing outside. You turn back around and look down the hallway the way you came.\n";
}

void Entrance::enter() {
	cout << endl << endl << "=====" << name << "=====" << endl;
	cout << description << endl;
}

void Entrance::update(string choice) {
	if (choice == "west") {
		charLocation = cafeteria;
		charLocation->enter();
	}
	else if (choice == "east")
	{
		charLocation = maintenanceCloset;
		charLocation->enter();
	}
	else if (choice == "south") {
		cout << "You can't go that way" << endl;
	}
	else if (choice == "north") {
		cout << "It's too dark that way. You need to find a flashlight" << endl;
	}
	else if (choice == "look") {
		charLocation->look();
	}
}

void Entrance::look() {
	for (int i = 0; i < 5; i++)
	{
		if (inventory[i] != NULL && inventory[i]->entranceExists == true)
		{
			cout << inventory[i]->name << " ";
		}
	}
}

void Entrance::removeItem(int i) {
	if(charLocation->inventory[i]->entanceExists = true)
	{
	charLocation->inventory[i]->entranceExists = false;
	}
	else {
		cout << "That Item is not here" << endl;
	}
}

void Entrance::addItem(int i) {
	charLocation->inventory[i]->entranceExists = true;
}

MaintenanceCloset::MaintenanceCloset()
{
	name = "Maintenance Closet";
	description = "You have entered the Maintenance Closet.\n";
}

void MaintenanceCloset::enter() {

}

void MaintenanceCloset::update(string choice) {

}

void MaintenanceCloset::look() {
	for (int i = 0; i < 5; i++)
	{
		if (inventory[i] != NULL && inventory[i]->maintExists == true)
		{
			cout << inventory[i]->name << " ";
		}
	}
}

void MaintenanceCloset::removeItem(int i) {
	if(charLocation->inventory[i]->maintExists = true)
	{
	charLocation->inventory[i]->maintExists = false;
	}
	else {
		cout << "That Item is not here" << endl;
	}
}

void MaintenanceCloset::addItem(int i) {
	charLocation->inventory[i]->maintExists = true;
}

Cafeteria::Cafeteria()
{
	name = "Cafeteria";
	description = "You have entered the school Cafeteria.\n";
}

void Cafeteria::enter() {
	cout << endl << endl << "=====" << name << "=====" << endl;
	cout << description << endl;
}

void Cafeteria::update(string choice) {

}

void Cafeteria::look() {
	for (int i = 0; i < 5; i++)
	{
		if (inventory[i] != NULL && inventory[i]->cafeExists == true)
		{
			cout << inventory[i]->name << " ";
		}
	}
}

void Cafeteria::removeItem(int i) {
	if(charLocation->inventory[i]->cafeExists = true)
	{
	charLocation->inventory[i]->cafeExists = false;
	}
	else {
		cout << "That Item is not here" << endl;
	}
}

void Cafeteria::addItem(int i) {
	charLocation->inventory[i]->cafeExists = true;
}

CompLab::CompLab()
{
	name = "Computer Lab";
	description = "You have entered the school Computer Lab.\n";
}

ChemLab::ChemLab()
{
	name = "Chemistry Lab";
	description = "You have entered the school Chemistry Lab.\n";
}

ChemCloset::ChemCloset()
{
	name = "Chemistry Closet";
	description = "You have entered the school Chemistry Closet.\n";
}
CurrentLoc::CurrentLoc()
{
	name = "";
	description = "";
}
