#pragma once


// Save dialog

class Save : public CDialogEx
{
	DECLARE_DYNAMIC(Save)

public:
	Save(CWnd* pParent = NULL);   // standard constructor
	virtual ~Save();
	int *checkS;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SAVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonYes();
	afx_msg void OnBnClickedBottomNo();
};

class Close : public CDialogEx
{
	DECLARE_DYNAMIC(Close)

public:
	Close(CWnd* pParent = NULL);   // standard constructor
	virtual ~Close();
	int* nClose;
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SAVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonYes();
	afx_msg void OnBnClickedBottomNo();
};