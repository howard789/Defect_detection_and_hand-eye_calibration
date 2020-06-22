// CDlg5.cpp: 实现文件
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "CDlg5.h"
#include "afxdialogex.h"


// CDlg5 对话框

IMPLEMENT_DYNAMIC(CDlg5, CDialogEx)
CDlg5::CDlg5(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc & doc, MotionControlCardUtil & motionCard, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LEADSHINE, pParent), doc(doc), motionCard(motionCard), cameraUtil(cameraUtil), halconUtil(halconUtil), paramUtil(paramUtil)


{

}


CDlg5::~CDlg5()
{
}

void CDlg5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_STATUS_X1, m_STATUS_X1);
	DDX_Control(pDX, IDC_STATUS_X2, m_STATUS_X2);
	DDX_Control(pDX, IDC_STATUS_X3, m_STATUS_X3);
	DDX_Control(pDX, IDC_STATUS_X4, m_STATUS_X4);
	DDX_Control(pDX, IDC_STATUS_X5, m_STATUS_X5);
	DDX_Control(pDX, IDC_STATUS_X6, m_STATUS_X6);
	DDX_Control(pDX, IDC_STATUS_X7, m_STATUS_X7);
	DDX_Control(pDX, IDC_STATUS_X8, m_STATUS_X8);
	DDX_Control(pDX, IDC_STATUS_X9, m_STATUS_X9);
	DDX_Control(pDX, IDC_STATUS_Y1, m_STATUS_Y1);
	DDX_Control(pDX, IDC_STATUS_Y2, m_STATUS_Y2);
	DDX_Control(pDX, IDC_STATUS_Y3, m_STATUS_Y3);
	DDX_Control(pDX, IDC_STATUS_Y4, m_STATUS_Y4);
	DDX_Control(pDX, IDC_STATUS_Y5, m_STATUS_Y5);
	DDX_Control(pDX, IDC_STATUS_Y6, m_STATUS_Y6);
	DDX_Control(pDX, IDC_STATUS_Y7, m_STATUS_Y7);
	DDX_Control(pDX, IDC_STATUS_Y8, m_STATUS_Y8);
	DDX_Control(pDX, IDC_STATUS_Z1, m_STATUS_Z1);
	DDX_Control(pDX, IDC_STATUS_Z2, m_STATUS_Z2);
	DDX_Control(pDX, IDC_STATUS_Z3, m_STATUS_Z3);
	DDX_Control(pDX, IDC_STATUS_Z4, m_STATUS_Z4);
	DDX_Control(pDX, IDC_STATUS_Z5, m_STATUS_Z5);
	DDX_Control(pDX, IDC_STATUS_Z6, m_STATUS_Z6);
	DDX_Control(pDX, IDC_STATUS_Z7, m_STATUS_Z7);
	DDX_Control(pDX, IDC_STATUS_Z8, m_STATUS_Z8);
	DDX_Control(pDX, IDC_STATUS_U1, m_STATUS_U1);
	DDX_Control(pDX, IDC_STATUS_U2, m_STATUS_U2);
	DDX_Control(pDX, IDC_STATUS_U3, m_STATUS_U3);
	DDX_Control(pDX, IDC_STATUS_U4, m_STATUS_U4);
	DDX_Control(pDX, IDC_STATUS_U5, m_STATUS_U5);
	DDX_Control(pDX, IDC_STATUS_U6, m_STATUS_U6);
	DDX_Control(pDX, IDC_STATUS_U7, m_STATUS_U7);
	DDX_Control(pDX, IDC_STATUS_U8, m_STATUS_U8);
	DDX_Control(pDX, IDC_OUT1, m_OUT1);
	DDX_Control(pDX, IDC_OUT2, m_OUT2);
	DDX_Control(pDX, IDC_OUT3, m_OUT3);
	DDX_Control(pDX, IDC_OUT4, m_OUT4);
	DDX_Control(pDX, IDC_OUT5, m_OUT5);
	DDX_Control(pDX, IDC_OUT6, m_OUT6);
	DDX_Control(pDX, IDC_OUT7, m_OUT7);
	DDX_Control(pDX, IDC_OUT8, m_OUT8);
	DDX_Control(pDX, IDC_OUT9, m_OUT9);
	DDX_Control(pDX, IDC_OUT10, m_OUT10);
	DDX_Control(pDX, IDC_OUT11, m_OUT11);
	DDX_Control(pDX, IDC_OUT12, m_OUT12);
	DDX_Control(pDX, IDC_OUT13, m_OUT13);
	DDX_Control(pDX, IDC_OUT14, m_OUT14);
	DDX_Control(pDX, IDC_OUT15, m_OUT15);
	DDX_Control(pDX, IDC_OUT16, m_OUT16);
	DDX_Control(pDX, IDC_OUT17, m_OUT17);
	DDX_Control(pDX, IDC_OUT18, m_OUT18);
	DDX_Control(pDX, IDC_OUT19, m_OUT19);
	DDX_Control(pDX, IDC_OUT20, m_OUT20);
	DDX_Control(pDX, IDC_OUT21, m_OUT21);
	DDX_Control(pDX, IDC_OUT22, m_OUT22);
	DDX_Control(pDX, IDC_OUT23, m_OUT23);
	DDX_Control(pDX, IDC_OUT24, m_OUT24);
	DDX_Control(pDX, IDC_OUT25, m_OUT25);
	DDX_Control(pDX, IDC_OUT26, m_OUT26);
	DDX_Control(pDX, IDC_OUT27, m_OUT27);
	DDX_Control(pDX, IDC_OUT28, m_OUT28);
	DDX_Control(pDX, IDC_OUT29, m_OUT29);
	DDX_Control(pDX, IDC_OUT30, m_OUT30);
	DDX_Control(pDX, IDC_OUT31, m_OUT31);
	DDX_Control(pDX, IDC_OUT32, m_OUT32);
}


