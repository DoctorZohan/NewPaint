#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <array>
#include "Canvas.h"

enum shape_type {
	rectangle,
	circle,
	triangle
};

class Canvas;
using namespace std;
class Shape
{
    public:
	  Shape(int color, shape_type type);
	  ~Shape();
	  void color(int color) { m_color = color; }
	  void color(int red, int green, int blue) { m_color = (red * 65536) + (green * 256) + blue; }
	  int color() const { return m_color; }
	  virtual void fill_cells(Canvas* canvas) {};
	  virtual bool check_availability(Canvas* canvas) { return false; };
	  void add_cell(int x, int y);
	  bool find_map(int x, int y);
	  shape_type get_shape_type() const { return m_shape_type; }
	  std::map<std::pair<int, int>, int>* get_cells() { return &cells; }
	  void is_selected(int is_selected) { m_is_selected = is_selected; }
	  int is_selected() const { return m_is_selected; }
	private:
	  int m_color;
	  shape_type m_shape_type;
	  std::map<std::pair<int, int>, int> cells;
	  bool m_is_selected;
};

