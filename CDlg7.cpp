// CDlg7.cpp: 实现文件
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "CDlg7.h"
#include "afxdialogex.h"


// CDlg7 对话框


#define Dis_From_Zero_To_CameraOne
#define Dis_From_CameraOne_To_CameraTwo
#define Dis_From_CameraTwo_To_GassOne
#define Dis_From_GassOne_To_GassTwo
#define Dis_From_GassTwo_To_GassThree

IMPLEMENT_DYNAMIC(CDlg7, CDialogEx)
CDlg7::CDlg7(dmc1380Util &dmc1380Util,ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc & doc, MotionControlCardUtil & motionCard, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LEADSHINE, pParent), doc(doc), motionCard(motionCard), cameraUtil(cameraUtil), halconUtil(halconUtil), paramUtil(paramUtil), dmcUtil(dmc1380Util)


	, m_value1(0)
	, m_value2(0)
	, m_value3(0)

{
	threadMode = 0;
	
}


CDlg7::~CDlg7()
{
}

void CDlg7::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMING, m_coming);
	DDX_Text(pDX, IDC_EDIT2, m_value1);
	DDX_Text(pDX, IDC_EDIT3, m_value2);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_sb1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_sb2);
	DDX_Text(pDX, IDC_EDIT4, m_value3);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_sb3);

}


BEGIN_MESSAGE_MAP(CDlg7, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg7::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CDlg7::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT7, &CDlg7::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT6, &CDlg7::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT5, &CDlg7::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_RADIO1, &CDlg7::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlg7::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDlg7::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CDlg7::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlg7::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg7::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlg7::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_GASSING1, &CDlg7::OnBnClickedGassing1)
	ON_BN_CLICKED(IDC_GASSING2, &CDlg7::OnBnClickedGassing2)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlg7::OnBnClickedButton6)

ON_WM_PAINT()
ON_WM_TIMER()
ON_BN_CLICKED(IDC_MOVE, &CDlg7::OnBnClickedMove)
ON_WM_HSCROLL()
ON_BN_CLICKED(IDC_BUTTON10, &CDlg7::OnBnClickedButton10)
ON_BN_CLICKED(IDC_CHECK3, &CDlg7::OnBnClickedCheck3)
ON_BN_CLICKED(IDC_BUTTON4, &CDlg7::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &CDlg7::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON8, &CDlg7::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON9, &CDlg7::OnBnClickedButton9)
ON_BN_CLICKED(IDC_RADIO5, &CDlg7::OnBnClickedRadio5)
ON_BN_CLICKED(IDC_MOVE2, &CDlg7::OnBnClickedMove2)
ON_BN_CLICKED(IDC_BUTTON11, &CDlg7::OnBnClickedButton11)
ON_EN_CHANGE(IDC_EDIT9, &CDlg7::OnEnChangeEdit9)
ON_BN_CLICKED(IDC_RADIO7, &CDlg7::OnBnClickedRadio7)
ON_BN_CLICKED(IDC_BUTTON14, &CDlg7::OnBnClickedButton14)
ON_BN_CLICKED(IDC_MOVE3, &CDlg7::OnBnClickedMove3)
ON_BN_CLICKED(IDC_MOVE4, &CDlg7::OnBnClickedMove4)
ON_BN_CLICKED(IDC_BUTTON13, &CDlg7::OnBnClickedButton13)
END_MESSAGE_MAP()


// CDlg7 消息处理程序

void CDlg7::test(Doc &doc)
{
	CPoint cp(100, 101);
	doc.setPixelMap(1, cp);
}

void CDlg7::OnBnClickedButton1()
{
	try {
		WriteClassMlp(halconUtil.hv_MLPHandle, _MLP_GMC_FILE_PATH);
        ReadClassMlp(_MLP_GMC_FILE_PATH, &halconUtil.hv_MLPHandle);
		MessageBox(_T("保存成功"));
	}
	catch (...)
	{
		MessageBox(_T("保存失败"));

	}
}


void CDlg7::OnEnChangeEdit1()
{
	CString rString;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(rString);
	try {
		int sp=MfcUtil::CStringToInt(rString);
		dmcUtil.nStart = sp;

	}catch(...){}
}


void CDlg7::OnEnChangeEdit7()
{
	CString rString;
	GetDlgItem(IDC_EDIT7)->GetWindowTextW(rString);
	try {
		int sp = MfcUtil::CStringToInt(rString);
		dmcUtil.nMSpeed = sp;

	}
	catch (...) {}
}


