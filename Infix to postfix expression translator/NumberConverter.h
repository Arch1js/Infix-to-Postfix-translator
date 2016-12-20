#include <string>

using namespace std;

class Numberconverter
{
private:
	int *numberName;
	Numberconverter *nextNumber;

public:
	Numberconverter();
	Numberconverter(int number);
	void setNextNumber(Numberconverter *next);
	Numberconverter *getNextNumber();
	int *getNumber();
};