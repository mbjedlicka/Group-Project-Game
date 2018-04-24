#include "Game.h"
Game::Game()
{

	choice = "";
	playing = true;
}

Game::~Game()
{
	delete character;

	delete entrance;
	delete maintenanceCloset;
	delete cafeteria;
	delete compLab;
	delete chemLab;
	delete chemCloset;

	delete flashDrive;
	delete mainKey;
	delete chemKey;
	delete acidBottle;
	delete flashLight;
}

//Functions
void Game::setGame()
{
	//creates all gameplay objects
	character = new Character();

	charLocation = new Locations();
	entrance = new Entrance();
	maintenanceCloset = new MaintenanceCloset();
	cafeteria = new Cafeteria();
	compLab = new CompLab();
	chemLab = new ChemLab();
	chemCloset = new ChemCloset();

	flashDrive = new FlashDrive();
	mainKey = new MaintenanceKey();
	chemKey = new ChemClosetKey();
	acidBottle = new AcidBottle();
	flashLight = new FlashLight();
	/*
	Inventory Locations
	0 = Flash Drive
	1 = Flash Light
	2 = Maintenance Key
	3 = Chemical Key
	4 = Acid Bottle
	*/
	//populates the items in locations
	entrance->inventory[0] = flashDrive;
	entrance->inventory[1] = flashLight;
	entrance->inventory[2] = mainKey;
	entrance->inventory[3] = chemKey;
	entrance->inventory[4] = acidBottle;

	cafeteria->inventory[0] = flashDrive;
	cafeteria->inventory[1] = flashLight;
	cafeteria->inventory[2] = mainKey;
	cafeteria->inventory[3] = chemKey;
	cafeteria->inventory[4] = acidBottle;

	entrance->inventory[0]->entranceExists = true;
	
	cafeteria->inventory[1]->cafeExists = true;

	charLocation = entrance;


	string input = "";
	cout << "Enter your characters name: ";
	getline(cin, input);
	character->setName(input);
	system("cls");

}

void Game::printIntro()
{
	cout << "     ======DORK======" << endl;
	cout << "Make an intro. You wake up confused on the floor and everything's real fuzzy." << endl;
	cout << "You get your bearings and realize you are in what looks like a school." << endl;
	cout << "Your eyes start to adjust and you can begin to make out a dimly lit hallway ahead of you." << endl << endl;
	cout << "Next to your feet you see a Flash Drive and you start to remember what happened before you got here" << endl;
	cout << "This Flash Drive got you into this mess and now it's here too. If it got you into this mess maybe it can get you out?" << endl;
	cout << "You should probably pick it up." << endl << endl;
	
	cout << "HINT: Type 'help' For A List Of Commands" << endl << endl;

	charLocation->enter();
}
void Game::printHelp()
{
	cout << endl;
	cout << "============HELP MENU============" << endl;
	cout << "North ------------> Moves Character North" << endl;
	cout << "South ------------> Moves Character South" << endl;
	cout << "East  ------------> Moves Character East" << endl;
	cout << "West  ------------> Moves Character West" << endl;
	cout << "Look  ------------> Describes Room and Objects" << endl;
	cout << "Grab  ------------> Attempts To Grab An Item" << endl;
	cout << "Use   ------------> Uses An Item In Inventory" << endl;
	cout << "Drop  ------------> Drops An Item From Inventory" << endl;
	cout << "Inventory --------> Looks At Character Inventory" << endl;
	cout << endl;

}
//drops item from player inventory
void Game::dropInventory() {
	string select;
	character->printInventory();
	cout << endl << "Enter name of Item you want to drop: ";
	getline(cin, select);
	for (int i = 0; i < 5; i++) {
		if (select.compare(character->inventory[i]->name) == 0) {
			if (character->inventory[i]->inventoryExists == true)
			{
				charLocation->inventory[i] = character->inventory[i];
				character->inventory[i]->inventoryExists = false;
				charLocation->addItem(i);
				break;
			}
			else {
				cout << "You do not have that item" << endl;
			}
		}
	}
}

void Game::grabInventory() {
	string select;
	cout << "You can grab: ";
	charLocation->look();
	cout << endl << "Enter name of Item you want to take: ";
	getline(cin, select);
	for (int i = 0; i < 5; i++) {
		if (select.compare(charLocation->inventory[i]->name) == 0) {
			charLocation->removeItem(i);
			character->inventory[i] = charLocation->inventory[i];
			character->inventory[i]->inventoryExists = true;
			cout << endl << "You picked up: " << character->inventory[i]->name;
			break;
		}
	}
}

string Game::keywordChecker(string input, bool& validInput)
{
	string inputReturn;
	validInput = false;
	//makes all characters lowercase
	string keywords[] = { "north", "south", "east", "west", "look", "grab", "use", "drop", "inventory", "help" };

	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
	//checks input against menu keywords
	for (int i = 0; i < 10; i++)
	{
		if (input.find(keywords[i]) != string::npos)
		{
			validInput = true;
			inputReturn = keywords[i];
			break;
		}
		else
			validInput = false;
	}
	return inputReturn;
}

void Game::gameMenu()
{
	bool validInput = false;

	

	do
	{
		cout << endl << "What do you do?: ";
		getline(cin, choice);
		if (keywordChecker(choice, validInput).compare("inventory") == 0)
		{
			character->printInventory();
		}
		else if (keywordChecker(choice, validInput).compare("grab") == 0)
		{
			grabInventory();
		}
		else if (keywordChecker(choice, validInput).compare("drop") == 0) {
			dropInventory();
		}
		else if (keywordChecker(choice, validInput).compare("help") == 0)
		{
			printHelp();
		}
		else
			charLocation->update(keywordChecker(choice, validInput));

	} while (validInput == false);

}

