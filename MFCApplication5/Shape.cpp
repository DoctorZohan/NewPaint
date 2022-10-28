#include "pch.h"
#include "Shape.h"

Shape::Shape(int color, shape_type type)
:m_color(color),
m_shape_type(type)
{

}
Shape::~Shape()
{

}

void Shape::add_cell(int x, int y)
{
	cells.insert({ std::make_pair(x, y), m_color });
}
bool Shape::find_map(int x, int y)
{
	return (cells.find(std::make_pair(x, y)) != cells.end());
}