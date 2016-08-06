// QQ_client.h : main header file for the QQ_CLIENT application
//

#if !defined(AFX_QQ_CLIENT_H__6813B991_DE0B_45EE_99F6_E57022C759D1__INCLUDED_)
#define AFX_QQ_CLIENT_H__6813B991_DE0B_45EE_99F6_E57022C759D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQQ_clientApp:
// See QQ_client.cpp for the implementation of this class
//

class CQQ_clientApp : public CWinApp
{
public:
	CQQ_clientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQ_clientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQQ_clientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQ_CLIENT_H__6813B991_DE0B_45EE_99F6_E57022C759D1__INCLUDED_)
