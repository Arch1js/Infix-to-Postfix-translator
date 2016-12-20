#include "SymbolConverterFunctions.h"
#include "NumberConverterFunctions.h"
#include <iostream>
#include <string>

using namespace std;

SymbolConverterFunctions SymbolfunctionClass;
NumberConverterFunctions NumberfunctionClass;


char decision;
bool keepConverting = true;
int result;
bool hasLetters = false;
string postfix = "";
string symbolAdded;
char expAdded[100]; //array for storing expression

//compare if it's an operator
bool isOperator(char character)
{
	if (character == '*' || character == '/' || character == '^' || character == '+' || character == '-')
	{
		return true;
	}
	else
	{
		return false;
	}
}
//compare if it's an operand
bool isOperand(char character)
{
	if (character >= '0' && character <= '9')
	{
		return true;
	}
	if (character >= 'a' && character <= 'z')
	{
		hasLetters = true;
		return true;
	}
	if (character >= 'A' && character <= 'Z')
	{
		hasLetters = true;
		return true;
	}
	else
	{
		return false;
	}
	
}

//Compare which operator is more important
int precendece(char operator1, char operator2)
{
	if ((operator1 == '+' || operator1 == '-') && (operator2 == '*' || operator2 == '/' || operator2 == '^'))
	{
		return 2;
	}
	else if ((operator1 == '*' || operator1 == '/' || operator1 == '^') && (operator2 == '+' || operator2 == '-'))
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int doCalculations(int operand1, int operand2, char operator1)
{
	switch (operator1)
	{
	case '+':
		NumberfunctionClass.addLastNumber(operand1 + operand2);
		result = NumberfunctionClass.listLastNumber();
		break;
	case '-':
		NumberfunctionClass.addLastNumber(operand2 - operand1);
		result = NumberfunctionClass.listLastNumber();
		break;
	case '*':
		NumberfunctionClass.addLastNumber(operand1 * operand2);
		result = NumberfunctionClass.listLastNumber();
		break;
	case '/':
		NumberfunctionClass.addLastNumber(operand2 / operand1);
		result = NumberfunctionClass.listLastNumber();
		break;
	case '^':
		NumberfunctionClass.addLastNumber(pow(operand2, operand1));
		result = NumberfunctionClass.listLastNumber();
		break;
	}
	return result;
}
void main()
{
	do
	{
		cout << "Enter infix expression: ";
		cin >> expAdded;
		cout << endl;

		for (int i = 0; i < strlen(expAdded); i++)
		{
			char currentSymbol(expAdded[i]);

			if (isOperand(expAdded[i]))
			{
				if (!NumberfunctionClass.isEmpty())
				{
					postfix += expAdded[i];
					char a = expAdded[i];
					NumberfunctionClass.addLastNumber(a - '0');
				}
				else
				{
					postfix += expAdded[i];
					char a = expAdded[i];
					NumberfunctionClass.addFirstNumber(a - '0');
				}
			}
			if (isOperator(expAdded[i]))
			{
				while (!SymbolfunctionClass.isEmpty() && SymbolfunctionClass.listLastSymbol() != '(' && precendece(SymbolfunctionClass.listLastSymbol(), expAdded[i]) <= 1)
				{
					postfix += SymbolfunctionClass.listLastSymbol();

					int temp = NumberfunctionClass.listLastNumber();
					NumberfunctionClass.removeLastNumber();
					int temp2 = NumberfunctionClass.listLastNumber();
					NumberfunctionClass.removeLastNumber();

					doCalculations(temp, temp2, SymbolfunctionClass.listLastSymbol());

					SymbolfunctionClass.removeLastSymbol();
					SymbolfunctionClass.listAllSymbols();

				}
				SymbolfunctionClass.addLastSymbol(currentSymbol);


				SymbolfunctionClass.listAllSymbols();
			}
			if (expAdded[i] == '(')
			{
				SymbolfunctionClass.addLastSymbol(currentSymbol);
			}
			if (expAdded[i] == ')')
			{

				while (!SymbolfunctionClass.isEmpty())
				{
					if (SymbolfunctionClass.listLastSymbol() == '(')
					{
						SymbolfunctionClass.removeLastSymbol();
						break;
					}
					else
					{
						postfix += SymbolfunctionClass.listLastSymbol();
						int temp3 = NumberfunctionClass.listLastNumber();
						NumberfunctionClass.removeLastNumber();
						int temp4 = NumberfunctionClass.listLastNumber();
						NumberfunctionClass.removeLastNumber();

						doCalculations(temp3, temp4, SymbolfunctionClass.listLastSymbol());
						SymbolfunctionClass.removeLastSymbol();
					}
				}

			}
		}
		while (!SymbolfunctionClass.isEmpty())
		{
			postfix += SymbolfunctionClass.listLastSymbol();
			int temp5 = NumberfunctionClass.listLastNumber();
			NumberfunctionClass.removeLastNumber();
			int temp6 = NumberfunctionClass.listLastNumber();
			NumberfunctionClass.removeLastNumber();

			doCalculations(temp5, temp6, SymbolfunctionClass.listLastSymbol());
			SymbolfunctionClass.removeLastSymbol();
		}

		cout << endl;
		cout << "Infix expression: " << expAdded << endl;
		cout << "Postfix expression: " << postfix << endl;

		if (hasLetters == true)
		{
			cout << "This expression doesn't have a result! " << endl;
		}
		else
		{
			cout << "Result is: " << result << endl;
		}

		cout << "Try another expression? Y/N?" << endl;
		cin >> decision;

		if (decision == 'Y' || decision == 'y')
		{
			postfix = "";
			char expAdded[100] = { 0 };
			keepConverting = true;
			hasLetters = false;
			system("cls");
		}
		else
		{
			keepConverting = false;
		}

	} while (keepConverting != false);				

		system("pause");
}

	