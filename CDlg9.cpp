// CDlg9.cpp: 实现文件
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "CDlg9.h"
#include "afxdialogex.h"


/////////////////////////////////////////////////////////////////////////////
// CDlg9 dialog



#define PORT		60000-2
#define FLAG		2
#define SIZEFILE	1024

#define WM_KSEND 123

const int SOCK_TCP = 0;	//TCP模式
const int SOCK_UDP = 1;	//UPD模式

CWinThread	*pThreadSendFile;	//发送文件线程-->_SendFileThread
CWinThread	*pThreadSendMsg;		//发送消息线程
CWinThread	*pThreadLisen;		//监听线程-->_ListenTcpThread
CWinThread	*pReceiveThread;		//接受线程-->_ReceiveThread
CWinThread  *pThreadCaputre;		//抓取屏幕线程


//////////////////////////////////////////////////////////////////////////////













// CDlg9 对话框

IMPLEMENT_DYNAMIC(CDlg9, CDialogEx)



CDlg9::CDlg9(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc & doc, MotionControlCardUtil & motionCard, CWnd* pParent /*=nullptr*/)
: CDialogEx(IDD_LEADSHINE, pParent), doc(doc), motionCard(motionCard), cameraUtil(cameraUtil), halconUtil(halconUtil), paramUtil(paramUtil)


{
	m_MsgSend = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nSockType = 0;//TCP
	m_WorkType = 2;//两者
	m_client = 0;
	m_server = 0;
	FileWork = false;
	FileStop = false;
	StopServer = false;
}

CDlg9::~CDlg9()
{
}

void CDlg9::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS_SEND_FILE, m_Progress);
	DDX_Control(pDX, IDC_LIST_BOX_ADDMSG, m_AddMsgLIst);
	DDX_Control(pDX, IDC_IPADDRESS, m_You_IP);
	DDX_Text(pDX, IDC_EDIT_SENDMSG, m_MsgSend);
}





BEGIN_MESSAGE_MAP(CDlg9, CDialogEx)

	//{{AFX_MSG_MAP(CDlg9)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, OnButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, OnButtonDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND_MSG, OnButtonSendMsg)
	ON_BN_CLICKED(IDC_BUTTON_SEND_FILE, OnButtonSendFile)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_RADIO_TCP, OnRadioTcp)
	ON_BN_CLICKED(IDC_RADIO_UDP, OnRadioUdp)
	ON_BN_CLICKED(IDC_RADIO_SERVER, OnRadioServer)
	ON_BN_CLICKED(IDC_RADIO_CLIENT, OnRadioClient)
	ON_BN_CLICKED(IDC_RADIO_BOTH, OnRadioBoth)
	ON_BN_CLICKED(IDC_BUTTON_STOP_FILE, OnButtonStopFile)
	//ON_MESSAGE(WM_KSEND, OnKSend)
	ON_BN_CLICKED(IDC_BUTTON_CAPUTER, OnButtonCaputer)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT_SENDMSG, &CDlg9::OnEnChangeEditSendmsg)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg9 message handlers

BOOL CDlg9::OnInitDialog()
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
	/////////////////////////////////////////////////////////
	CString strLocalName;
	GetLocalHostName(strLocalName);
	CString strLocalIP;
	GetIpAddress(strLocalName, strLocalIP);
	m_You_IP.SetWindowText(strLocalIP);	//设置默认IP为本机
	/////////////////////////////////////////////////////////
	((CButton*)GetDlgItem(IDC_RADIO_BOTH))->SetCheck(BST_CHECKED);//默认为服务器、客户端一体
	SetWindowText(_T("MyQQ TCP方式"));

	GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText(_T("启    动"));
	GetDlgItem(IDC_BUTTON_DISCONNECT)->SetWindowText(_T("关    闭"));

	GetDlgItem(IDC_BUTTON_CAPUTER)->EnableWindow(false);//默认为不可勇
	((CButton*)GetDlgItem(IDC_RADIO_TCP))->SetCheck(BST_CHECKED);//默认为TCP
	GetDlgItem(IDC_BUTTON_SEND_MSG)->EnableWindow(false);//发送消息不可用
	GetDlgItem(IDC_BUTTON_SEND_FILE)->EnableWindow(false);//发送文件不可用
	GetDlgItem(IDC_BUTTON_CLEAR)->EnableWindow(false);//清除不可用
	GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(false);//断开连接不可用
	GetDlgItem(IDC_PROGRESS_SEND_FILE)->ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlg9::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDlg9::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

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
HCURSOR CDlg9::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}
//////////////////////////////////线程///////////////////////////////////////////
//////////////////////////////////线程///////////////////////////////////////////



//////////////////////////////////服务器线程开始///////////////////////////////////////////

