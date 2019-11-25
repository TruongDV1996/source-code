#pragma once
#include"ShapeEx.h"
class Pen:public CShapeEx
{
public:
	Pen();
	void setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int m_size);
	void Draw(CDC* pDC);
};

