#include "Stringed.h"

Stringed::Stringed() : Base("��������"), name("�� ������"), nameManufacturer("�� ������"), FIOOwner("�� ������"), description("�� ������"),
	count(0), price(0.0)
{
	cout << "������ ����������� Stringed" << endl;
}

Stringed::Stringed(string name, string nameManufacturer, string FIOOwner, string description, int count, double price) :
	Base("��������"), name(name), nameManufacturer(nameManufacturer), FIOOwner(FIOOwner), description(description),
	count(count), price(price)
{
	cout << "������ ����������� Stringed" << endl;
}

Stringed::Stringed(const Stringed& stringed) :
	Base(stringed), name(stringed.name), nameManufacturer(stringed.nameManufacturer), 
	FIOOwner(stringed.FIOOwner), description(stringed.description), count(stringed.count), price(stringed.price)
{
	cout << "������ ����������� ����������� Stringed" << endl;
}

void Stringed::inputFromConsole()
{
	cout << "������� ��������: ";
	getline(cin, name);
	cout << "������� �������� �������������: ";
	getline(cin, nameManufacturer);
	cout << "������� ��� ���������: ";
	getline(cin, FIOOwner);
	cout << "������� ������� ��������: ";
	getline(cin, description);
	cout << "������� ��������� ������ � ��������: ";
	count = safeInput(1, INT32_MAX);
	cout << "������� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Stringed::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "��������: " << name << endl;
	cout << "�������� �������������: " << nameManufacturer << endl;
	cout << "��� ���������: " << FIOOwner << endl;
	cout << "������� ��������: " << description << endl;
	cout << "���������� ������ � ��������: " << count << endl;
	cout << "����: " << price << endl;
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
	cout << "������� ����� ��������: ";
	getline(cin, name);
	cout << "������� ����� �������� �������������: ";
	getline(cin, nameManufacturer);
	cout << "������� ��� ������ ���������: ";
	getline(cin, FIOOwner);
	cout << "������� ����� ������� ��������: ";
	getline(cin, description);
	cout << "������� ����� ��������� ������ � ��������: ";
	count = safeInput(1, INT32_MAX);
	cout << "������� ����� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}