//TCP监听线程
UINT _ListenTcpThread(LPVOID lparam)
{
	CDlg9 *pDlg = (CDlg9 *)lparam;
	if (pDlg->StopServer == true)	return -1;

	CSocket sockSrvr;
	pDlg->m_Potr = PORT + pDlg->m_server;//保存当前使用端口，用于关闭
	int createSucceed = sockSrvr.Create(pDlg->m_Potr);
	if (createSucceed == 0)
	{
		AfxMessageBox(_T("_ListenTcpThread Create错误!") + pDlg->GetError(GetLastError()));
		return -1;
	}

	int listenSucceed = sockSrvr.Listen();	//开始监听
	if (listenSucceed == 0)
	{
		AfxMessageBox(_T("_ListenTcpThread Listen错误!") + pDlg->GetError(GetLastError()));
		return -1;
	}

	CSocket recSo;
	SOCKADDR_IN client;
	int iAddrSize = sizeof(client);

	int acceptSucceed = sockSrvr.Accept(recSo, (SOCKADDR *)&client, &iAddrSize);	//接受连接并取得对方IP
	if (acceptSucceed == 0)
	{
		AfxMessageBox(_T("_ListenTcpThread Accept错误!") + pDlg->GetError(GetLastError()));
		return -1;
	}
	sockSrvr.Close();
	char flag[FLAG] = { 0 };
	if (recSo.Receive(flag, FLAG) != 2)
	{
		return -1;
	}
	pDlg->m_type = flag[0];
	if (pDlg->m_type == 'D') return 0;

	pThreadLisen = ::AfxBeginThread(_ListenTcpThread, pDlg);
	pDlg->ReceiveFileMsg(recSo, client);
	return 0;

}




UINT _UDPThread(LPVOID lparam)	/////UDP接受信息线程开始
{

	CDlg9 *pDlg = (CDlg9 *)lparam;
	if (pDlg->StopServer == true)	return -1;

	CSocket sockSrvrUdp;
	sockSrvrUdp.Create(PORT + pDlg->m_client, SOCK_DGRAM);
	char buff[100] = { 0 };
	int ret = 0;
	CString ipStr;
	CString msg;
	UINT port;
	for (;;)
	{

		ret = sockSrvrUdp.ReceiveFrom(buff, 100, ipStr, port);//IP和port均为返回值

		if (buff[0] == 'D') return 0;
		if (ret == SOCKET_ERROR)
		{
			break;
		}
		msg.Format(_T("%s"),buff);
		pDlg->AddMsgList(ipStr, msg);
	}
	sockSrvrUdp.Close();
	return 0;
}





////////////////////////////////////服务器线程结束//////////////////////////////////////


////////////////////////////////////客户端线程开始//////////////////////////////////////

//发送文件线程
UINT _SendFileThread(LPVOID lparam)
{

	CDlg9 *pDlg = (CDlg9 *)lparam;
	if (pDlg->StopServer == true)	return -1;

	CSocket sockClient;
	sockClient.Create();
	CString ip;
	pDlg->m_You_IP.GetWindowText(ip);
	sockClient.Connect(ip, PORT + pDlg->m_client);
	//首先发送标记F为文件,2
	int end = 0;
	end = sockClient.Send("F", FLAG);
	///////////////////////////////////////////////////////////////////发送标志是否成功
	if (end == SOCKET_ERROR)
	{
		AfxMessageBox(_T("_SendFileThread Send错误!") + pDlg->GetError(GetLastError()));
		return -1;
	}

	else if (end != 2)
	{
		AfxMessageBox(_T("文件头错误"));
		return -1;
	}
	///////////////////////////////////////////////////////////////////
	CFile myFile;
	FILEINFO myFileInfo;
	if (!myFile.Open(pDlg->m_fileName, CFile::modeRead | CFile::typeBinary))
		return -1;
	myFileInfo.fileLength = myFile.GetLength();		//得到文件大小
	const char* ss = MfcUtil::CStringToChar(myFile.GetFileName());
	strcpy_s(myFileInfo.fileName, sizeof(myFile.GetFileName()), ss);//得到文件名称

	sockClient.Send(&myFileInfo, sizeof(myFileInfo));	//发送文件信息

	pDlg->m_Progress.SetRange32(0, myFileInfo.fileLength);

	myFile.Seek(0, CFile::begin);
	char m_buf[SIZEFILE] = { 0 };
	CString strError;
	int num = 0;
	end = 0;
	int temp = 0;
	pDlg->GetDlgItem(IDC_BUTTON_STOP_FILE)->EnableWindow(true);

	for (;;)
	{
		if (pDlg->FileWork == false)
		{
			pDlg->FileWork = true;
			pDlg->GetDlgItem(IDCANCEL)->EnableWindow(false);
			pDlg->GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(false);
		}
		num = myFile.Read(m_buf, SIZEFILE);
		if (num == 0) break;
		end = sockClient.Send(m_buf, num);
		temp += end;
		pDlg->m_Progress.SetPos(temp);
		if (pDlg->FileStop == true)
		{
			pDlg->FileStop = false;
			pDlg->FileWork = false;
			break;
		}

		if (end == SOCKET_ERROR)
		{
			AfxMessageBox(_T("_SendFileThread Send错误!") + pDlg->GetError(GetLastError()));
			break;

		}
	}
	pDlg->m_Progress.SetPos(0);
	CString strLocalName;
	pDlg->GetLocalHostName(strLocalName);
	CString strLocalIP;
	pDlg->GetIpAddress(strLocalName, strLocalIP);
	if (temp == myFileInfo.fileLength)
		pDlg->AddMsgList(strLocalIP + "->" + strLocalName, _T("文件发送成功"));
	else
		pDlg->AddMsgList(strLocalIP + "->" + strLocalName, _T("文件发送失败"));
	myFile.Close();
	sockClient.Close();
	pDlg->FileWork = false;
	pDlg->GetDlgItem(IDC_PROGRESS_SEND_FILE)->ShowWindow(SW_HIDE);
	pDlg->GetDlgItem(IDC_BUTTON_STOP_FILE)->EnableWindow(false);

	pDlg->GetDlgItem(IDCANCEL)->EnableWindow(true);
	pDlg->GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(true);

	return 0;
}