BEGIN_MESSAGE_MAP(CDlg5, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHECK1, &CDlg5::OnBnClickedCheck1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK5, &CDlg5::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK2, &CDlg5::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK8, &CDlg5::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CDlg5::OnBnClickedCheck9)
END_MESSAGE_MAP()


// CDlg5 消息处理程序


BOOL CDlg5::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	myOnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CDlg5::myOnInitDialog()
{
	SetTimer(1,500,NULL);


	


}


void CDlg5::setPictureColorGreen(int mfcId, CStatic& m_static)
{

	CRect rc;
	CWnd *pWnd = GetDlgItem(mfcId);//参数为控件ID
	pWnd->GetClientRect(&rc);//rc为控件的大小。
	int py = rc.Height();
	int px = rc.Width();

	FillRect(m_static.GetDC()->GetSafeHdc(), &rc, CBrush(RGB(0, 255, 0)));

}

void CDlg5::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	//setPictureColorGreen(IDC_STATUS1,m_status1);

	MfcUtil mfcUtil;
	//mfcUtil.setPictureColorGreen(this,IDC_STATUS1, m_status1);

}


void CDlg5::OnBnClickedCheck1()
{
	writeOutBitLow(1);
}

bool CDlg5::check_m_STATUS_X1()
{
	return checkPositveLimit(0);
}

bool CDlg5::check_m_STATUS_X2()
{
	return checkNegativeLimit(0);
}

bool CDlg5::check_m_STATUS_X4()
{
	return checkORG(0);
}

bool CDlg5::check_m_STATUS_X7()
{
	return checkALM(0);
}

bool CDlg5::check_m_STATUS_X9()
{
	return checkEMG();
}

bool CDlg5::check_m_STATUS_Y1()
{
	return checkPositveLimit(1);
}

bool CDlg5::check_m_STATUS_Y2()
{
	return checkNegativeLimit(1);
}

bool CDlg5::check_m_STATUS_Y4()
{
	return checkORG(1);
}

