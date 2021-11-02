#include "Wind.h"

Wind::Wind() : Base("�������"), name("�� ������"), nameManufacturer("�� ������"), FIOOwner("�� ������"), deffects("�� ������"),
	count(0), price(0.0)
{
	cout << "������ ����������� Wind" << endl;
}

Wind::Wind(string name, string author, string annotation, string educationaInstitution,
	int yearReliase, int yearLearning, int volueme, double price) :
	Base("�������"), name(name), nameManufacturer(nameManufacturer),
	FIOOwner(FIOOwner), deffects(deffects), count(count), price(price)
{
	cout << "������ ����������� Wind" << endl;
}

Wind::Wind(const Wind& wind) :
	Base(wind), name(wind.name), nameManufacturer(wind.nameManufacturer),
	FIOOwner(wind.FIOOwner), deffects(wind.deffects), count(wind.count), price(wind.price)
{
	cout << "������ ����������� ����������� Wind" << endl;
}

void Wind::inputFromConsole()
{
	cout << "������� ��������: ";
	getline(cin, name);
	cout << "������� �������� �������������: ";
	getline(cin, nameManufacturer);
	cout << "������� ��� ���������: ";
	getline(cin, FIOOwner);
	cout << "������� ��������: ";
	getline(cin, deffects);
	cout << "������� ��������� ������ � ��������: ";
	count = safeInput(1, INT32_MAX);
	cout << "������� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}

void Wind::inputFromFile(std::ifstream& file, std::string& tmpS)
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
	cout << "��������: " << name << endl;
	cout << "�������� �������������: " << nameManufacturer << endl;
	cout << "��� ���������: " << FIOOwner << endl;
	cout << "��������: " << deffects << endl;
	cout << "���������� ������ � ��������: " << count << endl;
	cout << "����: " << price << endl;
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
	cout << "������� ����� ��������: ";
	getline(cin, name);
	cout << "������� ����� �������� �������������: ";
	getline(cin, nameManufacturer);
	cout << "������� ��� ������ ���������: ";
	getline(cin, FIOOwner);
	cout << "������� ����� ��������: ";
	getline(cin, deffects);
	cout << "������� ����� ��������� ������ � ��������: ";
	count = safeInput(1, INT32_MAX);
	cout << "������� ����� ����: ";
	price = safeInput(1.0, (double)INT32_MAX);
}