UINT _SendMsgThread(LPVOID lparam)	//TCP发送信息线程
{

	CDlg9 *pDlg = (CDlg9 *)lparam;
	if (pDlg->StopServer == true)	return -1;

	CSocket sockClient;
	sockClient.Create();
	CString ip, strError;
	pDlg->m_You_IP.GetWindowText(ip);
	int conn = sockClient.Connect(ip, PORT + pDlg->m_client);
	if (conn == 0)	///////////////////////////////////
	{
		AfxMessageBox(_T("_SendMsgThread Connect错误!") + pDlg->GetError(GetLastError()));
		sockClient.ShutDown(2);
		sockClient.Close();
		AfxEndThread(1L);
		return 0;

	}
	//首先发送标记M为信息,2
	int end = 0;
	end = sockClient.Send("M", FLAG);
	if (end == SOCKET_ERROR)
	{
		AfxMessageBox(_T("_SendMsgThread Send错误!") + pDlg->GetError(GetLastError()));
		return -1;
	}
	else if (end != 2)
	{
		AfxMessageBox(_T("消息头错误"));
		return -1;
	}
	CString strMsg = pDlg->m_MsgSend;
	USES_CONVERSION;
	char * ss = W2A(strMsg);
	end = sockClient.Send(ss, sizeof(ss));
	if (end == SOCKET_ERROR)
	{
		AfxMessageBox(_T("_SendMsgThread Send错误!") + pDlg->GetError(GetLastError()));
		return -1;
	}
	CString strLocalName;
	pDlg->GetLocalHostName(strLocalName);
	CString strLocalIP;
	pDlg->GetIpAddress(strLocalName, strLocalIP);
	pDlg->AddMsgList(strLocalIP + "->" + strLocalName, strMsg);

	int i = 0;
	sockClient.Close();

	return 0;
}
UINT _ThreadCapture(LPVOID lparam)	//抓取对方屏幕线程
{

	CDlg9 *pDlg = (CDlg9 *)lparam;
	if (pDlg->StopServer == true)	return -1;

	CSocket sockClient;
	sockClient.Create();
	CString ip;
	pDlg->m_You_IP.GetWindowText(ip);
	sockClient.Connect(ip, PORT + pDlg->m_client);
	//首先发送标记C为抓取,2
	int end = 0;
	end = sockClient.Send("C", FLAG);
	///////////////////////////////////////////////////////////////////发送标志是否成功
	if (end == SOCKET_ERROR)
	{
		AfxMessageBox(_T("_ThreadCapture Send错误!") + pDlg->GetError(GetLastError()));
		return -1;
	}

	else if (end != 2)
	{
		AfxMessageBox(_T("发送头错误"));
		return -1;
	}
	return 0;
}
///////////////////////////////////////////////////////////////////
UINT _SendMsgUdpThread(LPVOID lparam)	//UDP发送信息
{

	CDlg9 *pDlg = (CDlg9 *)lparam;
	if (pDlg->StopServer == true)	return -1;

	CSocket sockClientUdp;
	pDlg->m_type = PORT + pDlg->m_client + 10;
	sockClientUdp.Create(pDlg->m_type, SOCK_DGRAM);
	CString strMsg = pDlg->m_MsgSend;
	int ret = 0;
	CString ipStr;
	pDlg->m_You_IP.GetWindowText(ipStr);
	UINT port = PORT + pDlg->m_server;
	ret = sockClientUdp.SendTo(strMsg, strMsg.GetLength(), port, ipStr);
	if (ret == SOCKET_ERROR)
	{
		DWORD error = GetLastError();

	}
	CString strLocalName;
	pDlg->GetLocalHostName(strLocalName);
	CString strLocalIP;
	pDlg->GetIpAddress(strLocalName, strLocalIP);
	pDlg->AddMsgList(strLocalIP + "->" + strLocalName, strMsg);
	sockClientUdp.Close();
	return 0;

}

