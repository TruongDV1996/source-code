#include "stdafx.h"
#include "Pen.h"


Pen::Pen()
{
}

void Pen::setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int m_size)
{
	this->m_Start = m_start;
	this->m_End = m_end;
	this->m_BrushColor = m_brush;
	this->m_nPenStype = m_pen;
	this->m_nPenWidth = m_size;
	this->m_Type = PEN;
}

void Pen::Draw(CDC * pDC)
{
	pDC->MoveTo(m_Start);
	pDC->LineTo(m_End);
}
