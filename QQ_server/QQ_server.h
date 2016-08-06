// QQ_server.h : main header file for the QQ_SERVER application
//

#if !defined(AFX_QQ_SERVER_H__17ED7996_A85D_4077_B434_A9FF1BC07386__INCLUDED_)
#define AFX_QQ_SERVER_H__17ED7996_A85D_4077_B434_A9FF1BC07386__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQQ_serverApp:
// See QQ_server.cpp for the implementation of this class
//

class CQQ_serverApp : public CWinApp
{
public:
	CQQ_serverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQ_serverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQQ_serverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQ_SERVER_H__17ED7996_A85D_4077_B434_A9FF1BC07386__INCLUDED_)
