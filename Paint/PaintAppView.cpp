// PaintAppView.cpp : implementation of the CPaintAppView class
#include "stdafx.h"
#include "PaintApp.h"
#include <fstream>

// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PaintApp.h"
#endif

#include "PaintAppDoc.h"
#include "PaintAppView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPaintAppView

IMPLEMENT_DYNCREATE(CPaintAppView, CView)

BEGIN_MESSAGE_MAP(CPaintAppView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPaintAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_PEN, &CPaintAppView::OnPen)
	ON_UPDATE_COMMAND_UI(ID_PEN, &CPaintAppView::OnUpdatePen)
	ON_COMMAND(ID_CLOR_RED, &CPaintAppView::OnClorRed)
	ON_COMMAND(ID_CLOR_GREEN, &CPaintAppView::OnClorGreen)
	ON_COMMAND(ID_CLOR_BACK, &CPaintAppView::OnClorBack)
	ON_COMMAND(ID_CLOR_BROW, &CPaintAppView::OnClorBrow)
	ON_COMMAND(ID_CLOR_VIOLET, &CPaintAppView::OnClorViolet)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_LINE, &CPaintAppView::OnUpdateButtonLine)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_CIR, &CPaintAppView::OnUpdateButtonCir)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_DIAMO, &CPaintAppView::OnUpdateButtonDiamo)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_POS, &CPaintAppView::OnUpdateIndicatorPos)
	ON_COMMAND(ID_BUTTON_LINE, &CPaintAppView::OnButtonLine)
	ON_WM_PAINT()
	ON_COMMAND(ID_BUTTON_CIR, &CPaintAppView::OnButtonCir)
	ON_COMMAND(ID_BUTTON_CLORR, &CPaintAppView::OnButtonClorr)
	ON_COMMAND(ID_BUTTON_CHANG, &CPaintAppView::OnButtonChang)
	ON_COMMAND(ID_BUTTON_MOVE, &CPaintAppView::OnButtonMove)
	ON_COMMAND(ID_BUTTON_REG, &CPaintAppView::OnButtonReg)
	ON_COMMAND(ID_BUTTON_SQUARE, &CPaintAppView::OnButtonSquare)
	ON_COMMAND(ID_BUTTON_DELETE, &CPaintAppView::OnButtonDelete)
	ON_COMMAND(ID_FILE_SAVE, &CPaintAppView::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &CPaintAppView::OnFileOpen)
	ON_COMMAND(ID_BUTTON_1, &CPaintAppView::OnButton1)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_1, &CPaintAppView::OnUpdateButton1)
	ON_COMMAND(ID_BUTTON_2, &CPaintAppView::OnButton2)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_2, &CPaintAppView::OnUpdateButton2)
	ON_COMMAND(ID_BUTTON_3, &CPaintAppView::OnButton3)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_3, &CPaintAppView::OnUpdateButton3)
	ON_COMMAND(ID_BUTTON_DASHDOT, &CPaintAppView::OnButtonDashdot)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_DASHDOT, &CPaintAppView::OnUpdateButtonDashdot)
	ON_COMMAND(ID_BUTTON_DOT, &CPaintAppView::OnButtonDot)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_DOT, &CPaintAppView::OnUpdateButtonDot)
	ON_COMMAND(ID_BUTTON_SOLID, &CPaintAppView::OnButtonSolid)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_SOLID, &CPaintAppView::OnUpdateButtonSolid)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_REG, &CPaintAppView::OnUpdateButtonReg)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_SQUARE, &CPaintAppView::OnUpdateButtonSquare)
	ON_UPDATE_COMMAND_UI(ID_CLOR_BACK, &CPaintAppView::OnUpdateClorBack)
	ON_UPDATE_COMMAND_UI(ID_CLOR_BROW, &CPaintAppView::OnUpdateClorBrow)
	ON_UPDATE_COMMAND_UI(ID_CLOR_GREEN, &CPaintAppView::OnUpdateClorGreen)
	ON_UPDATE_COMMAND_UI(ID_CLOR_RED, &CPaintAppView::OnUpdateClorRed)
	ON_UPDATE_COMMAND_UI(ID_CLOR_VIOLET, &CPaintAppView::OnUpdateClorViolet)
	ON_COMMAND(ID_FILE_NEW, &CPaintAppView::OnFileNew)
	ON_COMMAND(ID_BUTTON_FILL, &CPaintAppView::OnButtonFill)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_FILL, &CPaintAppView::OnUpdateButtonFill)
	ON_COMMAND(ID_BUTTON_HEXA, &CPaintAppView::OnButtonHexa)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_HEXA, &CPaintAppView::OnUpdateButtonHexa)
	ON_COMMAND(ID_BUTTON_PENTA, &CPaintAppView::OnButtonPenta)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_PENTA, &CPaintAppView::OnUpdateButtonPenta)
	ON_COMMAND(ID_BUTTON_TRI, &CPaintAppView::OnButtonTri)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_TRI, &CPaintAppView::OnUpdateButtonTri)
	ON_COMMAND(ID_BUTTON_DIAMO, &CPaintAppView::OnButtonDiamo)
	ON_COMMAND(ID_BUTTON_ROTATE, &CPaintAppView::OnButtonRotate)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_ROTATE, &CPaintAppView::OnUpdateButtonRotate)
	ON_COMMAND(ID_INDICATOR_EXT, &CPaintAppView::OnIndicatorExt)
	ON_COMMAND(ID_FILE_SAVE_AS, &CPaintAppView::OnFileSaveAs)
	ON_COMMAND(ID_BUTTON_ELIP, &CPaintAppView::OnButtonElip)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_ELIP, &CPaintAppView::OnUpdateButtonElip)
	ON_COMMAND(ID_BUTTON_ZOOMOUT, &CPaintAppView::OnButtonZoomout)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_ZOOMOUT, &CPaintAppView::OnUpdateButtonZoomout)
	ON_COMMAND(ID_BUTTON_ZOOMIN, &CPaintAppView::OnButtonZoomin)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_ZOOMIN, &CPaintAppView::OnUpdateButtonZoomin)
