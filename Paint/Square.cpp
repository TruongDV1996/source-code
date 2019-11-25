#include "stdafx.h"
#include "Square.h"

Square::Square()
{
}

void Square::setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen,int m_size)
{
	if (m_start.x < m_end.x&&m_start.y < m_end.y) {
		this->m_Start = m_start;
		this->m_End.x = m_end.x;
		this->m_End.y = m_Start.y + (m_End.x - m_Start.x);
	}
	// duoi len trai phai
	if (m_start.x < m_end.x&&m_start.y > m_end.y) {
		this->m_Start = m_start;
		this->m_End.y = m_end.y;
		this->m_End.x = m_Start.x + (m_Start.y - m_End.y);
	}
	//tren xuong phai trai
	if (m_start.x > m_end.x&&m_start.y < m_end.y) {
		this->m_Start = m_start;
		this->m_End.y = m_end.y;
		this->m_End.x = m_Start.x - (m_End.y - m_Start.y);
	}
	// duoi len phai trai
	if (m_start.x > m_end.x&&m_start.y > m_end.y) {
		this->m_Start = m_start;
		this->m_End.y = m_end.y;
		this->m_End.x = m_Start.x - (m_Start.y - m_End.y);
	}
	this->m_BrushColor = m_brush;
	this->m_nPenStype = m_pen;
	this->m_nPenWidth = m_size;
	this->m_Type = SQUARE;
}

void Square::Draw(CDC * pDC)
{
	pDC->Rectangle(m_Start.x, m_Start.y, m_End.x, m_End.y);
}

void Square::drawZoomOut(CDC * pDC)
{
	startPoint = getStart();
	endPoint = getEnd();
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		pDC->Rectangle(startPoint.x - 50, startPoint.y - 50, endPoint.x + 50, endPoint.y + 50);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		pDC->Rectangle(startPoint.x - 50, startPoint.y + 50, endPoint.x + 50, endPoint.y - 50);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		pDC->Rectangle(startPoint.x + 50, startPoint.y + 50, endPoint.x - 50, endPoint.y - 50);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		pDC->Rectangle(startPoint.x + 50, startPoint.y - 50, endPoint.x - 50, endPoint.y + 50);
	}
}
void Square::drawZoomIn(CDC *pDC)
{
	startPoint = getStart();
	endPoint = getEnd();
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		pDC->Rectangle(startPoint.x + 50, startPoint.y + 50, endPoint.x - 50, endPoint.y - 50);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		pDC->Rectangle(startPoint.x + 50, startPoint.y - 50, endPoint.x - 50, endPoint.y + 50);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		pDC->Rectangle(startPoint.x - 50, startPoint.y - 50, endPoint.x + 50, endPoint.y + 50);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		pDC->Rectangle(startPoint.x - 50, startPoint.y + 50, endPoint.x + 50, endPoint.y - 50);
	}
}



