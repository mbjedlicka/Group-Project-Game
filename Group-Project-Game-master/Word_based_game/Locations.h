#pragma once
#include<string>
#include<iostream>
#include <iomanip>
#include"Items.h"

using namespace std;
class Locations
{
private:
public:
	string locKeywords[7];
	Items *inventory[5];
	string name;
	string description;
	//constructor
	Locations();
	~Locations();

	virtual void enter() {

	}

	virtual void update(string choice) {

	}

	virtual void look() {

	}

	virtual void removeItem(int) {

	}

	virtual void addItem(int) {

	}
};

extern Locations * charLocation;
extern Locations * entrance;
extern Locations * maintenanceCloset;
extern Locations * cafeteria;
extern Locations * compLab;
extern Locations * chemLab;
extern Locations * chemCloset;

class Entrance : public Locations
{
public:
	Entrance();
	//functions
	void enter();

	void update(string);

	void look();

	void removeItem(int);

	void addItem(int);
};


class MaintenanceCloset : public Locations
{
public:
	MaintenanceCloset();
	//functions
	void enter();

	void update(string);

	void look();

	void removeItem(int);

	void addItem(int);



};

class Cafeteria : public Locations
{
public:
	Cafeteria();
	//functions
	void enter();

	void update(string);

	void look();

	void removeItem(int);

	void addItem(int);
};

class CompLab : public Locations
{
public:
	CompLab();
	//functions
	void enter();

	void update(string);

	void look();

	void removeItem(int);

	void addItem(int);
};

class ChemLab : public Locations
{
public:
	ChemLab();
	//functions
	void enter();

	void update(string);

	void look();

	void removeItem(int);

	void addItem(int);
};

class ChemCloset : public Locations
{
public:
	ChemCloset();
	//functions
	void enter();

	void update(string);

	void look();

	void removeItem(int);

	void addItem(int);
};

