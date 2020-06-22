// LeadShine.cpp: 实现文件
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "CDlg1.h"
#include "afxdialogex.h"


// LeadShine 对话框

IMPLEMENT_DYNAMIC(CDlg1, CDialogEx)



CDlg1::CDlg1(ParamUtil &paramUtil,HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc & doc, MotionControlCardUtil & motionCard, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LEADSHINE, pParent), doc(doc), motionCard(motionCard), cameraUtil(cameraUtil), halconUtil(halconUtil),paramUtil(paramUtil)
	, testCircleWarehouseNum(0)
	, testSquareWarehouseNum(0)
{

	axisHome = 0;//单轴回零
	position_x = 0;
	position_y = 0;
	position_z = 0;
	position_u = 0;
	status = "静止";
	m_nSpeedst = 0.0;
	m_fAccel = 0.0;
	m_nSpeedmax = 0.0;
	m_yUp=new MyRealButton("m_yUp");
	m_yDown = new MyRealButton("m_yDown");
	m_xUp = new MyRealButton("m_xUp");
	m_xDown = new MyRealButton("m_xDown");

	m_zUp = new MyRealButton("m_zUp");
	m_zDown = new MyRealButton("m_zDown");
	m_uClock = new MyRealButton("m_uClock");
	m_uUnclock = new MyRealButton("m_uUnclock");





}



CDlg1::~CDlg1()
{
}

void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SPEEDST, m_nSpeedst);
	DDX_Text(pDX, IDC_EDIT_SPEEDMAX, m_nSpeedmax);
	DDX_Text(pDX, IDC_EDIT_ACCEL, m_fAccel);


	DDX_Control(pDX, IDC_Y_UP, *m_yUp);
	DDX_Control(pDX, IDC_Y_DOWN, *m_yDown);
	DDX_Control(pDX, IDC_X_DOWN, *m_xDown);
	DDX_Control(pDX, IDC_X_UP, *m_xUp);


	DDX_Control(pDX, IDC_Z_UP, *m_zUp);
	DDX_Control(pDX, IDC_Z_DOWN, *m_zDown);
	DDX_Control(pDX, IDC_U_CLOCK, *m_uClock);
	DDX_Control(pDX, IDC_U_UNCLOCK, *m_uUnclock);
	DDX_Text(pDX, IDC_EDIT2, testCircleWarehouseNum);
	DDX_Text(pDX, IDC_EDIT3, testSquareWarehouseNum);
}


BEGIN_MESSAGE_MAP(CDlg1, CDialogEx)
	ON_BN_CLICKED(IDC_Location1, &CDlg1::OnBnClickedLocation1)
	ON_BN_CLICKED(IDC_Location2, &CDlg1::OnBnClickedLocation2)
	ON_BN_CLICKED(IDC_Location3, &CDlg1::OnBnClickedLocation3)
	ON_BN_CLICKED(IDC_Location4, &CDlg1::OnBnClickedLocation4)
	ON_BN_CLICKED(IDC_Location5, &CDlg1::OnBnClickedLocation5)
	ON_BN_CLICKED(IDC_Location6, &CDlg1::OnBnClickedLocation6)
	ON_BN_CLICKED(IDC_Location7, &CDlg1::OnBnClickedLocation7)
	ON_BN_CLICKED(IDC_Location8, &CDlg1::OnBnClickedLocation8)
	ON_BN_CLICKED(IDC_Location9, &CDlg1::OnBnClickedLocation9)

	ON_BN_CLICKED(IDC_SET_ZERO, &CDlg1::OnBnClickedSetZero)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_S, &CDlg1::OnBnClickedS)
	ON_BN_CLICKED(IDC_T, &CDlg1::OnBnClickedT)
	ON_BN_CLICKED(IDC_RADIO_HIGHSPEED, &CDlg1::OnBnClickedRadioHighspeed)
	ON_BN_CLICKED(IDC_RADIO_LOWSPEED, &CDlg1::OnBnClickedRadioLowspeed)
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_RADIO_HOME_HIGHSPEED, &CDlg1::OnBnClickedRadioHomeHighspeed)
	ON_BN_CLICKED(IDC_RADIO_HOME_LOWSPEED, &CDlg1::OnBnClickedRadioHomeLowspeed)
	ON_BN_CLICKED(IDC_RADIO_HOME_POSITIVE, &CDlg1::OnBnClickedRadioHomePositive)
	ON_BN_CLICKED(IDC_RADIO_HOME_NEGATIVE, &CDlg1::OnBnClickedRadioHomeNegative)
	
	ON_BN_CLICKED(IDC_BACK_BASE_POINT, &CDlg1::OnBnClickedBackBasePoint)
	ON_BN_CLICKED(IDC_BACK_BASE_POINT2, &CDlg1::OnBnClickedBackBasePoint2)
	ON_BN_CLICKED(IDC_RADIO1, &CDlg1::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlg1::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDlg1::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CDlg1::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BACK_BASE_POINT3, &CDlg1::OnBnClickedBackBasePoint3)
	ON_BN_CLICKED(IDC_CHECK_USEDEFAULT, &CDlg1::OnBnClickedCheckUsedefault)
	ON_BN_CLICKED(IDC_Z_UP2, &CDlg1::OnBnClickedZUp2)
	ON_BN_CLICKED(IDC_Z_DOWN2, &CDlg1::OnBnClickedZDown2)
	ON_BN_CLICKED(IDC_Z_UP3, &CDlg1::OnBnClickedZUp3)
	ON_BN_CLICKED(IDC_Z_UP4, &CDlg1::OnBnClickedZUp4)
	ON_BN_CLICKED(IDC_Location10, &CDlg1::OnBnClickedLocation10)
	ON_BN_CLICKED(IDC_Location11, &CDlg1::OnBnClickedLocation11)
	ON_BN_CLICKED(IDC_Location12, &CDlg1::OnBnClickedLocation12)
	ON_BN_CLICKED(IDC_Location13, &CDlg1::OnBnClickedLocation13)
	ON_BN_CLICKED(IDC_Location14, &CDlg1::OnBnClickedLocation14)
	ON_BN_CLICKED(IDC_Location15, &CDlg1::OnBnClickedLocation15)
	ON_BN_CLICKED(IDC_Location16, &CDlg1::OnBnClickedLocation16)
	ON_BN_CLICKED(IDC_Location17, &CDlg1::OnBnClickedLocation17)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg1::OnBnClickedButton2)
