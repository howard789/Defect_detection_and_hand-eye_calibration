
// ProjectOneDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "ProjectOneDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProjectOneDlg 对话框



CProjectOneDlg::CProjectOneDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECTONE_DIALOG, pParent)
	, m_info(_T(""))
	, m_CURRENTSPEED(0)
{

	//AfxGetMainWnd()->m_hWnd;
	//CProjectOneDlg *thisDlg;
	//thisDlg->m_hWnd;  HalconMotionCardUnion &motionWarehouse

	m_page1=new CDlg1(paramUtil,halconUtil, cameraUtil, doc, motionCard);
	m_page2 =new CDlg2(paramUtil,halconUtil,cameraUtil, doc, motionCard);
	m_page3 =new CDlg3(halconMotionCardUnion,paramUtil,halconUtil,cameraUtil, doc, motionCard);
	//m_page4 =new CDlg4(paramUtil,halconUtil,cameraUtil, doc, motionCard);
	m_page5 =new CDlg5(paramUtil,halconUtil,cameraUtil, doc, motionCard);
	m_page6 =new CDlg6(paramUtil,halconUtil,cameraUtil, doc, motionCard);
	m_page7 =new CDlg7(dmcUtil,paramUtil,halconUtil,cameraUtil, doc, motionCard);
	m_page8 =new CDlg8(paramUtil,halconUtil,cameraUtil, doc, motionCard);
	m_page9 =new CDlg9(paramUtil,halconUtil,cameraUtil, doc, motionCard);
	m_page10 =new CDlg10();
	m_page11 =new CDlg11();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//ho_NG = nullptr;
	//ho_OK=nullptr;
	previousPicCount_ng=0;
	previousPicCount_ok=0;

	lucked = false;
	takePic = false;
}

void CProjectOneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Text(pDX, IDC_INFO, m_info);

	DDX_Control(pDX, IDC_DEVICE_COMBO, m_ctrlDeviceCombo);
	DDX_CBIndex(pDX, IDC_DEVICE_COMBO, m_nDeviceCombo);
	DDX_Text(pDX, IDC_EXPOSURE_EDIT, m_dExposureEdit);
	DDX_Text(pDX, IDC_GAIN_EDIT, m_dGainEdit);
	DDX_Text(pDX, IDC_FRAME_RATE_EDIT, m_dFrameRateEdit);



	//DDX_Control(pDX, IDC_PC2, m_HWindowID2);
}

BEGIN_MESSAGE_MAP(CProjectOneDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CProjectOneDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON1, &CProjectOneDlg::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CAMERA, &CProjectOneDlg::OnBnClickedCamera)
	ON_BN_CLICKED(IDC_TAKEPIC, &CProjectOneDlg::OnBnClickedTakepic)
	ON_BN_CLICKED(IDC_STOPCAMERA, &CProjectOneDlg::OnBnClickedStopcamera)
	ON_MESSAGE(WM_UPDATEDATA, OnUpdateData)
	ON_BN_CLICKED(IDC_RADIO1, &CProjectOneDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CProjectOneDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CProjectOneDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CProjectOneDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CProjectOneDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CProjectOneDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CProjectOneDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO12, &CProjectOneDlg::OnBnClickedRadio12)
	ON_BN_CLICKED(IDC_RADIO16, &CProjectOneDlg::OnBnClickedRadio16)
	ON_BN_CLICKED(IDC_RADIO17, &CProjectOneDlg::OnBnClickedRadio17)
	ON_BN_CLICKED(IDC_RADIO18, &CProjectOneDlg::OnBnClickedRadio18)
	ON_BN_CLICKED(IDC_ROTATE180, &CProjectOneDlg::OnBnClickedRotate180)
	ON_BN_CLICKED(IDC_RADIO11, &CProjectOneDlg::OnBnClickedRadio11)
	ON_BN_CLICKED(IDC_RADIO13, &CProjectOneDlg::OnBnClickedRadio13)
	ON_BN_CLICKED(IDC_RADIO15, &CProjectOneDlg::OnBnClickedRadio15)
	ON_BN_CLICKED(IDC_RADIO19, &CProjectOneDlg::OnBnClickedRadio19)
	ON_BN_CLICKED(IDC_RADIO20, &CProjectOneDlg::OnBnClickedRadio20)
	ON_BN_CLICKED(IDC_ROTATESecond, &CProjectOneDlg::OnBnClickedRotatesecond)
	ON_BN_CLICKED(IDC_BUTTON2, &CProjectOneDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CAMERA2, &CProjectOneDlg::OnBnClickedCamera2)
	ON_BN_CLICKED(IDC_TAKEPIC2, &CProjectOneDlg::OnBnClickedTakepic2)
	ON_BN_CLICKED(IDC_STOPCAMERA2, &CProjectOneDlg::OnBnClickedStopcamera2)
	ON_BN_CLICKED(IDC_RADIO14, &CProjectOneDlg::OnBnClickedRadio14)



	//Mvs
	ON_BN_CLICKED(IDC_ENUM_BUTTON, &CProjectOneDlg::OnBnClickedEnumButton)




	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CProjectOneDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_CLOSE_BUTTON, &CProjectOneDlg::OnBnClickedCloseButton)
	ON_BN_CLICKED(IDC_GET_PARAMETER_BUTTON, &CProjectOneDlg::OnBnClickedGetParameterButton)
	ON_BN_CLICKED(IDC_SET_PARAMETER_BUTTON, &CProjectOneDlg::OnBnClickedSetParameterButton)
END_MESSAGE_MAP()


// CProjectOneDlg 消息处理程序

BOOL CProjectOneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	myInitDlg();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CProjectOneDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CProjectOneDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	myOnPaint();
}

void CProjectOneDlg::myOnPaint()
{


}


//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CProjectOneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CProjectOneDlg::onTabInit()
{
	
		//创建两个对话框 
		m_page1->Create(IDD_Dlg1, &m_tab);
		m_page2->Create(IDD_Dlg2, &m_tab);
		m_page3->Create(IDD_Dlg3, &m_tab);
		//m_page4->Create(IDD_Dlg4, &m_tab);
		m_page5->Create(IDD_Dlg5, &m_tab);
		m_page6->Create(IDD_Dlg6, &m_tab);
		m_page7->Create(IDD_Dlg7, &m_tab);
		m_page8->Create(IDD_Dlg8, &m_tab);
		m_page9->Create(IDD_Dlg9, &m_tab);
		m_page10->Create(IDD_Dlg10, &m_tab);
		m_page11->Create(IDD_Dlg11, &m_tab);


		//设定在Tab内显示的范围 
		CRect tabRect;
		m_tab.GetClientRect(tabRect);
		tabRect.left += 0;
		tabRect.right -= 0;
		tabRect.top += 20;
		tabRect.bottom -= 0;
		m_page1->MoveWindow(&tabRect);
		m_page2->MoveWindow(&tabRect);
		m_page3->MoveWindow(&tabRect);
		//m_page4->MoveWindow(&tabRect);
		m_page5->MoveWindow(&tabRect);
		m_page6->MoveWindow(&tabRect);
		m_page7->MoveWindow(&tabRect);
		m_page8->MoveWindow(&tabRect);
		m_page9->MoveWindow(&tabRect);
		m_page10->MoveWindow(&tabRect);
		m_page11->MoveWindow(&tabRect);
	


		//显示初始页面 
		m_page1->ShowWindow(SW_SHOW);
		m_page2->ShowWindow(SW_HIDE);
		m_page3->ShowWindow(SW_HIDE);
		//m_page4->ShowWindow(SW_HIDE);
		m_page5->ShowWindow(SW_HIDE);
		m_page6->ShowWindow(SW_HIDE);
		m_page7->ShowWindow(SW_HIDE);
		m_page8->ShowWindow(SW_HIDE);
		m_page9->ShowWindow(SW_HIDE);
		m_page10->ShowWindow(SW_HIDE);
		m_page11->ShowWindow(SW_HIDE);
	

		//保存当前选择 
		m_CurSelTab = 0;



		//把对话框对象指针保存起来,在这里调整顺序（调整1）
		CString p0 = TEXT("运动控制");
		pDialog[0] = m_page1;//运动控制

		CString p1 = TEXT("手眼标定");
		pDialog[1] = m_page2;//手眼标定

		CString p2 = TEXT("参数调整");
		pDialog[2] = m_page3;//参数调整

		CString p3 = TEXT("IO检测");
		pDialog[3] = m_page5;//IO检测

		CString p4 = TEXT("缺陷检测");
		pDialog[4] = m_page7;//缺陷检测

		CString p5 = TEXT("双目相机");
		pDialog[5] = m_page6;//双目相机

		CString p6 = TEXT("网口通讯");
		pDialog[6] = m_page10;//网口通讯

		CString p7 = TEXT("传送带");
		pDialog[7] = m_page11;//传送带

	
		pDialog[8] = m_page8;//MindVersionSDK（NA）
		pDialog[9] = m_page9;//na
		

		//这里调整名称和显示顺序（调整2）
		m_tab.InsertItem(0, p0);
		m_tab.InsertItem(1, p1);
		m_tab.InsertItem(2, p2);
		m_tab.InsertItem(3, p3);
		m_tab.InsertItem(4, p4);
		m_tab.InsertItem(5, p5);
		m_tab.InsertItem(6, p6);
		m_tab.InsertItem(7, p7);

	

}


void CProjectOneDlg::ResizeWindow()
{
#ifndef _ResizeWindow_Fixed
	//得到显示器大小
	int   cx, cy;
	cx = GetSystemMetrics(SM_CXSCREEN);
	cy = GetSystemMetrics(SM_CYSCREEN);

	//再用MoveWindow
	CRect   rcTemp;
	rcTemp.BottomRight() = CPoint(cx, cy);
	rcTemp.TopLeft() = CPoint(0, 0);
	MoveWindow(&rcTemp);
	CWnd::SetWindowPos(NULL, 0, 0, rcTemp.Width(), rcTemp.Height(), SWP_NOZORDER | SWP_NOMOVE);

#else
	//HWND hWnd = AfxGetApp()->GetMainWnd()->GetSafeHwnd();

	//手动设置
	CRect   temprect(0, 0, FIXED_MAINWINDOW_WIDE, FIXED_MAINWINDOW_HIGH);
	MoveWindow(&temprect);
	CWnd::SetWindowPos(this, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);
#endif
}

void CProjectOneDlg::myInitDlg()
{
	

	onTabInit();
	ResizeWindow();
	SetTimer(1, 100, NULL);
	//SetTimer(2, 500, NULL);
	myStartPictureControl();//摄像机

	//radio
	showMode = 9;
	paramUtil.showModeSynWithMainWin = showMode;

	CheckRadioButton(IDC_RADIO1, IDC_RADIO18, IDC_RADIO18);
	
	((CButton*)GetDlgItem(IDC_RADIO18))->SetCheck(TRUE);




	switch (paramUtil.cameraMode)
	{
	case 1:
		CheckRadioButton(IDC_RADIO6, IDC_RADIO14, IDC_RADIO6);
		break;

	case 2:
		CheckRadioButton(IDC_RADIO6, IDC_RADIO14, IDC_RADIO7);
		break;
	case 3:
		CheckRadioButton(IDC_RADIO6, IDC_RADIO14, IDC_RADIO11);
		break;
	case 4:
		CheckRadioButton(IDC_RADIO6, IDC_RADIO14, IDC_RADIO13);
		break;
	case 5:
		CheckRadioButton(IDC_RADIO6, IDC_RADIO14, IDC_RADIO14);
		break;


	}



	switch (paramUtil.cameraModeSecond)
	{
	case 1:
		CheckRadioButton(IDC_RADIO15, IDC_RADIO22, IDC_RADIO15);
		break;

	case 2:
		CheckRadioButton(IDC_RADIO15, IDC_RADIO22, IDC_RADIO19);
		break;
	case 3:
		CheckRadioButton(IDC_RADIO15, IDC_RADIO22, IDC_RADIO20);
		break;

	case 4:
		CheckRadioButton(IDC_RADIO15, IDC_RADIO22, IDC_RADIO21);
		break;
	case 5:
		CheckRadioButton(IDC_RADIO15, IDC_RADIO22, IDC_RADIO22);
		break;

	}


	//checkBox
	paramUtil.rotate180 ?
		((CButton *)GetDlgItem(IDC_ROTATE180))->SetCheck(true) :
		((CButton *)GetDlgItem(IDC_ROTATE180))->SetCheck(false);
	paramUtil.rotate180Second ?
		((CButton *)GetDlgItem(IDC_ROTATESecond))->SetCheck(true) :
		((CButton *)GetDlgItem(IDC_ROTATESecond))->SetCheck(false);





}

