#include "Percussion.h"

Percussion::Percussion() : Base("�������"), type("�� ������"), name("�� ������"), FIOOwner("�� ������"), count(0), price(0.0)
{
	cout << "������ ����������� Percussion" << endl;
}

Percussion::Percussion(string type, string name, string FIOOwner, int count, double price) :
	Base("�������"), type(type), name(name), FIOOwner(FIOOwner), count(count), price(price)
{
	cout << "������ ����������� Percussion" << endl;
}

Percussion::Percussion(const Percussion& percussion) :
	Base(percussion), type(percussion.type), name(percussion.name), FIOOwner(percussion.FIOOwner), 
	count(percussion.count), price(percussion.price)
{
	cout << "������ ����������� ����������� Percussion" << endl;
}

void Percussion::inputFromConsole()
{
	cout << "������� ���: ";
	getline(cin, type);
	cout << "������� ��������: ";
	getline(cin, name);
	cout << "������� ��� ���������: ";
	getline(cin, FIOOwner);
	cout << "������� ��������� ������ � ��������: ";
	count = safeInput(1, INT32_MAX);
	cout << "������� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Percussion::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
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
	cout << "���: " << type << endl;
	cout << "��������: " << name << endl;
	cout << "��� ���������: " << FIOOwner << endl;
	cout << "���������� ������ � ��������: " << count << endl;
	cout << "����: " << price << endl;
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
	cout << "������� ����� ���: ";
	getline(cin, type);
	cout << "������� ����� ��������: ";
	getline(cin, name);
	cout << "������� ��� ������ ���������: ";
	getline(cin, FIOOwner);
	cout << "������� ����� ��������� ������ � ��������: ";
	count = safeInput(1, INT32_MAX);
	cout << "������� ����� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}