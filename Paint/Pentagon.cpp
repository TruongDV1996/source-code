#include "stdafx.h"
#include "Pentagon.h"


Pentagon::Pentagon()
{
}
void Pentagon::setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int m_size)
{
	this->m_Start = m_start;
	this->m_End = m_end;
	this->m_BrushColor = m_brush;
	this->m_nPenStype = m_pen;
	this->m_nPenWidth = m_size;
	this->m_Type = PENTAGON;
}

void Pentagon::Draw(CDC * pDC)
{

	CPoint TPoint[5];
	switch (m_rotatetype)
	{
	case (TOP) :
	{
		TPoint[0].SetPoint(m_Start.x, (m_Start.y + m_End.y) / 2);
		TPoint[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y);
		TPoint[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y);
		TPoint[3].SetPoint(m_End.x, (m_Start.y + m_End.y) / 2);
		TPoint[4].SetPoint((m_End.x + m_Start.x) / 2, m_Start.y);
		pDC->Polygon(TPoint, 5);
		break;
	}
	case (RIGHT) :
	{
		TPoint[0].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y);
		TPoint[1].SetPoint(m_Start.x, (3 * m_Start.y + m_End.y) / 4);
		TPoint[2].SetPoint(m_Start.x, (m_Start.y + 3 * m_End.y) / 4);
		TPoint[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y);
		TPoint[4].SetPoint(m_End.x, (m_End.y + m_Start.y) / 2);
		pDC->Polygon(TPoint, 5);
		break;
	}
	case (BOTTOM) :
	{
		TPoint[0].SetPoint(m_Start.x, (m_Start.y + m_End.y) / 2);
		TPoint[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_Start.y);
		TPoint[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_Start.y);
		TPoint[3].SetPoint(m_End.x, (m_Start.y + m_End.y) / 2);
		TPoint[4].SetPoint((m_End.x + m_Start.x) / 2, m_End.y);
		pDC->Polygon(TPoint, 5);
		break;
	}
	case (LEFT) :
	{
		TPoint[0].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y);
		TPoint[1].SetPoint(m_End.x, (3 * m_Start.y + m_End.y) / 4);
		TPoint[2].SetPoint(m_End.x, (m_Start.y + 3 * m_End.y) / 4);
		TPoint[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y);
		TPoint[4].SetPoint(m_Start.x, (m_End.y + m_Start.y) / 2);
		pDC->Polygon(TPoint, 5);
		break;
	}
	}
}
void Pentagon::drawZoomOut(CDC * pDC)
{
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y)
	{
		penPoints[0].SetPoint(m_Start.x-50, (m_Start.y + m_End.y) / 2);
		penPoints[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y+50);
		penPoints[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y+50);
		penPoints[3].SetPoint(m_End.x+50, (m_Start.y + m_End.y) / 2);
		penPoints[4].SetPoint((m_End.x + m_Start.x) / 2, m_Start.y-50);
		pDC->Polygon(penPoints, 5);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		penPoints[0].SetPoint(m_Start.x - 50, (m_Start.y + m_End.y) / 2);
		penPoints[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y - 50);
		penPoints[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y - 50);
		penPoints[3].SetPoint(m_End.x + 50, (m_Start.y + m_End.y) / 2);
		penPoints[4].SetPoint((m_End.x + m_Start.x) / 2, m_Start.y +50);
		pDC->Polygon(penPoints, 5);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		penPoints[0].SetPoint(m_Start.x + 50, (m_Start.y + m_End.y) / 2);
		penPoints[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y - 50);
		penPoints[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y - 50);
		penPoints[3].SetPoint(m_End.x - 50, (m_Start.y + m_End.y) / 2);
		penPoints[4].SetPoint((m_End.x + m_Start.x) / 2, m_Start.y + 50);
		pDC->Polygon(penPoints, 5);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		penPoints[0].SetPoint(m_Start.x + 50, (m_Start.y + m_End.y) / 2);
		penPoints[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y + 50);
		penPoints[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y + 50);
		penPoints[3].SetPoint(m_End.x - 50, (m_Start.y + m_End.y) / 2);
		penPoints[4].SetPoint((m_End.x + m_Start.x) / 2, m_Start.y - 50);
		pDC->Polygon(penPoints, 5);
	}
}
void Pentagon::drawZoomIn(CDC *pDC)
{
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		penPoints[0].SetPoint(m_Start.x + 50, (m_Start.y + m_End.y) / 2);
		penPoints[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y - 50);
		penPoints[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y - 50);
		penPoints[3].SetPoint(m_End.x - 50, (m_Start.y + m_End.y) / 2);
		penPoints[4].SetPoint((m_End.x + m_Start.x) / 2, m_Start.y + 50);
		pDC->Polygon(penPoints, 5);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		penPoints[0].SetPoint(m_Start.x + 50, (m_Start.y + m_End.y) / 2);
		penPoints[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y + 50);
		penPoints[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y + 50);
		penPoints[3].SetPoint(m_End.x - 50, (m_Start.y + m_End.y) / 2);
		penPoints[4].SetPoint((m_End.x + m_Start.x) / 2, m_Start.y - 50);
		pDC->Polygon(penPoints, 5);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		penPoints[0].SetPoint(m_Start.x - 50, (m_Start.y + m_End.y) / 2);
		penPoints[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y + 50);
		penPoints[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y + 50);
		penPoints[3].SetPoint(m_End.x + 50, (m_Start.y + m_End.y) / 2);
		penPoints[4].SetPoint((m_End.x + m_Start.x) / 2, m_Start.y - 50);
		pDC->Polygon(penPoints, 5);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		penPoints[0].SetPoint(m_Start.x - 50, (m_Start.y + m_End.y) / 2);
		penPoints[1].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y - 50);
		penPoints[2].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y - 50);
		penPoints[3].SetPoint(m_End.x + 50, (m_Start.y + m_End.y) / 2);
		penPoints[4].SetPoint((m_End.x + m_Start.x) / 2, m_Start.y + 50);
		pDC->Polygon(penPoints, 5);
	}
}


