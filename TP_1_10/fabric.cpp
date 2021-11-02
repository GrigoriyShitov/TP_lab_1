#include "fabric.h"

Base* createObj(string name)
{
	if (name == "Ударный")
		return new Percussion();
	if (name == "Струнный")
		return new Stringed();
	if (name == "Духовой")
		return new Wind();
	string err = "Тип объекта не распознан";
	throw err;
}