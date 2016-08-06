// QQ_clientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "QQ_client.h"
#include "QQ_clientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQQ_clientDlg dialog

CQQ_clientDlg::CQQ_clientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQQ_clientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQQ_clientDlg)
	m_username = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	index_image = 0;
}

void CQQ_clientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQQ_clientDlg)
	DDX_Control(pDX, IDC_LISTMEM, m_listmem);
	DDX_Text(pDX, IDC_USERNAME, m_username);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CQQ_clientDlg, CDialog)
	//{{AFX_MSG_MAP(CQQ_clientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_NOTIFY(NM_DBLCLK, IDC_LISTMEM, OnDblclkListmem)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SOCKET,OnSocket)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQQ_clientDlg message handlers

BOOL CQQ_clientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//创建图像列表
	m_imagelist.Create(32,32,ILC_COLOR32,4,4);
	//添加图像
	for(int i = 0;i < 4;i++)
	{
		m_imagelist.Add( LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(130+i)) );
	}
	//关联到列表控件中
	m_listmem.SetImageList(&m_imagelist,LVSIL_SMALL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CQQ_clientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQQ_clientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQQ_clientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CQQ_clientDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here

	//加载套接字库
	WORD	ver = MAKEWORD(2,0);
	WSADATA	wsadata;
	if( WSAStartup(ver,&wsadata) )
	{
		AfxMessageBox("加载套接字库失败");
		return;
	}
	
	//创建套接字，基于TCP
	socket_client = socket(AF_INET,SOCK_STREAM,NULL);
	if( INVALID_SOCKET == socket_client )
	{
		AfxMessageBox("创建套接字失败");
		return;
	}

	//连接服务器
	sockaddr_in	addr;
	addr.sin_family = AF_INET;
	addr.sin_port	= htons(80);
	addr.sin_addr.S_un.S_addr = inet_addr("10.170.1.135");		//默认服务器的IP值
	if( SOCKET_ERROR == connect(socket_client,(sockaddr *)&addr,sizeof(sockaddr)) )
	{
		AfxMessageBox("服务器连接失败");
		return;
	}

	//发送客户端名称信息
	UpdateData(true);
	CString str_name = "From:";
	str_name		+= m_username;
	str_name		+= "\r\n";

	from_name		 = m_username;					//保存客户端名称
	GetDlgItem(IDC_USERNAME)->EnableWindow(false);	//禁用用户名输入框

	if( SOCKET_ERROR == send(socket_client,str_name,str_name.GetLength(),NULL) )
	{
		AfxMessageBox("名称信息发送出错");
		return;
	}

	//设置异步套接字
	if( SOCKET_ERROR == WSAAsyncSelect(socket_client,this->m_hWnd,WM_SOCKET,FD_READ) )
	{
		AfxMessageBox("异步套接字设置出错");
		return;
	}

	//提示信息
	AfxMessageBox("连接服务器成功");
	GetDlgItem(IDC_CONNECT)->EnableWindow(false);	//禁用“连接服务器”按钮
}

void CQQ_clientDlg::OnSocket(WPARAM wParam,LPARAM lParam)
{
	char buff_recv[512] = "";
	CString str_temp;
	switch(lParam)
	{
	case FD_READ:
		if( SOCKET_ERROR == recv(socket_client,buff_recv,512,NULL) )
		{
			AfxMessageBox("信息接收失败");
			return;
		}

		//处理服务器发送过来的成员信息
		if(buff_recv[0] == 'L')
		{
			str_temp = getKeyMsg(buff_recv,"List");
			//更新图像列表
			UpdateList(str_temp);
			return;
		}

		//处理其他成员发送过来的信息
		if(buff_recv[0] == 'T')
		{
			//获取发送者信息
			str_temp = getKeyMsg(buff_recv,"From");
			to_name	 = str_temp;
			SetDlgItemText(IDC_FROM,to_name);
			
			//获取信息内容
			str_temp = getKeyMsg(buff_recv,"Context");
			SetDlgItemText(IDC_RECV,str_temp);

			return;
		}
		break;
	}
}
//更新列表控件成员
void CQQ_clientDlg::UpdateList(CString MemList)
{
	//先删除原来的列表图像
	int nCount = m_listmem.GetItemCount();
	for (int j=0; j < nCount; j++)
	{
		m_listmem.DeleteItem(0);
	}

	//添加新的成员
	index_image = 0;	//初始化图片索引
	CString name;
	for(int i=0;i<MemList.GetLength();i++)
	{
		if(MemList.GetAt(i) == ',' )
		{
			AddMem(name);
			name = "";
			continue;
		}
		name += MemList.GetAt(i);
	}
}

//对接收到的数据进行解析
CString CQQ_clientDlg::getKeyMsg(CString recv_msg,CString keyword)
{
	int index_start = 0,index_end = 0;
	int index = 0;
	CString str_temp = "";
	
	if("From" == keyword)
	{
		index_start = recv_msg.Find("From:");
		index_end	= recv_msg.Find("\r\n",index_start);
		for(index = index_start+5;index < index_end;index++)
		{
			str_temp += recv_msg.GetAt(index);
		}
		return str_temp;
	}

	if("List" == keyword)
	{
		index_start = recv_msg.Find("List:");
		index_end	= recv_msg.Find("\r\n",index_start);
		for(index = index_start+5;index < index_end;index++)
		{
			str_temp += recv_msg.GetAt(index);
		}
		return str_temp;
	}

	if("Context" == keyword)
	{
		index_start = recv_msg.Find("Context:");
		index_end	= recv_msg.Find("\r\n.\r\n",index_start);
		for(index = index_start+8;index < index_end;index++)
		{
			str_temp += recv_msg.GetAt(index);
		}
		return str_temp;
	}
	
	return "";
}

void CQQ_clientDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	closesocket(socket_client);

	WSACleanup();
	CDialog::OnCancel();
}

//往列表控件中添加成员
void CQQ_clientDlg::AddMem(CString name)
{
	LVITEM lvitem;
	memset(&lvitem,0,sizeof(LVITEM));
	lvitem.mask = LVIF_IMAGE | LVIF_TEXT;
	lvitem.pszText = name.GetBuffer(0);
	lvitem.iImage = index_image % 4;	//循环使用4幅图片
	
	m_listmem.InsertItem(&lvitem);
	index_image++;
}

void CQQ_clientDlg::OnDblclkListmem(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	POSITION pos = m_listmem.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox("No items were selected!\n");
		return;
	}
	else
	{
		int nItem = m_listmem.GetNextSelectedItem(pos);
		to_name = m_listmem.GetItemText(nItem,0);
		m_dlg.DoModal();
	}

	*pResult = 0;
}