void CDlg7::OnEnChangeEdit6()
{
	CString rString;
	GetDlgItem(IDC_EDIT6)->GetWindowTextW(rString);
	try {
		double sp = MfcUtil::CStringToDouble(rString);
		dmcUtil.nTAcc = sp;

	}
	catch (...) {}
}


void CDlg7::OnEnChangeEdit5()
{
	CString rString;
	GetDlgItem(IDC_EDIT5)->GetWindowTextW(rString);
	try {
		int sp = MfcUtil::CStringToInt(rString);
		dmcUtil.nPulse = sp;

	}
	catch (...) {}
}


void CDlg7::OnBnClickedRadio1()
{
	dmcUtil.moveMode_T = true;
}


void CDlg7::OnBnClickedRadio2()
{
	dmcUtil.moveMode_T = false;
}


void CDlg7::OnBnClickedRadio3()
{
	dmcUtil.moveModeFixPosFixDisSpeed = 1;
}


void CDlg7::OnBnClickedRadio4()
{
	dmcUtil.moveModeFixPosFixDisSpeed = 2;
}


void CDlg7::OnBnClickedButton7()
{
	dmcUtil.setCurrentPositionZero();
}

void CDlg7::myOnInitDialog()
{
	//radio 
	dmcUtil.moveMode_T ?
		CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1) :
		CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO2);

	if (dmcUtil.moveModeFixPosFixDisSpeed == 1)
		CheckRadioButton(IDC_RADIO3, IDC_RADIO7, IDC_RADIO3);
	else if (dmcUtil.moveModeFixPosFixDisSpeed == 2)
		CheckRadioButton(IDC_RADIO3, IDC_RADIO7, IDC_RADIO4);
	else
		CheckRadioButton(IDC_RADIO3, IDC_RADIO7, IDC_RADIO7);


	





	//edit 初始化
	int v1 = dmcUtil.nStart;
	CString str;
	str.Format(_T("%d"),v1);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(str);


	v1 = dmcUtil.nMSpeed;
	str.Format(_T("%d"), v1);
	GetDlgItem(IDC_EDIT7)->SetWindowTextW(str);

	double v2 = dmcUtil.nTAcc;
	str.Format(_T("%2lf"), v2);
	GetDlgItem(IDC_EDIT6)->SetWindowTextW(str);

	v1 = dmcUtil.nPulse;
	str.Format(_T("%d"), v1);
	GetDlgItem(IDC_EDIT5)->SetWindowTextW(str);

	v1 = dmcUtil.nPos;
	str.Format(_T("%d"), v1);
	GetDlgItem(IDC_EDIT9)->SetWindowTextW(str);

	//按钮失效
	CWnd *cSeBkBtnMy = GetDlgItem(IDC_MOVE);
	cSeBkBtnMy->EnableWindow(false);

	CWnd *GASSING1 = GetDlgItem(IDC_GASSING1);
	GASSING1->EnableWindow(false);

	CWnd *GASSING2 = GetDlgItem(IDC_GASSING2);
	GASSING2->EnableWindow(false);
	
	//on timer 
	SetTimer(1,10,NULL);
	SetTimer(2,100,NULL);


	//ScoreBar
	//二值化Min
	m_value1 = paramUtil.mlp_minGray;
	UpdateData(FALSE);
	m_sb1.SetScrollRange(0, 255);
	m_sb1.SetScrollPos(m_value1);

	/*/二值化Max*/
	m_value2 = paramUtil.mlp_maxGray;
	UpdateData(FALSE);
	m_sb2.SetScrollRange(0, 255);
	m_sb2.SetScrollPos(m_value2);

	/*容忍度*/
	m_value3 = paramUtil.mlp_openingCircleRadius;
	UpdateData(FALSE);
	m_sb3.SetScrollRange(0, 100);
	m_sb3.SetScrollPos(m_value3*10);


}

