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
	short n;//���-�� ���
	short index;//����� �������� �������
	cout << "��������� � �������� ������ ��� ���� ������ ������ ��� ����, �������� ������� ����� ������� � ����� ��� ����, �������� ������� ����� ����."
		<< endl << endl; 
	TextForeground(11);
	cout << "�� ������:\n";
	TextForeground(15);
	print_binary_code(data);
	cout << endl;
	do
	{
		cout << endl << "������� ���������� ���, ������� ���� ��������: ";
		do
		{
			cin >> n;
		} while (n > sizeof(data) * 8);
		cout << "������� ����� �������� �������(�� ������ ����� ��� + 1): ";
		do
		{
			cin >> index;
		} while (index > n + 1);
	} while (index - n < -1);
	binary_shift(data, n, index);
	cout << endl;
	TextForeground(11);
	cout << "����� ������:\n";
	TextForeground(15);
	print_binary_code(data);
}