END_MESSAGE_MAP()


// LeadShine 消息处理程序

void CDlg1::SaveNinePointPulseLocation(int pointNum)
{
	// TODO: 在此添加控件通知处理程序代码

  CPoint cp = motionCard.getCurrentPosition();


	
	doc.setPulseMap(pointNum, cp);
}



void CDlg1::SaveDefaultNinePointPulseLocation()
{
	doc.setPulseMap(1, *doc.fixed_location_point1);
	doc.setPulseMap(2, *doc.fixed_location_point2);
	doc.setPulseMap(3, *doc.fixed_location_point3);
	doc.setPulseMap(4, *doc.fixed_location_point4);
	doc.setPulseMap(5, *doc.fixed_location_point5);
	doc.setPulseMap(6, *doc.fixed_location_point6);
	doc.setPulseMap(7, *doc.fixed_location_point7);
	doc.setPulseMap(8, *doc.fixed_location_point8);
	doc.setPulseMap(9, *doc.fixed_location_point9);
}

void CDlg1::setZeroNinePointPulseLocation()
{

	CPoint cp(0,0);
	doc.setPulseMap(1, cp);
	doc.setPulseMap(2, cp);
	doc.setPulseMap(3, cp);
	doc.setPulseMap(4, cp);
	doc.setPulseMap(5, cp);
	doc.setPulseMap(6, cp);
	doc.setPulseMap(7, cp);
	doc.setPulseMap(8, cp);
	doc.setPulseMap(9, cp);
}



void CDlg1::myOnInitDialog()
{
	//radio 
	motionCard.isHighSpeedMode()?
		CheckRadioButton(IDC_RADIO_HIGHSPEED, IDC_RADIO_LOWSPEED, IDC_RADIO_HIGHSPEED) :
		CheckRadioButton(IDC_RADIO_HIGHSPEED, IDC_RADIO_LOWSPEED, IDC_RADIO_LOWSPEED);
	motionCard.isMoveMode_S()?
		CheckRadioButton(IDC_S, IDC_T, IDC_S) :
		CheckRadioButton(IDC_S, IDC_T, IDC_T);	

	motionCard.isHomeMode_HighSpeed()?
		CheckRadioButton(IDC_RADIO_HOME_HIGHSPEED, IDC_RADIO_HOME_LOWSPEED, IDC_RADIO_HOME_HIGHSPEED) :
		CheckRadioButton(IDC_RADIO_HOME_HIGHSPEED, IDC_RADIO_HOME_LOWSPEED, IDC_RADIO_HOME_LOWSPEED);

	motionCard.isHomeMode_PositiveSide() ?
		CheckRadioButton(IDC_RADIO_HOME_POSITIVE, IDC_RADIO_HOME_NEGATIVE, IDC_RADIO_HOME_POSITIVE) :
		CheckRadioButton(IDC_RADIO_HOME_POSITIVE, IDC_RADIO_HOME_NEGATIVE, IDC_RADIO_HOME_NEGATIVE);

	//单轴回零选择
	CheckRadioButton(IDC_RADIO1, IDC_RADIO4, IDC_RADIO1);

	//定时读取速度
	

}

