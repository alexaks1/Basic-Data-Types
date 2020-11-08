void binary_shift(char& symbol, short n, short index) {
	char one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)
	{
		bool value = (symbol & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (symbol & (one << j)))); ++j)
		{
			bool digit = symbol & (one << j);
			if (digit)
				symbol |= (one << (j - 1));//������ ������� � ��� 
			else
				symbol &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				symbol |= (one << j);//������ ������� � ��� 
			else
				symbol &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(signed char& symbol, short n, short index) {
	signed char one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)//���������� ���������
	{
		bool value = (symbol & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (symbol & (one << j)))); ++j)
		{
			bool digit = symbol & (one << j);
			if (digit)
				symbol |= (one << (j - 1));//������ ������� � ��� 
			else
				symbol &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				symbol |= (one << j);//������ ������� � ��� 
			else
				symbol &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(int& number, short n, short index) {
	int one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)
	{
		bool value = (number & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (number & (one << j)))); ++j)
		{
			bool digit = number & (one << j);
			if (digit)
				number |= (one << (j - 1));//������ ������� � ��� 
			else
				number &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				number |= (one << j);//������ ������� � ��� 
			else
				number &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(unsigned int& number, short n, short index) {
	unsigned int one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)
	{
		bool value = (number & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (number & (one << j)))); ++j)
		{
			bool digit = number & (one << j);
			if (digit)
				number |= (one << (j - 1));//������ ������� � ��� 
			else
				number &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				number |= (one << j);//������ ������� � ��� 
			else
				number &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(short& number, short n, short index) {
	short one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)
	{
		bool value = (number & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (number & (one << j)))); ++j)
		{
			bool digit = number & (one << j);
			if (digit)
				number |= (one << (j - 1));//������ ������� � ��� 
			else
				number &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				number |= (one << j);//������ ������� � ��� 
			else
				number &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(unsigned short& number, short n, short index) {
	unsigned short one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)
	{
		bool value = (number & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (number & (one << j)))); ++j)
		{
			bool digit = number & (one << j);
			if (digit)
				number |= (one << (j - 1));//������ ������� � ��� 
			else
				number &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				number |= (one << j);//������ ������� � ��� 
			else
				number &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(long& number, short n, short index) {
	long one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)
	{
		bool value = (number & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (number & (one << j)))); ++j)
		{
			bool digit = number & (one << j);
			if (digit)
				number |= (one << (j - 1));//������ ������� � ��� 
			else
				number &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				number |= (one << j);//������ ������� � ��� 
			else
				number &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(unsigned long& number, short n, short index) {
	unsigned long one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)
	{
		bool value = (number & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (number & (one << j)))); ++j)
		{
			bool digit = number & (one << j);
			if (digit)
				number |= (one << (j - 1));//������ ������� � ��� 
			else
				number &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				number |= (one << j);//������ ������� � ��� 
			else
				number &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(long long& number, short n, short index) {
	long long one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)
	{
		bool value = (number & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (number & (one << j)))); ++j)
		{
			bool digit = number & (one << j);
			if (digit)
				number |= (one << (j - 1));//������ ������� � ��� 
			else
				number &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				number |= (one << j);//������ ������� � ��� 
			else
				number &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(unsigned long long& number, short n, short index) {
	unsigned long long one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	for (int i = index; i > index - n; --i)
	{
		bool value = (number & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (number & (one << j)))); ++j)
		{
			bool digit = number & (one << j);
			if (digit)
				number |= (one << (j - 1));//������ ������� � ��� 
			else
				number &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				number |= (one << j);//������ ������� � ��� 
			else
				number &= ~(one << j);//������ ���� � ��� 
		}
	}
}
void binary_shift(float& number, short n, short index) {
	int one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	int* pnumber;
	pnumber = (int*)&(number);
	for (int i = index; i > index - n; --i)
	{
		bool value = (*pnumber & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (*pnumber & (one << j)))); ++j)
		{
			bool digit = *pnumber & (one << j);
			if (digit)
				*pnumber |= (one << (j - 1));//������ ������� � ��� 
			else
				*pnumber &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				*pnumber |= (one << j);//������ ������� � ��� 
			else
				*pnumber &= ~(one << j);//������ ���� � ��� 
		}
	}
	float* newptr = (float*)(pnumber);
	number = *newptr;
}
void binary_shift(double& number, short n, short index) {
	long long one = 1;//������� ��� ���� ������, � ������� ��������, ����� �� �������� ���-�� ��� �� ���� � ����
	long long* pnumber;
	pnumber = (long long*)&(number);
	for (int i = index; i > index - n; --i)
	{
		bool value = (*pnumber & (one << i));
		for (int j = i + 1; ((j <= index) && (value < (*pnumber & (one << j)))); ++j)
		{
			bool digit = *pnumber & (one << j);
			if (digit)
				*pnumber |= (one << (j - 1));//������ ������� � ��� 
			else
				*pnumber &= ~(one << (j - 1));//������ ���� � ��� 
			if (value)
				*pnumber |= (one << j);//������ ������� � ��� 
			else
				*pnumber &= ~(one << j);//������ ���� � ��� 
		}
	}
	double* newptr = (double*)(pnumber);
	number = *newptr;
}


