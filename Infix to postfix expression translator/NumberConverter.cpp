#include "NumberConverter.h"
#include <iostream>
#include <string>

using namespace std;

Numberconverter::Numberconverter()
{
	numberName - NULL;
	nextNumber = NULL;
}

Numberconverter::Numberconverter(int number2)
{
	numberName = new int(number2);
	nextNumber = NULL;
}

void Numberconverter::setNextNumber(Numberconverter *next2)
{
	nextNumber = next2;
}

Numberconverter* Numberconverter::getNextNumber()
{
	return nextNumber;
}

int* Numberconverter::getNumber()
{
	return numberName;
}

