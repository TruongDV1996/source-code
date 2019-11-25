#pragma once
#include"ShapeEx.h"
class Pentagon:public CShapeEx
{
private:
	CPoint penPoints[5];
public:
	Pentagon();
	void setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int  m_size);
	void Draw(CDC* pDC);
	void drawZoomOut(CDC *pDC);
	void drawZoomIn(CDC *pDC);
};

