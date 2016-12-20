#include "NumberConverter.h"

class NumberConverterFunctions
{
private:
	Numberconverter *start; // pointers for start and end of list
	Numberconverter *end;
public:
	NumberConverterFunctions();

	bool isEmpty();
	void addFirstNumber(int number);
	void addLastNumber(int number);
	void removeFirstNumber();
	void removeLastNumber();
	int listLastNumber();
};