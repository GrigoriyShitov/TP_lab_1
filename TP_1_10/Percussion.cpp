#include "Percussion.h"

Percussion::Percussion() : Base("Ударный"), type("Не задано"), name("Не задано"), FIOOwner("Не задано"), count(0), price(0.0)
{
	cout << "Вызван конструктор Percussion" << endl;
}

Percussion::Percussion(string type, string name, string FIOOwner, int count, double price) :
	Base("Ударный"), type(type), name(name), FIOOwner(FIOOwner), count(count), price(price)
{
	cout << "Вызван конструктор Percussion" << endl;
}

Percussion::Percussion(const Percussion& percussion) :
	Base(percussion), type(percussion.type), name(percussion.name), FIOOwner(percussion.FIOOwner), 
	count(percussion.count), price(percussion.price)
{
	cout << "Вызван конструктор копирования Percussion" << endl;
}

void Percussion::inputFromConsole()
{
	cout << "Введите тип: ";
	getline(cin, type);
	cout << "Введите название: ";
	getline(cin, name);
	cout << "Введите ФИО владельца: ";
	getline(cin, FIOOwner);
	cout << "Введите количесво единиц в оркестре: ";
	count = safeInput(1, INT32_MAX);
	cout << "Введите цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Percussion::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	type = tmpS;
	if (!getline(file, tmpS))
		throw err;
	name = tmpS;
	if (!getline(file, tmpS))
		throw err;
	FIOOwner = tmpS;
	if (!getline(file, tmpS))
		throw err;
	count = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	price = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Percussion::printToConsole()
{
	Base::printToConsole();
	cout << "Тип: " << type << endl;
	cout << "Название: " << name << endl;
	cout << "ФИО владельца: " << FIOOwner << endl;
	cout << "Количество единиц в оркестре: " << count << endl;
	cout << "Цена: " << price << endl;
}

void Percussion::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << type << endl;
	out << name << endl;
	out << FIOOwner << endl;
	out << count << endl;
	out << price << endl;
}

void Percussion::change()
{
	cout << "Введите новый тип: ";
	getline(cin, type);
	cout << "Введите новое название: ";
	getline(cin, name);
	cout << "Введите ФИО нового владельца: ";
	getline(cin, FIOOwner);
	cout << "Введите новое количесво единиц в оркестре: ";
	count = safeInput(1, INT32_MAX);
	cout << "Введите новую цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}