#pragma once
#include "Header.h"
#include "Pixel.h"
class Image
{
public:
	Header header;
	Pixel** pixels;
	Image();
	Image(Header _header, Pixel** _pixels);
	Image(Header _header);
	Image(const Image& otherObject);
	Image& operator=(const Image& otherObject);
	~Image();
	void ChangeGreen(unsigned char delta);
	void ChangeRed(unsigned char delta);
	void ChangeBlue(unsigned char delta);
	void MultiplyGreen(float delta);
	void MultiplyRed(float delta);
	void MultiplyBlue(float delta);
	void Split(Image& imageR, Image& imageG, Image& imageB);
	void Rotate();
};

