#pragma once
#include "Character.h"
#include "Locations.h"
#include "Items.h"
#include <iostream>
#include <string>
#include <iomanip>

class Game
{
private:
	//variables
	bool playing;
public:
	//variables
	string choice;
	//constructor
	Game();
	//destructor
	~Game();
	//Functions
	//Creates Character, Locations, and gets Character's name
	void setGame();
	//prints the intro to the game
	void printIntro();
	void printHelp();
	void dropInventory();
	void grabInventory();
	//the main game menu where the player will be asked for input
	void gameMenu();
	//check the player input against the available keywords 
	string keywordChecker(string, bool&);

	Character *character;
	/* Locations *charLocation;
	Entrance *entrance;
	LockerRoom *lockerRoom;
	Cafeteria *cafeteria;
	CompLab *compLab;
	ChemLab *chemLab;
	ChemCloset *chemCloset;*/
	FlashDrive *flashDrive;
	FlashLight *flashLight;
	ChemClosetKey *chemKey; 
	AcidBottle *acidBottle;
	MaintenanceKey *mainKey;
};


