#include <string>

using namespace std;

class SymbolConverter
{
private:
	char *symbolName;
	SymbolConverter *nextSymbol;

public:
	SymbolConverter();
	SymbolConverter(char symbol);
	void setNextSymbol(SymbolConverter *next);
	SymbolConverter *getNextSymbol();
	char *getSymbol();
};