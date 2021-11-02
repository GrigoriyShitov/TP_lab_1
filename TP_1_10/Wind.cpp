#include "Wind.h"

Wind::Wind() : Base("Духовой"), name("Не задано"), nameManufacturer("Не задано"), FIOOwner("Не задано"), deffects("Не задано"),
	count(0), price(0.0)
{
	cout << "Вызван конструктор Wind" << endl;
}

Wind::Wind(string name, string author, string annotation, string educationaInstitution,
	int yearReliase, int yearLearning, int volueme, double price) :
	Base("Духовой"), name(name), nameManufacturer(nameManufacturer),
	FIOOwner(FIOOwner), deffects(deffects), count(count), price(price)
{
	cout << "Вызван конструктор Wind" << endl;
}

Wind::Wind(const Wind& wind) :
	Base(wind), name(wind.name), nameManufacturer(wind.nameManufacturer),
	FIOOwner(wind.FIOOwner), deffects(wind.deffects), count(wind.count), price(wind.price)
{
	cout << "Вызван конструктор копирования Wind" << endl;
}

void Wind::inputFromConsole()
{
	cout << "Введите название: ";
	getline(cin, name);
	cout << "Введите название производителя: ";
	getline(cin, nameManufacturer);
	cout << "Введите ФИО владельца: ";
	getline(cin, FIOOwner);
	cout << "Введите деффекты: ";
	getline(cin, deffects);
	cout << "Введите количесво единиц в оркестре: ";
	count = safeInput(1, INT32_MAX);
	cout << "Введите цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Wind::inputFromFile(std::ifstream& file, std::string& tmpS)
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
	deffects = tmpS;
	if (!getline(file, tmpS))
		throw err;
	count = (checkStringToDouble(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	price = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void Wind::printToConsole()
{
	Base::printToConsole();
	cout << "Название: " << name << endl;
	cout << "Название производителя: " << nameManufacturer << endl;
	cout << "ФИО владельца: " << FIOOwner << endl;
	cout << "Деффекты: " << deffects << endl;
	cout << "Количество единиц в оркестре: " << count << endl;
	cout << "Цена: " << price << endl;
}

void Wind::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << name << endl;
	out << nameManufacturer << endl;
	out << FIOOwner << endl;
	out << deffects << endl;
	out << count << endl;
	out << price << endl;
}

void Wind::change()
{
	cout << "Введите новое название: ";
	getline(cin, name);
	cout << "Введите новое название производителя: ";
	getline(cin, nameManufacturer);
	cout << "Введите ФИО нового владельца: ";
	getline(cin, FIOOwner);
	cout << "Введите новые деффекты: ";
	getline(cin, deffects);
	cout << "Введите новое количесво единиц в оркестре: ";
	count = safeInput(1, INT32_MAX);
	cout << "Введите новую цену: ";
	price = safeInput(1.0, (double)INT32_MAX);
}