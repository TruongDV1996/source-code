#include "stdafx.h"
#include "Elip.h"


Elip::Elip()
{
}

void Elip::setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int m_size)
{
	this->m_Start = m_start;
	this->m_End = m_end;
	this->m_BrushColor = m_brush;
	this->m_nPenStype = m_pen;
	this->m_nPenWidth = m_size;
	this->m_Type = ELIP;
	
}

void Elip::Draw(CDC * pDC)
{
	pDC->Ellipse(m_Start.x, m_Start.y, m_End.x, m_End.y);
}

void Elip::drawZoomOut(CDC * pDC)
{
	startPoint = getStart();
	endPoint = getEnd();
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		pDC->Ellipse(startPoint.x - 50, startPoint.y - 50, endPoint.x + 50, endPoint.y + 50);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		pDC->Ellipse(startPoint.x - 50, startPoint.y + 50, endPoint.x + 50, endPoint.y - 50);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		pDC->Ellipse(startPoint.x + 50, startPoint.y + 50, endPoint.x - 50, endPoint.y - 50);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		pDC->Ellipse(startPoint.x + 50, startPoint.y - 50, endPoint.x - 50, endPoint.y + 50);
	}
}
void Elip::drawZoomIn(CDC *pDC)
{
	startPoint = getStart();
	endPoint = getEnd();
	if (m_Start.x < m_End.x&&m_Start.y < m_End.y) {
		pDC->Ellipse(startPoint.x + 50, startPoint.y + 50, endPoint.x - 50, endPoint.y - 50);
	}
	else if (m_Start.x<m_End.x&&m_Start.y >m_End.y) {
		pDC->Ellipse(startPoint.x + 50, startPoint.y - 50, endPoint.x - 50, endPoint.y + 50);
	}
	else if (m_Start.x > m_End.x&&m_Start.y >m_End.y) {
		pDC->Ellipse(startPoint.x - 50, startPoint.y - 50, endPoint.x + 50, endPoint.y + 50);
	}
	//tren xuong phai trai
	else if (m_End.x < m_Start.x&&m_Start.y < m_End.y) {
		pDC->Ellipse(startPoint.x - 50, startPoint.y + 50, endPoint.x + 50, endPoint.y - 50);
	}
}


