#pragma once
#include "Shape.h"
class CCircle :
    public Shape
{
public:
	CCircle(int posX, int posY, int radious, int color);
	~CCircle();
	void fill_cells(Canvas* canvas);
	bool check_availability(Canvas* canvas);
	int posX() const { return m_posX; }
	int posY() const { return m_posY; }
	int radious() const { return m_radious; }
private:
	int m_posX;
	int m_posY;
	int m_radious;
	void drawCircle(Canvas* canvas, int xc, int yc, int x, int y);
	void circleBres(Canvas* canvas, int xc, int yc, int r);
};

