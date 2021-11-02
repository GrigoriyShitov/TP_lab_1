#pragma once
#include "Base.h"
class Wind :
    public Base
{
private:
	string name, nameManufacturer, FIOOwner, deffects;
	int count;
	double price;
public:
	Wind();
	Wind(string name, string author, string annotation, string educationaInstitution,
		int yearReliase, int yearLearning, int volueme, double price);
	Wind(const Wind& wind);
	~Wind() { cout << "Вызван деструктор Wind" << endl; }

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

	string getDeffects() { return deffects; }
	void setDeffects(string deffects) { this->deffects = deffects; }

	int getCount() { return count; }
	void setCount(int count) { this->count = count; }

	double gePrice() { return price; }
	void setPrice(double price) { this->price = price; }
};

