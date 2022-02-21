
// MFC_project.h : main header file for the MFC_project application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPaintApp:
// See PaintApp.cpp for the implementation of this class
//

class CPaintApp : public CWinAppEx
{
public:
	CPaintApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();
	
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPaintApp theApp;
