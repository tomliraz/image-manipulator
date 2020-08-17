#pragma once
#include "Image.h"

Image::Image(Header _header, Pixel** _pixels)
{
	header = _header;
	pixels = _pixels;
}
Image::Image(){
	header = Header();
	pixels = nullptr;
}

Image::Image(Header _header)
{
	header = _header;
	pixels = new Pixel *[header.height];
	for (int h = 0; h < header.height; h++)
	{
		pixels[h] = new Pixel[header.width];
	}
}
Image::Image(const Image& otherObject)
{
	header = otherObject.header;
	pixels = new Pixel*[header.height];
	for (int h = 0; h < header.height; h++)
	{
		pixels[h] = new Pixel[header.width];
		for (int w = 0; w < header.width; w++)
		{
			pixels[h][w] = otherObject.pixels[h][w];
		}
	}
}

Image &Image::operator=(const Image& otherObject)
{
	for (int h = 0; h < header.height; h++)
		delete[] pixels[h];
	delete[] pixels;

	header = otherObject.header;
	pixels = new Pixel *[header.height];
	for (int h = 0; h < header.height; h++)
	{
		pixels[h] = new Pixel[header.width];
		for (int w = 0; w < header.width; w++)
		{
			pixels[h][w] = otherObject.pixels[h][w];
		}
	}
	return *this;
}

Image::~Image()
{
	for (int h = 0; h < header.height; h++)
		delete[] pixels[h];
	delete[] pixels;
}

void Image::ChangeGreen(unsigned char delta)
{
	float temp = 0;
	for(int h = 0; h < header.height; h++)
		for (int w = 0; w < header.width; w++)
		{
			temp = (float)pixels[h][w].green + (float)delta;
			if (temp < 0)
				temp = 0;
			else if (temp > 255)
				temp = 255;
			pixels[h][w].green = (unsigned char)temp;
		}
}

void Image::ChangeRed(unsigned char delta)
{
	float temp = 0;
	for (int h = 0; h < header.height; h++)
		for (int w = 0; w < header.width; w++)
		{
			temp = (float)pixels[h][w].red + (float)delta;
			if (temp < 0)
				temp = 0;
			else if (temp > 255)
				temp = 255;
			pixels[h][w].red = (unsigned char)temp;
		}
}

void Image::ChangeBlue(unsigned char delta)
{
	float temp = 0;
	for (int h = 0; h < header.height; h++)
		for (int w = 0; w < header.width; w++)
		{
			temp = (float)pixels[h][w].blue + (float)delta;
			if (temp < 0)
				temp = 0;
			else if (temp > 255)
				temp = 255;
			pixels[h][w].blue = (unsigned char)temp;
		}
}

void Image::MultiplyGreen(float delta)
{
	float temp = 0;
	for (int h = 0; h < header.height; h++)
		for (int w = 0; w < header.width; w++)
		{
			temp = (float)pixels[h][w].green * delta;
			if (temp < 0)
				temp = 0;
			else if (temp > 255)
				temp = 255;
			pixels[h][w].green = (unsigned char)temp;
		}
}

void Image::MultiplyRed(float delta)
{
	float temp = 0;
	for (int h = 0; h < header.height; h++)
		for (int w = 0; w < header.width; w++)
		{
			temp = (float)pixels[h][w].red * delta;
			if (temp < 0)
				temp = 0;
			else if (temp > 255)
				temp = 255;
			pixels[h][w].red = (unsigned char)temp;
		}
}

void Image::MultiplyBlue(float delta)
{

	float temp = 0;
	for (int h = 0; h < header.height; h++)
		for (int w = 0; w < header.width; w++)
		{
			temp = (float)pixels[h][w].blue * delta;
			if (temp < 0)
				temp = 0;
			else if (temp > 255)
				temp = 255;
			pixels[h][w].blue = (unsigned char)temp;
		}
}

void Image::Split(Image& imageR, Image& imageG, Image& imageB)
{
	imageR = Image(header);
	imageG = Image(header);
	imageB = Image(header);
	for (int h = 0; h < header.height; h++)
		for (int w = 0; w < header.width; w++)
		{
			imageR.pixels[h][w].red = pixels[h][w].red;
			imageR.pixels[h][w].green = pixels[h][w].red;
			imageR.pixels[h][w].blue = pixels[h][w].red;

			imageG.pixels[h][w].red = pixels[h][w].green;
			imageG.pixels[h][w].green = pixels[h][w].green;
			imageG.pixels[h][w].blue = pixels[h][w].green;

			imageB.pixels[h][w].red = pixels[h][w].blue;
			imageB.pixels[h][w].green = pixels[h][w].blue;
			imageB.pixels[h][w].blue = pixels[h][w].blue;
		}
}

void Image::Rotate()
{
	Pixel temp;
	for (int h = 0; h < header.height/2; h++)
		for (int w = 0; w < header.width; w++)
		{
			temp = pixels[h][w];
			pixels[h][w] = pixels[header.height - h - 1][header.width - w - 1];
			pixels[header.height - h - 1][header.width - w - 1] = temp;
		}
}