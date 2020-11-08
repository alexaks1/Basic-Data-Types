#pragma once
//Все функции возвращают булевый массив - значение каждого бита
bool* binary_code(char symbol);
bool* binary_code(signed char symbol);
bool* binary_code(short number);
bool* binary_code(unsigned short number);
bool* binary_code(int number);
bool* binary_code(unsigned int number);
bool* binary_code(long number);
bool* binary_code(unsigned long number);
bool* binary_code(long long number);
bool* binary_code(unsigned long long number);
bool* binary_code(float number);
bool* binary_code(double number);

template <typename T>
void print_binary_code(T data)
{
	cout << "Значение: " << data << endl << "В двоичном коде: ";
	bool* Bits = binary_code(data);
	for (int i = sizeof(T) * 8 - 1; i >= 0; --i)
		cout << Bits[i];
}