#pragma once

#include <vector>
#include "Zoom.h"

using namespace std;

class ZoomList
{
private:
	double m_xcenter{ 0 };
	double m_ycenter{ 0 };
	double m_scale{ 0 };

	int m_width{ 0 };
	int m_heigth{ 0 };
	vector<Zoom> zooms;

public:
	ZoomList(int width, int heigth);
	void Add(const Zoom& zoom);
	tuple<double, double> DoZoom(int x, int y)
	{
		return { static_cast<double>(x), static_cast<double>(y) };
	}
	~ZoomList();
};

