#if !defined(AFX_TALKDLG_H__34202D57_71EF_4AF6_B1E2_6D06AF097E7B__INCLUDED_)
#define AFX_TALKDLG_H__34202D57_71EF_4AF6_B1E2_6D06AF097E7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TalkDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTalkDlg dialog
class CQQ_clientDlg;		//new

class CTalkDlg : public CDialog
{
// Construction
public:
	CTalkDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTalkDlg)
	enum { IDD = IDD_TALK };
	CString	m_send;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTalkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CQQ_clientDlg	*pParent;
	SOCKET			socket_client;

	// Generated message map functions
	//{{AFX_MSG(CTalkDlg)
	afx_msg void OnSendbtn();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TALKDLG_H__34202D57_71EF_4AF6_B1E2_6D06AF097E7B__INCLUDED_)
