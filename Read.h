#pragma once

int digit_input(char symbol, short base);//������������� ��������� ������� � ������ � �������� ������� ���������
short read_base();
//���� ����� ������, �������� �� ���������
void read_base_type(char& symbol);
void read_base_type(signed char& symbol);
void read_base_type(short& number);
void read_base_type(unsigned short& number);
void read_base_type(int& number);
void read_base_type(unsigned int& number);
void read_base_type(long& number);
void read_base_type(unsigned long& number);
void read_base_type(long long& number);
void read_base_type(unsigned long long& number);
void read_base_type(float& number);
void read_base_type(double& number);
void read_base_type(long double& number);