////////////////////////////////////客户端线程结束//////////////////////////////////////



///////////////////////////////////函数//////////////////////////////////////////

int CDlg9::ReceiveFileMsg(CSocket &recSo, SOCKADDR_IN &client)//接受函数
{
	//	if(StopServer==true)	return -1;
	if (m_type == 'C')		//抓取
	{
		SaveYouScreen(CopyScreenToBitmap(), client);//发送地址
	}

	else if (m_type == 'F')			//文件
	{
		SaveYouFile(recSo, client);
	}

	else if (m_type == 'M')	//信息
	{
		char buff[100] = { 0 };
		CString msg;
		int ret = 0;
		for (;;)
		{
			ret = recSo.Receive(buff, 100);
			if (ret == 0)
				break;
			msg += buff;
		}
		CString strOut, strIn;
		m_You_IP.GetWindowText(strIn);
		GetNamebyAddress(strIn, strOut);
		CString youName;
		youName.Format(_T("%d"),inet_ntoa(client.sin_addr));
		CString str = youName + "<-" + strOut;
		AddMsgList(str, msg);
	}
	recSo.Close();
	return 0;
}



HBITMAP CDlg9::CopyScreenToBitmap()
{
	CRect rect(0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	HDC hScrDC, hMemDC;	// 屏幕和内存设备描述表
	HBITMAP hBitmap, hOldBitmap;// 位图句柄
	int xScrn, yScrn;	// 屏幕分辨率
	hScrDC = CreateDC((LPCWSTR)("DISPLAY"), NULL, NULL, NULL);	//为屏幕创建设备描述表
	


	hMemDC = CreateCompatibleDC(hScrDC);//为屏幕设备描述表创建兼容的内存设备描述表
	xScrn = GetDeviceCaps(hScrDC, HORZRES);// 获得屏幕分辨率
	yScrn = GetDeviceCaps(hScrDC, VERTRES);
	hBitmap = CreateCompatibleBitmap(hScrDC, rect.Width(), rect.Height());// 创建一个与屏幕设备描述表兼容的位图
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);// 把新位图选到内存设备描述表中
	BitBlt(hMemDC, 0, 0, rect.Width(), rect.Height(), hScrDC, rect.left, rect.top, SRCCOPY);// 把屏幕设备描述表拷贝到内存设备描述表中
	hBitmap = (HBITMAP)SelectObject(hMemDC, hOldBitmap);//得到屏幕位图的句柄
	DeleteDC(hScrDC);//清除 
	DeleteDC(hMemDC);
	return hBitmap;// 返回位图句柄
}