BOOL CDlg7::OnInitDialog()
{

	myOnInitDialog();
	CDialogEx::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlg7::OnBnClickedButton2()
{
	CString str;
	if (GetDlgItemText(IDC_BUTTON2, str), str == _T("电机使能"))
	{


		//此时可以转动
		dmcUtil.enpowerEngine(true);
		CWnd *cSeBkBtnMy = GetDlgItem(IDC_MOVE);
		cSeBkBtnMy->EnableWindow(true);


		SetDlgItemText(IDC_BUTTON2, _T("电机不使能"));
	}
	else
	{
		//此时不能转动
		dmcUtil.enpowerEngine(false);
		CWnd *cSeBkBtnMy = GetDlgItem(IDC_MOVE);
		cSeBkBtnMy->EnableWindow(false);
		SetDlgItemText(IDC_BUTTON2, _T("电机使能"));
	}
}


void CDlg7::OnBnClickedButton3()
{
	CString str;
	if (GetDlgItemText(IDC_BUTTON3, str), str == _T("低电平有效"))
	{
		dmcUtil.enableGassing(true);
		dmcUtil.gassing_no1(false);
		dmcUtil.gassing_no2(false);
		CWnd *GASSING1 = GetDlgItem(IDC_GASSING1);
		GASSING1->EnableWindow(true);

		CWnd *GASSING2 = GetDlgItem(IDC_GASSING2);
		GASSING2->EnableWindow(true);



		SetDlgItemText(IDC_BUTTON3, _T("低电平无效"));
	}
	else
	{
		dmcUtil.enableGassing(false);

		CWnd *GASSING1 = GetDlgItem(IDC_GASSING1);
		GASSING1->EnableWindow(false);

		CWnd *GASSING2 = GetDlgItem(IDC_GASSING2);
		GASSING2->EnableWindow(false);
		SetDlgItemText(IDC_BUTTON3, _T("低电平有效"));
	}
}


void CDlg7::OnBnClickedGassing1()
{
	CString str;
	if (GetDlgItemText(IDC_GASSING1, str), str == _T("1号吹气"))
	{
		dmcUtil.gassing_no1(true);
		SetDlgItemText(IDC_GASSING1, _T("1号不吹气"));
	}
	else
	{
		dmcUtil.gassing_no1(false);
		SetDlgItemText(IDC_GASSING1, _T("1号吹气"));
	}
}


void CDlg7::OnBnClickedGassing2()
{
	CString str;
	if (GetDlgItemText(IDC_GASSING2, str), str == _T("2号吹气"))
	{
		dmcUtil.gassing_no2(true);
		SetDlgItemText(IDC_GASSING2, _T("2号不吹气"));
	}
	else
	{
		dmcUtil.gassing_no2(false);
		SetDlgItemText(IDC_GASSING2, _T("2号吹气"));
	}
}


void CDlg7::OnBnClickedButton6()
{
	CString str;
	if (GetDlgItemText(IDC_BUTTON6, str), str == _T("启动震动盘"))
	{
		
		dmcUtil.enableVibrationPlate(true);
		SetDlgItemText(IDC_BUTTON6, _T("关闭震动盘"));
	}
	else
	{
		
		dmcUtil.enableVibrationPlate(false);
		SetDlgItemText(IDC_BUTTON6, _T("启动震动盘"));
	}
}


//HBRUSH CDlg7::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//
//	if (nCtlColor == IDC_COMING)
//		
//   {
//       pDC->SetBkColor(RGB(0, 255, 0));//设置字体颜色
//   }
//
//	return hbr;
//}





void CDlg7::setPictureColorGreen()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rc;
	CWnd *pWnd = GetDlgItem(IDC_COMING);//参数为控件ID
	pWnd->GetClientRect(&rc);//rc为控件的大小。
	int py = rc.Height();
	int px = rc.Width();

	FillRect(m_coming.GetDC()->GetSafeHdc(), &rc, CBrush(RGB(0, 255, 0)));

}

void CDlg7::setPictureColorRed()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rc;
	CWnd *pWnd = GetDlgItem(IDC_COMING);//参数为控件ID
	pWnd->GetClientRect(&rc);//rc为控件的大小。
	int py = rc.Height();
	int px = rc.Width();

	FillRect(m_coming.GetDC()->GetSafeHdc(), &rc, CBrush(RGB(255, 0, 0)));
}



void CDlg7::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	
	setPictureColorGreen();
}


void CDlg7::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1)
		myOnTimer();
	else if (nIDEvent == 2)
		updateCountData();


	CDialogEx::OnTimer(nIDEvent);
}