END_MESSAGE_MAP()
//int windowWidth = 1050, windowHeight = 820;
// CPaintAppView construction/destruction
CPaintAppView::CPaintAppView()
{
	bDown = false;
	checkObject = false; checkDelete = false;
	isFill = false; checkRotate = false; checkZoomIn = false; checkZoomOut = false;
	flag = "Null";
	Type = PEN;
}
CPaintAppView::~CPaintAppView()
{
	vector<CShapeEx*>::iterator it = shapes.begin();
	for (; it != shapes.end(); ++it) {
		delete (*it);
	}
	shapes.clear();
}

BOOL CPaintAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

void CPaintAppView::OnDraw(CDC* pDC)
{
	CPaintAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}
// CPaintAppView printing
void CPaintAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPaintAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPaintAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPaintAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}
void CPaintAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}
void CPaintAppView::OnPaint()
{
	// TODO: Add your message handler code here
	// Do not call CView::OnPaint() for painting messages
	// device context for painting
	CPaintDC dc(this);
	for (int i = 0; i < shapes.size(); i++)
	{
		CPen pen(shapes[i]->getPenStyle(), shapes[i]->getPenSize(), shapes[i]->getClorr());
		CBrush brush(shapes[i]->getFillClorr());
		dc.SelectObject(pen);
		dc.SelectObject(brush);
		if (checkZoomIn == true)
		{
			shapes[i]->drawZoomIn(&dc);
		}
		else if (checkZoomOut == true)
		{
			shapes[i]->drawZoomOut(&dc);
		}
		else
			shapes[i]->Draw(&dc);
		Invalidate(false);
	}
	if (bDown)
	{
		//V? nét v? t?m th?i khi ch?a Mouse Up
		if (flag == "Null" && pointStart != currentLocation&&isFill==false) {
			CPen pen(currPenStyle, currPenSize, currColor);
			dc.SelectObject(pen);
			CBrush brush(RGB(255, 255, 255));//mau trang 
			dc.SelectObject(brush);
			currShape->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			ShowLocationMove(&dc, pointStart);
			if (currShape->getTypeShape() != CIRCLE&&currShape->getTypeShape() != SQUARE_)
			{
				ShowLocationMove(&dc, currentLocation);
			}
			if (checkZoomIn == true)
			{
				currShape->drawZoomIn(&dc);
			}
			else if (checkZoomOut == true)
			{
				currShape->drawZoomOut(&dc);
			}
			else
				currShape->Draw(&dc);
		}
	}

	if (checkObject == true) {
		if (flag == "move" || flag == "change" ||
			flag == "rotate" || flag == "delete" || isFill == true) {
			for (int i = shapes.size() - 1; i >= 0; i--)
			{
				if (i == MoveIndex) {
					CPen pen(PS_DOT, 1, RGB(52, 109, 197));//but mau xanh
					dc.SelectObject(pen);
					CBrush brush(shapes[i]->getFillClorr());//mau do hinh
					dc.SelectObject(brush);
					selectShape(&dc, shapes[i]->getStart(), shapes[i]->getEnd());
				}
			}
		}
	}
	CView::OnPaint();
}