void CProjectOneDlg::myStartPictureControl()
{
	//PC1
	//takePic = false;
	//CRect Rect;
	//pWnd = GetDlgItem(IDC_PC1);
	//HWindowID = (Hlong)pWnd->m_hWnd;//获取父窗口句柄
	//pWnd->GetWindowRect(&Rect);
	//OpenWindow(0, 0, Rect.Width(), Rect.Height(), HWindowID, "visible", "", &m_HWindowID);

	//PC2
	
	//CRect Rect2;
	//pWnd = GetDlgItem(IDC_PC2);
	//HWindowID2 = (Hlong)pWnd->m_hWnd;//获取父窗口句柄
	//pWnd->GetWindowRect(&Rect2);
	//OpenWindow(0, 0, Rect2.Width(), Rect2.Height(), HWindowID2, "visible", "", &m_HWindowID2);


}

void CProjectOneDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	//把当前的页面隐藏起来
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	//得到新的页面索引
	m_CurSelTab = m_tab.GetCurSel();
	//把新的页面显示出来
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);

	*pResult = 0;
}


void CProjectOneDlg::OnBnClickedButton1()
{//紧急停止
	d2410_emg_stop();

	//motionCard.emergentStop();
	//dmc1380Util::emergentStop();
}


void CProjectOneDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (paramUtil.GoOriginal)
	{
		//((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);
		showMode = 1;
		paramUtil.showModeSynWithMainWin = showMode;
		paramUtil.GoOriginal = false;

	}
	// TODO: 在此添加消息处理程序代码和/或调用默认值

		CString str1;
		str1.Format(_T("%d"),motionCard.getCurrentPulse('x'));
		SetDlgItemTextW(IDC_EDIT_X_PULSE,str1);
		str1.Format(_T("%d"), motionCard.getCurrentPulse('y'));
		SetDlgItemTextW(IDC_EDIT_Y_PULSE, str1);
		str1.Format(_T("%d"), motionCard.getCurrentPulse('z'));
		SetDlgItemTextW(IDC_EDIT_Z_PULSE, str1);
		str1.Format(_T("%d"), motionCard.getCurrentPulse('u'));
		SetDlgItemTextW(IDC_EDIT_U_PULSE, str1);
		str1.Format(_T("%d"), motionCard.readCurrentSpeed(0));
		SetDlgItemTextW(IDC_EDIT_CURRENTSPEED, str1);
		str1.Format(_T("%d"), motionCard.readCurrentSpeed(1));
		SetDlgItemTextW(IDC_EDIT_CURRENTSPEED2, str1);

		SetDlgItemTextW(IDC_EDIT_X_STATYUS, motionCard.getStatus(false,'x'));
		SetDlgItemTextW(IDC_EDIT_Y_STATYUS, motionCard.getStatus(false,'y'));
		SetDlgItemTextW(IDC_EDIT_Z_STATYUS, motionCard.getStatus(false,'z'));
		SetDlgItemTextW(IDC_EDIT_U_STATYUS, motionCard.getStatus(false,'u'));



		if (paramUtil.cameraModeSecond == 2|| paramUtil.cameraModeSecond == 3)
		{
		
			updateNGAndOK();
			
		}



	CDialogEx::OnTimer(nIDEvent);
}



