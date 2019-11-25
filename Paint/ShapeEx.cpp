#include "stdafx.h"
#include "ShapeEx.h"


void CShapeEx::setStart(CPoint p)
{
	m_Start = p;
}

void CShapeEx::setEnd(CPoint p)
{
	m_End = p;
}

CPoint CShapeEx::getStart()
{
	return m_Start;
}

CPoint CShapeEx::getEnd()
{
	return m_End;
}

CShapeEx::CShapeEx()
{
	m_Start = NULL;
	m_End = NULL;
	m_bFilled = RGB(255, 255, 255);
	m_rotatetype = TOP;
	m_BrushColor= RGB(0, 0, 0);
	m_nPenStype=PS_DOT;
	m_nPenWidth=1;
}

CShapeEx::~CShapeEx()
{
}

COLORREF CShapeEx::getClorr()
{
	return m_BrushColor;
}

void CShapeEx::setClorr(COLORREF color)
{
	this->m_BrushColor = color;
}

void CShapeEx::setRect(RECT * rect)
{
	this->m_Start.x=rect->left;
	this->m_Start.y = rect->top;
	this->m_End.x = rect->right;
	this->m_End.y = rect->bottom;
}


int CShapeEx::getPenStyle()
{
	return this->m_nPenStype;
}

int CShapeEx::getPenSize()
{
	return this->m_nPenWidth;
}

void CShapeEx::setFillClorr(COLORREF color)
{
	this->m_bFilled = color;
}

COLORREF CShapeEx::getFillClorr()
{
	return this->m_bFilled;
}

void CShapeEx::setPenStyle(int m_pen)
{
	m_nPenStype = m_pen;
}

void CShapeEx::setPenSize(int m_size)
{
	this->m_nPenWidth = m_size;
}

void CShapeEx::setType(DRAWMODE type)
{
	this->m_Type = type;
}

DRAWMODE CShapeEx::getTypeShape()
{
	return this->m_Type;
}

bool CShapeEx::isIn(CPoint current)
{
	if ((m_Start.x < m_End.x)&& (m_Start.y < m_End.y) && ((current.x >= m_Start.x && current.x <= m_End.x && current.y >= m_Start.y && current.y <= m_End.y)
		|| (m_Start.x < m_End.x) && (m_Start.y > m_End.y) && (current.x >= m_Start.x && current.x <= m_End.x && current.y <= m_Start.y && current.y >= m_End.y)))
	{
		return true;
	}
	if ((m_Start.x > m_End.x) && (m_Start.y < m_End.y) &&(current.x >= m_End.x && current.x <= m_Start.x && current.y >= m_Start.y && current.y <= m_End.y)
		|| (m_Start.x > m_End.x) && (m_Start.y > m_End.y)&&(current.x >= m_End.x && current.x <= m_Start.x && current.y >= m_End.y && current.y <= m_Start.y)) {
		return true;
	}
	return false;
}

bool CShapeEx::isLine(CPoint current)
{
	int x = m_Start.x - m_End.x;
	int y = m_Start.y - m_End.y;
	int minX = m_Start.x <  m_End.x ? m_Start.x : m_End.x;
	int maxX = m_Start.x > m_End.x ? m_Start.x : m_End.x;
	int minY = m_Start.y < m_End.y ? m_Start.y : m_End.y;
	int maxY = m_Start.y > m_End.y ? m_Start.y : m_End.y;

	double m = (double)y / (double)x;
	if ((current.y - current.y - m*(current.x - m_Start.x)) - 7 && (current.y - m_Start.y - m*(current.x - m_Start.x) < 7) && (!(current.x < minX || current.x > maxX || current.y < minY || current.y > maxY)))
	return true;
	return false;
}
