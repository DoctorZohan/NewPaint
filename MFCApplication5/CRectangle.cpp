#include "pch.h"
#include "CRectangle.h"

CRectangle::CRectangle(int posX, int posY, int length, int width, int color)
:Shape(color, shape_type::rectangle),
m_posX(posX),
m_posY(posY),
m_length(length),
m_width(width)
{

}
CRectangle::~CRectangle()
{

}

bool CRectangle::check_availability(Canvas* canvas)
{
	if (m_posX < 0)
		return false;
	if (m_posY < 0)
		return false;
	if (m_posX + m_length < 0)
		return false;
	if (m_posY + m_width < 0)
		return false;
	if (m_posX + m_length > canvas->num_columns())
		return false;
	if (m_posY + m_width > canvas->num_rows())
		return false;
	for (int i = m_posX; i < m_posX + m_length; i++)
		for (int j = m_posY; j < m_posY + m_width; j++)
		{
			if (canvas->getColor(i, j) != canvas->init_color())
				return false;
		}
	return true;
}

void CRectangle::fill_cells(Canvas* canvas)
{
	for (int i = m_posX; i <  m_posX + m_length; i++)
		for (int j = m_posY; j < m_posY + m_width; j++)
		{
			//canvas->setColor(i, j, color());
			add_cell(i, j);
		}
}