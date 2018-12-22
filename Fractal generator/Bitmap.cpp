#include "Bitmap.h"
#include "Bitmapfileheader.h"
#include "Bitmapinfoheader.h"

#include <fstream>



Bitmap::Bitmap(int width, int heigth) : m_width(width), m_heigth(heigth), m_pPixels(new uint8_t[width*heigth * 3] {})
{
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t *pPixel = m_pPixels.get();

	pPixel += (y * 3) * m_width + (x * 3);

	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

bool Bitmap::write(string filename)
{
	BitmapFileHeader fileheader;
	BitmapInfoHeader infoheader;

	fileheader.filesize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_heigth * 3;
	fileheader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoheader.width = m_width;
	infoheader.heigth = m_heigth;

	ofstream file;

	file.open(filename, ios::out | ios::binary);

	if (!file)
	{
		return false;
	}

	file.write((char*)&fileheader, sizeof(fileheader));
	file.write((char*)&infoheader, sizeof(infoheader));
	file.write((char*)m_pPixels.get(), m_width*m_heigth * 3);

	file.close();





	return true;
}