//开始采集
void CProjectOneDlg::OnBnClickedCamera()
{
	if (paramUtil.cameraMode != 5)
	{
		//开启新线程处理
		if (StartImageState)//已经在采集了
			return;

		CWinThread *pt = AfxBeginThread(StartCameraThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	}
	else
	{
		if (FALSE == m_bOpenDevice || TRUE == m_bStartGrabbing)
		{
			return;
		}

		CWinThread *pt = AfxBeginThread(StartMvsCameraThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

	}
}

UINT CProjectOneDlg::StartMvsCameraThread(LPVOID pParam)
{

    CProjectOneDlg *pDlg = (CProjectOneDlg*)pParam;

	CRect Rect;
	pDlg->pWnd = pDlg->GetDlgItem(IDC_PC1);
	pDlg->HWindowID = (Hlong)pDlg->pWnd->m_hWnd;//获取父窗口句柄
	pDlg->pWnd->GetWindowRect(&Rect);
	OpenWindow(0, 0, Rect.Width(), Rect.Height(), pDlg->HWindowID, "visible", "", &pDlg->m_HWindowID);

	//CRect Rect2;
	//pDlg->pWnd = pDlg->GetDlgItem(IDC_PC2);
	//pDlg->HWindowID2 = (Hlong)pDlg->pWnd->m_hWnd;//获取父窗口句柄
	//pDlg->pWnd->GetWindowRect(&Rect2);
	//OpenWindow(0, 0, Rect2.Width(), Rect2.Height(), pDlg->HWindowID2, "visible", "", &pDlg->m_HWindowID2);





	return pDlg->runMvsCamera(pParam);

}


UINT CProjectOneDlg::runMvsCamera(LPVOID pParam)
{
	try
	{
		if (FALSE == m_bOpenDevice || TRUE == m_bStartGrabbing)
		{//m_bStartGrabbing==true表示已经在采集
			return 0;
		}

		int nRet = MV_OK;
		if (NULL != m_pcMyCamera)
		{
			nRet = m_pcMyCamera->StartGrabbing();
			if (nRet == MV_OK)
			{
				m_bStartGrabbing = TRUE;
				while (m_bStartGrabbing)
				{
					//ConverImgToHalcon(pParam);
					ImgMomeCopy(pParam);
				}
			}
			m_pcMyCamera->StopGrabbing();
			
			return 0;
		}
	}
	catch (...)
	{
		m_bStartGrabbing = FALSE;
		m_pcMyCamera->StopGrabbing();
		CloseDevice();
		
	}
}


void CProjectOneDlg::OnBnClickedCamera2()
{
	
	if (StartImageState2)//已经在采集了
		return;
	CWinThread *pt2 = AfxBeginThread(StartCameraThreadSecond, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

}




UINT CProjectOneDlg::StartCameraThreadSecond(LPVOID pParam)
{
	CProjectOneDlg *pDlg = (CProjectOneDlg*)pParam;
	CRect Rect2;
	pDlg->pWnd = pDlg->GetDlgItem(IDC_PC2);
	pDlg->HWindowID2 = (Hlong)pDlg->pWnd->m_hWnd;//获取父窗口句柄
	pDlg->pWnd->GetWindowRect(&Rect2);
	OpenWindow(0, 0, Rect2.Width(), Rect2.Height(), pDlg->HWindowID2, "visible", "", &pDlg->m_HWindowID2);

	pDlg->runSecondCamera(pParam);
	return -1;
}



UINT CProjectOneDlg::StartCameraThread(LPVOID pParam)
{
	CProjectOneDlg *pDlg = (CProjectOneDlg*)pParam;
	
	CRect Rect;
	pDlg->pWnd = pDlg->GetDlgItem(IDC_PC1);
	pDlg->HWindowID = (Hlong)pDlg->pWnd->m_hWnd;//获取父窗口句柄
	pDlg->pWnd->GetWindowRect(&Rect);
	OpenWindow(0, 0, Rect.Width(), Rect.Height(), pDlg->HWindowID, "visible", "", &pDlg->m_HWindowID);


	return pDlg->runFirstCamera(pParam);
	
}





void CProjectOneDlg::OnBnClickedTakepic()
{
	takePic = true;
}

void CProjectOneDlg::OnBnClickedTakepic2()
{
	takePic2 = true;
}


//停止采集
void CProjectOneDlg::OnBnClickedStopcamera()
{
	
	StartImageState = false;
	
	if (paramUtil.cameraMode != 5)
	{		
		MvsStopGrabbing();
	}
		

}


void CProjectOneDlg::MvsStopGrabbing()
{
	if (FALSE == m_bOpenDevice || FALSE == m_bStartGrabbing)
	{
		return;
	}

	int nRet = MV_OK;
	if (NULL != m_pcMyCamera)
	{
		nRet = m_pcMyCamera->StopGrabbing();
	}
	else
	{
		return;
	}

	if (MV_OK != nRet)
	{
		return;
	}
	m_bStartGrabbing = FALSE;


	return;

}



void CProjectOneDlg::OnBnClickedStopcamera2()
{
	StartImageState2 = false;
}


LRESULT CProjectOneDlg::OnUpdateData(WPARAM wParam, LPARAM lParam)
{
	UpdateData(wParam);
	return 0;
}

void CProjectOneDlg::OnBnClickedRadio1()
{
	showMode = 1;
	paramUtil.showModeSynWithMainWin = showMode;
}


void CProjectOneDlg::OnBnClickedRadio2()
{
	showMode = 2;
	paramUtil.showModeSynWithMainWin = showMode;
}


void CProjectOneDlg::OnBnClickedRadio3()
{
	showMode = 3;
	paramUtil.showModeSynWithMainWin = showMode;
}


void CProjectOneDlg::OnBnClickedRadio4()
{
	showMode = 4;
	paramUtil.showModeSynWithMainWin = showMode;
}


void CProjectOneDlg::OnBnClickedRadio5()
{
	showMode = 5;
	paramUtil.showModeSynWithMainWin = showMode;
}

void CProjectOneDlg::OnBnClickedRadio12()
{
	showMode = 6;
	paramUtil.showModeSynWithMainWin = showMode;
}


void CProjectOneDlg::OnBnClickedRadio16()
{
	showMode = 7;
	paramUtil.showModeSynWithMainWin = showMode;

	paramUtil.cameraMode = 3;
	paramUtil.cameraModeSecond = 1;

}


void CProjectOneDlg::OnBnClickedRadio17()
{
	showMode = 8;
	paramUtil.showModeSynWithMainWin = showMode;
}


void CProjectOneDlg::OnBnClickedRadio18()
{
	showMode = 9;
	paramUtil.showModeSynWithMainWin = showMode;
}


void CProjectOneDlg::OnBnClickedRadio6()
{
	paramUtil.cameraMode = 1;
}


void CProjectOneDlg::OnBnClickedRadio7()
{
	paramUtil.cameraMode = 2;
}

void CProjectOneDlg::OnBnClickedRadio11()
{
	showMode = 7;
	paramUtil.showModeSynWithMainWin = showMode;

	paramUtil.cameraMode = 3;
	paramUtil.cameraModeSecond = 1;
}


void CProjectOneDlg::OnBnClickedRadio13()
{
	paramUtil.cameraMode = 4;
	showMode = 9;
	paramUtil.showModeSynWithMainWin = showMode;
}


void CProjectOneDlg::OnBnClickedRadio15()
{
	showMode = 7;
	paramUtil.showModeSynWithMainWin = showMode;

	paramUtil.cameraMode = 3;
	paramUtil.cameraModeSecond = 1;
}


void CProjectOneDlg::OnBnClickedRadio19()
{
	//show NG
	paramUtil.cameraModeSecond = 2;
}


void CProjectOneDlg::OnBnClickedRadio20()
{
	//show OK
	paramUtil.cameraModeSecond = 3;
}






void CProjectOneDlg::OnBnClickedRotate180()
{
	int stat = ((CButton *)GetDlgItem(IDC_ROTATE180))->GetCheck();
	if (stat == 0)
		paramUtil.rotate180 = false;
	else
		paramUtil.rotate180 = true;
}



void CProjectOneDlg::OnBnClickedRotatesecond()
{
	int stat = ((CButton *)GetDlgItem(IDC_ROTATESecond))->GetCheck();
	if (stat == 0)
		paramUtil.rotate180Second = false;
	else
		paramUtil.rotate180Second = true;
}



UINT CProjectOneDlg::runSecondCamera(LPVOID pParam) {



	try {
		CProjectOneDlg *pDlg = (CProjectOneDlg*)pParam;
		HTuple  hv_Width;
		HTuple  hv_Height;
		HTuple  hv_AcqHandle;//PicControl 1
		HObject ho_GrayImage;
		HObject  ho_Regions, ho_ConnectedRegions, ho_ImageIlluminate;
		HObject  ho_SelectedRegions, ho_RegionIntersection, ho_RegionFillUp;
		HObject  ho_ConnectedRegions1, ho_Circle, ho_Rectangle;
		HTuple  hv_Area, hv_Row, hv_Column, hv_Radius;
		HTuple  hv_I, hv_y, hv_x, hv_mes;



		//QR CODE
		HTuple  hv_DataCodeHandle, hv_ResultHandles, hv_DecodedDataStrings;
		HObject ho_SymbolXLDs;




		//多模板
		HTuple  hv_i, hv_ModelID1, hv_ModelID2, hv_ModelIDs, hv_ColorIndex;
		// Local iconic variables
		HObject  ho_ImageROI, ho_ImageROI2, ho_Template, ho_SearchImage;
		HObject  ho_Contour, ho_ContoursAffineTrans;
		HObject  ho_UnionContours1;

		// Local control variables
		HTuple  hv_Row1, hv_Column1, hv_Phi, hv_Length1, hv_Length2;
		HTuple  hv_NumLevels, hv_AngleStart, hv_AngleExtent, hv_AngleStep;
		HTuple  hv_Optimization, hv_Metric, hv_Contrast, hv_MinContrast;
		HTuple  hv_TypesIndex, hv_AnglesTypes, hv_Types, hv_MinScore;
		HTuple  hv_NumMatches, hv_MaxOverlap, hv_SubPixel, hv_Greediness;
		HTuple  hv_Angle, hv_Score, hv_ModelIndex, hv_MaxScoreIndex;
		HTuple  hv_MaxScore, hv_CountModels, hv_Level, hv_HomMat2D;

		//xld
		HObject  ho_ImageScaled, ho_Border1, ho_SelectedXLD, ho_SelectedXLD2;
		HTuple hv_PointOrder;


		//xld走位
		HObject  ho_ObjectSelected;
		HTuple  hv_Number, hv_Row2, hv_Col2, hv_Index;


		//项目六
		HObject  ho_ImageEL, ho_ImageLE, ho_ImageES, ho_ImageSE;
		HObject  ho_ImageEE, ho_ImageLaws, ho_ImageTexture, ho_ImageTextureReduced;
		HObject  ho_ClassRegions, ho_Correct, ho_Errors, ho_ErrorsOpening;
		HObject  ho_ErrorsClosing, ho_ErrorsConnected, ho_FinalErrors, ho_RegionOpening, ho_RegionClosing;
		HTuple  hv_Error, hv_ErrorLog, hv_NumErrors;

		HTuple hv_FilePath;


		HTuple tmp;
		int tmp2;

		bool GrayDown = false;


		if (paramUtil.cameraModeSecond == 1) {
			//项目4

#ifdef _TestOffLine
			HTuple fileName = paramUtil.getCalibrationFilePath_HTuple();
			ReadImage(&ho_Image, fileName);
			halconUtil.calibrationImage_projectFour_CameraTwo = ho_Image;
			return 0;

#else
				OpenFramegrabber("MindVision17_X64", 1, 1, 0, 0, 0, 0, "progressive", 8, "Gray",
					-1, "false", "auto", "超人机器视觉1", 0, -1, &hv_AcqHandle);

#endif // DEBUG

			

			//OpenFramegrabber("DirectShow", 1, 1, 0, 0, 0, 0, "default", 8, "rgb", -1, "false",
				//"default", "[0] Integrated Camera", 0, -1, &hv_AcqHandle);
			
		}
		else if (paramUtil.cameraModeSecond == 2)
		{
			return 0;//显示NG
		}
		else if (paramUtil.cameraModeSecond == 3)
		{//显示OK
			return 0;
		}


		

		GrabImageStart(hv_AcqHandle, -1);


		pDlg->StartImageState2 = true;

		while (pDlg->StartImageState2)
		{

				GrabImageAsync(&(pDlg->ho_Image2), hv_AcqHandle, -1);

				if (paramUtil.rotate180Second) {
					RotateImage(pDlg->ho_Image2, &(pDlg->ho_Image2), 180, "constant"); //注意这里已经转了，后面都不要再转类
				}

				GetImageSize(pDlg->ho_Image2, &hv_Width, &hv_Height);
				SetPart(pDlg->m_HWindowID2, 0, 0, hv_Height, hv_Width);

				if (GrayDown)
					ho_GrayImage = pDlg->ho_Image2;
				else
					Rgb1ToGray(pDlg->ho_Image2, &ho_GrayImage);




				if (pDlg->takePic2) {
					HTuple fileName = paramUtil.getNewFilePath_HTuple();
					WriteImage(pDlg->ho_Image2, "bmp", 0, fileName);
					pDlg->takePic = false;
				}


				SetColor(pDlg->m_HWindowID2, "red");
			
			
			/*通用设定结束*/
			switch (pDlg->paramUtil.cameraModeSecond)
			{
				/*******************Project 4 ******************************************/
			case 1:
				//DispObj(pDlg->ho_Image2, pDlg->m_HWindowID2);
				Illuminate(pDlg->ho_Image2, &ho_ImageIlluminate, 101, 101, 0.7);
				Threshold(ho_GrayImage, &ho_Regions, paramUtil.minGray, paramUtil.maxGray);
				Connection(ho_Regions, &ho_ConnectedRegions);
				SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", paramUtil.selectShapMinArea, paramUtil.selectShapMaxArea);
				FillUp(ho_SelectedRegions, &ho_RegionFillUp);
				DispObj(ho_GrayImage, pDlg->m_HWindowID2);
				SetColored(pDlg->m_HWindowID2, 12);
				DispObj(ho_RegionFillUp, pDlg->m_HWindowID2);

				//标定9点拍照
				if (paramUtil.caseFourCalibration_CameraTwo)
				{

					halconUtil.calibrationImage_projectFour_CameraTwo = pDlg->ho_Image;

					paramUtil.caseFourCalibration_CameraTwo = false;
				}
				break;
				/******************* NG ******************************************/
			case 2:
				pDlg->StartImageState2 = false;
				break;

				/******************* OK ******************************************/
			case 3:
				pDlg->StartImageState2 = false;
				break;
			}

		}
		CloseFramegrabber(hv_AcqHandle);
		AfxEndThread(0);
		return 0;
	}
	catch (...) {
		try {
			CloseFramegrabber(hv_AcqHandle);
		}
		catch (...) {}

		try {
			AfxEndThread(0);
		}
		catch (...) {}


		return 0;
	};
}




/* 10/17amend*/
UINT CProjectOneDlg::runFirstCamera(LPVOID pParam) {
	try {
		CProjectOneDlg *pDlg = (CProjectOneDlg*)pParam;
		HTuple  hv_Width;
		HTuple  hv_Height;
		HTuple  hv_AcqHandle;
		HObject ho_GrayImage;
		HObject  ho_Regions, ho_ConnectedRegions, ho_ImageIlluminate;
		HObject  ho_SelectedRegions, ho_RegionIntersection, ho_RegionFillUp;
		HObject  ho_ConnectedRegions1, ho_Circle, ho_Rectangle;
		HTuple  hv_Area, hv_Row, hv_Column, hv_Radius;
		HTuple  hv_I, hv_y, hv_x, hv_mes;



		//QR CODE
		HTuple  hv_DataCodeHandle, hv_ResultHandles, hv_DecodedDataStrings;
		HObject ho_SymbolXLDs;




		//多模板
		HTuple  hv_i, hv_ModelID1, hv_ModelID2, hv_ModelIDs, hv_ColorIndex;
		// Local iconic variables
		HObject  ho_ImageROI, ho_ImageROI2, ho_Template, ho_SearchImage;
		HObject  ho_Contour, ho_ContoursAffineTrans;
		HObject  ho_UnionContours1;

		// Local control variables
		HTuple  hv_Row1, hv_Column1, hv_Phi, hv_Length1, hv_Length2;
		HTuple  hv_NumLevels, hv_AngleStart, hv_AngleExtent, hv_AngleStep;
		HTuple  hv_Optimization, hv_Metric, hv_Contrast, hv_MinContrast;
		HTuple  hv_TypesIndex, hv_AnglesTypes, hv_Types, hv_MinScore;
		HTuple  hv_NumMatches, hv_MaxOverlap, hv_SubPixel, hv_Greediness;
		HTuple  hv_Angle, hv_Score, hv_ModelIndex, hv_MaxScoreIndex;
		HTuple  hv_MaxScore, hv_CountModels, hv_Level, hv_HomMat2D;

		//xld
		HObject  ho_ImageScaled, ho_Border1, ho_SelectedXLD, ho_SelectedXLD2;
		HTuple hv_PointOrder;


		//xld走位
		HObject  ho_ObjectSelected;
		HTuple  hv_Number, hv_Row2, hv_Col2, hv_Index;


		//项目六
		HObject  ho_ImageEL, ho_ImageLE, ho_ImageES, ho_ImageSE;
		HObject  ho_ImageEE, ho_ImageLaws, ho_ImageTexture, ho_ImageTextureReduced;
		HObject  ho_ClassRegions, ho_Correct, ho_Errors, ho_ErrorsOpening;
		HObject  ho_ErrorsClosing, ho_ErrorsConnected, ho_FinalErrors, ho_RegionOpening, ho_RegionClosing;
		HTuple  hv_Error, hv_ErrorLog, hv_NumErrors;

		
		//项目5
		HObject ho_ImageReduced, ho_SortedRegions;

		HTuple tmp;
		int tmp2;

		bool GrayDown = false;


		if (paramUtil.cameraMode == 1) {
			OpenFramegrabber("DirectShow", 1, 1, 0, 0, 0, 0, "default", 8, "rgb", -1, "false",
				"default", "[0] Integrated Camera", 0, -1, &hv_AcqHandle);
		}
		else if (paramUtil.cameraMode == 2)
		{//项目一
			OpenFramegrabber("MindVision12_X64", 1, 1, 0, 0, 0, 0, "progressive", 8, "BGR24",
				-1, "false", "auto", "超人视觉相机", 0, -1, &hv_AcqHandle);
		}
		else if (paramUtil.cameraMode == 3)
		{//项目4

#ifdef _TestOffLine
			OpenFramegrabber("DirectShow", 1, 1, 0, 0, 0, 0, "default", 8, "rgb", -1, "false",
				"default", "[0] Integrated Camera", 0, -1, &hv_AcqHandle);
#else
			OpenFramegrabber("MindVision17_X64", 1, 1, 0, 0, 0, 0, "progressive", 8, "Gray",
				-1, "false", "auto", "cam2", 0, -1, &hv_AcqHandle);
			GrayDown = true;
#endif
		}
		else if (paramUtil.cameraMode == 4)
		{//项目6

			OpenFramegrabber("MVision", 1, 1, 0, 0, 0, 0, "progressive", 8, "default", -1,
				"false", "auto", "GEV:00C10802059", 0, -1, &hv_AcqHandle);
			

			//HOperatorSet.OpenFramegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "default", -1,
			//	"default", -1, "false", "default", "c42f90f0b12d_Hikvision_MVCA05010GM",


		}

		else if (paramUtil.cameraMode == 5)
		{//项目5传送带

			OpenFramegrabber("DirectShow", 1, 1, 0, 0, 0, 0, "default", 8, "rgb", -1, "false",
				"default", "[1]  cam2", 0, -1, &hv_AcqHandle);
		}

		GrabImageStart(hv_AcqHandle, -1);

		pDlg->StartImageState = true;

		CreateDataCode2dModel("QR Code", HTuple(), HTuple(), &hv_DataCodeHandle);


		while (pDlg->StartImageState)
		{

			GrabImageAsync(&(pDlg->ho_Image), hv_AcqHandle, -1);

			if (paramUtil.rotate180) {
				RotateImage(pDlg->ho_Image, &(pDlg->ho_Image), 180, "constant"); //注意这里已经转了，后面都不要再转类
			}

			GetImageSize(pDlg->ho_Image, &hv_Width, &hv_Height);
			SetPart(pDlg->m_HWindowID, 0, 0, hv_Height, hv_Width);

			if (GrayDown)
				ho_GrayImage = pDlg->ho_Image;
			else
				Rgb1ToGray(pDlg->ho_Image, &ho_GrayImage);




			if (pDlg->takePic) {
				HTuple fileName = paramUtil.getNewFilePath_HTuple();
				WriteImage(pDlg->ho_Image, "bmp", 0, fileName);
				pDlg->takePic = false;
			}


			SetColor(pDlg->m_HWindowID, "red");

			/*通用设定结束*/


			//int Choice;
			//if (paramUtil.isGrabbing)//motion card is using
			//	Choice = 1;
			//else
			//	Choice = showMode;

			switch (showMode)
			{
				/*******************原图 begin ******************************************/
			case 1:
				DispObj(pDlg->ho_Image, pDlg->m_HWindowID);
				break;
				/*******************二维码 begin ******************************************/
			case 2:
				SetSystem("filename_encoding", "utf8");
				SetColor(pDlg->m_HWindowID, "green");

				//读取图像中的二维码
				FindDataCode2d(pDlg->ho_Image, &ho_SymbolXLDs, hv_DataCodeHandle, HTuple(), HTuple(),
					&hv_ResultHandles, &hv_DecodedDataStrings);


				DispObj(pDlg->ho_Image, pDlg->m_HWindowID);

				//显示二维码区域
				DispObj(ho_SymbolXLDs, pDlg->m_HWindowID);

				pDlg->m_info = mfcUtil.UTF82WCS(hv_DecodedDataStrings.ToString());

				pDlg->SendMessage(WM_UPDATEDATA, FALSE);

				break;

				/******************* blob begin ******************************************/
			case 3:
				Illuminate(pDlg->ho_Image, &ho_ImageIlluminate, 101, 101, 0.7);
				Threshold(ho_GrayImage, &ho_Regions, paramUtil.minGray, paramUtil.maxGray);
				Connection(ho_Regions, &ho_ConnectedRegions);
				SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", paramUtil.selectShapMinArea, paramUtil.selectShapMaxArea);
				FillUp(ho_SelectedRegions, &ho_RegionFillUp);
				DispObj(ho_GrayImage, pDlg->m_HWindowID);
				SetColored(pDlg->m_HWindowID, 12);
				DispObj(ho_RegionFillUp, pDlg->m_HWindowID);


				//标定9点拍照
				if (paramUtil.isTakeCalibrationPic)
				{
					SortRegion(ho_RegionFillUp, &ho_RegionFillUp, "character", "true", "row");
					AreaCenter(ho_RegionFillUp, &hv_Area, &hv_Row, &hv_Column);
					halconUtil.hv_RowTmp= hv_Row;
					halconUtil.hv_ColumnTmp= hv_Column;

					//halconUtil.doTakeNinePointsCenter(hv_Row, hv_Column, &doc);

					//int i = halconUtil.takePointsNum;

					//string iSt = MfcUtil::IntToString(i, 10);

					//if (halconUtil.takePointsNum == 9) {
					//	//显示pixMap
					//	//showPixMap();
					//	//showPulseMap();
					//	MessageBox(_T("提取9点成功"));
					//}
					//else {
					//	string s = "points got not 9,but " + iSt + " .";


					//	MessageBox(MfcUtil::stringToLPCWSTR(s));
					//	
					//}

					//HTuple fileName = paramUtil.getCalibrationFilePath_HTuple();
					//WriteImage(pDlg->ho_Image, "bmp", 0, fileName);
					//halconUtil.calibrationImage = pDlg->ho_Image;
					paramUtil.isTakeCalibrationPic = false;
				}


				if (paramUtil.picTarget)
				{
					AreaCenter(ho_RegionFillUp, &hv_Area, &hv_Row, &hv_Column);
					HTuple end_val8 = (hv_Area.TupleLength()) - 1;
					HTuple step_val8 = 1;
					halconMotionCardUnion.step_1_resetTargetData();
					for (hv_I = 0; hv_I.Continue(end_val8, step_val8); hv_I += step_val8)
					{
						hv_y = HTuple(hv_Row[hv_I]);
						hv_x = HTuple(hv_Column[hv_I]);


						CPoint cp;

						//halconUtil.pixToWorld_motionCardAtBase(hv_y, hv_x, cp);
						halconUtil.pixToWorld(hv_y, hv_x, cp, motionCard.getCurrentPosition(), motionCard.getBasePosition());

						halconMotionCardUnion.step_3_addTargetDataWorld(cp, 2, 0);

					}

					halconMotionCardUnion.step_4_status_endGotFromData = true;
					//显示
					int totalNum = hv_Area.TupleLength();
					CString cst = TEXT("识别出");
					CString cst1;
					cst1.Format(_T("%d"), totalNum);
					cst = cst + cst1 + TEXT("个目标");

					MessageBox(cst);
					//将要移动动点位放到motionCard
					paramUtil.picTarget = false;
				}
				break;
				/******************* 多模板 begin ******************************************/
			case 4:
				DispObj(ho_GrayImage, pDlg->m_HWindowID);

				if (paramUtil.generateRectengle) //取得模板
				{
					SetColor(pDlg->m_HWindowID, "red");
					DrawCircle(pDlg->m_HWindowID, &hv_Row, &hv_Column, &hv_Radius);
					DrawRectangle2(pDlg->m_HWindowID, &hv_Row1, &hv_Column1, &hv_Phi, &hv_Length1, &hv_Length2);

					GenCircle(&ho_Circle, hv_Row, hv_Column, hv_Radius);
					GenRectangle2(&ho_Rectangle, hv_Row1, hv_Column1, hv_Phi, hv_Length1, hv_Length2);

					ReduceDomain(ho_GrayImage, ho_Circle, &ho_ImageROI);
					ReduceDomain(ho_GrayImage, ho_Rectangle, &ho_ImageROI2);

					hv_NumLevels = "auto";
					hv_AngleStart = -0.39;
					hv_AngleExtent = 0.79;
					hv_AngleStep = "auto";
					hv_Optimization = "auto";
					hv_Metric = "use_polarity";
					hv_Contrast = "auto";
					hv_MinContrast = "auto";

					hv_AngleStart = 0;
					hv_AngleExtent = HTuple(360).TupleRad();
					hv_AngleStep = "auto";
					hv_Optimization = "auto";
					hv_Metric = "ignore_global_polarity";
					hv_NumLevels = 5;

					//对比度
					hv_Contrast = "auto";
					hv_MinContrast = "auto";


					CreateShapeModel(ho_ImageROI, hv_NumLevels, hv_AngleStart, hv_AngleExtent, hv_AngleStep,
						hv_Optimization, hv_Metric, hv_Contrast, hv_MinContrast, &hv_ModelID1);

					CreateShapeModel(ho_ImageROI2, hv_NumLevels, hv_AngleStart, hv_AngleExtent, hv_AngleStep,
						hv_Optimization, hv_Metric, hv_Contrast, hv_MinContrast, &hv_ModelID2);


					//合并成一个数组
					hv_ModelIDs.Clear();
					hv_ModelIDs.Append(hv_ModelID1);
					hv_ModelIDs.Append(hv_ModelID2);
					hv_ColorIndex.Clear();
					hv_ColorIndex[0] = "red";
					hv_ColorIndex[1] = "magenta";
					hv_TypesIndex.Clear();
					hv_TypesIndex[0] = "C";//圆形
					hv_TypesIndex[1] = "R";

					paramUtil.generateRectengle = false;
					paramUtil.gotTemplate = true;
				}

				if (paramUtil.gotTemplate)
				{
					hv_AnglesTypes = HTuple();
					hv_Types = HTuple();

					hv_AngleStart = 0;
					hv_AngleExtent = HTuple(360).TupleRad();
					hv_MinScore = 0.7;
					hv_NumMatches = 0;
					hv_MaxOverlap = 0.5;
					hv_SubPixel = "least_squares";

					hv_NumLevels = 0;

					hv_Greediness = 0.9;

					//update param
					HalconUtil::stringToHTuple(hv_MinContrast, paramUtil.minContrast);
					HalconUtil::doubleToHTuple(hv_MinScore, paramUtil.minScore);
					HalconUtil::intToHTuple(hv_NumMatches, paramUtil.numMatches);


					//多模板匹配没有scale 不能缩放
					FindShapeModels(ho_GrayImage, hv_ModelIDs, hv_AngleStart, hv_AngleExtent, hv_MinScore,
						hv_NumMatches, hv_MaxOverlap, hv_SubPixel, hv_NumLevels, hv_Greediness, &hv_Row,
						&hv_Column, &hv_Angle, &hv_Score, &hv_ModelIndex);

					//抓取
					if (halconMotionCardUnion.step_2_status_startGotFromData)
					{
						HTuple hv_y, hv_x;

						HTuple end_val131 = (hv_Score.TupleLength()) - 1;
						HTuple step_val131 = 1;
						for (hv_I = 0; hv_I.Continue(end_val131, step_val131); hv_I += step_val131)
						{
							hv_y = HTuple(hv_Row[hv_I]);
							hv_x = HTuple(hv_Column[hv_I]);


							//先判断是哪个ModelID
							int warehouse = 0;
							HTuple x = hv_TypesIndex[HTuple(hv_ModelIndex[hv_I])];
							string str = HalconUtil::HTupleToString(x);
							if (str == "R")
								warehouse = 1;

							double angleRad = HTuple(hv_Angle[hv_I]);
							//double degree = HalconUtil::radToDegree(angleRad);

							CPoint cp;
							//halconUtil.pixToWorld_motionCardAtBase(hv_y, hv_x, cp);
							halconUtil.pixToWorld(hv_y, hv_x, cp, motionCard.getCurrentPosition(), motionCard.getBasePosition());


							halconMotionCardUnion.step_3_addTargetDataWorld(cp, warehouse, angleRad);
							//halconMotionCardUnion.step_3_addTargetData(hv_y, hv_x, warehouse, angleRad);

						}
						halconMotionCardUnion.step_2_status_startGotFromData = false;
						halconMotionCardUnion.step_4_status_endGotFromData = true;
					}


					hv_MaxScoreIndex = -1;
					hv_MaxScore = 0;


					//显示XLD
					if (0 != ((hv_Score.TupleLength()) == 0))
					{

					}
					else
					{

						//DispObj(ho_GrayImage1, pDlg->m_HWindowID);
						hv_CountModels.Clear();
						hv_CountModels[0] = 0;
						hv_CountModels[1] = 0;
						{
							HTuple end_val131 = (hv_Score.TupleLength()) - 1;
							HTuple step_val131 = 1;
							for (hv_I = 0; hv_I.Continue(end_val131, step_val131); hv_I += step_val131)
							{

								//先判断是哪个ModelID
								hv_Types = hv_Types.TupleConcat(HTuple(hv_TypesIndex[HTuple(hv_ModelIndex[hv_I])]));

								SetColor(pDlg->m_HWindowID, HTuple(hv_ColorIndex[HTuple(hv_ModelIndex[hv_I])]));
								hv_CountModels[HTuple(hv_ModelIndex[hv_I])] = HTuple(hv_CountModels[HTuple(hv_ModelIndex[hv_I])]) + 1;
								hv_Level = 1;
								//取得轮廓
								GetShapeModelContours(&ho_Contour, HTuple(hv_ModelIDs[HTuple(hv_ModelIndex[hv_I])]),
									hv_Level);
								//计算角度
								//vector_angle_to_rigid (0, 0, 0, Row[I], Column[I], Angle[I], HomMat2D)

								VectorAngleToRigid(0, 0, 0, HTuple(hv_Row[hv_I]), HTuple(hv_Column[hv_I]),
									HTuple(hv_Angle[hv_I]), &hv_HomMat2D);

								AffineTransContourXld(ho_Contour, &ho_ContoursAffineTrans, hv_HomMat2D);
								UnionAdjacentContoursXld(ho_ContoursAffineTrans, &ho_UnionContours1, 10, 1,
									"attr_keep");
								DispObj(ho_UnionContours1, pDlg->m_HWindowID);

							}
						}

					}
				}

				break;

				/******************* 单模板 begin ******************************************/
			case 5:
				DispObj(ho_GrayImage, pDlg->m_HWindowID);


				if (paramUtil.generateRectengle)
				{
					SetColor(pDlg->m_HWindowID, "red");
					SetLineWidth(pDlg->m_HWindowID, 1);
					HObject  ho_Rectangle, ho_ImageROI;
					HTuple  hv_Phi, hv_Length1, hv_Length2;
					HTuple hv_Row1, hv_Column1, hv_Row2, hv_Column2;
					DrawRectangle2(pDlg->m_HWindowID, &hv_Row1, &hv_Column1, &hv_Phi, &hv_Length1, &hv_Length2);

					GenRectangle2(&ho_Rectangle, hv_Row1, hv_Column1, hv_Phi, hv_Length1, hv_Length2);

					ReduceDomain(ho_GrayImage, ho_Rectangle, &ho_ImageROI);
					templateUtil.setTemplate(ho_ImageROI);
					paramUtil.generateRectengle = false;

					templateUtil.setParam_createTemplate(false, "fff");

					templateUtil.createTemplate();
					templateUtil.setParam_findTarget(false, "fff");
					paramUtil.gotTemplate = true;
				}


				if (paramUtil.generateCircle)
				{

					SetLineWidth(pDlg->m_HWindowID, 1);
					HObject  ho_Rectangle, ho_ImageROI;
					HTuple  hv_Phi, hv_Length1, hv_Length2;
					HTuple  Row1, Column1, Radius;

					ReduceDomain(ho_GrayImage, ho_Rectangle, &ho_ImageROI);
					templateUtil.setTemplate(ho_ImageROI);
					paramUtil.generateRectengle = false;

					templateUtil.setParam_createTemplate(false, "fff");

					templateUtil.createTemplate();
					templateUtil.setParam_findTarget(false, "fff");
					paramUtil.gotTemplate = true;
				}

				if (paramUtil.gotTemplate)
				{

					SetLineWidth(pDlg->m_HWindowID, 4);
					templateUtil.setSearchImage(ho_GrayImage);
					templateUtil.findTarget();
					vector<HObject> *xlds = new vector<HObject>;
					templateUtil.showXld(xlds);
					for (vector<HObject>::iterator ite = xlds->begin(); ite != xlds->end(); ite++)
					{
						HObject tmp = *ite;
						DispObj(tmp, pDlg->m_HWindowID);
					}
				}
				break;
				/******************* xld begin ******************************************/
			case 6:
				Illuminate(ho_GrayImage, &ho_GrayImage, 101, 101, 0.7);
				ScaleImage(ho_GrayImage, &ho_ImageScaled, 6.71053, -604);
				ThresholdSubPix(ho_ImageScaled, &ho_Border1, 128);


				SelectShapeXld(ho_Border1, &ho_SelectedXLD, "circularity", "and", 0.6, 1);


				SelectShapeXld(ho_SelectedXLD, &ho_SelectedXLD2, "area_points", "and", paramUtil.areaPintsMin, paramUtil.areaPintsMax);


				DispObj(ho_GrayImage, pDlg->m_HWindowID);

				DispObj(ho_SelectedXLD2, pDlg->m_HWindowID);
				AreaCenterXld(ho_SelectedXLD2, &hv_Area, &hv_Row, &hv_Column, &hv_PointOrder);


				//抓取
				if (halconMotionCardUnion.step_2_status_startGotFromData)
				{
					HTuple hv_y, hv_x, hv_I;
					HTuple end_val131 = (hv_Area.TupleLength()) - 1;
					HTuple step_val131 = 1;
					for (hv_I = 0; hv_I.Continue(end_val131, step_val131); hv_I += step_val131)
					{
						hv_y = HTuple(hv_Row[hv_I]);
						hv_x = HTuple(hv_Column[hv_I]);
						double radian = 0;
						CPoint cp;
						//halconUtil.pixToWorld_motionCardAtBase(hv_y, hv_x, cp);
						halconUtil.pixToWorld(hv_y, hv_x, cp, motionCard.getCurrentPosition(), motionCard.getBasePosition());


						halconMotionCardUnion.step_3_addTargetDataWorld(cp, 2, radian);
					}
					halconMotionCardUnion.step_2_status_startGotFromData = false;
					halconMotionCardUnion.step_4_status_endGotFromData = true;
				}

				//走位
				if (halconMotionCardUnion.startCollectContourPoint)
				{

					CountObj(ho_SelectedXLD2, &hv_Number);
					halconMotionCardUnion.cleanConTourList();
					int num = HalconUtil::HTupleToInt(hv_Number);
					halconMotionCardUnion.initContourListMap(num);
					{
						HTuple end_val35 = hv_Number;
						HTuple step_val35 = 1;
						int currentNum;
						for (hv_I = 1; hv_I.Continue(end_val35, step_val35); hv_I += step_val35)
						{
							currentNum = HalconUtil::HTupleToInt(hv_I);
							SelectObj(ho_SelectedXLD2, &ho_ObjectSelected, hv_I);
							GetContourXld(ho_ObjectSelected, &hv_Row2, &hv_Col2);

							{
								HTuple end_val39 = (hv_Row2.TupleLength()) - 1;
								HTuple step_val39 = 1;
								for (hv_Index = 0; hv_Index.Continue(end_val39, step_val39); hv_Index += step_val39)
								{
									hv_y = HTuple(hv_Row2[hv_Index]);
									hv_x = HTuple(hv_Col2[hv_Index]);


									CPoint cp;
									halconUtil.pixToWorld(hv_y, hv_x, cp, motionCard.getCurrentPosition(), motionCard.getBasePosition());

									halconMotionCardUnion.addContourList(currentNum, cp);
								}
							}
						}
						int totalNum = HalconUtil::HTupleToInt(hv_Number);
						CString cst = TEXT("要走");
						CString cst1;
						cst1.Format(_T("%d"), totalNum);
						CString cst2;
						cst2.Format(_T("%d"), halconMotionCardUnion.contourListSize(1));
						cst = cst + cst1 + TEXT("个Contour") + cst2 + TEXT("个Point");
						MessageBox(cst);
						halconMotionCardUnion.startCollectContourPoint = false;
						halconMotionCardUnion.CompleteCollectContourPoint = true;

					}
				}
				break;

				/******************* case 4 begin ******************************************/
			case 7:
				Illuminate(ho_Image, &ho_ImageIlluminate, 101, 101, 0.7);
				Threshold(ho_GrayImage, &ho_Regions, paramUtil.minGray, paramUtil.maxGray);
				Connection(ho_Regions, &ho_ConnectedRegions);
				SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", paramUtil.selectShapMinArea, paramUtil.selectShapMaxArea);
				FillUp(ho_SelectedRegions, &ho_RegionFillUp);
				DispObj(ho_GrayImage, pDlg->m_HWindowID);
				SetColored(pDlg->m_HWindowID, 12);
				DispObj(ho_RegionFillUp, pDlg->m_HWindowID);

				//标定9点拍照
				if (paramUtil.caseFourCalibration_CameraOne)
				{
					//HTuple fileName = paramUtil.getCalibrationFilePath_HTuple();
					//WriteImage(pDlg->ho_Image, "bmp", 0, fileName);
#ifdef _TestOffLine
					HTuple fileName = paramUtil.getCalibrationFilePath_HTuple();
					ReadImage(&ho_Image, fileName);
					halconUtil.calibrationImage_projectFour_CameraOne = ho_Image;
#else
					halconUtil.calibrationImage_projectFour_CameraOne = pDlg->ho_Image;
#endif

					
					paramUtil.caseFourCalibration_CameraOne = false;
				}

				break;


				/******************* case 5 begin ******************************************/
			case 8://传输带


				GetImageSize(ho_Image, &hv_Width, &hv_Height);

	

				Illuminate(ho_Image, &ho_ImageIlluminate, 101, 101, 0.7);


				Rgb1ToGray(ho_ImageIlluminate, &ho_GrayImage);


				GenRectangle1(&ho_Rectangle, 200, 220, 800, 850);
				ReduceDomain(ho_GrayImage, ho_Rectangle, &ho_ImageReduced);

				Threshold(ho_ImageReduced, &ho_Regions, 0, 107);
				Connection(ho_Regions, &ho_ConnectedRegions);

				SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", 5000, 30000);



				FillUp(ho_SelectedRegions, &ho_RegionFillUp);


				SortRegion(ho_RegionFillUp, &ho_SortedRegions, "character", "true", "row");
				DispObj(ho_Image, pDlg->m_HWindowID);
				SetColored(pDlg->m_HWindowID, 12);
				DispObj(ho_RegionFillUp, pDlg->m_HWindowID);

				if (paramUtil.conveyorTakeNine)
				{
					paramUtil.conveyorTakeNine = false;
					AreaCenter(ho_SortedRegions, &hv_Area, &hv_Row, &hv_Column);

					halconUtil.doTakeNinePointsCenter(hv_Row, hv_Column, &doc);

					int i = halconUtil.takePointsNum;

					string iSt = MfcUtil::IntToString(i, 10);

					if (halconUtil.takePointsNum == 9) {
						//显示pixMap
						MessageBox(_T("提取9点成功"));
					}
					else {
						string s = "提取点数不为9,实际提取 " + iSt + " 点.";
						MessageBox(MfcUtil::stringToLPCWSTR(s));
						
					}

				}

				break;


				/******************* case 6 begin ******************************************/
			case 9:
				


					DispObj(ho_GrayImage, pDlg->m_HWindowID);

					if (paramUtil.mlp_takeSample1) {

						WriteImage(pDlg->ho_Image, "bmp", 0, halconUtil.getMlpExampleFilePath(1));
						paramUtil.mlp_takeSample1 = false;
						paramUtil.mlp_gotSample1 = true;
						MessageBox(_T("记录样本一"));

					}
					else if (paramUtil.mlp_takeSample2) {
						WriteImage(pDlg->ho_Image, "bmp", 0, halconUtil.getMlpExampleFilePath(2));
						paramUtil.mlp_takeSample2 = false;
						paramUtil.mlp_gotSample2 = true;
						MessageBox(_T("记录样本二"));
					}
					else if (paramUtil.mlp_takeSample3) {
						WriteImage(pDlg->ho_Image, "bmp", 0, halconUtil.getMlpExampleFilePath(3));
						paramUtil.mlp_takeSample3 = false;
						paramUtil.mlp_gotSample3 = true;
						MessageBox(_T("记录样本三"));
					}
					else if (paramUtil.mlp_takeSample4) {
						WriteImage(pDlg->ho_Image, "bmp", 0, halconUtil.getMlpExampleFilePath(4));
						paramUtil.mlp_takeSample4 = false;
						paramUtil.mlp_gotSample4 = true;
						MessageBox(_T("记录样本四"));
					}

					SetDraw(pDlg->m_HWindowID, "margin");

					

					//mlp 显示
					Rgb1ToGray(pDlg->ho_Image, &ho_GrayImage);
					Threshold(ho_GrayImage, &ho_Regions, paramUtil.mlp_minGray, paramUtil.mlp_maxGray);
					OpeningCircle(ho_Regions, &ho_RegionOpening, 3.5);
					ClosingCircle(ho_RegionOpening, &ho_RegionClosing, 3.5);

					Connection(ho_RegionClosing, &ho_ConnectedRegions);
					FillUp(ho_ConnectedRegions, &ho_RegionFillUp);
					SelectShapeStd(ho_RegionFillUp, &ho_SelectedRegions, "max_area", 70);
					DispObj(ho_GrayImage, pDlg->m_HWindowID);
					DispObj(ho_SelectedRegions, pDlg->m_HWindowID);
					DumpWindowImage(&ho_DumpImg, pDlg->m_HWindowID);



					//辨识
					if (paramUtil.mlp_startDetect)
					{


						TextureLaws(pDlg->ho_Image, &ho_ImageEL, "el", 5, 5);
						TextureLaws(pDlg->ho_Image, &ho_ImageLE, "le", 5, 5);
						TextureLaws(pDlg->ho_Image, &ho_ImageES, "es", 1, 5);
						TextureLaws(pDlg->ho_Image, &ho_ImageSE, "se", 1, 5);
						TextureLaws(pDlg->ho_Image, &ho_ImageEE, "ee", 2, 5);
						Compose5(ho_ImageEL, ho_ImageLE, ho_ImageES, ho_ImageSE, ho_ImageEE, &ho_ImageLaws
						);
						SmoothImage(ho_ImageLaws, &ho_ImageTexture, "gauss", 3);
						ReduceDomain(ho_ImageTexture, ho_SelectedRegions, &ho_ImageTextureReduced);
						ClassifyImageClassMlp(ho_ImageTextureReduced, &ho_ClassRegions, halconUtil.hv_MLPHandle, 0.5);

						SelectObj(ho_ClassRegions, &ho_Correct, 1);

						SelectObj(ho_ClassRegions, &ho_Errors, 2);

						if (paramUtil.mlp_openingCircleRadius == 0)
							ho_ErrorsOpening = ho_Errors;
						else
							OpeningCircle(ho_Errors, &ho_ErrorsOpening, paramUtil.mlp_openingCircleRadius);

						//ClosingCircle(ho_ErrorsOpening, &ho_ErrorsClosing, 12.5);
						Connection(ho_ErrorsOpening, &ho_ErrorsConnected);
						SelectShape(ho_ErrorsConnected, &ho_FinalErrors, "area", "and", 1, 1000000);
						//SelectShapeStd(ho_ErrorsConnected, &ho_FinalErrors, "max_area", 70); 会出错多1，要用SelectShape
						CountObj(ho_FinalErrors, &hv_NumErrors);


						DispObj(ho_GrayImage, pDlg->m_HWindowID);
						SetDraw(pDlg->m_HWindowID, "fill");
						DispObj(ho_FinalErrors, pDlg->m_HWindowID);



						//int corNum = halconUtil.HTupleToInt(hv_NumErrors);
						int errNum = halconUtil.HTupleToInt(hv_NumErrors);

						if (errNum > 0)
						{
							
							pDlg->ho_NG = ho_DumpImg;

							
							HTuple fileName = paramUtil.getFilePath_NG_Write();
							WriteImage(pDlg->ho_DumpImg, "bmp", 0, fileName);
							
							pDlg->m_info = "NG";

							pDlg->SendMessage(WM_UPDATEDATA, FALSE);



						}
						else
						{
							pDlg->ho_OK = ho_DumpImg;


							HTuple fileName = paramUtil.getFilePath_OK_Write();
							WriteImage(pDlg->ho_DumpImg, "bmp", 0, fileName);


							pDlg->m_info = "OK";
							pDlg->SendMessage(WM_UPDATEDATA, FALSE);

						}
					}



			

		
	

	

				
				break;
			}

		}
		CloseFramegrabber(hv_AcqHandle);
		AfxEndThread(0);
		return 0;
	}
	catch (...) {
		try {
			CloseFramegrabber(hv_AcqHandle);
		}
		catch (...) {}

		try {
			AfxEndThread(0);
		}
		catch (...) {}


		return 0;
	};
}







void CProjectOneDlg::OnBnClickedButton2()
{
	dmcUtil.emergentStop();
}






bool CProjectOneDlg::ShowPic2(CString filePaTH, int ID)//形参可以为所给的图片对象的指针，这里为了通用性省去了形参
{
	try 
	{
		float cx, cy, dx, dy, k, t;//跟控件的宽和高以及图片宽和高有关的参数
		CRect   rect;//用于获取图片控件的宽和高
		CImage q;//为cimage图片类创建一个对象

		HRESULT result=q.Load(filePaTH);//构造函数的形参是所加载图片的路径 
		if (result == E_FAIL)
			return false;
		
		cx = q.GetWidth();
		cy = q.GetHeight();//获取图片的宽 高
		k = cy / cx;//获得图片的宽高比

		CWnd *pWnd = NULL;
		pWnd = GetDlgItem(ID);//获取控件句柄
		pWnd->GetClientRect(&rect);//获取Picture Control控件的客户区
		dx = rect.Width();
		dy = rect.Height();//获得控件的宽高比
		t = dy / dx;//获得控件的宽高比
		if (k >= t)
		{

			rect.right = floor(rect.bottom / k);
			rect.left = (dx - rect.right) / 2;
			rect.right = floor(rect.bottom / k) + (dx - rect.right) / 2;
		}
		else
		{
			rect.bottom = floor(k*rect.right);
			rect.top = (dy - rect.bottom) / 2;
			rect.bottom = floor(k*rect.right) + (dy - rect.bottom) / 2;
		}
		//相关的计算为了让图片在绘图区居中按比例显示，原理很好懂，如果图片很宽但是不高，就上下留有空白区；如果图片很高而不宽就左右留有空白区，并且保持两边空白区一样大

		CDC *pDc = NULL;
		pDc = pWnd->GetDC();//获取picture control的DC，这是什么玩意我也不知道，百度就行
		int ModeOld = SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);//设置指定设备环境中的位图拉伸模式

		GetDlgItem(ID)->ShowWindow(FALSE);
		GetDlgItem(ID)->ShowWindow(TRUE);
		q.StretchBlt(pDc->m_hDC, rect, SRCCOPY);//显示函数
		SetStretchBltMode(pDc->m_hDC, ModeOld);
		ReleaseDC(pDc);//释放指针空间
		return true;
	}catch(...)
	{
		return false;
	}
}


bool CProjectOneDlg::updateNGAndOK()
{

	lucked = true;
	if (paramUtil.cameraModeSecond == 2)
	{

		if (paramUtil.fileNameCount_NG > previousPicCount_ng)
		{
			int downNum = paramUtil.fileNameCount_NG - 1;
			if (downNum < 0)
				downNum = 0;
			CString path = paramUtil.getCStringFilePath_NG_Read(downNum);
			if (ShowPic2(path, IDC_PC2))
			{
				previousPicCount_ng = paramUtil.fileNameCount_NG;
				return true;
			}
			else
			{

				previousPicCount_ng = paramUtil.fileNameCount_NG;
				return false;
			}
		}

	}
	else if (paramUtil.cameraModeSecond == 3)
	{//update OK
		if (paramUtil.fileNameCount_OK > previousPicCount_ok)
		{
			int downNum = paramUtil.fileNameCount_OK - 1;
			CString path = paramUtil.getCStringFilePath_OK_Read(downNum);
			if(ShowPic2(path, IDC_PC2))
			{
				previousPicCount_ok = paramUtil.fileNameCount_OK;
				return true;
			}
			else
			{
				previousPicCount_ok = paramUtil.fileNameCount_OK;
				return false;
			}
		}

	}
	lucked = false;
	return true;
}

void CProjectOneDlg::OnBnClickedRadio14()
{
	// TODO: 在此添加控件通知处理程序代码
	paramUtil.cameraMode = 5;
	paramUtil.showModeSynWithMainWin = showMode;
}


void CProjectOneDlg::OnBnClickedEnumButton()
{
	CString strMsg;

	// ch:清除设备列表框中的信息 | en:Clear Device List Information
	m_ctrlDeviceCombo.ResetContent();

	// ch:初始化设备信息列表 | en:Device Information List Initialization
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));

	// ch:枚举子网内所有设备 | en:Enumerate all devices within subnet
	int nRet = CMyCamera::EnumDevices(&m_stDevList);
	if (MV_OK != nRet)
	{
		return;
	}

	// ch:将值加入到信息列表框中并显示出来 | en:Add value to the information list box and display
	unsigned int i;
	int nIp1, nIp2, nIp3, nIp4;
	for (i = 0; i < m_stDevList.nDeviceNum; i++)
	{
		MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
		if (NULL == pDeviceInfo)
		{
			continue;
		}
		if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
		{
			nIp1 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
			nIp2 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
			nIp3 = ((m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
			nIp4 = (m_stDevList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

			wchar_t* pUserName = NULL;
			if (strcmp("", (LPCSTR)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName)) != 0)
			{
				DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName), -1, NULL, 0);
				pUserName = new wchar_t[dwLenUserName];
				MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName), -1, pUserName, dwLenUserName);
			}
			else
			{
				char strUserName[256] = { 0 };
				sprintf_s(strUserName, "%s %s (%s)", pDeviceInfo->SpecialInfo.stGigEInfo.chManufacturerName,
					pDeviceInfo->SpecialInfo.stGigEInfo.chModelName,
					pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber);
				DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, NULL, 0);
				pUserName = new wchar_t[dwLenUserName];
				MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, pUserName, dwLenUserName);
			}
			strMsg.Format(_T("[%d]GigE:    %s  (%d.%d.%d.%d)"), i,
				pUserName, nIp1, nIp2, nIp3, nIp4);
			if (NULL != pUserName)
			{
				delete(pUserName);
				pUserName = NULL;
			}

		}
		else if (pDeviceInfo->nTLayerType == MV_USB_DEVICE)
		{
			wchar_t* pUserName = NULL;

			if (strcmp("", (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName) != 0)
			{
				DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName), -1, NULL, 0);
				pUserName = new wchar_t[dwLenUserName];
				MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName), -1, pUserName, dwLenUserName);
			}
			else
			{
				char strUserName[256];
				sprintf_s(strUserName, "%s %s (%s)", pDeviceInfo->SpecialInfo.stUsb3VInfo.chManufacturerName,
					pDeviceInfo->SpecialInfo.stUsb3VInfo.chModelName,
					pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber);
				DWORD dwLenUserName = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, NULL, 0);
				pUserName = new wchar_t[dwLenUserName];
				MultiByteToWideChar(CP_ACP, 0, (LPCSTR)(strUserName), -1, pUserName, dwLenUserName);
			}
			strMsg.Format(_T("[%d]UsbV3:  %s"), i, pUserName);
			if (NULL != pUserName)
			{
				delete(pUserName);
				pUserName = NULL;
			}

		}
		else
		{
			ShowErrorMsg(TEXT("Unknown device enumerated"), 0);;
		}
		m_ctrlDeviceCombo.AddString(strMsg);
	}

	if (0 == m_stDevList.nDeviceNum)
	{
		ShowErrorMsg(TEXT("No device"), 0);
		return;
	}
	m_ctrlDeviceCombo.SetCurSel(0);



	return;
}





void CProjectOneDlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int nRet = OpenDevice();
	if (MV_OK != nRet)
	{
		ShowErrorMsg(TEXT("Open Fail"), nRet);
		return;
	}

	OnBnClickedGetParameterButton(); // ch:获取参数 | en:Get Parameter

	return;
}


void CProjectOneDlg::OnBnClickedCloseButton()
{
	MvsStopGrabbing();
	CloseDevice();

	return;
}


void CProjectOneDlg::OnBnClickedGetParameterButton()
{

	int nRet = GetExposureTime();
	if (nRet != MV_OK)
	{
		ShowErrorMsg(TEXT("Get Exposure Time Fail"), nRet);
	}

	nRet = GetGain();
	if (nRet != MV_OK)
	{
		ShowErrorMsg(TEXT("Get Gain Fail"), nRet);
	}

	nRet = GetFrameRate();
	if (nRet != MV_OK)
	{
		ShowErrorMsg(TEXT("Get Frame Rate Fail"), nRet);
	}

	UpdateData(FALSE);
	return;
}


void CProjectOneDlg::OnBnClickedSetParameterButton()
{
	UpdateData(TRUE);

	bool bIsSetSucceed = true;
	int nRet = SetExposureTime();
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		ShowErrorMsg(TEXT("Set Exposure Time Fail"), nRet);
	}
	nRet = SetGain();
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		ShowErrorMsg(TEXT("Set Gain Fail"), nRet);
	}
	nRet = SetFrameRate();
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		ShowErrorMsg(TEXT("Set Frame Rate Fail"), nRet);
	}

	if (true == bIsSetSucceed)
	{
		ShowErrorMsg(TEXT("Set Parameter Succeed"), nRet);
	}

	return;
}