void CDlg9::SaveYouScreen(HBITMAP hBitmap, SOCKADDR_IN &client)//接受屏幕
{
	HDC hDC; //设备描述表
	int iBits;//当前显示分辨率下每个像素所占字节数
	WORD wBitCount;//位图中每个像素所占字节数
	DWORD dwPaletteSize = 0,//定义调色板大小
		dwBmBitsSize,//位图中像素字节大小
		dwDIBSize;//位图文件大小 
	BITMAP Bitmap;//位图属性结构
	BITMAPFILEHEADER bmfHdr;//位图文件头结构
	BITMAPINFOHEADER bi;//位图信息头结构 
	LPBITMAPINFOHEADER lpbi;//指向位图信息头结构
	HANDLE hDib, hPal, hOldPal = NULL;//定义文件，分配内存句柄，调色板句柄
	hDC = CreateDC((LPCWSTR)("DISPLAY"), NULL, NULL, NULL);
	iBits = GetDeviceCaps(hDC, BITSPIXEL) *
		GetDeviceCaps(hDC, PLANES);//计算位图文件每个像素所占字节数
	DeleteDC(hDC);
	if (iBits <= 1)
		wBitCount = 1;
	else if (iBits <= 4)
		wBitCount = 4;
	else if (iBits <= 8)
		wBitCount = 8;
	else if (iBits <= 24)
		wBitCount = 24;
	if (wBitCount <= 8)
		dwPaletteSize = (1 << wBitCount) * sizeof(RGBQUAD);//计算调色板大小

	//设置位图信息头结构
	GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&Bitmap);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = Bitmap.bmWidth;
	bi.biHeight = Bitmap.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = wBitCount;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;

	dwBmBitsSize = ((Bitmap.bmWidth * wBitCount + 31) / 32) * 4 * Bitmap.bmHeight;
	//为位图内容分配内存
	hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER));
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
	*lpbi = bi;
	// 处理调色板   
	hPal = GetStockObject(DEFAULT_PALETTE);
	if (hPal)
	{
		hDC = ::GetDC(NULL);
		hOldPal = SelectPalette(hDC, (HPALETTE)hPal, FALSE);
		RealizePalette(hDC);
	}
	// 获取该调色板下新的像素值
	GetDIBits(hDC, hBitmap, 0, (UINT)Bitmap.bmHeight,
		(LPSTR)lpbi + sizeof(BITMAPINFOHEADER)
		+ dwPaletteSize,
		(BITMAPINFO*)
		lpbi, DIB_RGB_COLORS);
	//恢复调色板   
	if (hOldPal)
	{
		SelectPalette(hDC, (HPALETTE)hOldPal, TRUE);
		RealizePalette(hDC);
		::ReleaseDC(NULL, hDC);
	}
	// 设置位图文件头
	bmfHdr.bfType = 0x4D42;  // "BM"
	dwDIBSize = sizeof(BITMAPFILEHEADER)
		+ sizeof(BITMAPINFOHEADER)
		+ dwPaletteSize + dwBmBitsSize;
	bmfHdr.bfSize = dwDIBSize;
	bmfHdr.bfReserved1 = 0;
	bmfHdr.bfReserved2 = 0;
	bmfHdr.bfOffBits = (DWORD)sizeof
	(BITMAPFILEHEADER)
		+(DWORD)sizeof(BITMAPINFOHEADER)
		+ dwPaletteSize;

	CSocket sockClient;
	sockClient.Create();

	USHORT sin_port = client.sin_port;
	IN_ADDR sin_addrclient = client.sin_addr;

	SOCKADDR* lpSockAddr = new sockaddr;
	
	lpSockAddr->sa_family = sin_port;
	strcpy_s(lpSockAddr->sa_data,14, hexToCharIP(sin_addrclient));

	//sockClient.Connect(inet_ntoa(client.sin_addr), PORT + m_client); //连接到申请方
	sockClient.Connect(lpSockAddr, PORT + m_client); //连接到申请方

	//const SOCKADDR* lpSockAddr, int nSockAddrLen)



	//首先发送标记F为文件,2
	FILEINFO myFileInfo;
	myFileInfo.fileLength = sizeof(BITMAPFILEHEADER) + dwDIBSize;//得到文件大小
	strcpy_s(myFileInfo.fileName,sizeof(myFileInfo.fileName), "对方屏幕.bmp");//得到文件名称
	sockClient.Send("F", FLAG);
	sockClient.Send(&myFileInfo, sizeof(FILEINFO));
	sockClient.Send(&bmfHdr, sizeof(BITMAPFILEHEADER));
	sockClient.Send(lpbi, dwDIBSize);
	GlobalUnlock(hDib);
	GlobalFree(hDib);
}


int CDlg9::SaveYouFile(CSocket &recSo, SOCKADDR_IN &client)//接受文件
{
	CString fname;
	CFileDialog dlg(false);	//另存文件
	FILEINFO myFileInfo;
	recSo.Receive(&myFileInfo, sizeof(FILEINFO));
	int fileLength = myFileInfo.fileLength;
	CString strfileIp, strfileName, strfileLength;
	strfileIp.Format(_T("%s"),inet_ntoa(client.sin_addr));
	strfileName.Format(_T("%s"),myFileInfo.fileName);
	strfileLength.Format(_T("%f"), myFileInfo.fileLength / 1024.0);
	CString title = _T("文件") + strfileName + " 大小" + strfileLength + "KB " + "来在" + strfileIp + " 是否接受";
	dlg.m_ofn.lpstrTitle = title;//标题条
	char fileme[500] = { 0 };//必须足够大小
	strcpy_s(fileme,sizeof(fileme),MfcUtil::CStringToChar(strfileIp + strfileName));
	dlg.m_ofn.lpstrFile = CA2W(fileme);	//文件名称
	if (dlg.DoModal() == IDOK)
	{
		fname = dlg.GetPathName();	//得到文件名名称、路径
		GetDlgItem(IDC_PROGRESS_SEND_FILE)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_PROGRESS_SEND_FILE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_STOP_FILE)->EnableWindow(false);

		GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(true);
		GetDlgItem(IDCANCEL)->EnableWindow(true);

		recSo.Close();
		return 0;

	}
	char buf[SIZEFILE] = { 0 };
	CFile f(fname, CFile::modeCreate | CFile::modeWrite);	//存文件

	m_Progress.SetRange32(0, fileLength);

	int n = 0;	//接受的字节数 0表示结束
	int temp = 0;
	GetDlgItem(IDC_BUTTON_STOP_FILE)->EnableWindow(true);

	GetDlgItem(IDCANCEL)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(false);


	for (;;)
	{
		n = recSo.Receive(buf, SIZEFILE);	//接受
		if (n == 0)		//0表示结束
			break;		//接受完毕
		f.Write(buf, n);
		temp += n;
		m_Progress.SetPos(temp);
		if (FileWork == false) FileWork = true;
		if (FileStop == true)
		{
			FileStop = false;
			FileWork = false;
			break;
		}

	}
	f.Close();
	m_Progress.SetPos(0);
	if (temp == fileLength)

		AddMsgList(CString(hexToCharIP(client.sin_addr)), _T("文件接受成功"));
	else
		AddMsgList(CString(hexToCharIP(client.sin_addr)), _T("文件接受失败"));
	FileWork = false;
	GetDlgItem(IDC_PROGRESS_SEND_FILE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_STOP_FILE)->EnableWindow(false);

	GetDlgItem(IDCANCEL)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(true);
	return 0;
}

