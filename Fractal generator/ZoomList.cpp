#include "ZoomList.h"




ZoomList::ZoomList(int width, int heigth) : m_width(width), m_heigth(heigth)
{
}

void ZoomList::Add(const Zoom & zoom)
{
	zooms.push_back(zoom);
	m_xcenter += (zoom.x - m_width / 2)*m_scale;
	m_ycenter += (zoom.y - m_heigth / 2)*m_scale;
}

ZoomList::~ZoomList()
{
}