// ch:显示错误信息 | en:Show error message
void CProjectOneDlg::ShowErrorMsg(CString csMessage, int nErrorNum)
{
	CString errorMsg;
	if (nErrorNum == 0)
	{
		errorMsg.Format(_T("%s"), csMessage);
	}
	else
	{
		errorMsg.Format(_T("%s: Error = %x: "), csMessage, nErrorNum);
	}

	switch (nErrorNum)
	{
	case MV_E_HANDLE:           errorMsg += "Error or invalid handle ";                                         break;
	case MV_E_SUPPORT:          errorMsg += "Not supported function ";                                          break;
	case MV_E_BUFOVER:          errorMsg += "Cache is full ";                                                   break;
	case MV_E_CALLORDER:        errorMsg += "Function calling order error ";                                    break;
	case MV_E_PARAMETER:        errorMsg += "Incorrect parameter ";                                             break;
	case MV_E_RESOURCE:         errorMsg += "Applying resource failed ";                                        break;
	case MV_E_NODATA:           errorMsg += "No data ";                                                         break;
	case MV_E_PRECONDITION:     errorMsg += "Precondition error, or running environment changed ";              break;
	case MV_E_VERSION:          errorMsg += "Version mismatches ";                                              break;
	case MV_E_NOENOUGH_BUF:     errorMsg += "Insufficient memory ";                                             break;
	case MV_E_ABNORMAL_IMAGE:   errorMsg += "Abnormal image, maybe incomplete image because of lost packet ";   break;
	case MV_E_UNKNOW:           errorMsg += "Unknown error ";                                                   break;
	case MV_E_GC_GENERIC:       errorMsg += "General error ";                                                   break;
	case MV_E_GC_ACCESS:        errorMsg += "Node accessing condition error ";                                  break;
	case MV_E_ACCESS_DENIED:	errorMsg += "No permission ";                                                   break;
	case MV_E_BUSY:             errorMsg += "Device is busy, or network disconnected ";                         break;
	case MV_E_NETER:            errorMsg += "Network error ";                                                   break;
	}

	MessageBox(errorMsg, TEXT("PROMPT"), MB_OK | MB_ICONWARNING);
}