////update chuot::
void CPaintAppView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CPaintDC dc(this);
	if (flag == "move" || flag == "change" || flag == "rotate" ||
		flag == "delete" || isFill == true)
	{
		for (int i = shapes.size() - 1; i >= 0; i--)
		{
			if ((shapes[i]->getTypeShape() == LINE ? shapes[i]->isLine(point) : shapes[i]->isIn(point)) && shapes[i]->getTypeShape() != PEN)
			{
				MoveIndex = i;
				checkDelete = true;
				bDown = true;
				checkObject = true;
				checkRotate = true;
				if (isFill == true) {
					shapes[i]->setFillClorr(fillColor);
				}
				break;
			}
			if (i == 0) {
				isFill = false;
			}
		}
		for (int i = shapes.size() - 1; i >= 0; i--)
		{
			if (i == MoveIndex) {
				InvalidateRect(&rect, 1);
				CPen pen(PS_DASH, 1, RGB(255, 0, 0));
				dc.SelectObject(pen);
				selectShape(&dc, shapes[i]->getStart(), shapes[i]->getEnd());
				getRect(shapes[i]->getStart(), shapes[i]->getEnd());
				InvalidateRect(&rect, 0);
			}
		}
	}
	 if (isFill == false) {
		switch (Type)
		{
		case(PEN) :
		{
			currShape = new Pen();
			break;
		}
		case(LINE) :
		{
			currShape = new Line();
			break;
		}
		case(CIRCLE) :
		{
			currShape = new Circle();
			break;
		}
		case(RECTANGLE) :
		{
			currShape = new Rectangle_();
			break;
		}
		case(SQUARE_) :
		{
			currShape = new Square();
			break;
		}
		case DIAMON:
			currShape = new Diamon();
			break;
		case PENTAGON:
			currShape = new Pentagon();
			break;
		case HEXAGON:
			currShape = new Hexagon();
			break;
		case TRIAGLE:
			currShape = new Triagle();
			break;
		case ELIP:
			currShape = new Elip();
			break;
		default:
			break;
		}
	}
	bDown = true;
	pointStart = point;
	CView::OnLButtonDown(nFlags, point);
}

