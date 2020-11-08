#include <iostream>
using namespace std;
#include <conio.h>
#include "MyCrt.h"
#include "Menu.h"
#include "Read.h"
#include "Binary.h"
#include "BinaryShift.h"
#include "climits"

//Работа подменю(выбор действий над типом)
template <typename T>
void SubMenuProccess(T& data, Menu& MainMenu, Menu& SubMenu, const short rows2, char Data[15][20])
{
	do
	{
		cout << "Вы выбрали тип данных ";
		TextForeground(11);//синий
		cout << Data[MainMenu.Item] << endl;//Вывод выбранного пункта главного меню синим цветом
		TextForeground(15);//белый
		//Далее работа подменю
		cout << "Выберите необходимый пункт:" << endl;
		Show_Menu(SubMenu);
		ItemChoice(SubMenu);
		ClrScr();
		GoToXY(0, 0);
		if (SubMenu.Item == 0)//Ввод
			read_base_type(data);
		if (SubMenu.Item == 1)//Двоичное представление
			print_binary_code(data);
		if (SubMenu.Item == 2)//Cдвиг по заданию
			binary_shift_process(data);
		if (SubMenu.Item != rows2 - 1)//Паузим выполнение для всех пунктов, кроме последнего
		{
			cout << endl;
			system("pause");
		}
		ClrScr();
	} while (SubMenu.Item != rows2 - 1);//Выбран пункт "В главное меню"
}

//В функции main описана работа главного меню(выбор необходимого типа)
int main()
{
    setlocale(LC_ALL, "Russian");

    Menu MainMenu;//главное меню
	Menu SubMenu;//подменю
	//Пункты главного меню:
    const short rows = 15, cols = 20;
    char Data[rows][cols] = {
        "char", 
        "signed char", 
        "short", 
        "unsigned short", 
        "int", 
        "unsigned int", 
        "long",
        "unsigned long",
        "long long",
        "unsigned long long",
        "float",
        "double",
        "long double",
		"Справка",
        "Выйти"
	};
    //Пункты подменю:
	const short rows2 = 4, cols2 = 30;
	char Data2[rows2][cols2] = {
		"Ввод",
		"Двоичное представление",
		"Задание на сдвиг",
		"В главное меню"
	};
	//Инициализация всех меню:
	InitMenu(MainMenu, 0, 2, 0, 0, 15, 11, rows, cols, *Data);
	InitMenu(SubMenu, 0, 2, 0, 0, 15, 11, rows2, cols2, *Data2);
	
	char ErrorMsg[] = "Программа не поддерживает выбранный тип для вашей системы. Подробности в справке.";
	//Работа главного меню:
	do
	{
		cout << "Внутреннее представление различных типов данных." << endl 
			 << "Выберите необходимый пункт:" << endl;
		Show_Menu(MainMenu);//Вывод главного меню
		ItemChoice(MainMenu);//Выбор нового пункта главного меню
		ClrScr();
		GoToXY(0, 0);
		//Далее условия, связанные с выбранным пунктом главного меню
		if (MainMenu.Item == 0)//char
		{
			char symbol = 0;
			if (sizeof(char) == 1)
				SubMenuProccess(symbol, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 1)//signed char
		{
			signed char symbol = 0;
			if (sizeof(signed char) == 1)
				SubMenuProccess(symbol, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 2)//short
		{
			short number = 0;
			if (sizeof(short) == 2)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 3)//unsigned short
		{
			unsigned short number = 0;
			if (sizeof(unsigned short) == 2)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 4)//int
		{
			int number = 0;
			if (sizeof(int) == 4)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 5)//unsigned int
		{
			unsigned int number = 0;
			if (sizeof(unsigned int) == 4)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 6)//long 
		{
			long number = 0;
			if (sizeof(long) == 4)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 7)//unsigned long
		{
			unsigned long number = 0;
			if (sizeof(unsigned long) == 4)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 8)//long long
		{
			long long number = 0;
			if (sizeof(long long) == 8)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 9)//unsigned long long
		{
			unsigned long long number = 0;
			if (sizeof(unsigned long long) == 8)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 10)//float
		{
			float number = 0;
			if (sizeof(float) == 4)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 11)//double
		{
			double number = 0;
			if (sizeof(double) == 8)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
		}
		if (MainMenu.Item == 12)//long double
		{
			/*
			long double number = 0;
			if (sizeof(long) == 10)
				SubMenuProccess(number, MainMenu, SubMenu, rows2, Data);
			else
			{
				cout << ErrorMsg << endl;
				system("pause");
			}
			*/
		}
		if (MainMenu.Item == 13)//Справка
		{
			cout << "Программа предназначена для вывода внутреннего представления различных типов данных." << endl << endl
				<< "Ввод осуществляется в выбранной пользователем системе счисления." << endl << endl
				<< "Порядок ввода:" << endl
				<< "  Символьные типы данных: 1 раз нажмите на необходимую клавишу клавиатуры." << endl
				<< "  Целочисленные типы данных: ввод осуществляется с помощью знаков выбранной системы счисления(и минуса) и нажатия клавиши <enter>." << endl
				<< "  Вещественные типы данных: вводятся так же, как и целочисленные типы с добавлением точки." << endl << endl << endl << endl
				<< "Программа выполнена студентом СПБГЭТУ \"ЛЭТИ\" гр. 9372 Аксёновым Александром" << endl << "2020" << endl;

			system("pause");
		}
		ClrScr();
		SubMenu.Item = 0;
    } while (MainMenu.Item != rows - 1);//Выбран пункт "Выйти"
    FreeMenu(MainMenu, 0);
	FreeMenu(SubMenu, 0);
    return 0;
}


