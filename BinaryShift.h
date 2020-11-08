#pragma once
void binary_shift(char& symbol, short n, short index);
void binary_shift(signed char& symbol, short n, short index);
void binary_shift(int& number, short n, short index);
void binary_shift(unsigned int& number, short n, short index);
void binary_shift(short& number, short n, short index);
void binary_shift(unsigned short& number, short n, short index);
void binary_shift(long& number, short n, short index);
void binary_shift(unsigned long& number, short n, short index);
void binary_shift(long long& number, short n, short index);
void binary_shift(unsigned long long& number, short n, short index);
void binary_shift(float& number, short n, short index);
void binary_shift(double& number, short n, short index);
template <typename T>
void binary_shift_process(T& data)
{
	short n;//кол-во бит
	short index;//номер старшего разр€да
	cout << "¬ыполнить в пределах группы бит путЄм сдвига вправо все биты, значение которых равно единице и влево все биты, значение которых равно нулю."
		<< endl << endl; 
	TextForeground(11);
	cout << "ƒо сдвига:\n";
	TextForeground(15);
	print_binary_code(data);
	cout << endl;
	do
	{
		cout << endl << "¬ведите количество бит, которые надо сдвинуть: ";
		do
		{
			cin >> n;
		} while (n > sizeof(data) * 8);
		cout << "¬ведите номер старшего разр€да(не больше числа бит + 1): ";
		do
		{
			cin >> index;
		} while (index > n + 1);
	} while (index - n < -1);
	binary_shift(data, n, index);
	cout << endl;
	TextForeground(11);
	cout << "ѕосле сдвига:\n";
	TextForeground(15);
	print_binary_code(data);
}