void CPaintAppView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//luu hinh vao vector
	if (flag == "Null"&&isFill == false) {
		switch (Type)
		{
		case(PEN) :
		{
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		case(LINE) :
		{
			Line *line = new Line();
			line->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			shapes.push_back(line);
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		case(CIRCLE) :
		{
			Circle *cricle = new Circle();
			cricle->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			shapes.push_back(cricle);
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		case(RECTANGLE) :
		{
			Rectangle_ *rec = new Rectangle_();
			rec->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			shapes.push_back(rec);
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		case(SQUARE_) :
		{
			Square *square = new Square();
			square->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			shapes.push_back(square);
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		case(DIAMON) :
		{
			Diamon *diamon = new Diamon();
			diamon->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			shapes.push_back(diamon);
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		case(HEXAGON) :
		{
			Hexagon *hexagon = new Hexagon();
			hexagon->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			shapes.push_back(hexagon);
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		case(PENTAGON) :
		{
			Pentagon *pentagon = new Pentagon();
			pentagon->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			shapes.push_back(pentagon);
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		case(TRIAGLE) :
		{
			Triagle *triagle = new Triagle();
			triagle->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			shapes.push_back(triagle);
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		case(ELIP) :
		{
			Elip *elip = new Elip();
			elip->setData(pointStart, currentLocation, currColor, currPenStyle, currPenSize);
			shapes.push_back(elip);
			if (currShape != NULL)
			{
				delete currShape;
				currShape = NULL;
			}
			break;
		}
		default:
			break;
		}
	}
	//xoa hinh
	else
		if (flag == "delete" && checkDelete == true) {
			shapes.erase(shapes.begin() + MoveIndex);
			Invalidate();
		}
	//xoay hinh theo 4 huong
		else if (checkRotate  && flag == "rotate") {
			CPaintDC dc(this);
			CRect r =NULL;
			r.left = shapes[MoveIndex]->getStart().x;
			r.right = shapes[MoveIndex]->getEnd().x;
			r.top = shapes[MoveIndex]->getStart().y;
			r.bottom = shapes[MoveIndex]->getEnd().y;
			CPoint center = r.CenterPoint();
			int deltaX = r.right - r.left;
			int deltaY = r.bottom - r.top;
			r.left = center.x - deltaY / 2;
			r.right = center.x + deltaY / 2;
			r.bottom = center.y + deltaX / 2;
			r.top = center.y - deltaX / 2;
			shapes[MoveIndex]->setRect(r);
			if (shapes[MoveIndex]->m_rotatetype == TOP)
			{
				shapes[MoveIndex]->m_rotatetype = RIGHT;
			}
			else if (shapes[MoveIndex]->m_rotatetype == RIGHT)
			{
				shapes[MoveIndex]->m_rotatetype = BOTTOM;
			}
			else if (shapes[MoveIndex]->m_rotatetype == BOTTOM)
			{
				shapes[MoveIndex]->m_rotatetype = LEFT;
			}
			else if (shapes[MoveIndex]->m_rotatetype == LEFT)
			{
				shapes[MoveIndex]->m_rotatetype = TOP;
			}
			else
				return;
			Invalidate();
		}
		//tra cac gia tri ve ban dau
		flag = "Null";
		bDown = false;
		checkObject = false;
		checkRotate = false;
		checkDelete = false;
		chooseChange = false;
		CView::OnLButtonUp(nFlags, point);
}

void CPaintAppView::OnMouseMove(UINT nFlags, CPoint point)
{
	currentLocation = point;
	locationPoint = point;
	CPaintDC dc(this);
	if (bDown) {
		if (flag == "move")
		{
			if (checkObject == true)
			{
				InvalidateRect(&rect, 1);
				COLORREF currColor_ = shapes[MoveIndex]->getClorr();
				//xet toa do moi dich hinh
				CPoint pointNewEnd = NULL;
				pointNewEnd.x = shapes[MoveIndex]->getEnd().x;
				pointNewEnd.x += (currentLocation.x - shapes[MoveIndex]->getStart().x);
				pointNewEnd.y = shapes[MoveIndex]->getEnd().y;
				pointNewEnd.y += (currentLocation.y - shapes[MoveIndex]->getStart().y);
				shapes[MoveIndex]->setEnd(pointNewEnd);
				shapes[MoveIndex]->setStart(currentLocation);
				currColor = currColor_;
				getRect(pointNewEnd, currentLocation);
				InvalidateRect(&rect, 0);
			}
		}
		else if (flag == "change")
		{
			if (checkObject == true) {
				int centerx = (shapes[MoveIndex]->getStart().x + shapes[MoveIndex]->getEnd().x) / 2;
				int centery = (shapes[MoveIndex]->getStart().y + shapes[MoveIndex]->getEnd().y) / 2;
				if (centerx > point.x&&centery > point.y&&chooseChange != 2)
				{
					InvalidateRect(&rect, 1);
					shapes[MoveIndex]->setStart(point);
					getRect(point, shapes[MoveIndex]->getEnd());
					InvalidateRect(&rect, 0);
					chooseChange = 1;
				}
				if (centerx < point.x&&centery < point.y&&chooseChange != 1)
				{
					InvalidateRect(&rect, 1);
					shapes[MoveIndex]->setEnd(point);
					getRect(shapes[MoveIndex]->getStart(), point);
					InvalidateRect(&rect, 0);
					chooseChange = 2;
				}
			}
		}
		else if (isFill == false)
		{
			switch (Type)
			{
			case(PEN) : {
				Pen *pen = new Pen();
				pen->setData(pointStart, point, currColor, currPenStyle, currPenSize);
				pointStart = point;
				shapes.push_back(pen);
				Invalidate(false);
				break;
			}
			default:
				InvalidateRect(&rect, 1);
				getRect(pointStart, currentLocation);
				InvalidateRect(&rect, 0);
				break;
			}
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CPaintAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}
// CPaintAppView diagnostics

#ifdef _DEBUG
void CPaintAppView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintAppDoc* CPaintAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintAppDoc)));
	return (CPaintAppDoc*)m_pDocument;
}
#endif //_DEBUG

// CPaintAppView message handlers
//SET CLORR
void CPaintAppView::OnClorRed()
{
	// TODO: Add your command handler code here
	currColor = RGB(255, 0, 0);
}

void CPaintAppView::OnClorGreen()
{
	// TODO: Add your command handler code here
	currColor = RGB(0, 255, 0);
}

void CPaintAppView::OnClorBack()
{
	// TODO: Add your command handler code here
	currColor = RGB(0, 0, 0);
}

void CPaintAppView::OnClorBrow()
{
	// TODO: Add your command handler code here
	currColor = RGB(64, 0, 0);
}

void CPaintAppView::OnClorViolet()
{
	// TODO: Add your command handler code here
	currColor = RGB(64, 0, 128);
}

void CPaintAppView::OnUpdateClorBack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currColor == RGB(0, 0, 0));
}


void CPaintAppView::OnUpdateClorBrow(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currColor == RGB(64, 0, 0));
}


void CPaintAppView::OnUpdateClorGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currColor == RGB(0, 255, 0));
}


void CPaintAppView::OnUpdateClorRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currColor == RGB(255, 0, 0));
}


