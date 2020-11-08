#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "MyCrt.h"

using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE),
hIn = GetStdHandle(STD_INPUT_HANDLE);

const char LEFT_BTN_CLICK = FROM_LEFT_1ST_BUTTON_PRESSED,
RIGHT_BTN_CLICK = RIGHTMOST_BUTTON_PRESSED,
DBL_CLICK = 3,
H_WHEELE = 4,
V_WHEELE = 5,
MOUSE_MOVE = 6;

void ColorMap()
{
	for (int i = 0; i < 16; ++i)
	{
		int b = i << 4;
		for (int f = 0; f < 16; ++f)
		{
			SetConsoleTextAttribute(hOut, b | f);
			cout << '*';
		}
		cout << endl;
	}
}

short MaxX()
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	return ConInfo.dwSize.X;
}

short MaxY()
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	return ConInfo.dwSize.Y;
}

void ConWidth(int W)
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	COORD c = { W, ConInfo.dwSize.Y };
	SetConsoleScreenBufferSize(hOut, c);
}

void ConHeight(int H)
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	if (H < 25)
		H = 25;
	COORD c = { ConInfo.dwSize.X, H };
	SetConsoleScreenBufferSize(hOut, c);
}

void ConSize(int W, int H)
{
	if (H < 25)
		H = 25;
	COORD c = { W, H };
	SetConsoleScreenBufferSize(hOut, c);
}

void ScrSize(int W, int H)
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	SMALL_RECT WRect = ConInfo.srWindow;
	COORD c = GetLargestConsoleWindowSize(hOut);
	if (W > c.X)
		W = c.X;
	if (H > c.Y)
		H = c.Y;
	if (W > ConInfo.dwSize.X)
		W = ConInfo.dwSize.X;
	if (H > ConInfo.dwSize.Y)
		H = ConInfo.dwSize.Y;
	WRect.Right = WRect.Left + W - 1;
	WRect.Bottom = WRect.Top + H - 1;
	SetConsoleWindowInfo(hOut, true, &WRect);
}

void FixedConSize(int Width, int Height) // Фиксирует размер консольного окна и буфера консоли
{
	ConSize(Width, Height);
	ScrSize(Width, Height);
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

int GetScrWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	return ConInfo.srWindow.Right - ConInfo.srWindow.Left + 1;
}

int GetScrHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	return ConInfo.srWindow.Bottom - ConInfo.srWindow.Top + 1;
}

void ScrGoTo(int X, int Y)
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	SMALL_RECT WRect = ConInfo.srWindow;
	WRect.Right = X + WRect.Right - WRect.Left;
	WRect.Bottom = Y + WRect.Bottom - WRect.Top;
	WRect.Left = X;
	WRect.Top = Y;
	SetConsoleWindowInfo(hOut, true, &WRect);
	GoToXY(X, Y);
}

void ScrollVert(int P)
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	SMALL_RECT WRect = ConInfo.srWindow;
	WRect.Top += P;
	WRect.Bottom += P;
	SetConsoleWindowInfo(hOut, true, &WRect);
	GoToXY(WhereX(), WhereY() + P);
}

void ScrollHor(int P)
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	SMALL_RECT WRect = ConInfo.srWindow;
	WRect.Left += P;
	WRect.Right += P;
	SetConsoleWindowInfo(hOut, true, &WRect);
	GoToXY(WhereX() + P, WhereY());
}

void CursorVisible(bool Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOut, &CursorInfo);
	CursorInfo.bVisible = Visible;
	SetConsoleCursorInfo(hOut, &CursorInfo);
}

void GoToXY(short x, short y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(hOut, c);
}

unsigned short WhereX()
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	return ConInfo.dwCursorPosition.X;
}

unsigned short WhereY()
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	return ConInfo.dwCursorPosition.Y;
}

void WhereXY(unsigned short& x, unsigned short& y)
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	GetConsoleScreenBufferInfo(hOut, &ConInfo);
	x = ConInfo.dwCursorPosition.X;
	y = ConInfo.dwCursorPosition.Y;
}

unsigned short GetTextColors()
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfo;
	if (GetConsoleScreenBufferInfo(hOut, &ConInfo))
		return ConInfo.wAttributes;
	else
		return 0;
}

void TextBackground(unsigned short Color)
{
	if (Color >= 16)
		return;
	Color = Color << 4;
	Color = GetTextColors() & 0xFF0F | Color;
	SetConsoleTextAttribute(hOut, Color);
}

void TextForeground(unsigned short Color)
{
	if (Color >= 16)
		return;
	Color = GetTextColors() & 0xFFF0 | Color;
	SetConsoleTextAttribute(hOut, Color);
}

void TextColor(unsigned short Colors)
{
	if (Colors >= 256)
		return;
	SetConsoleTextAttribute(hOut, Colors);
}

void ChangeTextAttribute(unsigned short Colors, unsigned short x, unsigned short y, unsigned short len)
{
	COORD c = { x, y };
	DWORD l;
	FillConsoleOutputAttribute(hOut, Colors, len, c, &l);
}

void ClrScr()
{
	COORD c = { 0, 0 };
	DWORD Chr;
	CONSOLE_SCREEN_BUFFER_INFO ConInfor;
	DWORD ConSize;
	if (!GetConsoleScreenBufferInfo(hOut, &ConInfor))
		return;
	ConSize = ConInfor.dwSize.X * ConInfor.dwSize.Y;
	if (!FillConsoleOutputCharacter(hOut, (TCHAR)' ', ConSize, c, &Chr))
		return;
	if (!FillConsoleOutputAttribute(hOut, ConInfor.wAttributes, ConSize, c, &Chr))
		return;
	SetConsoleCursorPosition(hOut, c);
}

