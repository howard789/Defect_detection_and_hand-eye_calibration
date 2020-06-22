#pragma once
#include "afxwin.h"
#include "winsock2.h"
#include "ws2tcpip.h"
#include "ParamUtil.h"

// CDlg10 对话框

class CDlg10 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg10)
	virtual BOOL OnInitDialog();
public:
	CDlg10(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg10();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg10 };
#endif

protected:
	//HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	// 生成的消息映射函数

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	//afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnSocket(WPARAM	w, LPARAM l);

	DECLARE_MESSAGE_MAP()


public:
	CString m_ip;
	CString m_port;
	CString m_SendMessage;
	//CListBox m_MessageList;

private:
	char* serverName;
	char* serverPort;
	WSADATA wsaData;
	SOCKET ConnectSocket;
	void myOnPant();
	void conn();
	void close();
public:

	afx_msg void OnClickedConnbutton();
	afx_msg void OnClickedSnedbutton();
	afx_msg void OnBnClickedDisconnbutton();
	CString m_MessageEdit;
	afx_msg void OnEnChangeEdit2();
};