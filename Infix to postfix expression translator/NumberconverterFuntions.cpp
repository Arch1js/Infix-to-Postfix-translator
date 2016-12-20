#include "NumberConverterFunctions.h"
#include <iostream>
#include <string>

using namespace std;

NumberConverterFunctions::NumberConverterFunctions()
{
	start = NULL;
	end = NULL;
}

bool NumberConverterFunctions::isEmpty()
{
	return start == NULL;
}

void NumberConverterFunctions::addFirstNumber(int number)
{
	cout << "Adding " << number << " at start of list" << endl;
	Numberconverter *current;
	current = new Numberconverter(number);
	start = current;
	end = current;
}

void NumberConverterFunctions::addLastNumber(int number)
{
	Numberconverter *current;
	if (end == NULL)
	{
		addFirstNumber(number);
	}
	else
	{
		current = new Numberconverter(number);
		end->setNextNumber(current);
		end = current;
	}
}

void NumberConverterFunctions::removeFirstNumber()
{
	Numberconverter* removeNumber;
	removeNumber = start;

	start = start->getNextNumber();
	delete removeNumber;
}

void NumberConverterFunctions::removeLastNumber()
{
	Numberconverter* removeNumber;
	removeNumber = end;

	if (start == end)
	{
		start = NULL;
		end = NULL;
	}
	else
	{
		Numberconverter* secondToLast = start;
		while (secondToLast->getNextNumber() != end)
		{
			secondToLast = secondToLast->getNextNumber();
		}
		end = secondToLast;
		end->setNextNumber(NULL);
	}
}

int NumberConverterFunctions::listLastNumber()
{
	Numberconverter* current;
	current = end;
	return *current->getNumber();
	current = current->getNextNumber();
}