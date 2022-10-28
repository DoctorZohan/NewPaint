#pragma once
#include "Shape.h"
class CRectangle :
    public Shape
{
public:
	CRectangle(int posX, int posY, int length, int width, int color);
	~CRectangle();
	void fill_cells(Canvas* canvas);
	bool check_availability(Canvas* canvas);
	int posX() const { return m_posX; }
	int posY() const { return m_posY; }
	int length() const { return m_length; }
	int width() const { return m_width; }
private:
	int m_posX;
	int m_posY;
	int m_length;
	int m_width;
};

