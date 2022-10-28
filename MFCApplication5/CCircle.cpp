#define _USE_MATH_DEFINES

#include "pch.h"
#include "CCircle.h"
#include <cmath>
using namespace std;


CCircle::CCircle(int posX, int posY, int radius, int color)
	:Shape(color, shape_type::circle),
	m_posX(posX),
	m_posY(posY),
	m_radius(radius)
{

}
CCircle::~CCircle()
{

}

bool CCircle::check_availability(Canvas* canvas)
{
	if ((m_posX - m_radius < 0)||
		(m_posY - m_radius < 0)||
        (m_posX + m_radius > canvas->num_columns())||
        (m_posY + m_radius > canvas->num_rows()))
		return false;
	return true;
}

void CCircle::drawCircle(Canvas* canvas, int xc, int yc, int x, int y)
{

	for (int i = -x + xc; i < x + xc; i++)
		{
			if (i > 0)
			{
				add_cell(i, y + yc);
				add_cell(i, -y + yc);
			}
		}
	for (int i = -y + xc; i < y + xc; i++)
	{
		if (i > 0)
		{
			add_cell(i, x + yc);
			add_cell(i, -x + yc);
		}
	}
}

// Function for circle-generation
// using Bresenham's algorithm
void CCircle::circleBres(Canvas* canvas,int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;
	drawCircle(canvas, xc, yc, x, y);
	while (y >= x)
	{
		// for each pixel we will
		// draw all eight pixels

		x++;

		// check for decision parameter
		// and correspondingly
		// update d, x, y
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(canvas, xc, yc, x, y);
	}
}

void CCircle::fill_cells(Canvas* canvas)
{
   circleBres(canvas, m_posX, m_posY, m_radius);
}