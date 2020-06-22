//#pragma once
//#include "ParamUtil.h"
//#include "SerialPort.h"
//#include "AnimateDlgIcon.h" 
//
//
//
//
//#include "corecrt_io.h"
//
//
//
//
//
//// CDlg4 对话框
//
//class CDlg4 : public CDialogEx
//{
//
//
//	DECLARE_DYNAMIC(CDlg4)
//
//public:
//	CDlg4(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc &doc, MotionControlCardUtil &motionCard, CWnd* pParent = nullptr);   // 标准构造函数
//	virtual ~CDlg4();
//
////construct 
//public:
//	BOOL m_bVisible;   //程序是否浮在最上面 用于图钉按钮功能
//	BOOL m_bStopDispRXData; //是否显示接收字符
//	CString m_strTempSendFilePathName; //发送文件路径名
//	long m_nFileLength;  //文件长度
//	BOOL m_bSendFile;    //是否发送文件
//	HICON m_hIconRed;    //串口打开时的红灯图标句柄
//	HICON m_hIconOff;    //串口关闭时的指示图标句柄
//	HICON m_hIconGreen;
//
//	int m_nBaud;       //波特率
//	int m_nCom;         //串口号
//	char m_cParity;    //校验
//	int m_nDatabits;    //数据位
//	int m_nStopbits;    //停止位
//	CSerialPort m_Port;  //CSerialPort类对象
//	CAnimateDlgIcon m_animIcon;  //动画图标
//
//// Dialog Data
//	CButton	m_ctrlHelp;
//	//CPushPinButton	m_ctrlPushPin;
//	CButton	m_ctrlSendFile;
//	CEdit	m_ctrlEditSendFile;
//	CStatic	m_ctrlTXCount;
//	CStatic	m_ctrlPortStatus;
//	CStatic	m_ctrlRXCOUNT;
//	CEdit	m_ctrlSavePath;
//	CButton	m_ctrlManualSend;
//	//CHyperLink	m_ctrlHyperLink2;
//	CButton	m_ctrlClearTXData;
//	CStatic	m_ctrlStaticXFS;
//	CButton	m_ctrlClose;
//	CButton	m_ctrlCounterReset;
//	CEdit	m_ctrlEditSend;
//	CEdit	m_ctrlReceiveData;
//	CButton	m_ctrlAutoClear;
//	CStatic	m_ctrlIconOpenoff;
//	//CHyperLink	m_ctrlHyperLinkWWW;
//	CComboBox	m_StopBits;
//	CComboBox	m_DataBits;
//	CComboBox	m_Parity;
//	CButton	m_ctrlAutoSend;
//	CButton	m_ctrlHexSend;
//	CButton	m_ctrlStopDisp;
//	CButton	m_ctrlOpenPort;
//	CButton	m_ctrlHexReceieve;
//	CComboBox	m_Speed;
//	CComboBox	m_Com;
//	CString	m_ReceiveData;
//	CString	m_strSendData;
//	CString	m_strCurPath;
//	CString	m_strSendFilePathName;
//
//
//
//
//	// Implementation
//protected:
//	int m_nCycleTime;
//	BOOL m_bAutoSend;
//	int Str2Hex(CString str, char *data);
//	char HexChar(char c);
//	DWORD m_dwCommEvents;
//	BOOL m_bOpenPort;
//	HICON m_hIcon;
//
//
//
//
//
//// 对话框数据
//#ifdef AFX_DESIGN_TIME
//	enum { IDD = IDD_Dlg4 };
//#endif
//
//protected:
//	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
//
//	DECLARE_MESSAGE_MAP()
//
//private:
//	ParamUtil &paramUtil;
//	MotionControlCardUtil &motionCard;
//	Doc &doc;
//	CameraUtil &cameraUtil;
//	HalconUtil &halconUtil;
//
//public:
//
//
//	
//	void myOnInitDialog();
//
//	virtual BOOL OnInitDialog();
//	afx_msg LRESULT OnCommunication(WPARAM ch, LPARAM port);
//	afx_msg LRESULT OnFileSendingEnded(WPARAM wParam, LPARAM port);
//	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
//	afx_msg void OnPaint();
//	afx_msg HCURSOR OnQueryDragIcon();
//	afx_msg void OnButtonClearReciArea();
//	afx_msg void OnButtonOpenport();
//	afx_msg void OnButtonStopdisp();
//	afx_msg void OnButtonManualsend();
//	afx_msg void OnCheckAutosend();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnChangeEditCycletime();
//	afx_msg void OnChangeEditSend();
//	afx_msg void OnButtonClearrecasenda();
//	afx_msg void OnSelendokComboComselect();
//	afx_msg void OnSelendokComboSpeed();
//	afx_msg void OnSelendokComboParity();
//	afx_msg void OnSelendokComboDatabits();
//	afx_msg void OnSelendokComboStopbits();
//	afx_msg void OnButtonSavedata();
//	afx_msg void OnButtonDirbrowser();
//	afx_msg void OnButtonSendfile();
//	afx_msg void OnButtonCountreset();
//	afx_msg void OnButtonClose();
//	afx_msg void OnButtonFilebrowser();
//	afx_msg void OnButtonPushpin();
//	afx_msg void OnDestroy();
//
//	afx_msg void OnBnClickedCheckHexsend();
//	afx_msg void OnBnClickedButton1();
//
//
//
//	void cleanPos();
//
//	void sendMsgHex(CString str);
//	void sendMsgNormal(CString str);
//	bool isSerialOpen();
//	int m_CurrentCircle;
//	int m_CurrentPos;
//	int m_AbsPos;
//	int m_PulsePerS;
//	int m_mmPerS;
//
//	bool isContinueReading;//连续读值
//	bool startVelocityMes;//开始测速
//	int btn_select;//记录本次选择，1=位置清零。2=读取当前位置
//	int m_PreviousPos;//上一次的脉冲，用于计算速度
//
//
//
//	afx_msg void OnBnClickedButton2();
//	afx_msg void OnBnClickedButton3();
//	afx_msg void OnBnClickedButton4();
//	void updatePosData(CString strTemp);
//	void updateVelocityData();
//	bool crc(byte buffer[]);
//	void receiveData(int btn_select, byte RecieveBuf[], vector<string>* vec);
//	afx_msg void OnCbnSelchangeComboComselect();
//};
