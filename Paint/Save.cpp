// Save.cpp : implementation file
//

#include "stdafx.h"
#include "PaintApp.h"
#include "Save.h"
#include "afxdialogex.h"


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
	*checkS = 1;
	CDialogEx::OnCancel();
}


void Save::OnBnClickedBottomNo()
{
	// TODO: Add your control notification handler code here
	*checkS = 2;
	CDialogEx::OnCancel();
}
