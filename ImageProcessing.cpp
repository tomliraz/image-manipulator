#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include "Header.h"
#include "Pixel.h"
#include "Image.h"

using namespace std;
void readImage(string filePath, Image &image);
void writeImage(string filePath, Image &image);
Image Multiply(Image &image1, Image &image2);
Image Subtract(Image &image1, Image &image2);
Image Screen(Image image1, Image image2);
bool isSameImage(Image &image1, Image &image2);
Image Overlay(Image image1, Image image2);
Image Merge(Image& imageR, Image& imageG, Image& imageB);
int main()
{
		//part 1
		Image pattern1;
		Image layer1;
		readImage("./input/pattern1.tga", pattern1);
		readImage("./input/layer1.tga", layer1);
		Image part1 = Multiply(pattern1, layer1);

		//part 2
		Image car;
		Image layer2;
		readImage("./input/car.tga", car);
		readImage("./input/layer2.tga", layer2);
		Image part2 = Subtract(car, layer2);

		//part 3
		Image pattern2;
		readImage("./input/pattern2.tga", pattern2);
		Image text;
		readImage("./input/text.tga", text);
		Image part3temp = Multiply(pattern2, layer1);
		Image part3 = Screen(part3temp, text);

		//part 4
		Image circles;
		readImage("./input/circles.tga", circles);
		Image part4temp = Multiply(circles, layer2);
		Image part4 = Subtract(part4temp, pattern2);
		
		//part 5
		Image part5 = Overlay(pattern1, layer1);

		//part 6
		Image part6 = car;
		part6.ChangeGreen(200);

		//part7
		Image part7 = car;
		part7.MultiplyRed(4);
		part7.MultiplyBlue(0);

		//part 8
		Image part8temp = car;
		Image part8_r;
		Image part8_g;
		Image part8_b;
		part8temp.Split(part8_r, part8_g, part8_b);

		//part9
		Image layer_red;
		Image layer_green;
		Image layer_blue;
		readImage("./input/layer_red.tga", layer_red);
		readImage("./input/layer_green.tga", layer_green);
		readImage("./input/layer_blue.tga", layer_blue);
		Image part9 = Merge(layer_red, layer_green, layer_blue);

		//part10
		Image text2;
		readImage("./input/text2.tga", text2);
		Image part10 = text2;
		part10.Rotate();

		writeImage("./output/part1.tga", part1);
		writeImage("./output/part2.tga", part2);
		writeImage("./output/part3.tga", part3);
		writeImage("./output/part4.tga", part4);
		writeImage("./output/part5.tga", part5);
		writeImage("./output/part6.tga", part6);
		writeImage("./output/part7.tga", part7);
		writeImage("./output/part8_r.tga", part8_r);
		writeImage("./output/part8_g.tga", part8_g);
		writeImage("./output/part8_b.tga", part8_b);
		writeImage("./output/part9.tga", part9);
		writeImage("./output/part10.tga", part10);

	return 0;
}

Image Overlay(Image image1, Image image2)
{
	Image result(image1.header);
	float color1 = 0;
	float color2 = 0;
	for (int h = 0; h < image1.header.height; h++)
	{
		for (int w = 0; w < image1.header.width; w++)
		{
			color1 = ((float)image1.pixels[h][w].red) / 255;
			color2 = ((float)image2.pixels[h][w].red) / 255;
			if(color1 <= 0.5f)
				result.pixels[h][w].red = (unsigned char)(2 * color1 * color2 * 255 + 0.5f);
			else
				result.pixels[h][w].red = (unsigned char)((1 - 2 * (1 - color1) * (1 - color2)) * 255 + 0.5f);

			color1 = ((float)image1.pixels[h][w].green) / 255;
			color2 = ((float)image2.pixels[h][w].green) / 255;
			if (color1 <= 0.5f)
				result.pixels[h][w].green = (unsigned char)(2 * color1 * color2 * 255 + 0.5f);
			else
				result.pixels[h][w].green = (unsigned char)((1 - 2 * (1 - color1) * (1 - color2)) * 255 + 0.5f);

			color1 = ((float)image1.pixels[h][w].blue) / 255;
			color2 = ((float)image2.pixels[h][w].blue) / 255;
			if (color1 <= 0.5f)
				result.pixels[h][w].blue = (unsigned char)(2 * color1 * color2 * 255 + 0.5f);
			else
				result.pixels[h][w].blue = (unsigned char)((1 - 2 * (1 - color1) * (1 - color2)) * 255 + 0.5f);

		}
	}
	return result;
}
Image Screen(Image image1, Image image2)
{
	Image result(image1.header);
	float color1 = 0;
	float color2 = 0;
	for (int h = 0; h < image1.header.height; h++)
	{
		for (int w = 0; w < image1.header.width; w++)
		{
			color1 = ((float)image1.pixels[h][w].red) / 255;
			color2 = ((float)image2.pixels[h][w].red) / 255;
			result.pixels[h][w].red = (unsigned char)((1-(1-color1) * (1-color2)) * 255 + 0.5f);

			color1 = ((float)image1.pixels[h][w].green) / 255;
			color2 = ((float)image2.pixels[h][w].green) / 255;
			result.pixels[h][w].green = (unsigned char)((1 - (1 - color1) * (1 - color2)) * 255 + 0.5f);

			color1 = ((float)image1.pixels[h][w].blue) / 255;
			color2 = ((float)image2.pixels[h][w].blue) / 255;
			result.pixels[h][w].blue = (unsigned char)((1 - (1 - color1) * (1 - color2)) * 255 + 0.5f);

		}
	}
	return result;
}

