#include "SymbolConverter.h"

class SymbolConverterFunctions
{
private:
	SymbolConverter *start; // pointers for start and end of list
	SymbolConverter *end;
public:
	SymbolConverterFunctions();
	bool isEmpty();
	void addFirstSymbol(char symbol);
	void addLastSymbol(char symbol);
	void listAllSymbols();
	void removeFirstSymbol();
	void removeLastSymbol();
	char listLastSymbol();
};