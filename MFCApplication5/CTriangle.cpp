#include "pch.h"
#include "CTriangle.h"

CTriangle::CTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color)
	:Shape(color, shape_type::triangle),
	m_x1(x1),
	m_y1(y1),
	m_x2(x2),
	m_y2(y2),
	m_x3(x3),
	m_y3(y3),
	m_p1 (x1,y1),
	m_p2 (x2, y2),
	m_p3 (x3, y3)
{
	if (m_p1.second > m_p3.second)
		std::swap(m_p1, m_p3);
	if (m_p1.second > m_p2.second)
		std::swap(m_p1, m_p2);
	if (m_p2.second > m_p3.second)
		std::swap(m_p2, m_p3);
}
CTriangle::~CTriangle()
{

}

bool CTriangle::check_availability(Canvas* canvas)
{
	if (m_x1 < 0 || m_x1 > canvas->num_columns())
		return false;
	if (m_x2 < 0 || m_x2 > canvas->num_columns())
		return false;
	if (m_x3 < 0 || m_x3 > canvas->num_columns())
		return false;
	if (m_y1 < 0 || m_y1 > canvas->num_rows())
		return false;
	if (m_y2 < 0 || m_y2 > canvas->num_rows())
		return false;
	if (m_y3 < 0 || m_y3 > canvas->num_rows())
		return false;
	return true;
}


void CTriangle::drawline(Canvas* canvas, int x0, int x1, int y)
{
	if (x0 > x1)
	{
		std::swap(x0, x1);
	}
	for (int x = x0; x <= x1; x++)
	{
		add_cell(x, y);
	}
}

void CTriangle::fillBottomFlatTriangle(Canvas* canvas, std::pair<int, int> v1, std::pair<int, int> v2, std::pair<int, int> v3)
{
	double invslope1 = (double)(v2.first - v1.first) / (v2.second - v1.second);
	double invslope2 = (double)(v3.first - v1.first) / (v3.second - v1.second);

	double curx1 = v1.first;
	double curx2 = v1.first;

	for (int scanlineY = v1.second; scanlineY <= v2.second; scanlineY++)
	{
		drawline(canvas, round(curx1), round(curx2), scanlineY);
		curx1 += invslope1;
		curx2 += invslope2;
	}
}

void CTriangle::fillTopFlatTriangle(Canvas* canvas, std::pair<int, int> v1, std::pair<int, int> v2, std::pair<int, int> v3)
{
	double invslope1 = (double)(v3.first - v1.first) / (v3.second - v1.second);
	double invslope2 = (double)(v3.first - v2.first) / (v3.second - v2.second);

	double curx1 = v3.first;
	double curx2 = v3.first;

	for (int scanlineY = v3.second; scanlineY > v1.second; scanlineY--)
	{
		drawline(canvas, round(curx1), round(curx2), scanlineY);
		curx1 -= invslope1;
		curx2 -= invslope2;
	}
}

void CTriangle::fill_cells(Canvas* canvas)
{
	if (m_p2.second == m_p3.second)
	{
		fillBottomFlatTriangle(canvas, m_p1, m_p2, m_p3);
	}
	/* check for trivial case of top-flat triangle */
	else if (m_p1.second == m_p2.second)
	{
		fillTopFlatTriangle(canvas, m_p1, m_p2, m_p3);
	}
	else
	{
		/* general case - split the triangle in a topflat and bottom-flat one */
		std::pair<int, int>  m_p4(round(m_p1.first + ((float)(m_p2.second - m_p1.second) / (float)(m_p3.second - m_p1.second)) * (m_p3.first - m_p1.first)), m_p2.second);
		fillBottomFlatTriangle(canvas, m_p1, m_p2, m_p4);
		fillTopFlatTriangle(canvas, m_p2, m_p4, m_p3);
	}
}