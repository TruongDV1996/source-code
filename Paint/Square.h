#pragma once
#include "ShapeEx.h"
class Square:public CShapeEx
{
private:
	CPoint startPoint;
	CPoint endPoint;
public:
	Square();
	void setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen,int m_size);
	void Draw(CDC* pDC);
	void drawZoomOut(CDC *pDC);
	void drawZoomIn(CDC *pDC);
};