Image Multiply(Image &image1, Image &image2)
{
	Image result(image1.header);
	float color1 = 0;
	float color2 = 0;
	for (int h = 0; h < image1.header.height; h++)
	{
		for (int w = 0; w < image1.header.width; w++)
		{
			color1 = ((float)image1.pixels[h][w].red) / 255;
			color2 = ((float)image2.pixels[h][w].red) / 255;
			result.pixels[h][w].red = (unsigned char)(color1 * color2 * 255 + 0.5f);
			color1 = ((float)image1.pixels[h][w].green) / 255;
			color2 = ((float)image2.pixels[h][w].green) / 255;
			result.pixels[h][w].green = (unsigned char)(color1 * color2 * 255 + 0.5f);
			color1 = ((float)image1.pixels[h][w].blue) / 255;
			color2 = ((float)image2.pixels[h][w].blue) / 255;
			result.pixels[h][w].blue = (unsigned char)(color1 * color2 * 255 + 0.5f);
		}
	}
	return result;
}


Image Subtract(Image &image1, Image &image2)
{
	Image result(image1.header);
	float color1 = 0;
	float color2 = 0;
	float color3 = 0;
	for (int h = 0; h < image1.header.height; h++)
	{
		for (int w = 0; w < image1.header.width; w++)
		{
			color1 = ((float)image1.pixels[h][w].red);
			color2 = ((float)image2.pixels[h][w].red);
			color3 = color1 - color2;
			if (color3 > 255)
			{
				color3 = 255;
			}
			else if (color3 < 0)
			{
				color3 = 0;
			}
			result.pixels[h][w].red = (unsigned char)color3;

			color1 = ((float)image1.pixels[h][w].green);
			color2 = ((float)image2.pixels[h][w].green);
			color3 = color1 - color2;
			if (color3 > 255)
			{
				color3 = 255;
			}
			else if (color3 < 0)
			{
				color3 = 0;
			}
			result.pixels[h][w].green = (unsigned char)color3;

			color1 = ((float)image1.pixels[h][w].blue);
			color2 = ((float)image2.pixels[h][w].blue);
			color3 = color1 - color2;
			if (color3 > 255)
			{
				color3 = 255;
			}
			else if (color3 < 0)
			{
				color3 = 0;
			}
			result.pixels[h][w].blue = (unsigned char)color3;
		}
	}
	return result;
}