void CDlg7::myOnTimer()
{
	int CurrentPusle = dmcUtil.getCurrentPulse();
	CString s;
	s.Format(_T("%d"), CurrentPusle);
	SetDlgItemTextW(IDC_EDIT8,s);


	if ((CurrentPusle - previousTrigerPulse) > 180)
	{
		if (dmcUtil.isItemsComing()) {
			setPictureColorRed();
			if (paramUtil.mlp_startDetect)
			{
				dmcUtil.m_count_trigger++;
				dmcUtil.dealTrigerDeque();
				previousTrigerPulse = CurrentPusle;
			}
		}
		else {
			setPictureColorGreen();
		}
	}

	


}

void CDlg7::updateCountData()
{


	CString str1;

	str1.Format(_T("%d"), dmcUtil.m_count_trigger);
	SetDlgItemTextW(IDC_EDIT10, str1);

	str1.Format(_T("%d"), dmcUtil.m_count_camera);
	SetDlgItemTextW(IDC_EDIT12, str1);

	str1.Format(_T("%d"), dmcUtil.m_count_ng);
	SetDlgItemTextW(IDC_EDIT13, str1);

	str1.Format(_T("%d"), dmcUtil.m_count_ok);
	SetDlgItemTextW(IDC_EDIT14, str1);

	str1.Format(_T("%d"), dmcUtil.m_count_gassing1);
	SetDlgItemTextW(IDC_EDIT15, str1);

	str1.Format(_T("%d"), dmcUtil.m_count_gassing2);
	SetDlgItemTextW(IDC_EDIT16, str1);

	double reuslt = getPassRate();
	str1.Format(_T("%.2f"), reuslt);
	str1 += TEXT("%");
	SetDlgItemTextW(IDC_EDIT17, str1);




}


double CDlg7::getPassRate()
{
	int totalNum = 10;
	int maxSize = dmcUtil.resultQue.size();
	if (maxSize < totalNum)
		totalNum = maxSize;

	int pass=0;
	for (int i = (maxSize- totalNum); i < maxSize; i++)
	{
		pass += dmcUtil.resultQue[i];
	}
	double result = (double)pass / (double)totalNum*100;
	return result;

}


void CDlg7::OnBnClickedMove()
{

	dmcUtil.Move();

	/*CString str;
	if (GetDlgItemText(IDC_MOVE, str), str == _T("转盘运动"))
	{

		dmc1380Util.Move();
		SetDlgItemText(IDC_MOVE, _T("转盘停止"));
	}
	else
	{

		dmc1380Util.generalStop();
		dmc1380Util.enableGassing(false);
		dmc1380Util.gassing_no1(false);
		dmc1380Util.gassing_no2(false);


		SetDlgItemText(IDC_MOVE, _T("转盘运动"));
	}*/
}






