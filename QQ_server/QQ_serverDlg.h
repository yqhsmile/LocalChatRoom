// QQ_serverDlg.h : header file
//

#if !defined(AFX_QQ_SERVERDLG_H__5D99A64D_4A30_41C3_B660_4D084A1F78C4__INCLUDED_)
#define AFX_QQ_SERVERDLG_H__5D99A64D_4A30_41C3_B660_4D084A1F78C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//自定义消息
#define WM_SOCKET	WM_USER + 100

//定义结构
struct client_info
{
	BOOL	isUsed;
	CString name;
	SOCKET	user_socket;
};
/////////////////////////////////////////////////////////////////////////////
// CQQ_serverDlg dialog

class CQQ_serverDlg : public CDialog
{
// Construction
public:
	CQQ_serverDlg(CWnd* pParent = NULL);	// standard constructor

	//维护成员列表的函数
	BOOL	addMember(CString name,SOCKET sock);
	BOOL	delMember(SOCKET sock);

	//解析接收到的信息
	CString getKeyMsg(CString recv_msg,CString keyword);

	//向客户端发送消息的函数
	void	SendMemName(SOCKET sock,CString name);
	void	SendAllMem();
	void	TransMsg(CString recv_msg);

	//列表框控件的操作
	void InitListView();
	void AddListMem(CString name,int index);

// Dialog Data
	//{{AFX_DATA(CQQ_serverDlg)
	enum { IDD = IDD_QQ_SERVER_DIALOG };
	CListCtrl	m_memlist;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQ_serverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON			m_hIcon;
	SOCKET			socket_server;
	client_info		info[5];
	CImageList		m_imagelist;

	// Generated message map functions
	//{{AFX_MSG(CQQ_serverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartrun();
	virtual void OnCancel();
	//}}AFX_MSG
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQ_SERVERDLG_H__5D99A64D_4A30_41C3_B660_4D084A1F78C4__INCLUDED_)
