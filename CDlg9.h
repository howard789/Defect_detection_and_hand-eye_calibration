#pragma once
#include "ParamUtil.h"
#include <afxsock.h>
#include "stdafx.h"

// CDlg9 对话框

class CDlg9 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg9)

public:
	CDlg9(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc &doc, MotionControlCardUtil &motionCard, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg9();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg9 };
#endif

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	// Generated message map functions
	//{{AFX_MSG(CMyQQDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonConnect();
	afx_msg void OnButtonDisconnect();
	afx_msg void OnButtonSendMsg();
	afx_msg void OnButtonSendFile();
	afx_msg void OnButtonClear();
	afx_msg void OnRadioTcp();
	afx_msg void OnRadioUdp();
	afx_msg void OnRadioServer();
	afx_msg void OnRadioClient();
	afx_msg void OnRadioBoth();
	afx_msg void OnButtonStopFile();
	afx_msg LRESULT OnKSend(WPARAM wParam, LPARAM lParam);//发送消息
	afx_msg void OnButtonCaputer();
	//}}AFX_MSG




private:
	ParamUtil &paramUtil;
	MotionControlCardUtil &motionCard;
	Doc &doc;
	CameraUtil &cameraUtil;
	HalconUtil &halconUtil;
public:
	afx_msg void OnBnClickedButtonConnect();

	char * hexToCharIP(in_addr addrIP);















public:
	CProgressCtrl	m_Progress;
	CListBox	m_AddMsgLIst;
	CIPAddressCtrl	m_You_IP;
	CString	m_MsgSend;

	virtual BOOL PreTranslateMessage(MSG* pMsg);

	int SaveYouFile(CSocket &recSo, SOCKADDR_IN &client);
	int ReceiveFileMsg(CSocket & socket, SOCKADDR_IN &client);
	int GetIpAddress(const CString & sHostName, CString & sIpAddress);
	int GetLocalHostName(CString &sHostName);
	CString GetError(DWORD error);
	int	m_nSockType;	//连接类型
	int m_WorkType;		//工作方式 server0,client1,both2
	void AddMsgList(CString IP, CString str); //LISTBOX控件添加信息
	int m_client, m_server;
	CString m_fileName;
	bool FileWork, FileStop, StopServer;
	void SaveYouScreen(HBITMAP hBitmap, SOCKADDR_IN &client);
	HBITMAP CopyScreenToBitmap();
	char m_type;//接受类型/F-文件，C-抓平，D-关闭,M-消息
	int m_Potr;//当前使用端口
	int GetNamebyAddress(const CString &IpAddress, CString &sYouName);//获得对方计算机名称







	afx_msg void OnEnChangeEditSendmsg();
};


struct FILEINFO
{
	int fileLength;
	char fileName[100];

};