// ch:最开始时的窗口初始化 | en:Initial window initialization
int CProjectOneDlg::DisplayWindowInitial(void)
{
	CWnd *pWnd = GetDlgItem(IDC_DISPLAY_STATIC);
	if (NULL == pWnd)
	{
		return STATUS_ERROR;
	}
	m_hwndDisplay = pWnd->GetSafeHwnd();
	if (NULL == m_hwndDisplay)
	{
		return STATUS_ERROR;
	}
	return MV_OK;
}


// ch:打开设备 | en:Open Device
int CProjectOneDlg::OpenDevice(void)
{
	if (TRUE == m_bOpenDevice)
	{
		return STATUS_ERROR;
	}
	UpdateData(TRUE);
	if (TRUE == m_bOpenDevice)
	{
		return STATUS_ERROR;
	}
	int nIndex = m_nDeviceCombo;
	if ((nIndex < 0) | (nIndex >= MV_MAX_DEVICE_NUM))
	{
		ShowErrorMsg(TEXT("Please select device"), 0);
		return STATUS_ERROR;
	}

	// ch:由设备信息创建设备实例 | en:Device instance created by device information
	if (NULL == m_stDevList.pDeviceInfo[nIndex])
	{
		ShowErrorMsg(TEXT("Device does not exist"), 0);
		return STATUS_ERROR;
	}

	if (NULL != m_pcMyCamera)
	{
		return STATUS_ERROR;
	}

	m_pcMyCamera = new CMyCamera;
	if (NULL == m_pcMyCamera)
	{
		return STATUS_ERROR;
	}

	int nRet = m_pcMyCamera->Open(m_stDevList.pDeviceInfo[nIndex]);
	if (MV_OK != nRet)
	{
		delete m_pcMyCamera;
		m_pcMyCamera = NULL;
		return nRet;
	}

	// ch:探测网络最佳包大小(只对GigE相机有效) | en:Detection network optimal package size(It only works for the GigE camera)
	if (m_stDevList.pDeviceInfo[nIndex]->nTLayerType == MV_GIGE_DEVICE)
	{
		int nPacketSize = m_pcMyCamera->GetOptimalPacketSize();
		if (nPacketSize > 0)
		{
			nRet = m_pcMyCamera->SetIntValue("GevSCPSPacketSize", nPacketSize);
			if (nRet != MV_OK)
			{
				ShowErrorMsg(TEXT("Warning: Set Packet Size fail!"), nRet);
			}
		}
		else
		{
			ShowErrorMsg(TEXT("Warning: Get Packet Size fail!"), nPacketSize);
		}
	}

	m_bOpenDevice = TRUE;

	return MV_OK;
}