void CDlg1::myOnCreate()
{
	SetTimer(1, 100, NULL);//更新motionCard状态显示
}

void CDlg1::OnBnClickedLocation1()
{
	SaveNinePointPulseLocation(1);
}



void CDlg1::OnBnClickedLocation2()
{
	SaveNinePointPulseLocation(2);
}


void CDlg1::OnBnClickedLocation3()
{
	SaveNinePointPulseLocation(3);
}


void CDlg1::OnBnClickedLocation4()
{
	SaveNinePointPulseLocation(4);
}


void CDlg1::OnBnClickedLocation5()
{
	SaveNinePointPulseLocation(5);
}


void CDlg1::OnBnClickedLocation6()
{
	SaveNinePointPulseLocation(6);
}


void CDlg1::OnBnClickedLocation7()
{
	SaveNinePointPulseLocation(7);
}


void CDlg1::OnBnClickedLocation8()
{
	SaveNinePointPulseLocation(8);
}


void CDlg1::OnBnClickedLocation9()
{
	SaveNinePointPulseLocation(9);
}




void CDlg1::OnBnClickedSetZero()
{
	setZeroNinePointPulseLocation();
}


int CDlg1::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	myOnCreate();
	return 0;
}


void CDlg1::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CString str1;

	str1.Format(_T("%d"), motionCard.readSpeedStart());
	SetDlgItemTextW(IDC_EDIT_SPEEDST, str1);
	str1.Format(_T("%d"), motionCard.readSpeedMax());
	SetDlgItemTextW(IDC_EDIT_SPEEDMAX, str1);
	str1.Format(_T("%f"), motionCard.readAccl());
	SetDlgItemTextW(IDC_EDIT_ACCEL, str1);

	CDialogEx::OnTimer(nIDEvent);
}








void CDlg1::OnBnClickedS()
{
	motionCard.setMovingMode_S();
}


void CDlg1::OnBnClickedT()
{
	motionCard.setMovingMode_T();
}


BOOL CDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	myOnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlg1::OnBnClickedRadioHighspeed()
{
	// TODO: 在此添加控件通知处理程序代码
	motionCard.setHighSpeed();

}


void CDlg1::OnBnClickedRadioLowspeed()
{
	// TODO: 在此添加控件通知处理程序代码.
	motionCard.setLowSpeed();
}






void CDlg1::OnBnClickedRadioHomeHighspeed()
{
	motionCard.setHomeMode_Speed(true);
}


void CDlg1::OnBnClickedRadioHomeLowspeed()
{
	motionCard.setHomeMode_Speed(false);
}


void CDlg1::OnBnClickedRadioHomePositive()
{
	motionCard.setHomeMode_Side(true);
}


void CDlg1::OnBnClickedRadioHomeNegative()
{
	motionCard.setHomeMode_Side(false);
}


BOOL CDlg1::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	//MyRealButton发出动 imessage
	switch (message)
	{
	case 9999:
		if (wParam == 0)    // 按钮被鼠标左键按下
		{
			if (lParam == 0) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"xUp按钮按下了");
				motionCard.moveContinue('x', true);
			}
			else if (lParam == 1) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"xDown按钮按下了");
				motionCard.moveContinue('x', false);
			}
			else if (lParam == 2) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"yUp按钮按下了");
				motionCard.moveContinue('y', true);
			}
			else if (lParam == 3) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"yDown按钮按下了");
				motionCard.moveContinue('y', false);
			}
			else if (lParam == 4) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"zUp按钮按下了");
				motionCard.moveContinue('z', true);
			}
			else if (lParam == 5) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"zDown按钮按下了");
				motionCard.moveContinue('z', false);
			}
			else if (lParam == 6) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"uClock按钮按下了");
				motionCard.moveContinue('u', true);
			}
			else if (lParam == 7) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"uUnclock按钮按下了");
				motionCard.moveContinue('u', false);
			}
		}
		




		else if (wParam == 1) // 按钮被鼠标左键抬起
		{
			if (lParam == 0) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"xUp按钮抬起了");
				motionCard.emergentStop();
			}
			else if (lParam == 1) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"xDown按钮抬起了");
				motionCard.emergentStop();
			}
			else if (lParam == 2) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"yUp按钮抬起了");
				motionCard.emergentStop();
			}
			else if (lParam == 3) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"yDown按钮抬起了");
				motionCard.emergentStop();
			}
			else if (lParam == 4) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"zUp按钮抬起了");
				motionCard.emergentStop();
			}
			else if (lParam == 5) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"zDown按钮抬起了");
				motionCard.emergentStop();
			}
			else if (lParam == 6) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"uClock按钮抬起了");
				motionCard.emergentStop();
			}
			else if (lParam == 7) {
				GetDlgItem(IDC_BUTTON_STATIC)->SetWindowTextW(L"uUnclock按钮抬起了");
				motionCard.emergentStop();
			}
		}







		break;
	default:
		break;
	}
	return CDialogEx::OnWndMsg(message, wParam, lParam, pResult);
}