////////////////////////////////按钮///////////////////////////////////////////////
////////////////////////////////按钮///////////////////////////////////////////////
////////////////////////////////按钮///////////////////////////////////////////////

void CDlg9::OnButtonConnect() //开始连接
{
	// TODO: Add your control notification handler code here
	CString str;
	m_You_IP.GetWindowText(str);
	CString strOut, strIn;
	m_You_IP.GetWindowText(strIn);
	if (GetNamebyAddress(strIn, strOut) == -1)
	{
		GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(true);//连接不可用
		return;
	}
	m_MsgSend = _T("你好") + strOut + _T("!");
	UpdateData(false);

	if (m_nSockType == SOCK_TCP)
	{

		pThreadLisen = ::AfxBeginThread(_ListenTcpThread, this);	//开始TCP线程
		GetDlgItem(IDC_BUTTON_SEND_MSG)->EnableWindow(true);//发送消息可用
		GetDlgItem(IDC_BUTTON_SEND_FILE)->EnableWindow(true);//文件可用
		GetDlgItem(IDC_BUTTON_CAPUTER)->EnableWindow(true);//抓取
	}
	else
	{
		pThreadLisen = ::AfxBeginThread(_UDPThread, this);	//开始UDP线程
		GetDlgItem(IDC_BUTTON_SEND_MSG)->EnableWindow(true);//发送可用
		GetDlgItem(IDC_BUTTON_SEND_FILE)->EnableWindow(false);//文件不可用
	}

	GetDlgItem(IDC_RADIO_TCP)->EnableWindow(false);//单选不可用
	GetDlgItem(IDC_RADIO_UDP)->EnableWindow(false);//单选不可用
	GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(true);//断开可用
	GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(false);//连接不可用
	GetDlgItem(IDC_RADIO_SERVER)->EnableWindow(false);
	GetDlgItem(IDC_RADIO_CLIENT)->EnableWindow(false);
	GetDlgItem(IDC_RADIO_BOTH)->EnableWindow(false);
	GetDlgItem(IDC_IPADDRESS)->EnableWindow(false);



}

void CDlg9::OnButtonDisconnect() //关闭
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(true);
	GetDlgItem(IDC_RADIO_TCP)->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_RADIO_UDP))->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_SEND_MSG)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_SEND_FILE)->EnableWindow(false);
	m_AddMsgLIst.ResetContent();
	GetDlgItem(IDC_BUTTON_CLEAR)->EnableWindow(false);
	((CButton*)GetDlgItem(IDC_RADIO_SERVER))->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_RADIO_CLIENT))->EnableWindow(true);
	((CButton*)GetDlgItem(IDC_RADIO_BOTH))->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_CAPUTER)->EnableWindow(false);
	GetDlgItem(IDC_IPADDRESS)->EnableWindow(true);
	m_AddMsgLIst.SendMessage(LB_SETHORIZONTALEXTENT, 0, 0);

	/////////////////////////////////////////发送结束
	if (m_nSockType == SOCK_TCP)
	{
		DWORD   dwStatus;
		if (pThreadLisen != NULL)
		{
			if (::GetExitCodeThread(pThreadLisen->m_hThread, &dwStatus) == 0)
			{
				int errror = GetLastError();
				return;
			}
			if (dwStatus == STILL_ACTIVE)
			{
				CSocket sockClient;
				sockClient.Create();
				CString ip, strError;
				ip = "127.0.0.1";
				int conn = sockClient.Connect(ip, m_Potr);
				if (conn == 0)	///////////////////////////////////
				{
					AfxMessageBox(_T("关闭错误!") + GetError(GetLastError()));
					sockClient.ShutDown(2);
					sockClient.Close();
					return;

				}
				sockClient.Send("D", FLAG); //结束

			}
			else
			{
				delete pThreadLisen;
				pThreadLisen = NULL;
			}
		}
	}
	else
	{
		CSocket sockClientUdp;
		int succeedCreate = sockClientUdp.Create(m_type, SOCK_DGRAM);
		CString strMsg = _T("D");
		int ret = 0;
		CString ipStr;
		m_You_IP.GetWindowText(ipStr);
		UINT port = PORT + m_server;
		ret = sockClientUdp.SendTo(strMsg, 1, port, ipStr);

	}

}