// ch:获取曝光时间 | en:Get Exposure Time
int CProjectOneDlg::GetExposureTime(void)
{
	float  fFloatValue = 0.0;
	int nRet = m_pcMyCamera->GetFloatValue("ExposureTime", &fFloatValue);
	if (MV_OK != nRet)
	{
		return nRet;
	}

	m_dExposureEdit = fFloatValue;

	return MV_OK;
}

// ch:设置曝光时间 | en:Set Exposure Time
int CProjectOneDlg::SetExposureTime(void)
{
	// ch:调节这两个曝光模式，才能让曝光时间生效
	// en:Adjust these two exposure mode to allow exposure time effective
	int nRet = m_pcMyCamera->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);
	if (MV_OK != nRet)
	{
		return nRet;
	}

	nRet = m_pcMyCamera->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);

	nRet = m_pcMyCamera->SetFloatValue("ExposureTime", m_dExposureEdit);
	if (MV_OK != nRet)
	{
		return nRet;
	}

	return MV_OK;
}

// ch:获取增益 | en:Get Gain
int CProjectOneDlg::GetGain(void)
{
	float  fFloatValue = 0.0;

	int nRet = m_pcMyCamera->GetFloatValue("Gain", &fFloatValue);
	if (MV_OK != nRet)
	{
		return nRet;
	}
	m_dGainEdit = (int)fFloatValue;

	return MV_OK;
}

// ch:设置增益 | en:Set Gain
int CProjectOneDlg::SetGain(void)
{
	// ch:设置增益前先把自动增益关闭，失败无需返回
	//en:Set Gain after Auto Gain is turned off, this failure does not need to return
	int nRet = m_pcMyCamera->SetEnumValue("GainAuto", 0);

	return m_pcMyCamera->SetFloatValue("Gain", m_dGainEdit);
}

// ch:获取帧率 | en:Get Frame Rate
int CProjectOneDlg::GetFrameRate(void)
{

	float  fFloatValue = 0.0;

	int nRet = m_pcMyCamera->GetFloatValue("ResultingFrameRate", &fFloatValue);
	if (MV_OK != nRet)
	{
		return nRet;
	}
	m_dFrameRateEdit = fFloatValue;

	return MV_OK;
}

// ch:设置帧率 | en:Set Frame Rate
int CProjectOneDlg::SetFrameRate(void)
{
	int nRet = m_pcMyCamera->SetBoolValue("AcquisitionFrameRateEnable", true);
	if (MV_OK != nRet)
	{
		return nRet;
	}

	return m_pcMyCamera->SetFloatValue("AcquisitionFrameRate", m_dFrameRateEdit);
}


// ch:关闭设备 | en:Close Device
int CProjectOneDlg::CloseDevice(void)
{
	if (m_pcMyCamera)
	{
		m_pcMyCamera->Close();
		delete m_pcMyCamera;
		m_pcMyCamera = NULL;
	}

	m_bOpenDevice = FALSE;
	m_bStartGrabbing = FALSE;

	if (m_pBufForDriver)
	{
		free(m_pBufForDriver);
		m_pBufForDriver = NULL;
	}
	m_nBufSizeForDriver = 0;

	return MV_OK;
}

