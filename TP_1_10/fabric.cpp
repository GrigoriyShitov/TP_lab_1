#include "fabric.h"

Base* createObj(string name)
{
	if (name == "�������")
		return new Percussion();
	if (name == "��������")
		return new Stringed();
	if (name == "�������")
		return new Wind();
	string err = "��� ������� �� ���������";
	throw err;
}