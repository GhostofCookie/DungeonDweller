#include "Image.h"

Image::Image(int h, int w, char c)
	: height{ h }, width{ w }, ch{ c }
{
	Create();
}

Image::Image(const Image& image)
	: height{ image.GetRows() }, width{ image.GetCols() }, screenX{ image.screenX }, screenY{ image.screenY }
{
}

Image::~Image()
{}

Image& Image::operator=(const Image& img)
{
	Img = img.Img;

	height = img.GetRows();
	width = img.GetCols();
	screenX = img.screenX;
	screenY = img.screenY;
	ch = img.ch;
	return *this;
}

int Image::GetRows() const { return height; }

int Image::GetCols() const { return width; }

bool Image::IsEven(const int& num) const { return(num % 2 == 0); }

void Image::Draw(Screen& screen) { Draw(screen, screenY, screenX); }

void Image::Draw(Screen& screen, int y, int x)
{
	int imgY = y;
	int imgX = x;

	// An algorithm that moves through each element in the Img
	// and attempts to place on the screen with the given start location
	for (unsigned int i = 0; i < Img.size(); ++i)
	{
		for (auto p = Img[i].begin(); p != Img[i].end(); ++p)
		{
			if ((imgX > 0 && imgX < screen.GetCols()-1) && (imgY > 0 && imgY < screen.GetRows()-1))
				screen.Set(imgY, imgX, *p);
			imgX++;
		}
		imgY++;
		imgX = x;
	}
	screen.DrawBorder();
}

void Image::Draw(Image& img) { Draw(img, screenY, screenX); }

void Image::Draw(Image& img, int y, int x)
{
	int imgY = y;
	int imgX = x;

	// An algorithm that moves through each element in the Img
	// and attempts to place on the screen with the given start location
	for (unsigned int i = 0; i < Img.size(); ++i)
	{
		for (auto p = Img[i].begin(); p != Img[i].end(); ++p)
		{
			if ((imgX >= 0 && imgX < img.GetCols()) && (imgY >= 0 && imgY < img.GetRows()))
				img.Set(imgY, imgX, *p);
			imgX++;
		}
		imgY++;
		imgX = x;
	}
}

void Image::Create()
{
	for (int i = 0; i < height; i++)
	{
		Img.push_back(std::vector<char>());
		for (int j = 0; j < width; j++)
			Img[i].push_back(ch);
	}
}

void Image::DrawBorder(char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				Set(i, j, ch);
}

void Image::Erase()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			Set(i, j, ' ');
}

void Image::Set(int y, int x, char ch)
{
	if ((y >= 0 || x >= 0) && (y < GetRows() && x < GetCols()))
		Img[y][x] = ch;
}

void Image::Fill(char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			Set(i, j, ch);
}

/******************************************************************************
 * ALIGN MEMBER FUNCTIONS
 *****************************************************************************/
void Image::SetOrigin(Screen& screen, int y, int x)
{
	assert(y >= 0 || y < screen.GetRows());
	assert(x >= 0 || x < screen.GetCols());
	screenX = x;
	screenY = y;
}

void Image::SetOrigin(Image& img, int y, int x)
{
	assert(y >= 0 || y < img.GetRows());
	assert(x >= 0 || x < img.GetCols());
	screenX = x;
	screenY = y;
}

void Image::FlipHoriz()
{
	std::vector<std::vector<char>> temp;
	int imgSize = static_cast<int>(Img.size());

	for (unsigned int i = 0; i < Img.size(); ++i)
	{
		std::vector<char> _temp;
		for (unsigned int j = imgSize - 1; j != 1; --j)
			_temp.push_back(Img[i][j]);

		temp.push_back(_temp);
	}

	Img = temp;
	FixSlants();// by-product of having console characters
}

void Image::FlipVert()
{
	std::vector<std::vector<char>> temp;
	int imgSize = static_cast<int>(Img.size());

	for (int i = imgSize - 1; i != -1; --i)
	{
		std::vector<char> _temp;
		for (unsigned int j = 0; j < Img[i].size(); ++j)
			_temp.push_back(Img[i][j]);

		temp.push_back(_temp);
	}

	Img = temp;
	FixSlants();// by-product of having console characters
}

void Image::AlignCenter(Screen& screen)
{
	int scrX = screen.GetCols() / 2;
	int scrY = screen.GetRows() / 2;
	int imgX = width / 2;
	int imgY = height / 2;

	// Relys on it being odd for centering perfection
	SetOrigin(screen, scrY - imgY, scrX - imgX);
}

void Image::AlignCenter(Image& img)
{
	// in this situation the screen is represented by the image
	int scrX = img.GetCols() / 2;
	int scrY = img.GetRows() / 2;
	int imgX = width / 2;
	int imgY = height / 2;

	// Relys on it being odd for centering perfection
	SetOrigin(img, scrY - imgY, scrX - imgX);
}

void Image::AlignCenter(Image& img, int x, int y)
{
	// in this situation the screen is represented by the image
	int scrX = x;
	int scrY = y;
	int imgX = width / 2;
	int imgY = height / 2;

	// Relys on it being odd for centering perfection
	SetOrigin(img, scrY - imgY, scrX - imgX);
}

// Ensures it draws one character from the border
void Image::AlignLeft(Image& img) { screenX = 1; }

void Image::AlignRight(Image& img)
{
	//uses the image's width and screen's width to find the right side
	screenX = static_cast<int>(img.GetCols() - Img[0].size() - 1);
}

// Ensures it draws one character from the border
void Image::AlignLeft(Screen& screen) { screenX = 1; };

void Image::AlignRight(Screen& screen)
{
	// uses the image's width and screen's width to find the right side
	screenX = static_cast<int>(screen.GetCols() - Img[0].size() - 1);
}

// Ensures it draws one character from the border
void Image::AlignTop(Screen& screen) { screenY = 1; };

// Ensures it draws one character from the border
void Image::AlignTop(Image& img) { screenY = img.screenY - 1; };

// Ensures it draws one character from the border
void Image::AlignBottom(Screen& screen) { screenY = static_cast<int>(screen.GetRows() - Img.size() - 1); };

// Ensures it draws one character from the border
void Image::AlignBottom(Image& img) { screenY = static_cast<int>(img.GetRows() - Img.size() - 1); };

void Image::ShiftUp(int num)
{
	int i = 0;
	while (i < num)
	{
		screenY--;
		i++;
	}
}

void Image::ShiftDown(Screen& screen, int num)
{
	int i = 0;
	while (i < num)
	{
		screenY++;
		i++;
	}
}

void 
Image::ShiftDown(Image& img, int num)
{
	int i = 0;
	while (i < num)
	{
		screenY++;
		i++;
	}
}

void Image::ShiftLeft(int num)
{
	int i = 0;
	while (i < num)
	{
		screenX--;
		i++;
	}
}

void Image::ShiftRight(Screen& screen, int num)
{
	int i = 0;
	while (i < num)
	{
		screenX++;
		i++;
	}
}

void Image::ShiftRight(Image& img, int num)
{
	int i = 0;
	while (i < num)
	{
		screenX++;
		i++;
	}
}

void Image::FixSlants()
{
	for (unsigned int i = 0; i < Img.size(); ++i)
	{
		for (unsigned int j = 0; j < Img[i].size(); ++j)
		{
			if (Img[i][j] == '/')
				Img[i][j] = '\\';
			else if (Img[i][j] == '\\')
				Img[i][j] = '/';
		}
	}
}