void FillChar(int x, int y, int len, char c)
{
	DWORD Chr;
	COORD coor = { x, y };
	FillConsoleOutputCharacter(hOut, (TCHAR)c, len, coor, &Chr);
}

void FillChar(int x, int y, int len, char c, short Colors)
{
	FillChar(x, y, len, c);
	ChangeTextAttribute(Colors, x, y, len);
}

void FillChar(int x, int y, int len, wchar_t c)
{
	DWORD Chr;
	COORD coor = { x, y };
	FillConsoleOutputCharacter(hOut, (TCHAR)c, len, coor, &Chr);
}

void FillChar(int x, int y, int len, wchar_t c, short Colors)
{
	FillChar(x, y, len, c);
	ChangeTextAttribute(Colors, x, y, len);
}

void ClearEoln()
{
	CONSOLE_SCREEN_BUFFER_INFO ConInfor;
	GetConsoleScreenBufferInfo(hOut, &ConInfor);
	DWORD Chr, Size = ConInfor.dwSize.X - ConInfor.dwCursorPosition.X;
	FillConsoleOutputCharacter(hOut, (TCHAR)' ', Size, ConInfor.dwCursorPosition, &Chr);
}

void WriteText(int x, int y, const wchar_t s[])
{
	GoToXY(x, y);
	wcout << s;
}

void WriteText(int x, int y, const wchar_t s[], short Colors)
{
	GoToXY(x, y);
	wcout << s;
	ChangeTextAttribute(Colors, x, y, wcslen(s));
}

void WriteText(int x, int y, const char s[])
{
	GoToXY(x, y);
	cout << s;
}

void WriteText(int x, int y, const char s[], short Colors)
{
	GoToXY(x, y);
	cout << s;
	ChangeTextAttribute(Colors, x, y, strlen(s));
}

bool ReadKey(wchar_t& c)
{
	bool b = 0;
	c = _getwch();
	if (c == 224 || !c)
		c = _getwch();
	else
		b = 1;
	return b;
}

bool ReadKey(char& c)
{
	bool b = 0;
	c = _getch();
	if (c == -32 || !c)
		c = _getch();
	else
		b = 1;
	return b;
}

int ReadKeyOrMouse(uKeyOrMouseInf& KMF)
{
	DWORD RealRead;
	int  Fl = 0;
	INPUT_RECORD InBuf;
	if (ReadConsoleInput(hIn, &InBuf, 1, &RealRead))
		switch (InBuf.EventType)
		{
		case KEY_EVENT:
			if (InBuf.Event.KeyEvent.bKeyDown)
			{
				KMF.KeyCode.kc = InBuf.Event.KeyEvent.uChar.UnicodeChar;
				KMF.KeyCode.sc = InBuf.Event.KeyEvent.wVirtualScanCode;
				Fl = 1;
			}
			break;
		case MOUSE_EVENT:
			KMF.MouseInf.x = InBuf.Event.MouseEvent.dwMousePosition.X;
			KMF.MouseInf.y = InBuf.Event.MouseEvent.dwMousePosition.Y;
			KMF.MouseInf.mState = 0;
			switch (InBuf.Event.MouseEvent.dwEventFlags)
			{
			case 0:
				if (InBuf.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					KMF.MouseInf.mState = LEFT_BTN_CLICK;
				else
					if (InBuf.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
						KMF.MouseInf.mState = RIGHT_BTN_CLICK;
				break;
			case DOUBLE_CLICK:
				KMF.MouseInf.mState = DBL_CLICK;
				break;
			case MOUSE_HWHEELED:
				KMF.MouseInf.mState = H_WHEELE;
				break;
			case MOUSE_MOVED:
				KMF.MouseInf.mState = MOUSE_MOVE;
				break;
			case MOUSE_WHEELED:
				KMF.MouseInf.mState = V_WHEELE;
				break;
			}
			Fl = 2;
		}
	FlushConsoleInputBuffer(hIn);
	return Fl;
}

bool CopyRect(int Left, int Top, int Right, int Bottom, CHAR_INFO* Buffer)
{
	SMALL_RECT Rect = { Left, Top, Right, Bottom };
	COORD BufSize = { Right - Left + 1, Bottom - Top + 1 };
	COORD BufCoord = { 0, 0 };
	return ReadConsoleOutput(hOut, Buffer, BufSize, BufCoord, &Rect);
}

bool CopyRect(int Left, int Top, int Right, int Bottom, char* Buffer)
{
	SMALL_RECT Rect = { Left, Top, Right, Bottom };
	COORD BufSize = { Right - Left + 1, Bottom - Top + 1 };
	COORD BufCoord = { 0, 0 };
	return ReadConsoleOutput(hOut, (CHAR_INFO*)Buffer, BufSize, BufCoord, &Rect);
}

bool PasteRect(int Left, int Top, int Right, int Bottom, char* Buffer)
{
	SMALL_RECT Rect = { Left, Top, Right, Bottom };
	COORD BufSize = { Right - Left + 1, Bottom - Top + 1 };
	COORD BufCoord = { 0, 0 };
	return WriteConsoleOutput(hOut, (CHAR_INFO*)Buffer, BufSize, BufCoord, &Rect);
}

bool PasteRect(int Left, int Top, int Right, int Bottom, CHAR_INFO* Buffer)
{
	SMALL_RECT Rect = { Left, Top, Right, Bottom };
	COORD BufSize = { Right - Left + 1, Bottom - Top + 1 };
	COORD BufCoord = { 0, 0 };
	return WriteConsoleOutput(hOut, Buffer, BufSize, BufCoord, &Rect);
}

char* ReadLine(char* S, int len)
// функция для корректного ввода с клавиатуры русских букв
{
	cin.getline(S, len);
	OemToAnsi(S, S);
	return S;
}

