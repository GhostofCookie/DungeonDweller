#include "Viewport.h"

#ifdef __linux__
#define SET_CURSOR_POS(i, j) {\
}
#elif _WIN64
#include "Windows.h"
#define SET_CURSOR_POS(row, column) {							\
	const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);\
	COORD coord = { short(row), short(column) };				\
	SetConsoleCursorPosition(hOut, coord);				\
}
#endif

Viewport::Viewport(int h, int w, int x, int y)
	: height{ h }, width{ w }, originX{ x }, originY{ y }
{
	Initialize(height, width);
	DrawBorder();
}

void Viewport::Initialize(int h, int w)
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

void Viewport::Resize(int h, int w)
{
	Wipe();
	height = h;
	width = w;
}

const char& Viewport::Get(int y, int x) const
{
	if (y > 0 && y < height && x > 0 && x < width)
		return Window[y][x];
	return ' ';
}

int Viewport::GetRows() const { return height; }

int Viewport::GetCols() const { return width; }

void Viewport::DrawBorder()
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

void Viewport::Fill()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (i != 0 && i != height - 1 && j != 0 && j != width - 1)
				Set(i, j, ' ');
}

void Viewport::Fill(char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (i != 0 && i != height - 1 && j != 0 && j != width - 1)
				Set(i, j, ch);
}

void Viewport::Set(int h, int w, char ch)
{
	if ((h >= 0 && h < height) && (w >= 0 && w < width))
		ChangeBuffer[h][w] = ch;
}

void Viewport::Erase()
{
	for (int i = 1; i < height - 1; i++)
		for (int j = 1; j < width - 1; j++)
			Set(i, j, ' ');
	DrawBorder();
}

void Viewport::Wipe()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			ChangeBuffer[i][j] = ' ';
	std::cout << this;
}

void Viewport::DisplayAll(const std::vector<std::shared_ptr<Viewport>>& screens)
{
	for (auto it = screens.begin(); it != screens.end(); ++it)
		std::cout << *it;
}

void Viewport::DisplayAll(const std::unordered_map<std::string, std::shared_ptr<Viewport>>& screens)
{
	for (auto it = screens.begin(); it != screens.end(); ++it)
		std::cout << it->second;
}

std::ostream& operator<<(std::ostream& os, const Viewport& s)
{
	//checks if s is empty
	if (s.Window.begin() == s.Window.end())
		return os;

	//Prints a two-dimensional std::vector of characters
	for (unsigned int i = 0; i < s.Window.size(); i++)
	{
		std::cout.flush();
		for (size_t j = 0; j < s.Window[i].size(); j++)
			if (s.Get(i, j) != s.ChangeBuffer[i][j])
			{
				const_cast<Viewport&>(s).Window[i][j] = s.ChangeBuffer[i][j];
				SET_CURSOR_POS(j + s.originX, i + s.originY);
				std::cout << s.Window[i][j];
			}
	}
	SET_CURSOR_POS(0, s.Window.size());
	return os;
}

std::ostream& operator<<(std::ostream& os, const Viewport* s)
{
	return os << *s;
}
