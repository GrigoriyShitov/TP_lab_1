#pragma once
#include "Base.h"
class Percussion :
    public Base
{
private:
    string type, name, FIOOwner;
    int count;
	double price;
public:
	Percussion();
	Percussion(string type, string name, string FIOOwner, int count, double price);
	Percussion(const Percussion& percussion);
	~Percussion() { cout << "Вызван деструктор Percussion" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getType() { return type; }
	void setType(string type) { this->type = type; }

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	string getFIOOwner() { return FIOOwner; }
	void setFIOOwner(string FIOOwner) { this->FIOOwner = FIOOwner; }

	int getCount() { return count; }
	void setCount(int count) { this->count = count; }

	double gePrice() { return price; }
	void setPrice(double price) { this->price = price; }

};

