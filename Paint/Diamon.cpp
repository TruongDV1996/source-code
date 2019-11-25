#include "stdafx.h"
#include "Diamon.h"

Diamon::Diamon()
{
}

void Diamon::setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int m_size)
{
	this->m_Start = m_start;
	this->m_End = m_end;
	this->m_BrushColor = m_brush;
	this->m_nPenStype = m_pen;
	this->m_Type = DIAMON;
	this->m_nPenWidth = m_size;
}

void Diamon::Draw(CDC * pDC)
{
	CPoint TPoints[4];
	TPoints[0].SetPoint(m_Start.x, (m_Start.y + m_End.y) / 2);
	TPoints[1].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y);
	TPoints[2].SetPoint(m_End.x, (m_Start.y + m_End.y) / 2);
	TPoints[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y);
	pDC->Polygon(TPoints, 4);
}
void Diamon::drawZoomOut(CDC * pDC)
{

	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		dPoints[0].SetPoint(m_Start.x - 50, (m_Start.y + m_End.y) / 2);
		dPoints[1].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y - 50);
		dPoints[2].SetPoint(m_End.x + 50, (m_Start.y + m_End.y) / 2);
		dPoints[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y + 50);
		pDC->Polygon(dPoints, 4);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		dPoints[0].SetPoint(m_Start.x - 50, (m_Start.y + m_End.y) / 2);
		dPoints[1].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		dPoints[2].SetPoint(m_End.x + 50, (m_Start.y + m_End.y) / 2);
		dPoints[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y - 50);
		pDC->Polygon(dPoints, 4);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		dPoints[0].SetPoint(m_Start.x + 50, (m_Start.y + m_End.y) / 2);
		dPoints[1].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		dPoints[2].SetPoint(m_End.x - 50, (m_Start.y + m_End.y) / 2);
		dPoints[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y - 50);
		pDC->Polygon(dPoints, 4);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		dPoints[0].SetPoint(m_Start.x + 50, (m_Start.y + m_End.y) / 2);
		dPoints[1].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y - 50);
		dPoints[2].SetPoint(m_End.x - 50, (m_Start.y + m_End.y) / 2);
		dPoints[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y + 50);
		pDC->Polygon(dPoints, 4);
	}
}
void Diamon::drawZoomIn(CDC *pDC)
{
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		dPoints[0].SetPoint(m_Start.x + 50, (m_Start.y + m_End.y) / 2);
		dPoints[1].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		dPoints[2].SetPoint(m_End.x - 50, (m_Start.y + m_End.y) / 2);
		dPoints[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y - 50);
		pDC->Polygon(dPoints, 4);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		dPoints[0].SetPoint(m_Start.x + 50, (m_Start.y + m_End.y) / 2);
		dPoints[1].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y - 50);
		dPoints[2].SetPoint(m_End.x - 50, (m_Start.y + m_End.y) / 2);
		dPoints[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y + 50);
		pDC->Polygon(dPoints, 4);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		dPoints[0].SetPoint(m_Start.x - 50, (m_Start.y + m_End.y) / 2);
		dPoints[1].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y - 50);
		dPoints[2].SetPoint(m_End.x + 50, (m_Start.y + m_End.y) / 2);
		dPoints[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y + 50);
		pDC->Polygon(dPoints, 4);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		dPoints[0].SetPoint(m_Start.x - 50, (m_Start.y + m_End.y) / 2);
		dPoints[1].SetPoint((m_Start.x + m_End.x) / 2, m_Start.y + 50);
		dPoints[2].SetPoint(m_End.x + 50, (m_Start.y + m_End.y) / 2);
		dPoints[3].SetPoint((m_Start.x + m_End.x) / 2, m_End.y - 50);
		pDC->Polygon(dPoints, 4);
	}
}