void CDlg7::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int tmp;
	double tmpDoulbe;
	if (pScrollBar == &m_sb1) {
		bool clicked = false;
		switch (nSBCode)
		{
		case SB_THUMBPOSITION://移动滑块位置
			clicked = true;
			tmp = nPos;
			break;
		case SB_LINELEFT://左箭头
			clicked = true;
			tmp = m_sb1.GetScrollPos() - 1;
			break;
		case SB_LINERIGHT://右箭头
			clicked = true;
			tmp = m_sb1.GetScrollPos() + 1;
			break;
		case SB_PAGELEFT://左区域
			clicked = true;
			tmp = m_sb1.GetScrollPos() - 5;
			break;
		case SB_PAGERIGHT://右区域
			clicked = true;
			tmp = m_sb1.GetScrollPos() + 5;
			break;
		}
		if (clicked)
		{
			UpdateData(TRUE);



			int max = m_value2;
			if (tmp >= max) {
				tmp = max - 1;
			}

			//abs start
			int absMax = 255;
			int absMin = 0;
			if (tmp > absMax) {
				tmp = absMax;
			}
			if (tmp < absMin) {
				tmp = absMin;
			}

			//abs end

			m_sb1.SetScrollPos(tmp);
			m_value1 = tmp;
			UpdateData(FALSE);
			paramUtil.mlp_minGray = tmp;
		}
	}

	else if (pScrollBar == &m_sb2) {

		bool clicked = false;
		switch (nSBCode)
		{
		case SB_THUMBPOSITION://移动滑块位置
			clicked = true;
			tmp = nPos;
			break;
		case SB_LINELEFT://左箭头
			clicked = true;
			tmp = m_sb2.GetScrollPos() - 1;
			break;
		case SB_LINERIGHT://右箭头
			clicked = true;
			tmp = m_sb2.GetScrollPos() + 1;
			break;
		case SB_PAGELEFT://左区域
			clicked = true;
			tmp = m_sb2.GetScrollPos() - 5;
			break;
		case SB_PAGERIGHT://右区域
			clicked = true;
			tmp = m_sb2.GetScrollPos() + 5;
			break;
		}
		if (clicked)
		{
			UpdateData(TRUE);
			int min = m_value1;
			if (tmp <= min) {
				tmp = min + 1;
			}
			//abs start
			int absMax = 255;
			int absMin = 0;
			if (tmp > absMax) {
				tmp = absMax;
			}
			if (tmp < absMin) {
				tmp = absMin;
			}

			//abs end

			m_sb2.SetScrollPos(tmp);
			m_value2 = tmp;
			UpdateData(FALSE);
			paramUtil.mlp_maxGray = tmp;
		}
	}
	else if (pScrollBar == &m_sb3) 
	{

		bool clicked = false;
		switch (nSBCode)
		{
		case SB_THUMBPOSITION://移动滑块位置
			clicked = true;
			tmp = nPos;
			break;
		case SB_LINELEFT://左箭头
			clicked = true;
			tmp = m_sb3.GetScrollPos() - 1;
			break;
		case SB_LINERIGHT://右箭头
			clicked = true;
			tmp = m_sb3.GetScrollPos() + 1;
			break;
		case SB_PAGELEFT://左区域
			clicked = true;
			tmp = m_sb3.GetScrollPos() - 5;
			break;
		case SB_PAGERIGHT://右区域
			clicked = true;
			tmp = m_sb3.GetScrollPos() + 5;
			break;
		}
		if (clicked)
		{
	/*		UpdateData(TRUE);
			int min = m_value1;
			if (tmp <= min) {
				tmp = min + 1;
			}*/
			//abs start
			int absMax = 100;
			int absMin = 0;
			if (tmp > absMax) {
				tmp = absMax;
			}
			if (tmp < absMin) {
				tmp = absMin;
			}

			//abs end

			m_sb3.SetScrollPos(tmp);
			m_value3 = (double)tmp/10;
			UpdateData(FALSE);
			paramUtil.mlp_openingCircleRadius = m_value3;
		}
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDlg7::OnBnClickedButton10()
{



	if (paramUtil.mlp_useDefaultSamplePics == false)
	{
		if (paramUtil.mlp_gotSample1 == false || paramUtil.mlp_gotSample2 == false || paramUtil.mlp_gotSample3 == false || paramUtil.mlp_gotSample4 == false)
		{
			MessageBox(_T("未取得样本照片"));
			return;
		}
	}
	
	AfxBeginThread(startTrainThread,this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	

}



UINT CDlg7::startTrainThread(LPVOID param)
{
	CDlg7 *pWind = (CDlg7*)param;
	// Local iconic variables
	HObject  ho_Image, ho_GrayImage, ho_Regions, ho_RegionOpening;
	HObject  ho_RegionClosing, ho_ConnectedRegions, ho_RegionFillUp;
	HObject  ho_SelectedRegions, ho_EmptyRegion, ho_ObjectsConcat;
	HObject  ho_ImageEL, ho_ImageLE, ho_ImageES, ho_ImageSE;
	HObject  ho_ImageEE, ho_ImageLaws, ho_ImageTexture, ho_ImageTextureReduced;
	HObject  ho_ClassRegions, ho_Correct, ho_Errors, ho_ErrorsOpening;
	HObject  ho_ErrorsClosing, ho_ErrorsConnected, ho_FinalErrors;

	// Local control variables
	HTuple  hv_WindowHandle, hv_ImageFiles, hv_Number;
	HTuple  hv_Index, hv_Error, hv_ErrorLog, hv_NumErrors;


	CreateClassMlp(5, 9, 2, "softmax", "principal_components", 3, 42, &(pWind->halconUtil.hv_MLPHandle));

	//Image Acquisition 01: Code generated by Image Acquisition 01
	try {
		if (pWind->paramUtil.mlp_useDefaultSamplePics) {
			ListFiles(_MLP_DEFAULT_EXAMPLE_FILE_PATH, (HTuple("files").Append("follow_links")), &hv_ImageFiles);
		}
		else
		{
			ListFiles(_MLP_NEW_EXAMPLE_FILE_PATH, (HTuple("files").Append("follow_links")), &hv_ImageFiles);

		}
	}
	catch (...)
	{
		pWind->MessageBox(_T("无法取得档案"));
		return 0;
	}
	TupleRegexpSelect(hv_ImageFiles, (HTuple("\\.(tif|tiff|gif|bmp|jpg|jpeg|jp2|png|pcx|pgm|ppm|pbm|xwd|ima|hobj)$").Append("ignore_case")),
		&hv_ImageFiles);
	{
		HTuple end_val9 = (hv_ImageFiles.TupleLength()) - 1;
		HTuple step_val9 = 1;
		for (hv_Index = 0; hv_Index.Continue(end_val9, step_val9); hv_Index += step_val9)
		{
			ReadImage(&ho_Image, HTuple(hv_ImageFiles[hv_Index]));
			Rgb1ToGray(ho_Image, &ho_GrayImage);
			Threshold(ho_GrayImage, &ho_Regions, pWind->paramUtil.mlp_minGray, pWind->paramUtil.mlp_maxGray);
			OpeningCircle(ho_Regions, &ho_RegionOpening, 3.5);
			ClosingCircle(ho_RegionOpening, &ho_RegionClosing, 3.5);

			Connection(ho_RegionClosing, &ho_ConnectedRegions);

			CountObj(ho_ConnectedRegions, &hv_Number);
			int ConnectedRegionsNum = pWind->halconUtil.HTupleToInt(hv_Number);



			FillUp(ho_ConnectedRegions, &ho_RegionFillUp);




			SelectShapeStd(ho_RegionFillUp, &ho_SelectedRegions, "max_area", 70);


			CountObj(ho_SelectedRegions, &hv_Number);
			int i = pWind->halconUtil.HTupleToInt(hv_Number);

			GenEmptyRegion(&ho_EmptyRegion);
			ConcatObj(ho_SelectedRegions, ho_EmptyRegion, &ho_ObjectsConcat);


			TextureLaws(ho_Image, &ho_ImageEL, "el", 5, 5);
			TextureLaws(ho_Image, &ho_ImageLE, "le", 5, 5);
			TextureLaws(ho_Image, &ho_ImageES, "es", 1, 5);
			TextureLaws(ho_Image, &ho_ImageSE, "se", 1, 5);
			TextureLaws(ho_Image, &ho_ImageEE, "ee", 2, 5);
			Compose5(ho_ImageEL, ho_ImageLE, ho_ImageES, ho_ImageSE, ho_ImageEE, &ho_ImageLaws
			);
			SmoothImage(ho_ImageLaws, &ho_ImageTexture, "gauss", 3);


			AddSamplesImageClassMlp(ho_ImageTexture, ho_ObjectsConcat, pWind->halconUtil.hv_MLPHandle);


		}
	}
	SetRejectionParamsClassMlp(pWind->halconUtil.hv_MLPHandle, "sampling_strategy", "hyperbox_ring_around_each_class");
	SetRejectionParamsClassMlp(pWind->halconUtil.hv_MLPHandle, "rejection_sample_factor", .3);
	pWind->MessageBox(_T("开始训练"));
	TrainClassMlp(pWind->halconUtil.hv_MLPHandle, 200, 1, 0.01, &hv_Error, &hv_ErrorLog);


	//WriteClassMlp(halconUtil.hv_MLPHandle, _MLP_GMC_FILE_PATH);
	//ReadClassMlp(_MLP_GMC_FILE_PATH, &halconUtil.hv_MLPHandle);
	pWind->MessageBox(_T("训练完成"));
	pWind->paramUtil.mlp_completeTrain = true;

	return 0;
}


void CDlg7::OnBnClickedCheck3()
{

	int stat = ((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck();
	if (stat == 0)
		paramUtil.mlp_useDefaultSamplePics = false;
	else
		paramUtil.mlp_useDefaultSamplePics = true;


}


void CDlg7::OnBnClickedButton4()
{
	if(paramUtil.showModeSynWithMainWin!=9)
		MessageBox(_T("请调整模式"));

	if (paramUtil.mlp_useDefaultSamplePics)
	{
		MessageBox(_T("请调取消使用预设的样本照片"));
	}



	paramUtil.mlp_takeSample1 = true;

}


void CDlg7::OnBnClickedButton5()
{
	if (paramUtil.showModeSynWithMainWin != 9)
		MessageBox(_T("请调整模式"));

	if (paramUtil.mlp_useDefaultSamplePics)
	{
		MessageBox(_T("请调取消使用预设的样本照片"));
	}
	paramUtil.mlp_takeSample2 = true;
}


void CDlg7::OnBnClickedButton8()
{
	if (paramUtil.showModeSynWithMainWin != 9)
		MessageBox(_T("请调整模式"));

	if (paramUtil.mlp_useDefaultSamplePics)
	{
		MessageBox(_T("请调取消使用预设的样本照片"));
	}
	paramUtil.mlp_takeSample3 = true;
}


void CDlg7::OnBnClickedButton9()
{
	if (paramUtil.showModeSynWithMainWin != 9)
		MessageBox(_T("请调整模式"));

	if (paramUtil.mlp_useDefaultSamplePics)
	{
		MessageBox(_T("请调取消使用预设的样本照片"));
	}
	paramUtil.mlp_takeSample4 = true;
}


void CDlg7::OnBnClickedRadio5()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlg7::OnBnClickedMove2()
{
	previousTrigerPulse = dmcUtil.getCurrentPulse();

	if (paramUtil.caseSixMode == 1)
	{
		if (paramUtil.mlp_completeTrain == false)
		{
			MessageBox(_T("尚未完成训练"));
			return;
		}
		else
			paramUtil.mlp_startDetect = true;
	}
	dmcUtil.runThread = true;
	//开启2个thread,gassing 1 和 gassing 2


	AfxBeginThread(runWorkThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);


	AfxBeginThread(runWorkThread2, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);


}


void CDlg7::OnBnClickedButton11()
{
	paramUtil.mlp_startDetect = false;
	dmcUtil.runThread = false;
}


void CDlg7::OnEnChangeEdit9()
{
	CString rString;
	GetDlgItem(IDC_EDIT9)->GetWindowTextW(rString);
	try {
		int sp = MfcUtil::CStringToInt(rString);
		dmcUtil.nPos = sp;

	}
	catch (...) {}
}


void CDlg7::OnBnClickedRadio7()
{
	// TODO: 在此添加控件通知处理程序代码
	dmcUtil.moveModeFixPosFixDisSpeed = 0;
}


void CDlg7::OnBnClickedButton14()
{
	try {
		//WriteClassMlp(halconUtil.hv_MLPHandle, _MLP_GMC_FILE_PATH);
		ReadClassMlp(_MLP_GMC_FILE_PATH, &halconUtil.hv_MLPHandle);
		MessageBox(_T("读取成功"));
		paramUtil.mlp_completeTrain = true;
	}
	catch (...)
	{
		paramUtil.mlp_completeTrain = false;
		MessageBox(_T("读取失败"));
	}
}


void CDlg7::OnBnClickedMove3()
{
	// TODO: 在此添加控件通知处理程序代码
	dmcUtil.generalStop();
	/*dmc1380Util.enableGassing(false);
	dmc1380Util.gassing_no1(false);
	dmc1380Util.gassing_no2(false);*/



}


void CDlg7::OnBnClickedMove4()
{
	// TODO: 在此添加控件通知处理程序代码
	dmcUtil.clearDeques();

	

	dmcUtil.resetCount();

	paramUtil.isClearQue = true;
}

UINT CDlg7::runWorkThread(LPVOID param)
{
	CDlg7* pWin = (CDlg7*)param;

	pWin->dmcUtil.dealGass1Deque();

	
	return 0;
}



UINT CDlg7::runWorkThread2(LPVOID param)
{
	CDlg7* pWin = (CDlg7*)param;

	pWin->dmcUtil.dealGass2Deque();


	return 0;
}



void CDlg7::OnBnClickedButton13()
{
	try {
		//WriteClassMlp(halconUtil.hv_MLPHandle, _MLP_GMC_FILE_PATH);
		ReadClassMlp(_MLP_GMC_FILE_PATH_READONLY, &halconUtil.hv_MLPHandle);
		MessageBox(_T("读取成功"));
		paramUtil.mlp_completeTrain = true;
	}
	catch (...)
	{
		paramUtil.mlp_completeTrain = false;
		MessageBox(_T("读取失败"));
	}
}
