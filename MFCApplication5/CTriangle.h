#pragma once
#include "Shape.h"
class CTriangle :
    public Shape
{
public:
	CTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color);
	~CTriangle();
	void fill_cells(Canvas* canvas);
	bool check_availability(Canvas* canvas);
	int x1() const { return m_x1; }
	int y1() const { return m_y1; }
	int x2() const { return m_x2; }
	int y2() const { return m_y2; }
	int x3() const { return m_x3; }
	int y3() const { return m_y3; }
private:
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
	int m_x3;
	int m_y3;
	std::pair<int, int> m_p1;
	std::pair<int, int> m_p2;
	std::pair<int, int> m_p3;
	void fillBottomFlatTriangle(Canvas* canvas, std::pair<int, int> v1, std::pair<int, int> v2, std::pair<int, int> v3);
	void fillTopFlatTriangle(Canvas* canvas, std::pair<int, int> v1, std::pair<int, int> v2, std::pair<int, int> v3);
	void drawline(Canvas* canvas, int x0, int x1, int y);
};

