#pragma once
#include <iostream>
#include <string>
#include"Items.h"
#include"Locations.h"

using namespace std;

class Character
{
private:
	//variables
	string name;
	Locations * current;
	string previousLocation;
public:
	Items * inventory[5];
	//constructor
	Character();
	//destructor
	~Character();
	//Functions
	string getName() { return this->name; }
	void setName(string name) { this->name = name; };
	void printInventory();
	void move();
	void action();
};

extern Character * character;