void CPaintAppView::OnUpdateClorViolet(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currColor == RGB(64, 0, 128));
}

void CPaintAppView::OnButtonClorr()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		currColor = dlg.GetColor();
	}
	Invalidate(false);
	OnPaint();
}
void CPaintAppView::OnButtonFill()
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		fillColor = dlg.GetColor();
	}
	isFill = true;
	Invalidate(false);
	OnPaint();
}

void CPaintAppView::OnUpdateButtonFill(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(isFill == true);
}


void CPaintAppView::OnButtonLine()
{
	Type = LINE;
	isFill = false;
}

void CPaintAppView::OnButtonCir()
{
	// TODO: Add your command handler code here
	Type = CIRCLE;
	isFill = false;
}

void CPaintAppView::OnPen()
{
	// TODO: Add your command handler code here
	Type = PEN;
	isFill = false;
}

void CPaintAppView::OnButtonReg()
{
	// TODO: Add your command handler code here
	Type = RECTANGLE;
	isFill = false;
}

void CPaintAppView::OnButtonSquare()
{
	// TODO: Add your command handler code here
	Type = SQUARE_;
	isFill = false;
}


void CPaintAppView::OnButtonDiamo()
{
	// TODO: Add your command handler code here
	Type = DIAMON;
	isFill = false;
}

void CPaintAppView::OnButtonHexa()
{
	// TODO: Add your command handler code here
	Type = HEXAGON;
	isFill = false;
}

void CPaintAppView::OnButtonPenta()
{
	// TODO: Add your command handler code here
	Type = PENTAGON;
	isFill = false;
}

void CPaintAppView::OnButtonTri()
{
	// TODO: Add your command handler code here
	Type = TRIAGLE;
	isFill = false;
}
//set hinh
void CPaintAppView::OnUpdatePen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == PEN);
}

void CPaintAppView::OnUpdateButtonLine(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == LINE);
}

void CPaintAppView::OnUpdateButtonCir(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == CIRCLE);
}
void CPaintAppView::OnUpdateButtonReg(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == RECTANGLE);
}

void CPaintAppView::OnUpdateButtonSquare(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == SQUARE_);
}

void CPaintAppView::OnUpdateButtonDiamo(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == DIAMON);
}

void CPaintAppView::OnUpdateButtonHexa(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == HEXAGON);
}

void CPaintAppView::OnUpdateButtonPenta(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == PENTAGON);
}

void CPaintAppView::OnUpdateButtonTri(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == TRIAGLE);
}

void CPaintAppView::OnButtonElip()
{
	// TODO: Add your command handler code here
	Type = ELIP;
}

void CPaintAppView::OnUpdateButtonElip(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(Type == ELIP);
}


void CPaintAppView::OnButtonDelete()
{
	// TODO: Add your command handler code here
	//checkDelete = true;
	flag = "delete";
}
void CPaintAppView::OnButtonRotate()
{
	// TODO: Add your command handler code here
	flag = "rotate";
}

//set dich hinh
void CPaintAppView::OnButtonChang()
{
	// TODO: Add your command handler code here
	flag = "change";
}

void CPaintAppView::OnButtonMove()
{
	// TODO: Add your command handler code here
	flag = "move";
}
void CPaintAppView::OnUpdateButtonRotate(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(flag == "rotate");
}

void CPaintAppView::OnButton1()
{
	// TODO: Add your command handler code here
	currPenSize = 1;
}

void CPaintAppView::OnUpdateButton1(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currPenSize == 1);

}

void CPaintAppView::OnButton2()
{
	// TODO: Add your command handler code here
	currPenSize = 2;
}

void CPaintAppView::OnUpdateButton2(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currPenSize == 2);
}

void CPaintAppView::OnButton3()
{
	// TODO: Add your command handler code here
	currPenSize = 3;
}

void CPaintAppView::OnUpdateButton3(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currPenSize == 3);
}

void CPaintAppView::OnButtonDashdot()
{
	// TODO: Add your command handler code here
	currPenStyle = PS_DASHDOT;
}

void CPaintAppView::OnUpdateButtonDashdot(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currPenStyle == PS_DASHDOT);
}

void CPaintAppView::OnButtonDot()
{
	// TODO: Add your command handler code here
	currPenStyle = PS_DOT;
}

void CPaintAppView::OnUpdateButtonDot(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	//if(chos)
	pCmdUI->SetCheck(currPenStyle == PS_DOT);
}

void CPaintAppView::OnButtonSolid()
{
	// TODO: Add your command handler code here
	currPenStyle = PS_SOLID;
}


void CPaintAppView::OnUpdateButtonZoomout(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(checkZoomOut == true);
}


