#pragma once

#include <vector>
#include <set>
#include "Shape.h"
#include "Canvas.h"

class Shape;

class CellElement
{
public:
	int m_color;
	bool m_selected;
	bool m_is_busy;
};


class Canvas
{
public:
	Canvas(int m, int n);
	~Canvas();
	bool addObject(Shape* obj);
	void removeObject(Shape* obj);
	void setBusy(int x, int y, int busy);
	int getBusy(int x, int y);
	void setColor(int x, int y, int color);
	int getColor(int x, int y);
	void setSelect(int x, int y, bool select);
	bool getSelect(int x, int y);
	void num_rows(int num_rows) { m_num_rows = num_rows; }
	int num_rows() const { return m_num_rows; }
	void num_columns(int num_columns) { m_num_columns = num_columns; }
	int num_columns() const { return m_num_columns; }
	void init_color(int init_color) { m_init_color = init_color; }
	int init_color() const { return m_init_color; }
	void cell_size(int cell_size) { m_cell_size = cell_size; }
	int cell_size() const { return m_cell_size; }
	bool redraw_canvas(int sizeX, int sizeY, int initColor);
	Shape* object;
	Shape* get_shape_with_current_point(int x, int y);
	void select_object(Shape* object, bool select);
	Shape* get_current_select_object();
private:
	std::vector< std::vector<CellElement> > m_map;
	std::set<Shape*> m_objects;
	int m_num_rows;
	int m_num_columns;
	int m_init_color;
	int m_cell_size;
};

