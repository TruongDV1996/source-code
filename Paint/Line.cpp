#include "stdafx.h"
#include "Line.h"

Line::Line()
{
}

void Line::setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int m_size)
{
	this->m_Start = m_start;
	this->m_End = m_end;
	this->m_BrushColor = m_brush;
	this->m_nPenStype = m_pen;
	this->m_nPenWidth = m_size;
	this->m_Type = LINE;
}

void Line::Draw(CDC * pDC)
{
	switch (m_rotatetype)
	{
		case TOP:
		{
			pDC->MoveTo(m_Start);
			pDC->LineTo(m_End);
			break;
		}
		case RIGHT:
		{
			pDC->MoveTo(m_End.x, m_Start.y);
			pDC->LineTo(m_Start.x, m_End.y);
			break;
		}
		case BOTTOM:
		{
			pDC->MoveTo(m_Start);
			pDC->LineTo(m_End);
			break;
		}
		case LEFT:
		{
			pDC->MoveTo(m_End.x, m_Start.y);
			pDC->LineTo(m_Start.x, m_End.y);
			break;
		}
	}
}
void Line::drawZoomOut(CDC * pDC)
{
	startPoint = getStart();
	endPoint = getEnd();
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		pDC->MoveTo(startPoint.x-50, startPoint.y-50);
		pDC->LineTo(endPoint.x+50, endPoint.y+50);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		pDC->MoveTo(startPoint.x - 50, startPoint.y + 50);
		pDC->LineTo(endPoint.x + 50, endPoint.y - 50);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		pDC->MoveTo(startPoint.x + 50, startPoint.y + 50);
		pDC->LineTo(endPoint.x - 50, endPoint.y - 50);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		pDC->MoveTo(startPoint.x + 50, startPoint.y - 50);
		pDC->LineTo(endPoint.x - 50, endPoint.y + 50);
	}
}
void Line::drawZoomIn(CDC *pDC)
{
	startPoint = getStart();
	endPoint = getEnd();
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		pDC->MoveTo(startPoint.x + 50, startPoint.y + 50);
		pDC->LineTo(endPoint.x - 50, endPoint.y - 50);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		pDC->MoveTo(startPoint.x + 50, startPoint.y - 50);
		pDC->LineTo(endPoint.x - 50, endPoint.y + 50);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		pDC->MoveTo(startPoint.x - 50, startPoint.y - 50);
		pDC->LineTo(endPoint.x + 50, endPoint.y + 50);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		pDC->MoveTo(startPoint.x - 50, startPoint.y + 50);
		pDC->LineTo(endPoint.x + 50, endPoint.y - 50);
	}
}
