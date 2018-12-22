#pragma once
#include <iostream>
#include <cstdint>

#pragma pack (push,2)

struct BitmapInfoHeader
{
	int32_t headerSize{ 40 };
	int32_t width;
	int32_t heigth;
	int16_t planes{ 1 };
	int16_t bitsPerpixel{ 24 };
	int32_t compression{ 0 };
	int32_t dataSize{ 0 };
	int32_t HorizontalResolution{ 2400 };
	int32_t VerticalResolution{ 2400 };
	int32_t colors{ 0 };
	int32_t importantcolors{ 0 };
};

#pragma pack(pop)