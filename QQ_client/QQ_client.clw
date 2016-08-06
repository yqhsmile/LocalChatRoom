; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTalkDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "QQ_client.h"

ClassCount=4
Class1=CQQ_clientApp
Class2=CQQ_clientDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_QQ_CLIENT_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CTalkDlg
Resource4=IDD_TALK

[CLS:CQQ_clientApp]
Type=0
HeaderFile=QQ_client.h
ImplementationFile=QQ_client.cpp
Filter=N

[CLS:CQQ_clientDlg]
Type=0
HeaderFile=QQ_clientDlg.h
ImplementationFile=QQ_clientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LISTMEM

[CLS:CAboutDlg]
Type=0
HeaderFile=QQ_clientDlg.h
ImplementationFile=QQ_clientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_QQ_CLIENT_DIALOG]
Type=1
Class=CQQ_clientDlg
ControlCount=9
Control1=IDCANCEL,button,1342242816
Control2=IDC_CONNECT,button,1342242816
Control3=IDC_LISTMEM,SysListView32,1350631426
Control4=IDC_STATIC,static,1342308352
Control5=IDC_USERNAME,edit,1350631552
Control6=IDC_FROM,static,1342308352
Control7=IDC_RECV,edit,1352728580
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[DLG:IDD_TALK]
Type=1
Class=CTalkDlg
ControlCount=3
Control1=IDC_SENDBTN,button,1342242816
Control2=IDC_SEND,edit,1352728580
Control3=IDC_STATIC,static,1342308352

[CLS:CTalkDlg]
Type=0
HeaderFile=TalkDlg.h
ImplementationFile=TalkDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SEND

