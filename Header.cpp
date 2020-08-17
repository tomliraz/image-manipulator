#pragma once
#include "Header.h"
#include <fstream>

void Header::PrintHeader()
{
	cout << "ID length: " << (short)idLength << endl;
	cout << "Color Map Type: " << (short)colorMapType << endl;
	cout << "Data type code: " << (short)dataTypeCode << endl;
	cout << "Color Map Origin: " << colorMapOrigin << endl;
	cout << "Color Map Length: " << colorMapLength << endl;
	cout << "Color Map Depth: " << colorMapDepth << endl;
	cout << "X Origin: " << xOrigin << endl;
	cout << "Y Origin: " << yOrigin << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << "Bits per pixel: " << (short)bitsPerPixel << endl;
	cout << "Image Descriptor: " << (short)imageDescriptor << endl;
}