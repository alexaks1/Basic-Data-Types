// Меню.cpp
//

//#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include "MyCrt.h"
#include "Menu.h"

using namespace std;

//struct MItem					// Тип данных одного элемента меню
//{
//	char *Text;				// Текст команды элемента меню
//	int Length;				// Длина текста элемента меню
//	int Pos;				// Координата Х положения на экране текста элемента меню
//};
//
//struct Menu					// Тип данных Menu
//{
//	int X,					// Координата Х верхнего левого угла меню
//		Y,					// Координата Y верхнего левого угла меню
//		CCount,				// Количество столбцов меню
//		TabType;			// Вид линий сетки меню (0 - одиночные; 1 - двойные)
//		bool Horizont;		// True - горизонтальное меню: False - вертикальное
//	int Item;				// Номер выбранной команды меню (начинается с 0)
//	short NormColors,		// Цветовые аттрибуты не выбранных ячеек (см. MyCrt)
//		  SelectColors;		// Цветовые аттрибуты выбранной ячейки (см. MyCrt)
//	MItem *Items;			// Массив строк команд меню
//	int MenuWidth,			// Служебное поле - ширина меню на экране
//	    MenuHeight;			// Служебное поле - высота меню на экране
//	char *Buf;				// Указатель на буфер для сохранения изображения под меню
//};
//
//void InitMenu(			// Инициализация параметров меню Т
//	Menu &T,				// Переменная для меню
//	int X, int Y,			// Координаты Х и Y верхнего левого угла меню
//	int TabType,			// Вид линий сетки меню (0 - одиночные; 1 - двойные)
//	bool Horizont,			// True - горизонтальное меню: False - вертикальное
//	short NormColors,		// Цветовые аттрибуты не выбранных команд (см. MyCrt)
//	short SelectColors,		// Цветовые аттрибуты выбранной команды (см. MyCrt)
//	int n, int m,			// Размерности двумерного массива Data[n][m]
//	char *Data
//	); 
//void HideMenu(Menu T, short Colors);					// Стереть меню с экрана цветом Colors
//void Show_Menu(Menu T);								// Показать меню на экране		
//void FreeMenu(Menu T, short Colors);					// Уничтожить меню в памяти и на экране
//void DrawEmptyMenu(Menu T);							// Нарисовать меню без команд на экране
//void FillMenu(Menu T);								// Заполнить меню командами из массива команд
//bool ItemChoice(Menu &T);								// Выбор команды меню

void InitMenu(Menu &T, int X, int Y, int TabType, bool Horizont, short NormColors, short SelectColors, int n, int m, char *Data)
{
	T.X = X;
	T.Y = Y;
	T.CCount = n;
	T.TabType = TabType;
	T.Horizont = Horizont;
	T.NormColors = NormColors;
	T.SelectColors = SelectColors;
	T.Item = 0;
	T.Items = new MItem [n];
	int P = X + 2;
	int MaxL = 0;
	for (int i = 0; i < n; ++ i)
	{
		T.Items[i].Text = Data + i * m;
		T.Items[i].Length = strlen(T.Items[i].Text);
		if (T.Items[i].Length > MaxL)
			MaxL = T.Items[i].Length;
		T.Items[i].Pos = P;
		if (Horizont)
			P += T.Items[i].Length + 3;
	}
	if (Horizont)
	{
		T.MenuWidth = T.Items[T.CCount - 1].Pos + T.Items[T.CCount - 1].Length + 2;
		T.MenuHeight = T.TabType == -1 ? 1 : 3;
	}
	else
	{
		T.MenuWidth = MaxL + 4;
		T.MenuHeight = T.TabType == -1 ? T.CCount : T.CCount + 2;
	}
	T.Buf = new char[T.MenuWidth * T.MenuHeight * sizeof(CHAR_INFO)];
}

void HideMenu(Menu T, short Colors)
{
	int BX = WhereX(), BY = WhereY();
	PasteRect(T.X, T.Y, T.X + T.MenuWidth - 1, T.Y + T.MenuHeight - 1, T.Buf);
	GoToXY(BX, BY);
}

void FreeMenu(Menu &T, short Colors)
{
	delete [] T.Items;
	T.Items = NULL;
	delete [] T.Buf;
	T.Buf = NULL;
}

void Show_Menu(Menu T)
{
	DrawEmptyMenu(T);
	FillMenu(T);
}

