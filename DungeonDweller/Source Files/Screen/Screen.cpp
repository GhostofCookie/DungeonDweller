#include "Screen.h"
#include "Windows.h"

Screen::Screen(int h, int w, int x, int y)
	: height{ h }, width{ w }, originX{ x }, originY{ y }
{
	Initialize(height, width);
	DrawBorder();
}

void Screen::Initialize(int h, int w)
{
	for (int i = 0; i < h; i++)
	{
		ChangeBuffer.push_back(std::vector<char>());
		Window.push_back(std::vector<char>());
		for (int j = 0; j < w; j++)
		{
			ChangeBuffer[i].push_back(' ');
			Window[i].push_back(' ');
		}
	}
}

void Screen::Resize(int h, int w)
{
	height = h;
	width = w;

	Window.clear();
	ChangeBuffer.clear();
}

const char& Screen::Get(int y, int x) const
{
	if (y > 0 && y < height && x > 0 && x < width)
		return ChangeBuffer[y][x];
	return ' ';
}

int Screen::GetRows() const { return height; }

int Screen::GetCols() const { return width; }

bool Screen::IsEven(const int& num) const
{
	if (num % 2 == 0)
		return true;
	return false;
}

void Screen::DrawBorder(char ch)
{
	if (outlineOn)
	{
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
					Set(i, j, ch);
	}
}

void Screen::DrawBorder()
{
	if (outlineOn)
	{
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if ((i == 0 && j == 0) ||
					(i == 0 && j == width - 1) ||
					(i == height - 1 && j == 0) ||
					(i == height - 1 && j == width - 1))
					Set(i, j, '+');
				else if (i == 0 || i == height - 1)
					Set(i, j, '-');
				else if (j == 0 || j == width - 1)
					Set(i, j, '|');
	}
}

void Screen::Fill()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (i != 0 && i != height - 1 && j != 0 && j != width - 1)
				Set(i, j, ' ');
}

void Screen::Fill(char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (i != 0 && i != height - 1 && j != 0 && j != width - 1)
				Set(i, j, ch);
}

void Screen::Set(int h, int w, char ch)
{
	if ((h >= 0 && h < height) && (w >= 0 && w < width))
		ChangeBuffer[h][w] = ch;
}

void Screen::Erase()
{
	for (int i = 1; i < height - 1; i++)
		for (int j = 1; j < width - 1; j++)
			Set(i, j, ' ');
	if (outlineOn)
		DrawBorder();
}

void Screen::Wipe()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			Set(i, j, ' ');
	std::cout << this;
}

void Screen::MultiPrint(const std::vector<Screen>& screens)
{
	for (auto it = screens.begin(); it != screens.end(); ++it)
		std::cout << *it;
}

std::ostream& operator <<(std::ostream& os, const Screen& s)
{
	//checks if s is empty
	if (s.Window.begin() == s.Window.end())
		return os;

	const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//Prints a two-dimensional std::vector of characters
	for (unsigned int i = 0; i < s.Window.size(); i++)
	{
		std::cout.flush();
		for (size_t j = 0; j < s.Window[i].size(); j++)
			if (s.Window[i][j] != s.ChangeBuffer[i][j])
			{
				const_cast<Screen&>(s).Window[i][j] = s.ChangeBuffer[i][j];
				COORD coord = { short(j + s.originX), short(i + s.originY) };
				SetConsoleCursorPosition(hOut, coord);
				std::cout << s.Window[i][j];
			}
	}
	COORD coord = { 0, short(s.Window.size()) };
	SetConsoleCursorPosition(hOut, coord);
	return os;
}

std::ostream& operator <<(std::ostream& os, const Screen* s)
{
	return os << *s;
}
