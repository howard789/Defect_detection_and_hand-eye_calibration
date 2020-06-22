#pragma once
#pragma warning( disable : 4996) 
#include "SerialPort.h"

// CDlg11 对话框

class CDlg11 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg11)

public:
	CDlg11(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg11();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()



public:

private:
	CSerialPort m_SerialPort;
	BOOL m_bSerialPortOpened;   //判断串口是否打开

	CString m_strEditReceiveMsg;
	CString m_strEditSendMsg;
	CComboBox m_ctrlComboComport;

	///真正的发送数据区域
	void SendCommand(CString strCommand);

	///字符串转换为十六进制
	int Str2Hex(CString str, char *senddata);

	///将0-F字符转换为相应的十进制数
	char HexChar(char c);

	///计算CRC-Modbus校验码
	unsigned short CRC_Modbus(unsigned char*puchMsg, unsigned short usDataLen);








	int m_CurrentCircle;
	int m_CurrentPos;
	int m_AbsPos;
	int m_PulsePerS;
	int m_mmPerS;

	bool isContinueReading;//连续读值
	bool startVelocityMes;//开始测速
	int btn_select;//记录本次选择，1=位置清零。2=读取当前位置
	int m_PreviousPos;//上一次的脉冲，用于计算速度

public:
	afx_msg LRESULT OnComm(WPARAM ch, LPARAM port);  //串口响应函数

	afx_msg void OnBnClickedOpenComport();
	afx_msg void OnBnClickedCloseComport();
	afx_msg void OnBnClickedButtonSend();
};