int CProjectOneDlg::ImgMomeCopy(LPVOID pParam)
{

	CProjectOneDlg *pDlg = (CProjectOneDlg*)pParam;
	m_nSaveImageType = MV_Image_Bmp;
	if (FALSE == m_bStartGrabbing)
	{
		return STATUS_ERROR;
	}
	// ch:获取1张图 | en:get one image
	unsigned int nRecvBufSize = 0;
	int nRet = MV_OK;

	// ch:仅在第一次保存图像时申请缓存，在 CloseDevice 时释放
	// en:Request buffer only when save image for first time, release after CloseDevice
	if (NULL == m_pBufForDriver)
	{
		// ch:从相机中获取一帧图像大小 | en:Get size of one frame from camera
		nRet = m_pcMyCamera->GetIntValue("PayloadSize", &nRecvBufSize);
		if (nRet != MV_OK)
		{
			ShowErrorMsg(TEXT("failed in get PayloadSize"), nRet);
			return nRet;
		}
		// ch:一帧数据大小
		// en:One frame size
		m_nBufSizeForDriver = nRecvBufSize;
		m_pBufForDriver = (unsigned char *)malloc(m_nBufSizeForDriver);
		if (NULL == m_pBufForDriver)
		{
			ShowErrorMsg(TEXT("malloc m_pBufForDriver failed, run out of memory"), 0);
			return nRet;
		}
	}

	MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
	memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));

	unsigned int nDataSize = nRecvBufSize;
	unsigned int nImageNum = 1;
	unsigned int nDataLen = 0;
	byte *m_pImageData = nullptr;

	

	HObject  ho_ImageEL, ho_ImageLE, ho_ImageES, ho_ImageSE;
	HObject  ho_ImageEE, ho_ImageLaws, ho_ImageTexture, ho_ImageTextureReduced;
	HObject  ho_ClassRegions, ho_Correct, ho_Errors, ho_ErrorsOpening;
	HObject  ho_ErrorsClosing, ho_ErrorsConnected, ho_FinalErrors, ho_RegionOpening, ho_RegionClosing;
	HTuple  hv_Error, hv_ErrorLog, hv_NumErrors, hv_Number;
	HObject  ho_Regions, ho_ConnectedRegions, ho_ImageIlluminate;
	HObject  ho_SelectedRegions, ho_RegionIntersection, ho_RegionFillUp;



	//deque<InfoUnit>::iterator it;
	InfoUnit info;

	int dequecount = 0;

	

	while (m_bStartGrabbing)
	{


			


		   nRet = m_pcMyCamera->GetOneFrameTimeout(m_pBufForDriver, &nDataLen, m_nBufSizeForDriver, &stImageInfo, 1000);
			


		   if (nullptr == m_pImageData)
		   {
			   // ch:BMP图片大小：width * height * 3 + 2048(预留BMP头大小)
			   // en:// BMP image size: width * height * 3 + 2048 (Reserved BMP header size)
			   //m_nBufSizeForSaveImage = stImageInfo.nWidth * stImageInfo.nHeight * 3 + 2048;


			   int bytewidth = (stImageInfo.nWidth * 3 + 3) / 4 * 4; ;
			 //  int bytewidthg = (stImageInfo.nHeight + 3) / 4 * 4;

			  // byte *m_pImageDataR = new byte[stImageInfo.nWidth * stImageInfo.nHeight];
			  // byte *m_pImageDataG = new byte[stImageInfo.nWidth * stImageInfo.nHeight];
			  // byte *m_pImageDataB = new byte[stImageInfo.nWidth * stImageInfo.nHeight];
			  // byte *m_pImageDatagray = new byte[stImageInfo.nWidth * stImageInfo.nHeight];
			   m_pImageData = new byte[bytewidth * stImageInfo.nHeight];

		   }

		
		if (nRet == MV_OK)
		{		
			memcpy(m_pImageData, m_pBufForDriver, stImageInfo.nWidth * stImageInfo.nHeight);

			//
			HObject *m_ho_Image;
			HObject	ho_GrayImage;
			HTuple hv_Width, hv_Height, hv_Area, hv_Row, hv_Column;

			m_ho_Image = new HObject;
			//GenImage1Extern(m_ho_Image, "byte", stImageInfo.nWidth, stImageInfo.nHeight, (long)m_pImageData, (long)free);
			NewImage(m_ho_Image, m_pImageData, stImageInfo.nWidth, stImageInfo.nHeight);

		
			
			Rgb1ToGray(*m_ho_Image, &ho_GrayImage);
			GetImageSize(ho_GrayImage, &hv_Width, &hv_Height);
			SetPart(pDlg->m_HWindowID, 0, 0, hv_Height, hv_Width);


			
			DispObj(ho_GrayImage, pDlg->m_HWindowID);


			/*if (paramUtil.mlp_takeSample1) {

				WriteImage(*m_ho_Image, "bmp", 0, halconUtil.getMlpExampleFilePath(1));
				paramUtil.mlp_takeSample1 = false;
				paramUtil.mlp_gotSample1 = true;
				MessageBox(_T("记录样本一"));

			}
			else if (paramUtil.mlp_takeSample2) {
				WriteImage(*m_ho_Image, "bmp", 0, halconUtil.getMlpExampleFilePath(2));
				paramUtil.mlp_takeSample2 = false;
				paramUtil.mlp_gotSample2 = true;
				MessageBox(_T("记录样本二"));
			}
			else if (paramUtil.mlp_takeSample3) {
				WriteImage(*m_ho_Image, "bmp", 0, halconUtil.getMlpExampleFilePath(3));
				paramUtil.mlp_takeSample3 = false;
				paramUtil.mlp_gotSample3 = true;
				MessageBox(_T("记录样本三"));
			}
			else if (paramUtil.mlp_takeSample4) {
				WriteImage(*m_ho_Image, "bmp", 0, halconUtil.getMlpExampleFilePath(4));
				paramUtil.mlp_takeSample4 = false;
				paramUtil.mlp_gotSample4 = true;
				MessageBox(_T("记录样本四"));
			}*/

		Loop2:
			if (paramUtil.isClearQue)
				dequecount = 0;
		

			if (paramUtil.mlp_startDetect&&dmcUtil.Camera1Deque.size() > dequecount)
			{

				int currentPulse = dmcUtil.getCurrentPulse();
				info = dmcUtil.Camera1Deque[dequecount];

				dequecount++;

				if (currentPulse > info.cameraOnePicPulse_schedule_Max)
				{
					//MessageBox(_T("转盘速度太快"));
					pDlg->m_info = _T("转盘速度太快");
					pDlg->SendMessage(WM_UPDATEDATA, FALSE);
					goto Loop2;
				}



			
				while (dmcUtil.getCurrentPulse() < info.cameraOnePicPulse_schedule_Mid);
				Loop:
				//重新取照片


				nRet = m_pcMyCamera->GetOneFrameTimeout(m_pBufForDriver, &nDataLen, m_nBufSizeForDriver, &stImageInfo, 1000);

				memcpy(m_pImageData, m_pBufForDriver, stImageInfo.nWidth * stImageInfo.nHeight);

				//
				HObject *m_ho_Image;
				HObject	ho_GrayImage;
				HTuple hv_Width, hv_Height;

				m_ho_Image = new HObject;
				//GenImage1Extern(m_ho_Image, "byte", stImageInfo.nWidth, stImageInfo.nHeight, (long)m_pImageData, (long)free);
				NewImage(m_ho_Image, m_pImageData, stImageInfo.nWidth, stImageInfo.nHeight);

	

				pDlg->ho_Image = *m_ho_Image;

				//mlp 显示
				Rgb1ToGray(pDlg->ho_Image, &ho_GrayImage);
				Threshold(ho_GrayImage, &ho_Regions, paramUtil.mlp_minGray, paramUtil.mlp_maxGray);
				OpeningCircle(ho_Regions, &ho_RegionOpening, 3.5);
				ClosingCircle(ho_RegionOpening, &ho_RegionClosing, 3.5);

				Connection(ho_RegionClosing, &ho_ConnectedRegions);

				//CountObj(ho_ConnectedRegions, &hv_Number);
				//if (0 != (hv_Number != 1))
				//{
				//	//disp_message(hv_WindowHandle, "数量必须为1", "window", 12, 12, "black", "true");
				//	pDlg->m_info = _T("数量必须为1");
				//	pDlg->SendMessage(WM_UPDATEDATA, FALSE);
				//	goto Loop;
				//}


				AreaCenter(ho_ConnectedRegions, &hv_Area, &hv_Row, &hv_Column);

				if (0 != (hv_Area < 20000))
				{
						//pDlg->m_info = _T("数量必须为1");
						//pDlg->SendMessage(WM_UPDATEDATA, FALSE);
						HTuple fileName = paramUtil.getFilePath_SysErr_Write();
						WriteImage(pDlg->ho_Image, "bmp", 0, fileName);
						goto Loop;
				}


				dmcUtil.m_count_camera++;
				

				SetDraw(pDlg->m_HWindowID, "margin");


				FillUp(ho_ConnectedRegions, &ho_RegionFillUp);
				SelectShapeStd(ho_RegionFillUp, &ho_SelectedRegions, "max_area", 70);

				SetColor(pDlg->m_HWindowID, "red");


				//DispObj(ho_GrayImage, pDlg->m_HWindowID);
				//DispObj(ho_SelectedRegions, pDlg->m_HWindowID);
				//DumpWindowImage(&ho_DumpImg, pDlg->m_HWindowID);



				//辨识

					TextureLaws(pDlg->ho_Image, &ho_ImageEL, "el", 5, 5);
					TextureLaws(pDlg->ho_Image, &ho_ImageLE, "le", 5, 5);
					TextureLaws(pDlg->ho_Image, &ho_ImageES, "es", 1, 5);
					TextureLaws(pDlg->ho_Image, &ho_ImageSE, "se", 1, 5);
					TextureLaws(pDlg->ho_Image, &ho_ImageEE, "ee", 2, 5);
					Compose5(ho_ImageEL, ho_ImageLE, ho_ImageES, ho_ImageSE, ho_ImageEE, &ho_ImageLaws
					);
					SmoothImage(ho_ImageLaws, &ho_ImageTexture, "gauss", 3);
					ReduceDomain(ho_ImageTexture, ho_SelectedRegions, &ho_ImageTextureReduced);
					ClassifyImageClassMlp(ho_ImageTextureReduced, &ho_ClassRegions, halconUtil.hv_MLPHandle, 0.5);

					SelectObj(ho_ClassRegions, &ho_Correct, 1);

					SelectObj(ho_ClassRegions, &ho_Errors, 2);

					if (paramUtil.mlp_openingCircleRadius == 0)
						ho_ErrorsOpening = ho_Errors;
					else
						OpeningCircle(ho_Errors, &ho_ErrorsOpening, paramUtil.mlp_openingCircleRadius);

					//ClosingCircle(ho_ErrorsOpening, &ho_ErrorsClosing, 12.5);
					Connection(ho_ErrorsOpening, &ho_ErrorsConnected);
					SelectShape(ho_ErrorsConnected, &ho_FinalErrors, "area", "and", 1, 1000000);
					//SelectShapeStd(ho_ErrorsConnected, &ho_FinalErrors, "max_area", 70); 会出错多1，要用SelectShape
					CountObj(ho_FinalErrors, &hv_NumErrors);


					DispObj(ho_GrayImage, pDlg->m_HWindowID);
					DispObj(ho_FinalErrors, pDlg->m_HWindowID);
					DumpWindowImage(&ho_DumpImg, pDlg->m_HWindowID);

					int errNum = halconUtil.HTupleToInt(hv_NumErrors);

					if (errNum > 0)
					{

						HTuple fileName = paramUtil.getFilePath_NG_Write();
						WriteImage(ho_DumpImg, "bmp", 0, fileName);

#ifdef _WriteBlankPic
						HTuple fileName1 = paramUtil.getFilePath_NG_Blank_Write();
						WriteImage(pDlg->ho_Image, "bmp", 0, fileName1);
#endif

						paramUtil.fileNameCount_NG++;
						

						pDlg->m_info = "NG";

						dmcUtil.resultQue.push_back(0);


						pDlg->SendMessage(WM_UPDATEDATA, FALSE);

						dmcUtil.setResult(info, false, true);

					}
					else
					{


						//HTuple fileName = paramUtil.getFilePath_OK_Write();
						//WriteImage(ho_DumpImg, "bmp", 0, fileName);
						
#ifdef _WriteBlankPic
						HTuple fileName1 = paramUtil.getFilePath_OK_Blank_Write();
						WriteImage(pDlg->ho_Image, "bmp", 0, fileName1);
#endif

						paramUtil.fileNameCount_OK++;

						pDlg->m_info = "OK";

						dmcUtil.resultQue.push_back(1);

						pDlg->SendMessage(WM_UPDATEDATA, FALSE);
						dmcUtil.setResult(info, true, true);

					}

			}
		}

		
	}
    return nRet;
}




int CProjectOneDlg::genOnTimeImg(HObject  *m_ho_Image,byte *m_pImageData,unsigned int nDataLen, MV_FRAME_OUT_INFO_EX stImageInfo)
{
	int nRet = m_pcMyCamera->GetOneFrameTimeout(m_pBufForDriver, &nDataLen, m_nBufSizeForDriver, &stImageInfo, 1000);
	if (nRet == MV_OK)
	{
		memcpy(m_pImageData, m_pBufForDriver, stImageInfo.nWidth * stImageInfo.nHeight);
		GenImage1Extern(m_ho_Image, "byte", stImageInfo.nWidth, stImageInfo.nHeight, (long)m_pImageData, (long)free);
	}
	return nRet;
}



void CProjectOneDlg::NewImage(HObject * newImg, unsigned char  *image, HTuple wide, HTuple hight)
{


	GenImage1Extern(newImg, "byte", wide, hight, (long)image, (long)free);
}
