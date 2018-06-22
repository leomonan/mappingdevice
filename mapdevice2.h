// mapdevice2.h : main header file for the MAPDEVICE2 application
//

#if !defined(AFX_MAPDEVICE2_H__F9D3471C_65BB_4EBE_802F_F39106709B04__INCLUDED_)
#define AFX_MAPDEVICE2_H__F9D3471C_65BB_4EBE_802F_F39106709B04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMapdevice2App:
// See mapdevice2.cpp for the implementation of this class
//

class CMapdevice2App : public CWinApp
{
public:
	CMapdevice2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapdevice2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMapdevice2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPDEVICE2_H__F9D3471C_65BB_4EBE_802F_F39106709B04__INCLUDED_)