void DrawTabLine(Menu T, int Y, int Line)
{
	setlocale(LC_ALL, "C");
	char TabChars[][4][4] = {
		{
			{'\332','\304','\304','\277'},    // ┌--┐
			{'\263','\40','\40','\263'},      // │  │    
			{'\300','\304','\304','\331'}     // └--┘
		},
		{
			{'\311','\315','\315','\273'},    // ╔══╗
			{'\272','\40','\40','\272'},        
			{'\310','\315','\315','\274'}     
		}
	};
	GoToXY(T.X, Y);
	if (T.TabType != -1)
		cout << TabChars[T.TabType][Line][0];
	int ColCount = T.Horizont ? T.CCount : 1;
	for (int i = 0; i < ColCount; ++i)
	{
		int L = T.Horizont ? T.Items[i].Length + 2 : T.MenuWidth - 2;
		for (int j = 1; j <= L; ++j)
			cout << TabChars[T.TabType][Line][1];
		if (i != ColCount - 1)
    		cout << TabChars[T.TabType][Line][2];
	}
	if (T.TabType != -1)
		cout << TabChars[T.TabType][Line][3];
	else 
		cout << "  ";
	setlocale(LC_ALL, "Russian");
}

void DrawEmptyMenu(Menu T)
{
	CopyRect(T.X, T.Y, T.X + T.MenuWidth - 1, T.Y + T.MenuHeight - 1, T.Buf);
	short BColors = GetTextColors();
	TextColor(T.NormColors);
	SetConsoleCP(1251);
	int Y = T.Y - 1;
	if (T.TabType != -1)
	   	DrawTabLine(T, ++Y, 0);
	int H = T.Horizont ? 1 : T.CCount;
	for (int i = 0; i < H; ++ i)
  		DrawTabLine(T, ++ Y, 1);
	if (T.TabType != -1)
	   	DrawTabLine(T, ++Y, 2);
	cout << endl;
	SetConsoleCP(866);
	TextColor(BColors);
}

void ChangeCellAtr(Menu T, bool Select, int Item)
{
	short C;
	if (Select)
		C = T.SelectColors;
	else
		C = T.NormColors;
	int Y = T.Horizont ? T.Y : T.Y + Item;
	if (T.TabType != -1)
		ChangeTextAttribute(C, T.Items[Item].Pos - 1, Y + 1, T.Items[Item].Length + 2);
	else
		ChangeTextAttribute(C, T.Items[Item].Pos - 1, Y, T.Items[Item].Length + 2);
}

bool ItemChoice(Menu &T)
{
	char Ch;
	int BVal;
	CursorVisible(false);
	do
	{
		ChangeCellAtr(T, true, T.Item);
		BVal = T.Item;
		Ch = _getch();
		switch (Ch)
		{
		case 77: //Right
			T.Item = T.Item < T.CCount - 1 ? T.Item + 1 : 0;
			break;
		case 80: //Down
			T.Item = T.Item < T.CCount - 1 ? T.Item + 1 : 0;
			break;
		case 75: //Left
			T.Item = T.Item > 0 ? T.Item - 1 : T.CCount - 1;
			break;
		case 72: //Up
			T.Item = T.Item > 0 ? T.Item - 1 : T.CCount - 1;
			break;
		case 71: //Home
			if (T.Item > 0)
				T.Item = 0;
			break;
		case 73: //PgUp
			if (T.Item > 0)
				T.Item = 0;
			break;
		case 79: //End
			if (T.Item < T.CCount - 1)
				T.Item = T.CCount - 1;
			break;
		case 81: //PgDn
			if (T.Item < T.CCount - 1)
				T.Item = T.CCount - 1;
			break;
		case 27: //Esc
			break;
		case 13: //Enter
			break;
		};
		if (T.Item != BVal)
			ChangeCellAtr(T, false, BVal);
	}
	while ((Ch != 13) && (Ch != 27));
	CursorVisible(true);
	return Ch == 13;
}

void FillMenu(Menu T)
{ 
	int BX = WhereX(), BY = WhereY();
	short BColors = GetTextColors();
	TextColor(T.NormColors);
	for (int j = 0; j < T.CCount; ++ j)
	{
		int Y = T.Horizont ? T.Y : T.Y + j;
		if (T.TabType != -1)
			GoToXY(T.Items[j].Pos, Y + 1);
		else
			GoToXY(T.Items[j].Pos, Y);
		cout << T.Items[j].Text;
	};
	ChangeCellAtr(T, true, T.Item);
    TextColor(BColors);
	GoToXY(BX, BY);
}