void CPaintAppView::OnButtonZoomin()
{
	// TODO: Add your command handler code here
	checkZoomIn = !checkZoomIn;
	OnPaint();
	Invalidate();
}


void CPaintAppView::OnUpdateButtonZoomin(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(checkZoomIn == true);
}
//Save, LodaingFile
void CPaintAppView::saveToBinaryFile(string filePath)
{
	std::ofstream out;
	out.open(filePath, std::iostream::out | std::iostream::binary | std::iostream::trunc);
	if (out.is_open()) {
		int size = shapes.size();
		out.write(reinterpret_cast<const char *>(&size), sizeof(size));
		for (CShapeEx* shape : shapes) {
			int typeShape = shape->getTypeShape();
			COLORREF color = shape->getClorr();
			COLORREF fillColor_ = shape->getFillClorr();
			RECT* rect1 = new RECT();
			rect1->left = shape->getStart().x;
			rect1->top = shape->getStart().y;
			rect1->right = shape->getEnd().x;
			rect1->bottom = shape->getEnd().y;
			int typePenStype = shape->getPenStyle();
			int typePenSize = shape->getPenSize();
			out.write(reinterpret_cast<const char*>(&typeShape), sizeof(typeShape));
			out.write(reinterpret_cast<const char*>(&color), sizeof(COLORREF));
			out.write(reinterpret_cast<const char*>(rect1), sizeof(RECT));
			out.write(reinterpret_cast<const char*>(&typePenStype), sizeof(typePenStype));
			out.write(reinterpret_cast<const char*>(&typePenSize), sizeof(typePenSize));
			out.write(reinterpret_cast<const char*>(&fillColor_), sizeof(COLORREF));
			delete rect1;
		}
	}
	else {
		OutputDebugString(L"Can't open data.bin to write");
	}

	out.close();
}

void CPaintAppView::OnUpdateButtonSolid(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(currPenStyle == PS_SOLID);
}
// gioi han luu so hinh 127*256+256;
void CPaintAppView::loadFromBinaryFile(string filePath)
{
	std::ifstream in;
	in.open(filePath, std::iostream::in | std::iostream::binary);
	if (in.is_open()) {
		char* buffer = new char[100];
		int size = 0;
		int flag = 1;
		in.read(buffer, sizeof(size));
		for (int i = 1; i < 100; i++) {
			int z = buffer[i];
			//int z1 = buffer[0];
			if (z > 0)
				size += 256 * z;
		}
		if (int(buffer[0]) > 0) {
			size += buffer[0];
		}
		else {
			size += 256 + buffer[0];
		}
		shapes.clear();
		for (int i = 0; i < size; i++)
		{
			char* item_buff = new char[20];
			CShapeEx* shape = NULL;
			int typeShape, typePenStype, typePenSize;;
			COLORREF color;
			COLORREF fillColor_;
			in.read(item_buff, sizeof(typeShape));
			typeShape = item_buff[0];
			in.read(item_buff, sizeof(COLORREF));
			int r = item_buff[0];
			
			int g = item_buff[1];
			
			int b = item_buff[2];
			color = RGB(r, g, b);

			switch (typeShape)
			{
			case LINE:
				shape = new Line();
				break;
			case CIRCLE:
				shape = new Circle();
				break;
			case RECTANGLE:
				shape = new Rectangle_();
				break;
			case SQUARE:
				shape = new Square();
				break;
			case PEN:
				shape = new Pen();
				break;
			case DIAMON:
				shape = new Diamon();
				break;
			case PENTAGON:
				shape = new Pentagon();
				break;
			case HEXAGON:
				shape = new Hexagon();
				break;
			case TRIAGLE:
				shape = new Triagle();
				break;
			case ELIP:
				shape = new Elip();
				break;
			default:
				break;
			}
			shape->setType((DRAWMODE)typeShape);
			shape->setClorr(color);

			RECT* rect;
			in.read(item_buff, sizeof(RECT));
			rect = reinterpret_cast<RECT*>(item_buff);
			shape->setRect(rect);

			in.read(buffer, sizeof(typePenStype));
			typePenStype = buffer[0];

			in.read(buffer, sizeof(typePenSize));
			typePenSize = buffer[0];

			shape->setPenStyle(typePenStype);
			shape->setPenSize(typePenSize);

			in.read(item_buff, sizeof(COLORREF));
			int r1 = item_buff[0];;
		
			int g1 = item_buff[1];;
			int b1 = item_buff[2];
			fillColor_ = RGB(r1, g1, b1);

			shape->setFillClorr(fillColor_);

			shapes.push_back(shape);

			delete[] item_buff;
			item_buff = NULL;
			if (shape == NULL) {
				delete shape;
				shape = NULL;
			}
		}
		delete[] buffer;
		buffer = NULL;
	}
	else {
		OutputDebugString(L"Can't open data.bin to read");
	}
	in.close();
}
string defaultFilePath = "data.bin";
void CPaintAppView::OnFileSave()
{
	if (defaultFilePath == "data.bin") {
		OPENFILENAME ofn;
		WCHAR szFileName[MAX_PATH] = L"";
		ZeroMemory(&ofn, sizeof(ofn));

		ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
		ofn.lpstrFilter = L"Binary Files (*.bin)\0*.bin\0All Files (*.*)\0*.*\0";
		ofn.lpstrFile = szFileName;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
		ofn.lpstrDefExt = L"bin";
		if (GetSaveFileName(&ofn))
		{
			//ghi duong dan va szFileName 
			wstring ws(szFileName);
			// your new String
			string fileName(ws.begin(), ws.end());
			defaultFilePath = fileName;
			saveToBinaryFile(fileName);
			defaultFilePath = fileName;
		}
	}
	else
		saveToBinaryFile(defaultFilePath);
	Invalidate(false);
	OnPaint();
	//SetWindowTextA(defaultFilePath);
}

