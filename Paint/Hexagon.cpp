#include "stdafx.h"
#include "Hexagon.h"


Hexagon::Hexagon()
{
}


void Hexagon::setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int m_size)
{
	this->m_Start = m_start;
	this->m_End = m_end;
	this->m_BrushColor = m_brush;
	this->m_nPenStype = m_pen;
	this->m_Type = HEXAGON;
	this->m_nPenWidth = m_size;
}

void Hexagon::Draw(CDC * pDC)
{
	CPoint hexagonalPoints[6];
	switch (m_rotatetype)
	{
	case (TOP) :
	{
		hexagonalPoints[0].SetPoint(m_Start.x, (3 * m_End.y + m_Start.y) / 4);
		hexagonalPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y);
		hexagonalPoints[2].SetPoint(m_End.x, (3 * m_End.y + m_Start.y) / 4);
		hexagonalPoints[3].SetPoint(m_End.x, (3 * m_Start.y + m_End.y) / 4);
		hexagonalPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y);
		hexagonalPoints[5].SetPoint(m_Start.x, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexagonalPoints, 6);
		break;
	}
	case (RIGHT) :
	{
		hexagonalPoints[0].SetPoint((3 * m_Start.x + m_End.x) / 4, m_Start.y);
		hexagonalPoints[1].SetPoint(m_Start.x, (m_End.y + m_Start.y) / 2);
		hexagonalPoints[2].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y);
		hexagonalPoints[3].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y);
		hexagonalPoints[4].SetPoint(m_End.x, (m_End.y + m_Start.y) / 2);
		hexagonalPoints[5].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_Start.y);
		pDC->Polygon(hexagonalPoints, 6);
		break;
	}
	case (BOTTOM) :
	{

		hexagonalPoints[0].SetPoint(m_Start.x, (3 * m_End.y + m_Start.y) / 4);
		hexagonalPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y);
		hexagonalPoints[2].SetPoint(m_End.x, (3 * m_End.y + m_Start.y) / 4);
		hexagonalPoints[3].SetPoint(m_End.x, (3 * m_Start.y + m_End.y) / 4);
		hexagonalPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y);
		hexagonalPoints[5].SetPoint(m_Start.x, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexagonalPoints, 6);
		break;
	}
	case (LEFT) :
	{
		hexagonalPoints[0].SetPoint((3 * m_Start.x + m_End.x) / 4, m_Start.y);
		hexagonalPoints[1].SetPoint(m_Start.x, (m_End.y + m_Start.y) / 2);
		hexagonalPoints[2].SetPoint((3 * m_Start.x + m_End.x) / 4, m_End.y);
		hexagonalPoints[3].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_End.y);
		hexagonalPoints[4].SetPoint(m_End.x, (m_End.y + m_Start.y) / 2);
		hexagonalPoints[5].SetPoint((m_Start.x + 3 * m_End.x) / 4, m_Start.y);
		pDC->Polygon(hexagonalPoints, 6);
		break;
	}
	}
}
void Hexagon::drawZoomOut(CDC * pDC)
{
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		hexPoints[0].SetPoint(m_Start.x-50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y+50);
		hexPoints[2].SetPoint(m_End.x+50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[3].SetPoint(m_End.x+50, (3 * m_Start.y + m_End.y) / 4);
		hexPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y-50);
		hexPoints[5].SetPoint(m_Start.x-50, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexPoints, 6);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		hexPoints[0].SetPoint(m_Start.x - 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y - 50);
		hexPoints[2].SetPoint(m_End.x + 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[3].SetPoint(m_End.x + 50, (3 * m_Start.y + m_End.y) / 4);
		hexPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		hexPoints[5].SetPoint(m_Start.x - 50, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexPoints, 6);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		hexPoints[0].SetPoint(m_Start.x + 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y - 50);
		hexPoints[2].SetPoint(m_End.x - 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[3].SetPoint(m_End.x - 50, (3 * m_Start.y + m_End.y) / 4);
		hexPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		hexPoints[5].SetPoint(m_Start.x + 50, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexPoints, 6);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		hexPoints[0].SetPoint(m_Start.x + 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y + 50);
		hexPoints[2].SetPoint(m_End.x - 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[3].SetPoint(m_End.x - 50, (3 * m_Start.y + m_End.y) / 4);
		hexPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y - 50);
		hexPoints[5].SetPoint(m_Start.x + 50, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexPoints, 6);
	}
}
void Hexagon::drawZoomIn(CDC *pDC)
{
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		hexPoints[0].SetPoint(m_Start.x + 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y - 50);
		hexPoints[2].SetPoint(m_End.x - 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[3].SetPoint(m_End.x - 50, (3 * m_Start.y + m_End.y) / 4);
		hexPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		hexPoints[5].SetPoint(m_Start.x + 50, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexPoints, 6);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		hexPoints[0].SetPoint(m_Start.x + 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y - 50);
		hexPoints[2].SetPoint(m_End.x - 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[3].SetPoint(m_End.x - 50, (3 * m_Start.y + m_End.y) / 4);
		hexPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		hexPoints[5].SetPoint(m_Start.x + 50, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexPoints, 6);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		hexPoints[0].SetPoint(m_Start.x + 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y - 50);
		hexPoints[2].SetPoint(m_End.x - 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[3].SetPoint(m_End.x - 50, (3 * m_Start.y + m_End.y) / 4);
		hexPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		hexPoints[5].SetPoint(m_Start.x + 50, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexPoints, 6);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		hexPoints[0].SetPoint(m_Start.x + 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[1].SetPoint((m_End.x + m_Start.x) / 2, m_End.y - 50);
		hexPoints[2].SetPoint(m_End.x - 50, (3 * m_End.y + m_Start.y) / 4);
		hexPoints[3].SetPoint(m_End.x - 50, (3 * m_Start.y + m_End.y) / 4);
		hexPoints[4].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		hexPoints[5].SetPoint(m_Start.x + 50, (3 * m_Start.y + m_End.y) / 4);
		pDC->Polygon(hexPoints, 6);
	}
}