
// MFC_projectView.h : interface of the CPaintAppView class
//
#pragma once
#include "Line.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Square.h"
#include "Pen.h"
#include "Diamon.h"
#include "Hexagon.h"
#include "Pentagon.h"
#include "Triagle.h"
#include <vector>
#include "Save.h"
#include "Elip.h"
using namespace std;
class CPaintAppView : public CView
{
protected: // create from serialization only
	CPaintAppView();
	DECLARE_DYNCREATE(CPaintAppView)
	//	COLORREF CurrentColor;
	// Attributes
public:
	CPaintAppDoc* GetDocument() const;

	// Operations
public:

	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	// value
public:
	vector<CShapeEx*> shapes;
	CShapeEx * currShape = NULL;
	COLORREF currColor = RGB(0, 0, 0);
	int currPenSize =1;
	int currPenStyle =PS_SOLID;
	COLORREF fillColor= RGB(255, 255, 255);
	DRAWMODE Type;
	int chooseChange=0;
	int MoveIndex = -1;
	string flag;
	CPoint currentLocation = NULL, pointStart = NULL,locationPoint=NULL;
	CDC *pDc;
	BOOL bDown,checkObject,checkDelete,isFill,checkRotate,checkZoomIn,checkZoomOut;
	CRect rect;
public:
	virtual ~CPaintAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPen();
	afx_msg void OnUpdatePen(CCmdUI *pCmdUI);
	afx_msg void OnClorRed();
	afx_msg void OnClorGreen();
	afx_msg void OnClorBack();
	afx_msg void OnClorBrow();
	afx_msg void OnClorViolet();
	afx_msg void OnUpdateIndicatorPos(CCmdUI *pCmdUI);
	afx_msg void OnUpdateButtonLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateButtonCir(CCmdUI *pCmdUI);
	afx_msg void OnUpdateButtonDiamo(CCmdUI *pCmdUI);
	afx_msg void OnButtonLine();
	afx_msg void OnPaint();
	afx_msg void OnButtonCir();
	afx_msg void OnButtonClorr();
	afx_msg void OnButtonChang();
	afx_msg void OnButtonMove();
	afx_msg void OnButtonReg();
	afx_msg void OnButtonSquare();
	afx_msg void OnButtonDelete();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	void saveToBinaryFile(string filePath);
	void loadFromBinaryFile(string filePath);
	afx_msg void OnButton1();
	afx_msg void OnUpdateButton1(CCmdUI *pCmdUI);
	afx_msg void OnButton2();
	afx_msg void OnUpdateButton2(CCmdUI *pCmdUI);
	afx_msg void OnButton3();
	afx_msg void OnUpdateButton3(CCmdUI *pCmdUI);
	afx_msg void OnButtonDashdot();
	afx_msg void OnUpdateButtonDashdot(CCmdUI *pCmdUI);
	afx_msg void OnButtonDot();
	afx_msg void OnUpdateButtonDot(CCmdUI *pCmdUI);
	afx_msg void OnButtonSolid();
	afx_msg void OnUpdateButtonSolid(CCmdUI *pCmdUI);
	afx_msg void OnUpdateButtonReg(CCmdUI *pCmdUI);
	afx_msg void OnUpdateButtonSquare(CCmdUI *pCmdUI);
	afx_msg void OnUpdateClorBack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateClorBrow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateClorGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateClorRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateClorViolet(CCmdUI *pCmdUI);
	afx_msg void OnFileNew();
	afx_msg void OnButtonFill();
	afx_msg void OnUpdateButtonFill(CCmdUI *pCmdUI);
	afx_msg void OnButtonHexa();
	afx_msg void OnUpdateButtonHexa(CCmdUI *pCmdUI);
	afx_msg void OnButtonPenta();
	afx_msg void OnUpdateButtonPenta(CCmdUI *pCmdUI);
	afx_msg void OnButtonTri();
	afx_msg void OnUpdateButtonTri(CCmdUI *pCmdUI);
	afx_msg void OnButtonDiamo();
	afx_msg void OnButtonRotate();
	afx_msg void OnUpdateButtonRotate(CCmdUI *pCmdUI);
	afx_msg void OnIndicatorExt();
	afx_msg void ShowLocationMove(CDC *, CPoint);
	afx_msg void selectShape(CDC *,CPoint pointStart ,CPoint pointEnd);
	afx_msg void getRect(CPoint start, CPoint end);
	afx_msg void OnFileSaveAs();

	afx_msg void OnButtonElip();
	afx_msg void OnUpdateButtonElip(CCmdUI *pCmdUI);
	afx_msg void OnButtonZoomout();
	afx_msg void OnUpdateButtonZoomout(CCmdUI *pCmdUI);
	afx_msg void OnButtonZoomin();
	afx_msg void OnUpdateButtonZoomin(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in MFC_projectView.cpp
inline CPaintAppDoc* CPaintAppView::GetDocument() const
{
	return reinterpret_cast<CPaintAppDoc*>(m_pDocument);
}
#endif

