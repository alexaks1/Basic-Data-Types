#pragma once;

//#define _WIN32_WINNT 0x0500
#include <Windows.h>

struct sKeyCode {
	wchar_t kc, sc;
};

struct sMouseInf {
	char mState;
	int x, y;
};

union uKeyOrMouseInf {
	sKeyCode KeyCode;
	sMouseInf MouseInf;
};

short MaxX();  // Возвращает ширину буфера вывода
short MaxY();  // Возвращает высоту буфера вывода
void ConWidth(int W);  // Устанавливает ширину W буфера вывода
void ConHeight(int H); // Устанавливает высоту H буфера вывода
void ConSize(int W, int H); // Устанавливает ширину W и высоту H буфера вывода
void ScrollVert(int P); // Перемещает окно консоли по вертикали на Р строк (при Р > 0 - вниз; при Р < 0 - вверх)
void ScrollHor(int P); // Перемещает окно консоли по горизонтали на Р колонок (при Р > 0 - вправо; при Р < 0 - влево)
int GetScrWidth(); // Возвращает ширину окна консоли
int GetScrHeight(); // Возвращает высоту окна консоли
void ScrSize(int W, int H); // Устанавливает ширину W и высоту H окна консоли
void FixedConSize(int Width, int Height); // Фиксирует размер консольного окна и буфера консоли
void ScrGoTo(int X, int Y); // Перемещает окно консоли в точку буфера вывода с координатами (X, Y)
void CursorVisible(bool Visible); // Включает и отключает видимость курсора в окне консоли
void GoToXY(short x, short y); // Перемещает курсор в точку буфера консоли с координатами (X, Y)
unsigned short WhereX(); // Возвращает координату Х текущего положения курсора
unsigned short WhereY(); // Возвращает координату Y текущего положения курсора
void WhereXY(unsigned short& x, unsigned short& y); // Возвращает координаты Х и Y текущего положения курсора
unsigned short GetTextColors(); // Возвращает цветовые аттрибуты буфера вывода в шестнадцатеричном формате
void TextBackground(unsigned short Color); // Устанавливает цвет фона
void TextForeground(unsigned short Color); // Устанавливает цвет символов
void TextColor(unsigned short Colors); // Устанавливает цвета фона и символов 
// Изменяет цветовые аттрибуты на Colors начиная с точки с координатами (X, Y) на участке длиной len символов
void ChangeTextAttribute(unsigned short Colors, unsigned short x, unsigned short y, unsigned short len);
void ClrScr(); // Очистка буфера вывода консоли установленным цветом фона 
void FillChar(int x, int y, int len, char c); // Начиная с точки (X, Y) выводит len раз символ С
void FillChar(int x, int y, int len, char c, short Colors); // Начиная с точки (X, Y) выводит len раз символ С цветами Colors
void FillChar(int x, int y, int len, wchar_t c); // Начиная с точки (X, Y) выводит len раз символ С
void FillChar(int x, int y, int len, wchar_t c, short Colors); // Начиная с точки (X, Y) выводит len раз символ С цветами Colors
void ClearEoln(); // Очищает строку от текущей позиции курсора до конца строки
void WriteText(int x, int y, const wchar_t s[]); // Выводит текст S в точку с координатами (X, Y)
void WriteText(int x, int y, const wchar_t s[], short Colors); // Выводит текст S в точку с координатами (X, Y) с цветами Colors
void WriteText(int x, int y, const char s[]); // Выводит текст S в точку с координатами (X, Y)
void WriteText(int x, int y, const char s[], short Colors); // Выводит текст S в точку с координатами (X, Y) с цветами Colors
bool ReadKey(wchar_t& c); // Осуществляет чтение кода С нажатой клавиши. Возвращает TRUE, если нажата обычная клавиша
bool ReadKey(char& c); // Осуществляет чтение кода С нажатой клавиши. Возвращает TRUE, если нажата обычная клавиша
int ReadKeyOrMouse(uKeyOrMouseInf& KMF); // Обрабатывает события клавиатуры и мыши
bool CopyRect(int Left, int Top, int Right, int Bottom, char* Buffer);	// Копировать прямоугольную область экрана в буфер
bool PasteRect(int Left, int Top, int Right, int Bottom, char* Buffer); // Поместить изображение прямоугольной области экрана из буфера на экран
bool CopyRect(int Left, int Top, int Right, int Bottom, CHAR_INFO* Buffer);
bool PasteRect(int Left, int Top, int Right, int Bottom, CHAR_INFO* Buffer);

char* ReadLine(char* S, int len); 	// функция для корректного ввода с клавиатуры русских букв

// Во всех функциях параметр Colors задает цветовые аттрибуты буфера вывода в шестнадцатеричном формате.
// Например: 0х1F - определяет следующие цвета 1 - цвет фона (темно-синий), F - цвет символов (ярко-белый)
