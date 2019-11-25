#include "stdafx.h"
#include "Triagle.h"


Triagle::Triagle()
{
}

void Triagle::setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int m_size)
{
	this->m_Start = m_start;
	this->m_End = m_end;
	this->m_BrushColor = m_brush;
	this->m_nPenStype = m_pen;
	this->m_Type = TRIAGLE;
	this->m_nPenWidth = m_size;
}

void Triagle::Draw(CDC * pDC)
{
	CPoint point[3];
	switch (m_rotatetype)
	{
	case (TOP) :
	{
		point[0].SetPoint(m_Start.x, m_End.y);
		point[1].SetPoint(m_End.x, m_End.y);
		point[2].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y);
		pDC->Polygon(point, 3);
		break;
	}
	case (RIGHT) :
	{
		point[0].SetPoint(m_Start.x, m_Start.y);
		point[1].SetPoint(m_Start.x, m_End.y);
		point[2].SetPoint(m_End.x, (m_Start.y + m_End.y) / 2);
		pDC->Polygon(point, 3);
		break;
	}
	case (BOTTOM) :
	{
		point[0].SetPoint(m_Start.x, m_Start.y);
		point[1].SetPoint(m_End.x, m_Start.y);
		point[2].SetPoint((m_Start.x + m_End.x) / 2, m_End.y);
		pDC->Polygon(point, 3);
		break;
	}
	case (LEFT) :
	{
		point[0].SetPoint(m_End.x, m_End.y);
		point[1].SetPoint(m_End.x, m_Start.y);
		point[2].SetPoint(m_Start.x, (m_Start.y + m_End.y) / 2);
		pDC->Polygon(point, 3);
		break;
	}
	}
}

void Triagle::drawZoomOut(CDC * pDC)
{
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		triPoints[0].SetPoint(m_Start.x-50, m_End.y+50);
		triPoints[1].SetPoint(m_End.x+50, m_End.y+50);
		triPoints[2].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y-50);
		pDC->Polygon(triPoints, 3);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		triPoints[0].SetPoint(m_Start.x - 50, m_End.y - 50);
		triPoints[1].SetPoint(m_End.x + 50, m_End.y - 50);
		triPoints[2].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		pDC->Polygon(triPoints, 3);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		triPoints[0].SetPoint(m_Start.x + 50, m_End.y - 50);
		triPoints[1].SetPoint(m_End.x - 50, m_End.y - 50);
		triPoints[2].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		pDC->Polygon(triPoints, 3);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		triPoints[0].SetPoint(m_Start.x +50, m_End.y + 50);
		triPoints[1].SetPoint(m_End.x - 50, m_End.y +50);
		triPoints[2].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y - 50);
		pDC->Polygon(triPoints, 3);
	}
}
void Triagle::drawZoomIn(CDC *pDC)
{
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		triPoints[0].SetPoint(m_Start.x + 50, m_End.y - 50);
		triPoints[1].SetPoint(m_End.x - 50, m_End.y -50);
		triPoints[2].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		pDC->Polygon(triPoints, 3);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		triPoints[0].SetPoint(m_Start.x + 50, m_End.y + 50);
		triPoints[1].SetPoint(m_End.x - 50, m_End.y + 50);
		triPoints[2].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y - 50);
		pDC->Polygon(triPoints, 3);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		triPoints[0].SetPoint(m_Start.x - 50, m_End.y + 50);
		triPoints[1].SetPoint(m_End.x + 50, m_End.y + 50);
		triPoints[2].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y - 50);
		pDC->Polygon(triPoints, 3);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		triPoints[0].SetPoint(m_Start.x - 50, m_End.y - 50);
		triPoints[1].SetPoint(m_End.x + 50, m_End.y - 50);
		triPoints[2].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		pDC->Polygon(triPoints, 3);
	}
}


