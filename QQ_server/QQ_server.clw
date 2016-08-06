; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQQ_serverDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "QQ_server.h"

ClassCount=3
Class1=CQQ_serverApp
Class2=CQQ_serverDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_QQ_SERVER_DIALOG

[CLS:CQQ_serverApp]
Type=0
HeaderFile=QQ_server.h
ImplementationFile=QQ_server.cpp
Filter=N

[CLS:CQQ_serverDlg]
Type=0
HeaderFile=QQ_serverDlg.h
ImplementationFile=QQ_serverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_MEMBER

[CLS:CAboutDlg]
Type=0
HeaderFile=QQ_serverDlg.h
ImplementationFile=QQ_serverDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_QQ_SERVER_DIALOG]
Type=1
Class=CQQ_serverDlg
ControlCount=4
Control1=IDCANCEL,button,1342242816
Control2=IDC_STARTRUN,button,1342242816
Control3=IDC_MEMBER,SysListView32,1350631426
Control4=IDC_STATIC,static,1342308352

