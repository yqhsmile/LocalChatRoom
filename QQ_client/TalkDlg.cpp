// TalkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "QQ_client.h"
#include "TalkDlg.h"

#include "QQ_clientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTalkDlg dialog


CTalkDlg::CTalkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTalkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTalkDlg)
	m_send = _T("");
	//}}AFX_DATA_INIT
}


void CTalkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTalkDlg)
	DDX_Text(pDX, IDC_SEND, m_send);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTalkDlg, CDialog)
	//{{AFX_MSG_MAP(CTalkDlg)
	ON_BN_CLICKED(IDC_SENDBTN, OnSendbtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTalkDlg message handlers

void CTalkDlg::OnSendbtn() 
{
	// TODO: Add your control notification handler code here

	//构造信息
	CString send_msg = "To:";
	send_msg += pParent->to_name;
	send_msg += "\r\nFrom:";
	send_msg += pParent->from_name;
	send_msg += "\r\nContext:";
	UpdateData(true);
	send_msg += m_send;
	send_msg += "\r\n.\r\n";

	if( SOCKET_ERROR == send(socket_client,send_msg,send_msg.GetLength(),NULL) )
	{
		int err_code = WSAGetLastError();
	}

	CDialog::OnCancel();		//发完消息关闭对话框
}

BOOL CTalkDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//获取父窗口句柄
	pParent = (CQQ_clientDlg *)GetParent();
	//获取父窗口成员变量
	socket_client = pParent->socket_client;

	CString str_msg = "发送信息到：";
	str_msg += pParent->to_name;
	this->SetWindowText(str_msg);

	//清空文本框
	SetDlgItemText(IDC_SEND,"");

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


