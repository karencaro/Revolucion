// Revolucion.h : main header file for the Revolucion application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CRevolucionApp:
// See Revolucion.cpp for the implementation of this class
//

class CRevolucionApp : public CWinApp
{
public:
	CRevolucionApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRevolucionApp theApp;