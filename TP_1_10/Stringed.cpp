#include "Stringed.h"

Stringed::Stringed() : Base("Струнный"), name("Не задано"), nameManufacturer("Не задано"), FIOOwner("Не задано"), description("Не задано"),
	count(0), price(0.0)
{
	cout << "Вызван конструктор Stringed" << endl;
}

Stringed::Stringed(string name, string nameManufacturer, string FIOOwner, string description, int count, double price) :
	Base("Струнный"), name(name), nameManufacturer(nameManufacturer), FIOOwner(FIOOwner), description(description),
	count(count), price(price)
{
	cout << "Вызван конструктор Stringed" << endl;
}

Stringed::Stringed(const Stringed& stringed) :
	Base(stringed), name(stringed.name), nameManufacturer(stringed.nameManufacturer), 
	FIOOwner(stringed.FIOOwner), description(stringed.description), count(stringed.count), price(stringed.price)
{
	cout << "Вызван конструктор копирования Stringed" << endl;
}

void Stringed::inputFromConsole()
{
	cout << "Введите название: ";
	getline(cin, name);
	cout << "Введите название производителя: ";
	getline(cin, nameManufacturer);
	cout << "Введите ФИО владельца: ";
	getline(cin, FIOOwner);
	cout << "Введите краткое описание: ";
	getline(cin, description);
	cout << "Введите количесво единиц в оркестре: ";
	count = safeInput(1, INT32_MAX);
	cout << "Введите цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Stringed::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	name = tmpS;
	if (!getline(file, tmpS))
		throw err;
	nameManufacturer = tmpS;
	if (!getline(file, tmpS))
		throw err;
	FIOOwner = tmpS;
	if (!getline(file, tmpS))
		throw err;
	description = tmpS;
	if (!getline(file, tmpS))
		throw err;
	count = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	price = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Stringed::printToConsole()
{
	Base::printToConsole();
	cout << "Название: " << name << endl;
	cout << "Название производителя: " << nameManufacturer << endl;
	cout << "ФИО владельца: " << FIOOwner << endl;
	cout << "Краткое описание: " << description << endl;
	cout << "Количество единиц в оркестре: " << count << endl;
	cout << "Цена: " << price << endl;
}

void Stringed::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << name << endl;
	out << nameManufacturer << endl;
	out << FIOOwner << endl;
	out << description << endl;
	out << count << endl;
	out << price << endl;
}

void Stringed::change()
{
	cout << "Введите новое название: ";
	getline(cin, name);
	cout << "Введите новое название производителя: ";
	getline(cin, nameManufacturer);
	cout << "Введите ФИО нового владельца: ";
	getline(cin, FIOOwner);
	cout << "Введите новое краткое описание: ";
	getline(cin, description);
	cout << "Введите новое количесво единиц в оркестре: ";
	count = safeInput(1, INT32_MAX);
	cout << "Введите новую цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}