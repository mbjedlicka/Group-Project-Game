#pragma once
#include <iostream>
#include <string>

using namespace std;
class Items
{
private:
	

public:
	//variables
	string name;
	string description;
	bool inventoryExists;
	bool entranceExists;
	bool cafeExists;
	bool maintExists;
	bool compExists;
	bool chemLabExists;
	bool chemClosetExists;
	//constructor
	Items();
	//destructor
	~Items();
};

extern Items * flashDrive;
extern Items * flashLight;
extern Items * mainKey;
extern Items * chemKey;
extern Items * acidBottle;

class FlashDrive:public Items
{
public:
	FlashDrive();
};
class FlashLight:public Items
{
public:
	FlashLight();
};
class ChemClosetKey :public Items
{
public:
	ChemClosetKey();
};
class AcidBottle :public Items
{
public:
	AcidBottle();
};
class MaintenanceKey :public Items
{
public:
	MaintenanceKey();
};