bool CDlg5::check_m_STATUS_Y7()
{
	return checkALM(1);
}

bool CDlg5::check_m_STATUS_Z1()
{
	return checkPositveLimit(2);
}

bool CDlg5::check_m_STATUS_Z2()
{
	return checkNegativeLimit(2);
}

bool CDlg5::check_m_STATUS_Z4()
{
	return checkORG(2);
}

bool CDlg5::check_m_STATUS_Z7()
{
	return checkALM(2);
}






bool CDlg5::checkPositveLimit(int axis)
{

	//检测正限位
	int r1 = d2410_axis_io_status(axis);
	int res1 = r1 >> 12 & 1;
	if (res1 == 0)
		return false;
	else
		return true;
}

bool CDlg5::checkNegativeLimit(int axis)
{
	//负限位
	int r10 = d2410_axis_io_status(2);

	int res10 = r10 >> 13 & 1;
	if (0 == res10)
		return false;
	else
		return true;
}

bool CDlg5::checkORG(int axis)
{
	//检测x轴原点
	int r = d2410_axis_io_status(0);
	int res = r >> 14 & 1;
	if (0 == res)
		return false;
	else
		return true;
}

bool CDlg5::checkALM(int axis)
{

	//检测x轴伺服报警信号
	int r3 = d2410_axis_io_status(0);
	int res3 = r3 >> 11 & 1;
	if (0 == res3)
		return false;
	else
		return true;
}

bool CDlg5::checkEMG()
{
	UINT res14 = d2410_get_rsts(0);
	UINT res15 = res14 >> 7 & 1;
	if (res15 == 0) 
		return false;
	else
		return true;
}

bool CDlg5::checkOut()
{
	int res;
	res = d2410_read_inbit(0, 1);
	if (res==1)
		mfcUtil.setPictureColorRed(this, IDC_OUT1, m_OUT1);
	else if(res==0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT1, m_OUT1);


	res = d2410_read_inbit(0, 2);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT2, m_OUT2);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT2, m_OUT2);

	res = d2410_read_inbit(0, 3);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT3, m_OUT3);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT3, m_OUT3);

	res = d2410_read_inbit(0, 4);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT4, m_OUT4);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT4, m_OUT4);

	res = d2410_read_inbit(0, 5);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT5, m_OUT5);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT5, m_OUT5);

	res = d2410_read_inbit(0, 6);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT6, m_OUT6);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT6, m_OUT6);

	res = d2410_read_inbit(0, 7);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT7, m_OUT7);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT7, m_OUT7);

	res = d2410_read_inbit(0, 8);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT8, m_OUT8);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT8, m_OUT8);

	res = d2410_read_inbit(0, 9);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT9, m_OUT9);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT9, m_OUT9);

	res = d2410_read_inbit(0, 10);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT10, m_OUT10);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT10, m_OUT10);

	res = d2410_read_inbit(0, 11);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT11, m_OUT11);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT11, m_OUT11);

	res = d2410_read_inbit(0, 12);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT12, m_OUT12);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT12, m_OUT12);

	res = d2410_read_inbit(0, 13);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT13, m_OUT13);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT13, m_OUT13);

	res = d2410_read_inbit(0, 14);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT14, m_OUT14);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT14, m_OUT14);

	res = d2410_read_inbit(0, 15);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT15, m_OUT15);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT15, m_OUT15);

	res = d2410_read_inbit(0, 16);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT16, m_OUT16);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT16, m_OUT16);

	res = d2410_read_inbit(0, 17);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT17, m_OUT17);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT17, m_OUT17);

	res = d2410_read_inbit(0, 18);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT18, m_OUT18);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT18, m_OUT18);

	res = d2410_read_inbit(0, 19);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT19, m_OUT19);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT19, m_OUT19);


	res = d2410_read_inbit(0, 20);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT20, m_OUT20);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT20, m_OUT20);

	res = d2410_read_inbit(0, 21);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT21, m_OUT21);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT21, m_OUT21);

	res = d2410_read_inbit(0, 22);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT22, m_OUT22);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT22, m_OUT22);

	res = d2410_read_inbit(0, 23);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT23, m_OUT23);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT23, m_OUT23);

	res = d2410_read_inbit(0, 24);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT24, m_OUT24);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT24, m_OUT24);

	res = d2410_read_inbit(0, 25);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT25, m_OUT25);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT25, m_OUT25);

	res = d2410_read_inbit(0, 26);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT26, m_OUT26);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT26, m_OUT26);

	res = d2410_read_inbit(0, 27);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT27, m_OUT27);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT27, m_OUT27);

	res = d2410_read_inbit(0, 28);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT28, m_OUT28);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT28, m_OUT28);

	res = d2410_read_inbit(0, 29);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT29, m_OUT29);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT29, m_OUT29);

	res = d2410_read_inbit(0, 30);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT30, m_OUT30);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT30, m_OUT30);

	res = d2410_read_inbit(0, 31);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT31, m_OUT31);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT31, m_OUT31);

	res = d2410_read_inbit(0, 32);
	if (res == 1)
		mfcUtil.setPictureColorRed(this, IDC_OUT32, m_OUT32);
	else if (res == 0)
		mfcUtil.setPictureColorGreen(this, IDC_OUT32, m_OUT32);









	return false;
}