void CDlg1::OnBnClickedBackBasePoint()
{
	motionCard.moveToBasePoint(axisHome);
}





void CDlg1::OnBnClickedBackBasePoint2()
{
	motionCard.moveToBaseCPoint();
}


void CDlg1::OnBnClickedRadio1()
{
	axisHome = 0;
}


void CDlg1::OnBnClickedRadio2()
{
	axisHome = 1;
}


void CDlg1::OnBnClickedRadio3()
{
	axisHome = 2;
}


void CDlg1::OnBnClickedRadio4()
{
	axisHome = 3;
}


void CDlg1::OnBnClickedBackBasePoint3()
{
	motionCard.moveToBaseCPointAll();
	//motionCard.moveToBasePointCS();
}





void CDlg1::OnBnClickedCheckUsedefault()
{
	doc.setDefaultLocation();
	SaveDefaultNinePointPulseLocation();
}


void CDlg1::OnBnClickedZUp2()
{
	motionCard.moveToBaesZ();
}


void CDlg1::OnBnClickedZDown2()
{
	motionCard.moveToInHolePoint();
}


void CDlg1::OnBnClickedZUp3()
{
	motionCard.inHole();
}


void CDlg1::OnBnClickedZUp4()
{
	motionCard.gassing();
}


void CDlg1::OnBnClickedLocation10()
{
	CPoint cp = motionCard.getCurrentPosition();

	doc.fixed_location_circle1.x=cp.x;
	doc.fixed_location_circle1.y=cp.y;

}


void CDlg1::OnBnClickedLocation11()
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint cp = motionCard.getCurrentPosition();

	doc.fixed_location_circle2.x = cp.x;
	doc.fixed_location_circle2.y = cp.y;
}


void CDlg1::OnBnClickedLocation12()
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint cp = motionCard.getCurrentPosition();

	doc.fixed_location_circle3.x = cp.x;
	doc.fixed_location_circle3.y = cp.y;
}


void CDlg1::OnBnClickedLocation13()
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint cp = motionCard.getCurrentPosition();

	doc.fixed_location_circle4.x = cp.x;
	doc.fixed_location_circle4.y = cp.y;
}


void CDlg1::OnBnClickedLocation14()
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint cp = motionCard.getCurrentPosition();


	doc.fixed_location_spuare1.x = cp.x;
	doc.fixed_location_spuare1.y = cp.y;
}


void CDlg1::OnBnClickedLocation15()
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint cp = motionCard.getCurrentPosition();

	doc.fixed_location_spuare2.x = cp.x;
	doc.fixed_location_spuare2.y = cp.y;
}


void CDlg1::OnBnClickedLocation16()
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint cp = motionCard.getCurrentPosition();

	doc.fixed_location_spuare3.x = cp.x;
	doc.fixed_location_spuare3.y = cp.y;
}


void CDlg1::OnBnClickedLocation17()
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint cp = motionCard.getCurrentPosition();

	doc.fixed_location_spuare4.x = cp.x;
	doc.fixed_location_spuare4.y = cp.y;
}


void CDlg1::OnBnClickedButton1()
{
	UpdateData(true);
	int i = testCircleWarehouseNum;
	CPoint cp = doc.getCircleWarehouseLocation(i);


	motionCard.moveToPoint(cp);
}


void CDlg1::OnBnClickedButton2()
{
	UpdateData(true);
	int i = testSquareWarehouseNum;
	CPoint cp = doc.getSquareWarehouseLocation(i);
	motionCard.moveToPoint(cp);
}