void CPaintAppView::OnFileOpen()
{
	// TODO: Add your command handler code here
	//saveToBinaryFile(defaultFilePath);
	vector<CShapeEx*>::iterator it = shapes.begin();
	for (; it != shapes.end(); ++it) {
		delete (*it);
	}
	shapes.clear();
	OPENFILENAME ofn;
	WCHAR szFilePath[MAX_PATH] = L"";
	WCHAR szFileTitle[MAX_PATH] = L"";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
	ofn.lpstrFilter = L"Binary Files (*.bin)\0*.bin\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFilePath;
	ofn.lpstrFileTitle = szFileTitle;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = L"bin";

	if (GetOpenFileName(&ofn))
	{
		// Do something usefull with the filename stored in szFileName 
		wstring ws(szFilePath);
		// your new String
		string fileName(ws.begin(), ws.end());
		loadFromBinaryFile(fileName);
		defaultFilePath = fileName;
	}
	Invalidate();
	OnPaint();
}
void CPaintAppView::OnFileSaveAs()
{
	// TODO: Add your command handler code here
	OPENFILENAME ofn;
	WCHAR szFileName[MAX_PATH] = L"";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
	ofn.lpstrFilter = L"Binary Files (*.bin)\0*.bin\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	ofn.lpstrDefExt = L"bin";
	if (GetSaveFileName(&ofn))
	{
		// Do something usefull with the filename stored in szFileName 
		wstring ws(szFileName);
		// your new String
		string fileName(ws.begin(), ws.end());
		defaultFilePath = fileName;
		saveToBinaryFile(fileName);
		defaultFilePath = fileName;
	}
	Invalidate(false);
	OnPaint();
}

//lam moi file
void CPaintAppView::OnFileNew()
{
	// TODO: Add your command handler code here
	Save save;
	if (shapes.size() > 0) {
		save.DoModal();
	}
	if (*(save.checkS) == 1) {
		OPENFILENAME ofn;
		WCHAR szFileName[MAX_PATH] = L"";

		ZeroMemory(&ofn, sizeof(ofn));

		ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
		ofn.lpstrFilter = L"Binary Files (*.bin)\0*.bin\0All Files (*.*)\0*.*\0";
		ofn.lpstrFile = szFileName;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
		ofn.lpstrDefExt = L"bin";

		if (GetSaveFileName(&ofn))
		{
			// Do something usefull with the filename stored in szFileName 
			wstring ws(szFileName);
			// your new String
			string fileName(ws.begin(), ws.end());
			defaultFilePath = fileName;
			saveToBinaryFile(fileName);
		}
		if (defaultFilePath != "data.bin")
		{
			shapes.clear();
			Invalidate();
		}
	}
	else if (*(save.checkS) == 2)
	{
		shapes.clear();
		Invalidate();
	}
	defaultFilePath = "data.bin";
	Invalidate(false);
	OnPaint();
}
//set to do
void CPaintAppView::OnUpdateIndicatorPos(CCmdUI *pCmdUI)
{
	CString strPos;
	strPos.Format(_T("(X: %d,Y: %d)"), locationPoint.x, locationPoint.y);
	pCmdUI->Enable();
	pCmdUI->SetText(strPos);
}


void CPaintAppView::OnIndicatorExt()
{
	// TODO: Add your command handler code here
	MessageBox(_T("Ban muon thoat"));
}

