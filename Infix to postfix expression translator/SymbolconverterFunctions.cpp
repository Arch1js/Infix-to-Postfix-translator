#include "SymbolConverterFunctions.h"
#include <iostream>
#include <string>

using namespace std;

SymbolConverterFunctions::SymbolConverterFunctions()
{
	start = NULL;
	end = NULL;
}

bool SymbolConverterFunctions::isEmpty()
{
	return start == NULL;
}

void SymbolConverterFunctions::addFirstSymbol(char symbol)
{
	cout << "Adding " << symbol << " at start of list" << endl;
	SymbolConverter *current;
	current = new SymbolConverter(symbol);
	start = current;
	end = current;
}

void SymbolConverterFunctions::addLastSymbol(char symbol)
{
	cout << "Adding " << symbol << " to end of list " << endl;
	SymbolConverter *current;
	if (end == NULL)
	{
		addFirstSymbol(symbol);
	}
	else
	{
		current = new SymbolConverter(symbol);
		end->setNextSymbol(current);
		end = current;
	}
}

void SymbolConverterFunctions::listAllSymbols()
{
	SymbolConverter *current;
	if (!isEmpty())
	{
		current = start;
		while (current != NULL)
		{
			cout << "The next is: " << *current->getSymbol() << endl;			
			current = current->getNextSymbol();
		}		
	}
	else
	{
		cout << "Link list is empty!" << endl;
	}
}
void SymbolConverterFunctions::removeFirstSymbol()
{
	SymbolConverter* removeSymbol;
	removeSymbol = start;

	start = start->getNextSymbol();
	delete removeSymbol;
}

void SymbolConverterFunctions::removeLastSymbol()
{
	SymbolConverter* removeSymbol;
	removeSymbol = end;

	if (start == end)
	{
		start = NULL;
		end = NULL;
	}
	else
	{
		SymbolConverter* secondToLast = start;
		while (secondToLast->getNextSymbol() != end)
		{
			secondToLast = secondToLast->getNextSymbol();
		}
		end = secondToLast;
		end->setNextSymbol(NULL);
	}
}

char SymbolConverterFunctions::listLastSymbol()
{
	SymbolConverter* current;
	current = end;
	return *current->getSymbol();
	current = current->getNextSymbol();
}
