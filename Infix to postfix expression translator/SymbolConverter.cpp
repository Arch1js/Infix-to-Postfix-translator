#include "SymbolConverter.h"
#include <iostream>
#include <string>

using namespace std;

SymbolConverter::SymbolConverter()
{
	symbolName = NULL;
	nextSymbol = NULL;
}

SymbolConverter::SymbolConverter(char symbol)
{
	symbolName = new char(symbol);
	nextSymbol = NULL;
}

void SymbolConverter::setNextSymbol(SymbolConverter *next)
{
	nextSymbol = next;
}

SymbolConverter* SymbolConverter::getNextSymbol()
{
	return nextSymbol;
}

char* SymbolConverter::getSymbol()
{
	return symbolName;
}


