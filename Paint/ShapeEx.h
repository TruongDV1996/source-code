#pragma once
enum DRAWMODE {
	PEN = 0, LINE = 1, SQUARE = 2, CIRCLE = 3, RECTANGLE = 4, SQUARE_ = 5, DIAMON = 6, HEXAGON = 7,
	PENTAGON = 8, TRIAGLE = 9, ELIP=10,FILL_COLOR = 11, DELETE_ = 12
};
enum ROTATE { TOP = 0, RIGHT = 1, BOTTOM = 2, LEFT = 3 };
class CShapeEx : public CObject
{
protected:
	CPoint m_Start; //toa do diem bat dau cua rect
	CPoint m_End; //toa do diem ket thuc  cua rect
	COLORREF m_BrushColor; //mau cua but ve
	DRAWMODE m_Type; //enum cac shape
	int m_nPenStype; //loai but ve
	int  m_nPenWidth; //kich thuc but
	COLORREF m_bFilled; //mau nen cua shape
public:
	CShapeEx();
	~CShapeEx();
	ROTATE m_rotatetype; // enum xoay 
	void setStart(CPoint p);
	void setEnd(CPoint p);
	CPoint getStart();
	CPoint getEnd();
	virtual void setData(CPoint m_start, CPoint m_end, COLORREF m_brush, int m_pen, int m_size) = 0;
	virtual void Draw(CDC *dc) = 0;
	virtual void drawZoomOut(CDC *dc){}
	virtual void drawZoomIn(CDC *dc) {}
	void setFillClorr(COLORREF color);
	COLORREF getFillClorr();
	void setClorr(COLORREF color);
	COLORREF getClorr();
	void setRect(RECT* rect);
	int getPenStyle();
	int getPenSize();
	void setPenStyle(int m_pen);
	void setPenSize(int m_size);
	void setType(DRAWMODE type);
	DRAWMODE getTypeShape();
	bool isIn(CPoint);// xet vi tri chon co nam trong hinh
	bool isLine(CPoint);//xet vi tri kich co trong Line
};