void writeImage(string filePath, Image &image)
{
	ofstream outFile(filePath, ios_base::binary);

	if (outFile.is_open())
	{
		outFile.write(&image.header.idLength, sizeof(image.header.idLength));

		outFile.write(&image.header.colorMapType, sizeof(image.header.colorMapType));

		outFile.write(&image.header.dataTypeCode, sizeof(image.header.dataTypeCode));

		outFile.write((char*)&image.header.colorMapOrigin, sizeof(image.header.colorMapOrigin));

		outFile.write((char*)&image.header.colorMapLength, sizeof(image.header.colorMapLength));

		outFile.write(&image.header.colorMapDepth, sizeof(image.header.colorMapDepth));

		outFile.write((char*)&image.header.xOrigin, sizeof(image.header.xOrigin));

		outFile.write((char*)&image.header.yOrigin, sizeof(image.header.yOrigin));

		outFile.write((char*)&image.header.width, sizeof(image.header.width));

		outFile.write((char*)&image.header.height, sizeof(image.header.height));

		outFile.write(&image.header.bitsPerPixel, sizeof(image.header.bitsPerPixel));

		outFile.write(&image.header.imageDescriptor, sizeof(image.header.imageDescriptor));

		for (int h = 0; h < image.header.height; h++)
		{
			for (int w = 0; w < image.header.width; w++)
			{
				outFile.write((char*)&image.pixels[h][w].blue, sizeof(image.pixels[h][w]).blue);
				outFile.write((char*)&image.pixels[h][w].green, sizeof(image.pixels[h][w]).green);
				outFile.write((char*)&image.pixels[h][w].red, sizeof(image.pixels[h][w]).red);
			}
		}
	}
}
void readImage(string filePath, Image &image)
{
	ifstream file(filePath, ios_base::binary);
	file.read(&image.header.idLength, sizeof(image.header.idLength));

	file.read(&image.header.colorMapType, sizeof(image.header.colorMapType));

	file.read(&image.header.dataTypeCode, sizeof(image.header.dataTypeCode));

	file.read((char*)&image.header.colorMapOrigin, sizeof(image.header.colorMapOrigin));

	file.read((char*)&image.header.colorMapLength, sizeof(image.header.colorMapLength));

	file.read(&image.header.colorMapDepth, sizeof(image.header.colorMapDepth));

	file.read((char*)&image.header.xOrigin, sizeof(image.header.xOrigin));

	file.read((char*)&image.header.yOrigin, sizeof(image.header.yOrigin));

	file.read((char*)&image.header.width, sizeof(image.header.width));

	file.read((char*)&image.header.height, sizeof(image.header.height));

	file.read(&image.header.bitsPerPixel, sizeof(image.header.bitsPerPixel));

	file.read(&image.header.imageDescriptor, sizeof(image.header.imageDescriptor));

	image.pixels = new Pixel *[image.header.height];
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	for (int h = 0; h < image.header.height; h++)
	{
		image.pixels[h] = new Pixel[image.header.width];
		for (int w = 0; w < image.header.width; w++)
		{
			file.read((char*)&blue, sizeof(blue));
			file.read((char*)&green, sizeof(blue));
			file.read((char*)&red, sizeof(blue));
			image.pixels[h][w] = Pixel(red, green, blue);
		}
	}
}

bool isSameImage(Image &image1, Image &image2)
{
	if (
		image1.header.idLength != image2.header.idLength ||
		image1.header.colorMapType != image2.header.colorMapType ||
		image1.header.dataTypeCode != image2.header.dataTypeCode ||
		image1.header.colorMapOrigin != image2.header.colorMapOrigin ||
		image1.header.colorMapLength != image2.header.colorMapLength ||
		image1.header.colorMapDepth != image2.header.colorMapDepth ||
		image1.header.xOrigin != image2.header.xOrigin ||
		image1.header.yOrigin != image2.header.yOrigin ||
		image1.header.width != image2.header.width ||
		image1.header.height != image2.header.height ||
		image1.header.bitsPerPixel != image2.header.bitsPerPixel ||
		image1.header.imageDescriptor != image2.header.imageDescriptor
		)
	{
		return false;
	}
	for (int h = 0; h < image1.header.height; h++)
	{
		for (int w = 0; w < image1.header.width; w++)
		{
			if (image1.pixels[h][w].red != image2.pixels[h][w].red)
			{
				return false;
			}
			if (image1.pixels[h][w].blue != image2.pixels[h][w].blue)
			{
				return false;
			}
			if (image1.pixels[h][w].green != image2.pixels[h][w].green)
			{
				return false;
			}
		}
	}
	return true;
}

Image Merge(Image& imageR, Image& imageG, Image& imageB)
{
	Image image = Image(imageR.header);
	 float redChannel = 0;
	float greenChannel = 0;
	float blueChannel = 0;
	for (int h = 0; h < image.header.height; h++)
		for (int w = 0; w < image.header.width; w++)
		{
			redChannel = (float)imageR.pixels[h][w].red;
			redChannel += (float)imageR.pixels[h][w].green;
			redChannel += (float)imageR.pixels[h][w].blue;

			greenChannel = (float)imageG.pixels[h][w].red;
			greenChannel += (float)imageG.pixels[h][w].green;
			greenChannel += (float)imageG.pixels[h][w].blue;

			blueChannel = (float)imageB.pixels[h][w].red;
			blueChannel += (float)imageB.pixels[h][w].green;
			blueChannel += (float)imageB.pixels[h][w].blue;

			image.pixels[h][w].red = (unsigned char)(redChannel / 3 + 0.5f);
			image.pixels[h][w].green = (unsigned char)(greenChannel / 3 + 0.5f);
			image.pixels[h][w].blue = (unsigned char)(blueChannel / 3 + 0.5f);
		}
	return image;
}