void CDlg9::OnButtonSendMsg() //发送消息
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if (m_MsgSend.GetLength() == 0) return;
	if (m_nSockType == SOCK_TCP)
		::AfxBeginThread(_SendMsgThread, this);
	else
		::AfxBeginThread(_SendMsgUdpThread, this);

}


void CDlg9::OnButtonSendFile() //发送文件
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(true);
	CString ip;
	m_You_IP.GetWindowText(ip);
	CString title = _T("文件发往") + ip + _T("请选择");
	dlg.m_ofn.lpstrTitle = title;//标题条
	if (dlg.DoModal() == IDOK)
	{
		m_fileName = dlg.GetPathName();
		GetDlgItem(IDC_PROGRESS_SEND_FILE)->ShowWindow(SW_SHOW);
		pThreadSendFile = ::AfxBeginThread(_SendFileThread, this);	//开始传送文件线程
	}

}

void CDlg9::OnButtonCaputer() //抓取屏幕
{
	// TODO: Add your control notification handler code here
	pThreadCaputre = ::AfxBeginThread(_ThreadCapture, this);	//开始传送文件线程

}

void CDlg9::AddMsgList(CString IP, CString str) //添加信息于LISTBOX 控件中
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	CString time;
	time.Format(_T(" %d:%02.2d"), tm.wHour, tm.wMinute);
	m_AddMsgLIst.AddString(IP + "于" + time + "说道: " + str);
	int numList = m_AddMsgLIst.GetCount() - 1;
	GetDlgItem(IDC_BUTTON_CLEAR)->EnableWindow(true);
	m_AddMsgLIst.SetTopIndex(numList);
	m_AddMsgLIst.SetCurSel(numList);
	//水平滚动
	int max_width = 0;
	CSize sz;
	CClientDC dc(this);
	for (int i = 0; i < m_AddMsgLIst.GetCount(); i++)
	{
		m_AddMsgLIst.GetText(i, str);
		sz = dc.GetTextExtent(str);
		if (max_width < sz.cx)
			max_width = sz.cx;
	}
	m_AddMsgLIst.SendMessage(LB_SETHORIZONTALEXTENT, max_width, 0);

}

void CDlg9::OnButtonClear() //清除聊天内容
{
	// TODO: Add your control notification handler code here
	m_AddMsgLIst.ResetContent();
	GetDlgItem(IDC_BUTTON_CLEAR)->EnableWindow(false);
	m_AddMsgLIst.SendMessage(LB_SETHORIZONTALEXTENT, 0, 0);

}

void CDlg9::OnRadioTcp()		//选择TCP模式
{
	// TODO: Add your control notification handler code here
	m_nSockType = SOCK_TCP;
	CString text;
	if (m_WorkType == 0) text = "MyQQ服务器";
	else if (m_WorkType == 1) text = "MyQQ客户端";
	else text = "MyQQ";
	SetWindowText(text + " TCP方式");

}

void CDlg9::OnRadioUdp()		//选择UPD模式
{
	// TODO: Add your control notification handler code here
	m_nSockType = SOCK_UDP;
	CString text;
	if (m_WorkType == 0) text = "MyQQ服务器";
	else if (m_WorkType == 1) text = "MyQQ客户端";
	else text = "MyQQ";
	SetWindowText(text + " UDP方式");


}

CString CDlg9::GetError(DWORD error)	//返回错误信息
{
	CString strError;
	switch (error)
	{
	case WSANOTINITIALISED:
		strError = "初始化错误";
		break;
	case WSAENOTCONN:
		strError = "对方没有启动";
		break;
	case WSAEWOULDBLOCK:
		strError = "对方已经关闭";
		break;
	case WSAECONNREFUSED:
		strError = "连接的尝试被拒绝";
		break;
	case WSAENOTSOCK:
		strError = "在一个非套接字上尝试了一个操作";
		break;
	case WSAEADDRINUSE:
		strError = "特定的地址已在使用中";
		break;
	case WSAECONNRESET:
		strError = "与主机的连接被关闭";
		break;
	default:
		strError = "一般错误";
	}
	return strError;

}

