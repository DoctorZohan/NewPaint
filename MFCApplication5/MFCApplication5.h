
// MFCApplication5.h : main header file for the MFCApplication5 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include "Canvas.h"
#include "MainFrm.h"

// CPaintApp:
// See MFCApplication5.cpp for the implementation of this class
//

static int get_int_from_cedit(const CEdit& edit)
{
	CString sWindowText;
	edit.GetWindowText(sWindowText);
	return _ttoi(sWindowText);
}

static CString get_CString(int value)
{
	CString strValue;
	strValue.Format(_T("%d"), value);
	return strValue;
}




class CPaintApp : public CWinApp
{
public:
	CPaintApp() noexcept;
	~CPaintApp();
	CMainFrame* m_pFrame;
	Canvas* m_canvas;
// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnAddRectangle();
	afx_msg void OnFileEditcanvas();
	afx_msg void OnAddCircle();
	afx_msg void OnAddTriangle();
	afx_msg void OnEditDelete();
};

extern CPaintApp theApp;
