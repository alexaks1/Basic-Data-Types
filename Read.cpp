#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

//«десь функции, которые не допускают некорректного ввода типов данных
int digit_input(char symbol, short base)//ввод и сопоставление введЄнного символа с цифрой в введЄнной системе счислени€(2 - 36)
{
	int digit = 0;
	if ((symbol >= '0') && (symbol <= '9'))
		digit = symbol - '0';
	if ((symbol >= 'A') && (symbol <= 'Z'))
		digit = symbol - 'A' + 10;
	return digit;
}
short read_base()//ввод пользователем системы счислени€
{
	char c;
	short i = 0;
	short base = 0;
	do
	{
		c = _getch();

		if ((i < 2) && (c >= '0') && (c <= '9'))
		{
			cout << c;
			base = base * 10 + c - '0';
			++i;
		}
		if ((c == 8) && (base > 0))
		{
			cout << "\b \b";
			base /= 10;
			--i;
		}


	} while ((c != 13) || (base < 2) || (base > 36));
	cout << endl;
	return base;
}
void read_base_type(char& symbol)
{
	cout << "¬ведите символ: ";
	symbol = _getch();
	cout << symbol << endl;
}
void read_base_type(signed char& symbol)
{
	cout << "¬ведите символ: ";
	symbol = _getch();
	cout << symbol << endl;
}
void read_base_type(short& number)
{
	number = 0;
	short i = 0;
	char symbol;
	bool sign = 0;//1 - минус, 0 - плюс
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		symbol = _getch();
		if ((i == 0) && ((symbol == '-') || (symbol == '+')))
		{
			if (symbol == '-')
				sign = 1;
			cout << symbol;
			++i;
		}
		if (((base <= 10) && (symbol >= '0') && (symbol <= '0' + base - 1)) || ((base > 10) && ((symbol >= '0') && (symbol <= '9') || (symbol >= 'A') && (symbol <= 'A' + base - 11))))
		{
			if (i == 0)
			{
				sign = 0;
				cout << '+';
				++i;
			}
			cout << symbol;
			if (sign == 0)
				number = number * base + digit_input(symbol, base);
			else
				number = number * base - digit_input(symbol, base);
			++i;
		}
		if ((symbol == 8) && (i > 0))
		{
			cout << "\b \b";
			--i;
			number /= base;
			if (i == 0)
				sign = 0;
		}
	} while (symbol != 13);
	cout << endl;
}
void read_base_type(unsigned short& number)
{
	number = 0;
	char c;
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		c = _getch();
		if (((base <= 10) && (c >= '0') && (c <= '0' + base - 1)) || ((base > 10) && ((c >= '0') && (c <= '9') || (c >= 'A') && (c <= 'A' + base - 11))))
		{
			cout << c;
			number = number * base + digit_input(c, base);
		}
		if ((c == 8) && (number > 0))
		{
			cout << "\b \b";
			number /= base;
		}
	} while (c != 13);
	cout << endl;
}
void read_base_type(int& number)//читаем тип int, учитыва€ особенности типа
{
	number = 0;
	short i = 0;
	char symbol;
	bool sign = 0;//1 - минус, 0 - плюс
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		symbol = _getch();
		if ((i == 0) && ((symbol == '-') || (symbol == '+')))
		{
			if (symbol == '-')
				sign = 1;
			cout << symbol;
			++i;
		}
		if (((base <= 10) && (symbol >= '0') && (symbol <= '0' + base - 1)) || ((base > 10) && ((symbol >= '0') && (symbol <= '9') || (symbol >= 'A') && (symbol <= 'A' + base - 11))))
		{
			if (i == 0)
			{
				sign = 0;
				cout << '+';
				++i;
			}
			cout << symbol;
			if (sign == 0)
				number = number * base + digit_input(symbol, base);
			else
				number = number * base - digit_input(symbol, base);
			++i;
		}
		if ((symbol == 8) && (i > 0))
		{
			cout << "\b \b";
			--i;
			number /= base;
			if (i == 0)
				sign = 0;
		}
	} while (symbol != 13);
	cout << endl;
}
void read_base_type(unsigned int& number)
{
	number = 0;
	char c;
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		c = _getch();
		if (((base <= 10) && (c >= '0') && (c <= '0' + base - 1)) || ((base > 10) && ((c >= '0') && (c <= '9') || (c >= 'A') && (c <= 'A' + base - 11))))
		{
			cout << c;
			number = number * base + digit_input(c, base);
		}
		if ((c == 8) && (number > 0))
		{
			cout << "\b \b";
			number /= base;
		}
	} while (c != 13);
	cout << endl;
}
void read_base_type(long& number)//читаем тип int, учитыва€ особенности типа
{
	number = 0;
	short i = 0;
	char symbol;
	bool sign = 0;//1 - минус, 0 - плюс
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		symbol = _getch();
		if ((i == 0) && ((symbol == '-') || (symbol == '+')))
		{
			if (symbol == '-')
				sign = 1;
			cout << symbol;
			++i;
		}
		if (((base <= 10) && (symbol >= '0') && (symbol <= '0' + base - 1)) || ((base > 10) && ((symbol >= '0') && (symbol <= '9') || (symbol >= 'A') && (symbol <= 'A' + base - 11))))
		{
			if (i == 0)
			{
				sign = 0;
				cout << '+';
				++i;
			}
			cout << symbol;
			if (sign == 0)
				number = number * base + digit_input(symbol, base);
			else
				number = number * base - digit_input(symbol, base);
			++i;
		}
		if ((symbol == 8) && (i > 0))
		{
			cout << "\b \b";
			--i;
			number /= base;
			if (i == 0)
				sign = 0;
		}
	} while (symbol != 13);
	cout << endl;
}
void read_base_type(unsigned long& number)
{
	number = 0;
	char c;
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		c = _getch();
		if (((base <= 10) && (c >= '0') && (c <= '0' + base - 1)) || ((base > 10) && ((c >= '0') && (c <= '9') || (c >= 'A') && (c <= 'A' + base - 11))))
		{
			cout << c;
			number = number * base + digit_input(c, base);
		}
		if ((c == 8) && (number > 0))
		{
			cout << "\b \b";
			number /= base;
		}
	} while (c != 13);
	cout << endl;
}
void read_base_type(long long& number)//читаем тип int, учитыва€ особенности типа
{
	number = 0;
	short i = 0;
	char symbol;
	bool sign = 0;//1 - минус, 0 - плюс
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		symbol = _getch();
		if ((i == 0) && ((symbol == '-') || (symbol == '+')))
		{
			if (symbol == '-')
				sign = 1;
			cout << symbol;
			++i;
		}
		if (((base <= 10) && (symbol >= '0') && (symbol <= '0' + base - 1)) || ((base > 10) && ((symbol >= '0') && (symbol <= '9') || (symbol >= 'A') && (symbol <= 'A' + base - 11))))
		{
			if (i == 0)
			{
				sign = 0;
				cout << '+';
				++i;
			}
			cout << symbol;
			if (sign == 0)
				number = number * base + digit_input(symbol, base);
			else
				number = number * base - digit_input(symbol, base);
			++i;
		}
		if ((symbol == 8) && (i > 0))
		{
			cout << "\b \b";
			--i;
			number /= base;
			if (i == 0)
				sign = 0;
		}
	} while (symbol != 13);
	cout << endl;
}
void read_base_type(unsigned long long& number)
{
	number = 0;
	char c;
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		c = _getch();
		if (((base <= 10) && (c >= '0') && (c <= '0' + base - 1)) || ((base > 10) && ((c >= '0') && (c <= '9') || (c >= 'A') && (c <= 'A' + base - 11))))
		{
			cout << c;
			number = number * base + digit_input(c, base);
		}
		if ((c == 8) && (number > 0))
		{
			cout << "\b \b";
			number /= base;
		}
	} while (c != 13);
	cout << endl;
}
void read_base_type(float& number)
{
	string input;
	number = 0;
	float floatpart = 0;
	short i = 0;
	char symbol;
	bool sign = 0;//1 - минус, 0 - плюс
	bool whichpart = 0;//0 - цела€ часть, 1 - вещественна€
	short dotpos = 0;// переменна€ дл€ хранени€ положени€ точки
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		symbol = _getch();
		if ((i == 0) && ((symbol == '-') || (symbol == '+')))
		{
			if (symbol == '-')
				sign = 1;
			cout << symbol;
			++i;
			input += symbol;
		}
		if (((base <= 10) && (symbol >= '0') && (symbol <= '0' + base - 1)) || ((base > 10) && ((symbol >= '0') && (symbol <= '9') || (symbol >= 'A') && (symbol <= 'A' + base - 11))))
		{
			if (i == 0)
			{
				sign = 0;
				cout << '+';
				++i;
				input += '+';
			}
			cout << symbol;
			input += symbol;
			++i;
		}
		if ((i > 1) && (symbol == '.') && (!whichpart))
		{
			cout << symbol;
			++i;
			dotpos = i;
			whichpart = 1;
			input += symbol;
		}
		if ((symbol == 8) && (i > 0))
		{
			cout << "\b \b";
			if (i == dotpos)
			{
				whichpart = 0;
				dotpos = 0;
			}
			input.pop_back();
			--i;
			if (i == 0)
				sign = 0;
		}
	} while (symbol != 13);
	cout << endl;
	//cout << input << endl;
	whichpart = 0;
	for (int i = 1; i < input.length(); ++i)
	{
		if (input[i] == '.')
			whichpart = 1;
		if (!whichpart)
		{
			number = number * base + digit_input(input[i], base);
		}
		else
		{
			floatpart = floatpart * base + digit_input(input[i], base);
		}
	}
	while (floatpart >= 1)
	{
		floatpart /= base;
	}
	number += floatpart;
	if (sign != 0)
		number *= -1;
}
void read_base_type(double& number)
{
	string input;
	number = 0;
	double floatpart = 0;
	short i = 0;
	char symbol;
	bool sign = 0;//1 - минус, 0 - плюс
	bool whichpart = 0;//0 - цела€ часть, 1 - вещественна€
	short dotpos = 0;// переменна€ дл€ хранени€ положени€ точки
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		symbol = _getch();
		if ((i == 0) && ((symbol == '-') || (symbol == '+')))
		{
			if (symbol == '-')
				sign = 1;
			cout << symbol;
			++i;
			input += symbol;
		}
		if (((base <= 10) && (symbol >= '0') && (symbol <= '0' + base - 1)) || ((base > 10) && ((symbol >= '0') && (symbol <= '9') || (symbol >= 'A') && (symbol <= 'A' + base - 11))))
		{
			if (i == 0)
			{
				sign = 0;
				cout << '+';
				++i;
				input += '+';
			}
			cout << symbol;
			input += symbol;
			++i;
		}
		if ((i > 1) && (symbol == '.') && (!whichpart))
		{
			cout << symbol;
			++i;
			dotpos = i;
			whichpart = 1;
			input += symbol;
		}
		if ((symbol == 8) && (i > 0))
		{
			cout << "\b \b";
			if (i == dotpos)
			{
				whichpart = 0;
				dotpos = 0;
			}
			input.pop_back();
			--i;
			if (i == 0)
				sign = 0;
		}
	} while (symbol != 13);
	cout << endl;
	//cout << input << endl;
	whichpart = 0;
	for (int i = 1; i < input.length(); ++i)
	{
		if (input[i] == '.')
			whichpart = 1;
		if (!whichpart)
		{
			number = number * base + digit_input(input[i], base);
		}
		else
		{
			floatpart = floatpart * base + digit_input(input[i], base);
		}
	}
	while (floatpart >= 1)
	{
		floatpart /= base;
	}
	number += floatpart;
	if (sign != 0)
		number *= -1;
}
void read_base_type(long double& number)
{
	string input;
	number = 0;
	long double floatpart = 0;
	short i = 0;
	char symbol;
	bool sign = 0;//1 - минус, 0 - плюс
	bool whichpart = 0;//0 - цела€ часть, 1 - вещественна€
	short dotpos = 0;// переменна€ дл€ хранени€ положени€ точки
	cout << "¬ведите основание системы счислени€: ";
	short base = read_base();
	cout << "¬ведите число: ";
	do
	{
		symbol = _getch();
		if ((i == 0) && ((symbol == '-') || (symbol == '+')))
		{
			if (symbol == '-')
				sign = 1;
			cout << symbol;
			++i;
			input += symbol;
		}
		if (((base <= 10) && (symbol >= '0') && (symbol <= '0' + base - 1)) || ((base > 10) && ((symbol >= '0') && (symbol <= '9') || (symbol >= 'A') && (symbol <= 'A' + base - 11))))
		{
			if (i == 0)
			{
				sign = 0;
				cout << '+';
				++i;
				input += '+';
			}
			cout << symbol;
			input += symbol;
			++i;
		}
		if ((i > 1) && (symbol == '.') && (!whichpart))
		{
			cout << symbol;
			++i;
			dotpos = i;
			whichpart = 1;
			input += symbol;
		}
		if ((symbol == 8) && (i > 0))
		{
			cout << "\b \b";
			if (i == dotpos)
			{
				whichpart = 0;
				dotpos = 0;
			}
			input.pop_back();
			--i;
			if (i == 0)
				sign = 0;
		}
	} while (symbol != 13);
	cout << endl;
	//cout << input << endl;
	whichpart = 0;
	for (int i = 1; i < input.length(); ++i)
	{
		if (input[i] == '.')
			whichpart = 1;
		if (!whichpart)
		{
			number = number * base + digit_input(input[i], base);
		}
		else
		{
			floatpart = floatpart * base + digit_input(input[i], base);
		}
	}
	while (floatpart >= 1)
	{
		floatpart /= base;
	}
	number += floatpart;
	if (sign != 0)
		number *= -1;
}