void CDlg5::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (paramUtil.openIOcheck) {
		checkIOStatus();
		checkOut();
	}
	CDialogEx::OnTimer(nIDEvent);
}



void  CDlg5::checkIOStatus()
{
	if (check_m_STATUS_X1())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_X1, m_STATUS_X1);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_X1, m_STATUS_X1);

	if (check_m_STATUS_X2())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_X2, m_STATUS_X2);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_X2, m_STATUS_X2);



	if (check_m_STATUS_X4())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_X4, m_STATUS_X4);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_X4, m_STATUS_X4);




	if (check_m_STATUS_X7())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_X7, m_STATUS_X7);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_X7, m_STATUS_X7);



	if (check_m_STATUS_X9())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_X9, m_STATUS_X9);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_X9, m_STATUS_X9);



	if (check_m_STATUS_Y1())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_Y1, m_STATUS_Y1);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_Y1, m_STATUS_Y1);

	if (check_m_STATUS_Y2())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_Y2, m_STATUS_Y2);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_Y2, m_STATUS_Y2);

	if (check_m_STATUS_Y4())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_Y4, m_STATUS_Y4);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_Y4, m_STATUS_Y4);

	if (check_m_STATUS_Y7())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_Y7, m_STATUS_Y7);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_Y7, m_STATUS_Y7);


	if (check_m_STATUS_Z1())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_Z1, m_STATUS_Z1);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_Z1, m_STATUS_Z1);


	if (check_m_STATUS_Z2())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_Z2, m_STATUS_Z2);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_Z2, m_STATUS_Z2);



	if (check_m_STATUS_Z4())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_Z4, m_STATUS_Z4);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_Z4, m_STATUS_Z4);



	if (check_m_STATUS_Z7())
		mfcUtil.setPictureColorRed(this, IDC_STATUS_Z7, m_STATUS_Z7);
	else
		mfcUtil.setPictureColorGreen(this, IDC_STATUS_Z7, m_STATUS_Z7);


}

void CDlg5::writeOutBitLow(int no)
{
	d2410_write_outbit(0, no, 0);
}


void CDlg5::OnBnClickedCheck5()
{
	int res = ((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck();
	if (res == 0)
		paramUtil.openIOcheck = false;
	else
		paramUtil.openIOcheck = true;

}


void CDlg5::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	writeOutBitLow(2);
}


void CDlg5::OnBnClickedCheck8()
{
	// TODO: 在此添加控件通知处理程序代码
	writeOutBitLow(3);
}


void CDlg5::OnBnClickedCheck9()
{
	// TODO: 在此添加控件通知处理程序代码
	writeOutBitLow(4);
}
