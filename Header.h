#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Header
{
public:
	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;
	void PrintHeader();
};