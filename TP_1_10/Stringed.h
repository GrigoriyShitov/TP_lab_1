#pragma once
#include "Base.h"

class Stringed :
    public Base
{
private:
	string name, nameManufacturer, FIOOwner, description;
	int count;
	double price;
public:
	Stringed();
	Stringed(string name, string nameManufacturer, string FIOOwner, string description, int count, double price);
	Stringed(const Stringed& stringed);
	~Stringed() { cout << "Вызван деструктор Stringed" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	string getNameManufacturer() { return nameManufacturer; }
	void setNameManufacturer(string nameManufacturer) { this->nameManufacturer = nameManufacturer; }

	string getFIOOwner() { return FIOOwner; }
	void setFIOOwner(string FIOOwner) { this->FIOOwner = FIOOwner; }

	string getDescription() { return description; }
	void setDescription(string description) { this->description = description; }

	int getCount() { return count; }
	void setCount(int count) { this->count = count; }

	double gePrice() { return price; }
	void setPrice(double price) { this->price = price; }
};

