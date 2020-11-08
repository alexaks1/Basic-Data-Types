#include <iostream>
using namespace std;

bool* binary_code(char symbol)
{
	bool Bits[sizeof(char) * 8];
	bool digit;
	short one = 1;
	for (int i = sizeof(char) * 8 - 1; i >= 0; --i)
	{
		digit = (symbol & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(signed char symbol)
{
	bool Bits[sizeof(signed char) * 8];
	bool digit;
	short one = 1;
	for (int i = sizeof(signed char) * 8 - 1; i >= 0; --i)
	{
		digit = (symbol & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(short number)
{
	bool Bits[sizeof(short) * 8];
	bool digit;
	short one = 1;
	for (int i = sizeof(short) * 8 - 1; i >= 0; --i)
	{
		digit = (number & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(unsigned short number)
{
	bool Bits[sizeof(unsigned short) * 8];
	bool digit;
	unsigned short one = 1;
	for (int i = sizeof(unsigned short) * 8 - 1; i >= 0; --i)
	{
		digit = (number & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(int number)
{
	bool Bits[sizeof(int) * 8];
	bool digit;
	int one = 1;
	for (int i = sizeof(int) * 8 - 1; i >= 0; --i)
	{
		digit = (number & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(unsigned int number)
{
	bool Bits[sizeof(unsigned int) * 8];
	bool digit;
	unsigned int one = 1;
	for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; --i)
	{
		digit = (number & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(long number)
{
	bool Bits[sizeof(long) * 8];
	bool digit;
	long one = 1;
	for (int i = sizeof(long) * 8 - 1; i >= 0; --i)
	{
		digit = (number & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(unsigned long number)
{
	bool Bits[sizeof(unsigned long) * 8];
	bool digit;
	unsigned long one = 1;
	for (int i = sizeof(unsigned long) * 8 - 1; i >= 0; --i)
	{
		digit = (number & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(long long number)
{
	bool Bits[sizeof(long long) * 8];
	bool digit;
	long long one = 1;
	for (int i = sizeof(long long) * 8 - 1; i >= 0; --i)
	{
		digit = (number & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(unsigned long long number)
{
	bool Bits[sizeof(unsigned long long) * 8];
	bool digit;
	unsigned long long one = 1;
	for (int i = sizeof(unsigned long long) * 8 - 1; i >= 0; --i)
	{
		digit = (number & (one << i));
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(float number)
{
	bool Bits[sizeof(float) * 8];
	int* ptr;
	int one = 1;//тк sizeof(float) == sizeof(int)
	ptr = (int*)&number;
	for (int i = sizeof(float) * 8 - 1; i >= 0; i--)
	{
		bool digit = *ptr & (one << i);
		Bits[i] = digit;
	}
	return Bits;
}
bool* binary_code(double number)
{
	bool Bits[sizeof(double) * 8];
	long long* ptr;
	long long one = 1;//тк sizeof(double) == sizeof(long long)
	ptr = (long long*)&number;
	for (int i = sizeof(double) * 8 - 1; i >= 0; i--)
	{
		bool digit = *ptr & (one << i);
		Bits[i] = digit;
	}
	return Bits;
}

/*
void binary_code(long double number)
{
	unsigned char* c;
	cout << "В десятичном представлении: " << number << endl << "В двоичном: ";

	c = (unsigned char*)&number;

	for (int i = sizeof(long double) - 1; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			cout << bool(*(c + i) & (unsigned char(1) << j));
		}
	}
}
*/



