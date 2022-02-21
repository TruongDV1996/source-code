// Save.cpp : implementation file
//

#include "stdafx.h"
#include "PaintApp.h"
#include "Base.h"
#include "afxdialogex.h"

typedef enum tYesNo {
	Yes = 1,
	No = 2
}tYesNo;


// Save dialog

IMPLEMENT_DYNAMIC(Save, CDialogEx)

Save::Save(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_SAVE, pParent)
{
	checkS = new int;
	*checkS = 0;
}

Save::~Save()
{	
	checkS = 0;
	delete checkS;
}

void Save::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Save, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_YES, &Save::OnBnClickedButtonYes)
	ON_BN_CLICKED(ID_BOTTOM_NO, &Save::OnBnClickedBottomNo)
END_MESSAGE_MAP()


// Save message handlers


void Save::OnBnClickedButtonYes()
{
	// TODO: Add your control notification handler code here
	*checkS = Yes;
	CDialogEx::OnCancel();
}


void Save::OnBnClickedBottomNo()
{
	// TODO: Add your control notification handler code here
	*checkS = No;
	CDialogEx::OnCancel();
}

IMPLEMENT_DYNAMIC(Close, CDialogEx)
Close::Close(CWnd* pParent) 
	: CDialogEx(IDD_DIALOG_SAVE, pParent)
{
	nClose = new int;
	nClose = 0;
}

Close::~Close()
{
	nClose = 0;
	delete nClose;
}

BEGIN_MESSAGE_MAP(Close, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_YES, &Close::OnBnClickedButtonYes)
	ON_BN_CLICKED(ID_BOTTOM_NO, &Close::OnBnClickedBottomNo)
END_MESSAGE_MAP()

void Close::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void Close::OnBnClickedButtonYes()
{
	// TODO: Add your control notification handler code here
	*nClose = Yes;
	CDialogEx::OnCancel();
}

void Close::OnBnClickedBottomNo()
{
	*nClose = No;
	CDialogEx::OnCancel();
}