void CPaintAppView::ShowLocationMove(CDC *pDC, CPoint m_point)
{
	pDC->SetPixel(m_point, RGB(52, 109, 197));
	pDC->SetPixel(m_point.x, m_point.y + 1, RGB(52, 109, 197));
	pDC->SetPixel(m_point.x, m_point.y - 1, RGB(52, 109, 197));
	pDC->SetPixel(m_point.x + 1, m_point.y, RGB(52, 109, 197));
	pDC->SetPixel(m_point.x - 1, m_point.y, RGB(52, 109, 197));
	pDC->SetPixel(m_point.x + 1, m_point.y + 1, RGB(52, 109, 197));
	pDC->SetPixel(m_point.x - 1, m_point.y - 1, RGB(52, 109, 197));
	pDC->SetPixel(m_point.x + 1, m_point.y - 1, RGB(52, 109, 197));
	pDC->SetPixel(m_point.x - 1, m_point.y + 1, RGB(52, 109, 197));
}

void CPaintAppView::selectShape(CDC * dc, CPoint pointStart, CPoint pointEnd)
{
	dc->MoveTo(pointStart.x, pointStart.y);
	dc->LineTo(pointEnd.x, pointStart.y);
	dc->MoveTo(pointEnd.x, pointStart.y);
	dc->LineTo(pointEnd.x, pointEnd.y);
	dc->MoveTo(pointEnd.x, pointEnd.y);
	dc->LineTo(pointStart.x, pointEnd.y);
	dc->MoveTo(pointStart.x, pointEnd.y);
	dc->LineTo(pointStart.x, pointStart.y);
}

void CPaintAppView::getRect(CPoint start, CPoint end)
{
	//tren xuong trai phai
	if (start.x < end.x&&start.y < end.y)
	{
		if (checkZoomOut == false)
		{
			if (Type == CIRCLE || Type == SQUARE_)
			{
				rect.left = start.x - 1;
				rect.top = start.y - 1;
				rect.right = end.x + 1;
				rect.bottom = start.y + (end.x - start.x) + 1;
			}
			else
			{
				rect.left = start.x - 3;
				rect.top = start.y - 3;
				rect.right = end.x + 3;
				rect.bottom = end.y + 3;
			}
		}
		else
		{
			rect.left = start.x - 53;
			rect.top = start.y - 53;
			rect.right = end.x + 53;
			rect.bottom = end.y + 53;
		}
	}

	// duoi len trai phai
	if (start.x<end.x&&start.y >end.y)
	{
		if (checkZoomOut == false)
		{
			if (Type == CIRCLE || Type == SQUARE_)
			{
				rect.left = start.x - 1;
				rect.top = start.y + 1;
				rect.right = start.x + (start.y - end.y) + 1;
				rect.bottom = end.y - 1;
			}
			else
			{
				rect.left = start.x - 3;
				rect.top = start.y + 3;
				rect.right = end.x + 3;
				rect.bottom = end.y - 3;
			}
		}
		else
		{
			rect.left = start.x - 53;
			rect.top = start.y + 53;
			rect.right = end.x + 53;
			rect.bottom = end.y - 53;
		}
	}

	// duoi len phai trai
	if (start.x > end.x&&start.y > end.y)
	{
		if (checkZoomOut == false)
		{
			if (Type == CIRCLE || Type == SQUARE_)
			{
				rect.left = start.x + 3;
				rect.top = start.y + 3;
				rect.right = start.x - (start.y - end.y) - 3;
				rect.bottom = end.y - 3;
			}
			else
			{
				rect.left = start.x + 3;
				rect.top = start.y + 3;
				rect.right = end.x - 3;
				rect.bottom = end.y - 3;
			}
		}
		else
		{
			rect.left = start.x + 53;
			rect.top = start.y + 53;
			rect.right = end.x - 53;
			rect.bottom = end.y - 53;
		}
	}

	//tren xuong phai trai
	if (end.x < start.x&&start.y < end.y)
	{
		if (checkZoomOut == false)
		{
			if (Type == CIRCLE || Type == SQUARE_)
			{
				rect.left = start.x + 1;
				rect.top = start.y - 1;
				rect.right = start.x - (end.y - start.y) - 1;
				rect.bottom = end.y + 1;
			}
			else
			{
				rect.left = start.x + 3;
				rect.top = start.y - 3;
				rect.right = end.x - 3;
				rect.bottom = end.y + 3;
			}
		}
		else
		{
			rect.left = start.x + 53;
			rect.top = start.y - 53;
			rect.right = end.x - 53;
			rect.bottom = end.y + 53;
		}
	}
}
void CPaintAppView::OnButtonZoomout()
{
	// TODO: Add your command handler code here
	checkZoomOut = !checkZoomOut;
	OnPaint();
	Invalidate();
}