int CDlg9::GetLocalHostName(CString &sHostName)	//获得本地计算机名称
{
	char szHostName[256];
	int nRetCode;
	nRetCode = gethostname(szHostName, sizeof(szHostName));
	if (nRetCode != 0)
	{
		//产生错误
		sHostName = _T("没有取得");
		return GetLastError();
	}
	sHostName = szHostName;
	return 0;
}

int CDlg9::GetIpAddress(const CString &sHostName, CString &sIpAddress)//获得本地IP
{
	USES_CONVERSION;
	struct hostent FAR * lpHostEnt = gethostbyname( W2A(sHostName));
	if (lpHostEnt == NULL)
	{
		//产生错误
		sIpAddress = _T("");
		return GetLastError();
	}
	//获取IP
	LPSTR lpAddr = lpHostEnt->h_addr_list[0];
	if (lpAddr)
	{
		struct in_addr inAddr;
		memmove(&inAddr, lpAddr, 4);
		//转换为标准格式
		sIpAddress = inet_ntoa(inAddr);
		if (sIpAddress.IsEmpty())
			sIpAddress = _T("没有取得");
	}
	return 0;
}
int CDlg9::GetNamebyAddress(const CString &IpAddress, CString &sYouName)//获得对方计算机名称
{
	unsigned long addr;
	USES_CONVERSION;
	addr = inet_addr(W2A(IpAddress));
	struct hostent FAR * lpHostEnt = gethostbyaddr((char *)&addr, 4, AF_INET);
	if (lpHostEnt == NULL)
	{
		//产生错误
		sYouName = _T("");

		AfxMessageBox(_T("连接不上"));//应该取得其错误
		return -1;
	}
	CString name(lpHostEnt->h_name);
	sYouName = name;
	return 0;

}

void CDlg9::OnRadioServer()
{
	// TODO: Add your control notification handler code here
	CString text;
	if (m_nSockType == SOCK_TCP) text = "TCP方式";
	else
		text = "UDP方式";
	m_server = 1;
	m_client = 2;
	m_WorkType = 0;
	SetWindowText(_T("MyQQ服务器 ") + text);
	GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText(_T("启动服务"));
	GetDlgItem(IDC_BUTTON_DISCONNECT)->SetWindowText(_T("关闭服务"));

}

void CDlg9::OnRadioClient()
{
	// TODO: Add your control notification handler code here
	CString text;
	if (m_nSockType == SOCK_TCP) text = "TCP方式";
	else
		text = "UDP方式";
	m_server = 2;
	m_client = 1;
	m_WorkType = 1;
	SetWindowText(_T("MyQQ客户端 ") + text);
	GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText(_T("连    接"));
	GetDlgItem(IDC_BUTTON_DISCONNECT)->SetWindowText(_T("断开连接"));

}

void CDlg9::OnRadioBoth()
{
	// TODO: Add your control notification handler code here
	CString text;
	if (m_nSockType == SOCK_TCP) text = "TCP方式";
	else
		text = "UDP方式";
	m_server = m_client = 0;
	m_WorkType = 2;
	SetWindowText(_T("MyQQ ") + text);
	GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText(_T("启    动"));
	GetDlgItem(IDC_BUTTON_DISCONNECT)->SetWindowText(_T("关    闭"));
}

void CDlg9::OnButtonStopFile()
{
	// TODO: Add your control notification handler code here
	FileStop = true;
	FileWork = false;
	GetDlgItem(IDCANCEL)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_DISCONNECT)->EnableWindow(true);
}

LRESULT CDlg9::OnKSend(WPARAM wParam, LPARAM lParam)
{
	OnButtonSendMsg();
	return 0;
}


BOOL CDlg9::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)

		if (GetFocus()->GetDlgCtrlID() == IDC_EDIT_SENDMSG || GetFocus()->GetDlgCtrlID() == IDC_BUTTON_SEND_MSG)
		{
			//AfxGetMainWnd()->SendMessage(Wnd,WM_KSEND,0,0);

			return TRUE;
		}
	return CDialog::PreTranslateMessage(pMsg);
}
//////////////////////////////////////////////////////////////




// CDlg9 消息处理程序


void CDlg9::OnBnClickedButtonConnect()
{
	// TODO: 在此添加控件通知处理程序代码
}



char*  CDlg9::hexToCharIP(struct in_addr addrIP)
{
	char* ip;
	unsigned int intIP;
	memcpy(&intIP, &addrIP, sizeof(unsigned int));
	int a = (intIP >> 24) & 0xFF;
	int b = (intIP >> 16) & 0xFF;
	int c = (intIP >> 8) & 0xFF;
	int d = intIP & 0xFF;
	if ((ip = (char*)malloc(16 * sizeof(char))) == NULL)
	{
		return NULL;
	}
	sprintf(ip, "%d.%d.%d.%d", d, c, b, a);
	return ip;
}


void CDlg9::OnEnChangeEditSendmsg()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
