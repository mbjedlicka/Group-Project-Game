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

void CompLab::enter() {
	cout << endl << endl << "=====" << name << "=====" << endl;
	cout << description << endl;
}

void CompLab::update(string choice) {

}

void CompLab::look() {
	for (int i = 0; i < 5; i++)
	{
		if (inventory[i] != NULL && inventory[i]->compExists == true)
		{
			cout << inventory[i]->name << " ";
		}
	}
}

void CompLab::removeItem(int i) {
	if(charLocation->inventory[i]->compExists = true)
	{
	charLocation->inventory[i]->compExists = false;
	}
	else {
		cout << "That Item is not here" << endl;
	}
}

void CompLab::addItem(int i) {
	charLocation->inventory[i]->compExists = true;
}


ChemLab::ChemLab()
{
	name = "Chemistry Lab";
	description = "You have entered the school Chemistry Lab.\n";
}

void ChemLab::enter() {
	cout << endl << endl << "=====" << name << "=====" << endl;
	cout << description << endl;
}

void ChemLab::update(string choice) {

}

void ChemLab::look() {
	for (int i = 0; i < 5; i++)
	{
		if (inventory[i] != NULL && inventory[i]->chemLabExists == true)
		{
			cout << inventory[i]->name << " ";
		}
	}
}

void ChemLab::removeItem(int i) {
	if(charLocation->inventory[i]->chemLabExists = true)
	{
	charLocation->inventory[i]->chemLabExists = false;
	}
	else {
		cout << "That Item is not here" << endl;
	}
}

void ChemLab::addItem(int i) {
	charLocation->inventory[i]->chemLabExists = true;
}


ChemCloset::ChemCloset()
{
	name = "Chemistry Closet";
	description = "You have entered the school Chemistry Closet.\n";
}

void ChemCloset::enter() {
	cout << endl << endl << "=====" << name << "=====" << endl;
	cout << description << endl;
}

void ChemCloset::update(string choice) {

}

void ChemCloset::look() {
	for (int i = 0; i < 5; i++)
	{
		if (inventory[i] != NULL && inventory[i]->chemClosetExists == true)
		{
			cout << inventory[i]->name << " ";
		}
	}
}

void ChemCloset::removeItem(int i) {
	if(charLocation->inventory[i]->chemClosetExists = true)
	{
	charLocation->inventory[i]->cafeExists = false;
	}
	else {
		cout << "That Item is not here" << endl;
	}
}

void ChemCloset::addItem(int i) {
	charLocation->inventory[i]->chemClosetExists = true;
}
