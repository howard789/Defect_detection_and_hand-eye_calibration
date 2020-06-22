// CDlg3.cpp: 实现文件
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "CDlg3.h"
#include "afxdialogex.h"


// CDlg3 对话框

IMPLEMENT_DYNAMIC(CDlg3, CDialogEx)
CDlg3::CDlg3(HalconMotionCardUnion &motionWarehouse,ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc & doc, MotionControlCardUtil & motionCard, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LEADSHINE, pParent), doc(doc), motionCard(motionCard), cameraUtil(cameraUtil), halconUtil(halconUtil), paramUtil(paramUtil), halconMotionCardUnion(motionWarehouse)
	, m_value3(0)
	, m_value4(0)
	, m_value5(0)
	, m_value6(_T(""))
	, m_value7(_T(""))
	, m_value8(0)
	, m_value9(0)
	, m_value10(0)
	, m_value11(0)
{
	mode = 0;//blob
	pointLocation = 0;//BasePoint
	m_value1 = 0;
	m_value2 = 0;

}

CDlg3::~CDlg3()
{
}

void CDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_value1);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_sb1);
	DDX_Text(pDX, IDC_EDIT3, m_value2);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_sb2);
	DDX_Control(pDX, IDC_SCROLLBAR8, m_sb3);
	DDX_Control(pDX, IDC_SCROLLBAR9, m_sb4);
	DDX_Text(pDX, IDC_EDIT4, m_value3);
	DDX_Text(pDX, IDC_EDIT40, m_value4);
	DDX_Text(pDX, IDC_EDIT41, m_value5);
	DDX_Text(pDX, IDC_EDIT43, m_value6);
	DDX_Text(pDX, IDC_EDIT44, m_value7);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_sb5);
	DDX_Control(pDX, IDC_SCROLLBAR10, m_sb6);
	DDX_Control(pDX, IDC_SCROLLBAR11, m_sb7);
	DDX_Control(pDX, IDC_SCROLLBAR4, m_sb8);
	DDX_Text(pDX, IDC_EDIT42, m_value8);
	DDX_Text(pDX, IDC_EDIT45, m_value9);
	DDX_Control(pDX, IDC_SCROLLBAR12, m_sb9);


	DDX_Text(pDX, IDC_EDIT46, m_value10);
	DDX_Text(pDX, IDC_EDIT47, m_value11);
	DDX_Control(pDX, IDC_SCROLLBAR13, m_sb10);
	DDX_Control(pDX, IDC_SCROLLBAR14, m_sb11);
}


BEGIN_MESSAGE_MAP(CDlg3, CDialogEx)
	ON_WM_HSCROLL()

	//ON_BN_CLICKED(IDC_CHECK2, &CDlg3::OnBnClickedCheck2)

	ON_BN_CLICKED(IDC_MOVETOLOCATION, &CDlg3::OnBnClickedMovetolocation)
	ON_BN_CLICKED(IDC_IDENTIFY, &CDlg3::OnBnClickedIdentify)
	ON_BN_CLICKED(IDC_AUTOTAKE, &CDlg3::OnBnClickedAutotake)

	ON_BN_CLICKED(IDC_GEN_REC2, &CDlg3::OnBnClickedGenRec2)
	ON_BN_CLICKED(IDC_GEN_REC3, &CDlg3::OnBnClickedGenRec3)
	ON_BN_CLICKED(IDC_AUTOTAKE2, &CDlg3::OnBnClickedAutotake2)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlg3::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlg3::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_AUTOTAKE3, &CDlg3::OnBnClickedAutotake3)
	ON_BN_CLICKED(IDC_BUTTON11, &CDlg3::OnBnClickedButton11)
END_MESSAGE_MAP()


// CDlg3 消息处理程序







void CDlg3::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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
			paramUtil.minGray = tmp;
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
			paramUtil.maxGray = tmp;
		}
	}
	else if (pScrollBar == &m_sb3) {

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
			UpdateData(TRUE);
			int max = m_value4;
			if (tmp >=max) {
				tmp = max - 1;
			}
			//abs start
			int absMax = 30000;
			int absMin = 0;
			if (tmp > absMax) {
				tmp = absMax;
			}
			if (tmp < absMin) {
				tmp = absMin;
			}

			//abs end



			m_sb3.SetScrollPos(tmp);
			m_value3 = tmp;
			UpdateData(FALSE);
			paramUtil.selectShapMinArea = tmp;
		}
	}
	else if (pScrollBar == &m_sb4) 
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
				tmp = m_sb4.GetScrollPos() - 1;
				break;
			case SB_LINERIGHT://右箭头
				clicked = true;
				tmp = m_sb4.GetScrollPos() + 1;
				break;
			case SB_PAGELEFT://左区域
				clicked = true;
				tmp = m_sb4.GetScrollPos() - 5;
				break;
			case SB_PAGERIGHT://右区域
				clicked = true;
				tmp = m_sb4.GetScrollPos() + 5;
				break;
			}
			if (clicked)
			{
				UpdateData(TRUE);
				int min = m_value3;
				if (tmp <= min) {
					tmp = min + 1;
				}

				//abs start
				int absMax = 30000;
				int absMin = 0;
				if (tmp > absMax) {
					tmp = absMax;
				}
				if (tmp < absMin) {
					tmp = absMin;
				}

				//abs end
				m_sb4.SetScrollPos(tmp);
				m_value4 = tmp;
				UpdateData(FALSE);
				paramUtil.selectShapMaxArea = tmp;
			}
		}

	else if (pScrollBar == &m_sb5)//匹配度 0.1
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
			tmp = m_sb5.GetScrollPos() - 1;
			break;
		case SB_LINERIGHT://右箭头
			clicked = true;
			tmp = m_sb5.GetScrollPos() + 1;
			break;
		case SB_PAGELEFT://左区域
			clicked = true;
			tmp = m_sb5.GetScrollPos() - 2;
			break;
		case SB_PAGERIGHT://右区域
			clicked = true;
			tmp = m_sb5.GetScrollPos() + 2;
			break;
		}
		if (clicked)
		{
			//UpdateData(TRUE);
			//int min = m_value3;
			//if (tmp <= min) {
			//	tmp = min + 1;
			//}
			//abs start
			double absMax = 10;
			double absMin = 0;
			if (tmp > absMax) {


				tmp = absMax;
			}
			if (tmp < absMin) {
				tmp = absMin;
			}

			//abs end

			m_sb5.SetScrollPos(tmp);
			m_value5 = ((double)tmp)/10;
			UpdateData(FALSE);
			paramUtil.minScore = m_value5;
		}
	}

	else if (pScrollBar == &m_sb6)//最小对比度 0-40
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
			tmp = m_sb6.GetScrollPos() - 1;
			break;
		case SB_LINERIGHT://右箭头
			clicked = true;
			tmp = m_sb6.GetScrollPos() + 1;
			break;
		case SB_PAGELEFT://左区域
			clicked = true;
			tmp = m_sb6.GetScrollPos() - 5;
			break;
		case SB_PAGERIGHT://右区域
			clicked = true;
			tmp = m_sb6.GetScrollPos() + 5;
			break;
		}
		if (clicked)
		{
			//UpdateData(TRUE);
			//int min = m_value3;
			//if (tmp <= min) {
			//	tmp = min + 1;
			//}
			//abs start
			int absMax = 40;
			int absMin = 0;
			if (tmp > absMax) {
				tmp = absMax;
			}
			if (tmp < absMin) {
				tmp = absMin;
			}

			//abs end


			m_sb6.SetScrollPos(tmp);

			if (tmp == 0) {
				m_value6 = "auto";
			}
			else {
				m_value6.Format(_T("%d"),tmp);;

			}
			UpdateData(FALSE);
			paramUtil.minContrast = MfcUtil::CStringToString(m_value6);
				
		}
	}

	else if (pScrollBar == &m_sb7)//查找数量 0-20
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
			tmp = m_sb7.GetScrollPos() - 1;
			break;
		case SB_LINERIGHT://右箭头
			clicked = true;
			tmp = m_sb7.GetScrollPos() + 1;
			break;
		case SB_PAGELEFT://左区域
			clicked = true;
			tmp = m_sb7.GetScrollPos() - 3;
			break;
		case SB_PAGERIGHT://右区域
			clicked = true;
			tmp = m_sb7.GetScrollPos() + 3;
			break;
		}
		if (clicked)
		{
			//UpdateData(TRUE);
			//int min = m_value3;
			//if (tmp <= min) {
			//	tmp = min + 1;
			//}

			//abs start
			int absMax = 20;
			int absMin = 0;
			if (tmp > absMax) {
				tmp = absMax;
			}
			if (tmp < absMin) {
				tmp = absMin;
			}

			//abs end
			m_sb7.SetScrollPos(tmp);

			if (tmp == 0) {
				m_value7 = "查找全部";
			}
			else {
				m_value7.Format(_T("%d"), tmp);;
			}
			UpdateData(FALSE);
			paramUtil.numMatches = tmp;
		}
	}

	

	else if (pScrollBar == &m_sb8)//areaPoints min 0-2000
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
			tmp = m_sb8.GetScrollPos() - 1;
			break;
		case SB_LINERIGHT://右箭头
			clicked = true;
			tmp = m_sb8.GetScrollPos() + 1;
			break;
		case SB_PAGELEFT://左区域
			clicked = true;
			tmp = m_sb8.GetScrollPos() - 20;
			break;
		case SB_PAGERIGHT://右区域
			clicked = true;
			tmp = m_sb8.GetScrollPos() + 20;
			break;
		}
		if (clicked)
		{
			UpdateData(TRUE);
			int max = m_value9;
			if (tmp >= max) {
				tmp = max - 1;
			}
			//abs start
			int absMax = 2000;
			int absMin = 0;
			if (tmp > absMax) {
				tmp = absMax;
			}
			if (tmp < absMin) {
				tmp = absMin;
			}

			//abs end
			m_sb8.SetScrollPos(tmp);

			m_value8 = tmp;
			UpdateData(FALSE);
			paramUtil.areaPintsMin = tmp;
		}

	}
	else if (pScrollBar == &m_sb9)//areaPoints max 0-2000
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
				tmp = m_sb9.GetScrollPos() - 1;
				break;
			case SB_LINERIGHT://右箭头
				clicked = true;
				tmp = m_sb9.GetScrollPos() + 1;
				break;
			case SB_PAGELEFT://左区域
				clicked = true;
				tmp = m_sb9.GetScrollPos() - 20;
				break;
			case SB_PAGERIGHT://右区域
				clicked = true;
				tmp = m_sb9.GetScrollPos() + 20;
				break;
			}
			if (clicked)
			{
				UpdateData(TRUE);
				int min = m_value8;
				if (tmp <= min) {
					tmp = min + 1;
				}
				//abs start
				int absMax = 2000;
				int absMin = 0;
				if (tmp > absMax) {
					tmp = absMax;
				}
				if (tmp < absMin) {
					tmp = absMin;
				}

				//abs end

				m_sb9.SetScrollPos(tmp);

				m_value9 = tmp;
				UpdateData(FALSE);
				paramUtil.areaPintsMax = tmp;
			}
	}

	else if (pScrollBar == &m_sb10)//circulity max 0-1
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
			tmp = m_sb10.GetScrollPos() - 5;
			break;
		case SB_LINERIGHT://右箭头
			clicked = true;
			tmp = m_sb10.GetScrollPos() + 5;
			break;
		case SB_PAGELEFT://左区域
			clicked = true;
			tmp = m_sb10.GetScrollPos() - 10;
			break;
		case SB_PAGERIGHT://右区域
			clicked = true;
			tmp = m_sb10.GetScrollPos() + 10;
			break;
		}
		if (clicked)
		{
			UpdateData(TRUE);
			int max = (double)m_value11*100;
			if (tmp >= max) {
				tmp = max - 5;
			}
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

			m_sb10.SetScrollPos(tmp);

			m_value10 = (double)tmp/100;
			UpdateData(FALSE);
			paramUtil.circularityMin = m_value10;
		}
	}

	else if (pScrollBar == &m_sb11)//circulity max 0-1
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
			tmp = m_sb11.GetScrollPos() - 5;
			break;
		case SB_LINERIGHT://右箭头
			clicked = true;
			tmp = m_sb11.GetScrollPos() + 5;
			break;
		case SB_PAGELEFT://左区域
			clicked = true;
			tmp = m_sb11.GetScrollPos() - 10;
			break;
		case SB_PAGERIGHT://右区域
			clicked = true;
			tmp = m_sb11.GetScrollPos() + 10;
			break;
		}
		if (clicked)
		{
			UpdateData(TRUE);
			double min = (double)m_value10 * 100;
			if (tmp <= min) {
				tmp = min + 5;
			}
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

			m_sb11.SetScrollPos(tmp);

			m_value11 = (double)tmp / 100;
			UpdateData(FALSE);
			paramUtil.circularityMax = m_value11;
		}
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}







BOOL CDlg3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	myOnInitDialog();



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlg3::myOnInitDialog()
{

	//ScoreBar
	//二值化Min
	m_value1 = paramUtil.minGray;
	UpdateData(FALSE);
	m_sb1.SetScrollRange(0, 255);
	m_sb1.SetScrollPos(m_value1);

	/*/二值化Max*/
	m_value2 = paramUtil.maxGray;
	UpdateData(FALSE);
	m_sb2.SetScrollRange(0, 255);
	m_sb2.SetScrollPos(m_value2);

	//最小区域
	m_value3 = paramUtil.selectShapMinArea;
	UpdateData(FALSE);
	m_sb3.SetScrollRange(0, 30000);
	m_sb3.SetScrollPos(m_value3);
	//最大区域
	m_value4 = paramUtil.selectShapMaxArea;
	UpdateData(FALSE);
	m_sb4.SetScrollRange(0, 30000);
	m_sb4.SetScrollPos(m_value4);


	//匹配度
	m_value5 = paramUtil.minScore;
	UpdateData(FALSE);
	m_sb5.SetScrollRange(0, 1.0*10);
	m_sb5.SetScrollPos(m_value5*10);

	//最小对比度
	m_value6 = paramUtil.minContrast.c_str();
	UpdateData(FALSE);
	m_sb6.SetScrollRange(0, 40);
	int intValueContrast ;
	if (m_value6.CompareNoCase(_T("auto"))) {
		intValueContrast = 0;
	}
	else {
		intValueContrast =_ttoi(m_value6);
	}

	

	m_sb6.SetScrollPos(intValueContrast);

	//查找数量
	int numMatchesInt = paramUtil.numMatches;
	if (numMatchesInt == 0) {
		m_value7 = "查找全部";
	}
	else {
		m_value7.Format(_T("%d"), numMatchesInt);
	}
	UpdateData(FALSE);
	m_sb7.SetScrollRange(0, 20);
	m_sb7.SetScrollPos(numMatchesInt);


	//area_points min
	m_value8 = paramUtil.areaPintsMin;
	UpdateData(FALSE);
	m_sb8.SetScrollRange(0, 2000);
	m_sb8.SetScrollPos(m_value8);

	//area_points max
	m_value9 = paramUtil.areaPintsMax;
	UpdateData(FALSE);
	m_sb9.SetScrollRange(0, 2000);
	m_sb9.SetScrollPos(m_value9);


	//circulity min
	m_value10 = paramUtil.circularityMin;
	UpdateData(FALSE);
	m_sb10.SetScrollRange(0, 100);
	m_sb10.SetScrollPos(m_value10*100);
	
	//circulity min
	m_value11 = paramUtil.circularityMax;
	UpdateData(FALSE);
	m_sb11.SetScrollRange(0, 100);
	m_sb11.SetScrollPos(m_value11 * 100);





}







//void CDlg3::OnBnClickedCheck2()
//{
//	int nState = ((CButton*)GetDlgItem(IDC_CHECK_SHOW))->GetCheck();
//	if (nState == BST_CHECKED)
//	{
//		//选中    
//		cameraUtil.showAmendedPic = true;
//	}
//	else
//	{
//		//未选中
//		cameraUtil.showAmendedPic = false;
//	}
//}





void CDlg3::OnBnClickedMovetolocation()
{
	motionCard.moveToBasePointCS();
}


void CDlg3::OnBnClickedIdentify()
{
	if (paramUtil.locked)
		return;


	if (paramUtil.completeCalibration == false)
	{
		MessageBox(_T("请先标定"));
		return;
	}

	if (paramUtil.showModeSynWithMainWin != 3)
	{
		MessageBox(_T("请调整显示模式"));
		return;
	}

	



	//z轴要回到一定的高度才准确
	motionCard.moveToBaesZ();

	halconMotionCardUnion.step_1_resetTargetData();
	halconMotionCardUnion.step_2_status_startGotFromData = true;

	paramUtil.picTarget = true;




}



void CDlg3::OnBnClickedAutotake()
{
	if (paramUtil.locked)
		return;



	paramUtil.GoOriginal = true;

	
	

	if (paramUtil.picTarget)
		return;

	paramUtil.dlg3ThreadMode = 1;
	paramUtil.locked = true;
	AfxBeginThread(wrokThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

}




void CDlg3::OnBnClickedGenRec2()
{
	if (paramUtil.locked)
		return;

	if (paramUtil.showModeSynWithMainWin != 4)
	{
		MessageBox(_T("请调整显示模式"));
		return;
	}

	paramUtil.generateRectengle = true;
}




void CDlg3::OnBnClickedIdentify2()
{
	
}


void CDlg3::OnBnClickedAutotake2()
{
	if (paramUtil.locked)
		return;

	paramUtil.GoOriginal = true;

	if (halconMotionCardUnion.step_4_status_endGotFromData == false)
	{
		return ;
	}
		


	paramUtil.dlg3ThreadMode = 3;
	paramUtil.locked = true;
	AfxBeginThread(wrokThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

	
}

UINT CDlg3::wrokThread(LPVOID pParam)
{
	CDlg3 *pDlg3 = (CDlg3*)pParam;
	switch (pDlg3->paramUtil.dlg3ThreadMode)
	{
	case 1:
		return pDlg3->runBlobThread(pParam);
	case 2:
		return pDlg3->runTemplateThread(pParam);
	case 3:
		return pDlg3->runXldGrabThread(pParam);
	case 4:
		return pDlg3->runXldFaceThread(pParam);

	}

	return -1;
}






void CDlg3::OnBnClickedButton7()
{
	if (paramUtil.locked)
		return;

	if (paramUtil.completeCalibration == false)
	{
		MessageBox(_T("请先标定"));
		return;
	}

	if (paramUtil.showModeSynWithMainWin != 6)
	{
		MessageBox(_T("请调整显示模式"));
		return;
	}





	halconMotionCardUnion.step_1_resetTargetData();
	halconMotionCardUnion.step_2_status_startGotFromData = true;
}


//xld识别
void CDlg3::OnBnClickedButton8()
{
	if (paramUtil.locked)
		return;

	if (paramUtil.completeCalibration == false)
	{ 
		MessageBox(_T("请先标定"));
		return;
	}
	if (paramUtil.showModeSynWithMainWin != 4)
	{
		MessageBox(_T("请调整显示模式"));
		return;
	}



	halconMotionCardUnion.step_1_resetTargetData();

	halconMotionCardUnion.step_2_status_startGotFromData = true;

}


//xld开始分拣
void CDlg3::OnBnClickedGenRec3()
{
	if (paramUtil.locked)
		return;
	paramUtil.GoOriginal = true;

	if (halconMotionCardUnion.step_4_status_endGotFromData == false)
		return;
	paramUtil.dlg3ThreadMode = 2;
	paramUtil.locked = true;
	AfxBeginThread(wrokThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	
}


void CDlg3::OnBnClickedAutotake3()
{
	if (paramUtil.locked)
		return;

	if (paramUtil.completeCalibration == false)
	{
		MessageBox(_T("请先标定"));
		return;
	}

	if (paramUtil.showModeSynWithMainWin != 6)
	{
		MessageBox(_T("请调整显示模式"));
		return;
	}

	halconMotionCardUnion.startCollectContourPoint = true;
}


void CDlg3::OnBnClickedButton11()
{
	if (paramUtil.locked)
		return;

	paramUtil.GoOriginal = true;
	paramUtil.locked = true;
	paramUtil.dlg3ThreadMode = 4;
	AfxBeginThread(wrokThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

}


UINT CDlg3::runBlobThread(LPVOID pParam)
{
	paramUtil.isGrabbing = true;
	
	while (!motionCard.isAllStop());
	halconMotionCardUnion.step_5_doAction(doc);
	while (!motionCard.isAllStop());
	motionCard.moveToBaseCPointAll();
	while (!motionCard.isAllStop());
	paramUtil.locked = false;
	paramUtil.isGrabbing = false;
	return 0;
}

UINT CDlg3::runTemplateThread(LPVOID pParam)
{
	paramUtil.isGrabbing = true;
	while (!motionCard.isAllStop());
	halconMotionCardUnion.step_5_doAction(doc);
	while (!motionCard.isAllStop());
	motionCard.moveToBaseCPointAll();
	while (!motionCard.isAllStop());
	paramUtil.locked = false;
	paramUtil.isGrabbing = false;
	return 0;
}

UINT CDlg3::runXldGrabThread(LPVOID pParam)
{
	paramUtil.isGrabbing = true;
	CDlg3 *pDlg = (CDlg3*)pParam;
	while (!motionCard.isAllStop());
	halconMotionCardUnion.step_5_doAction(doc);
	while (!motionCard.isAllStop());
	motionCard.moveToBaseCPointAll();
	while (!motionCard.isAllStop());
	paramUtil.locked = false;
	paramUtil.isGrabbing = false;
	return 0;
}

UINT CDlg3::runXldFaceThread(LPVOID pParam)
{
	paramUtil.isGrabbing = true;
	if (halconMotionCardUnion.CompleteCollectContourPoint)
	{
		motionCard.setMovingMode_S();
		while (!motionCard.isAllStop());
		motionCard.moveToBaesZ();
		while (!motionCard.isAllStop());
		halconMotionCardUnion.CompleteCollectContourPoint = false;
		int totalContourNum = halconMotionCardUnion.contourMapSize();


		for (int i = 1; i <= totalContourNum; i++)
		{

			vector<CPoint> contourList;
			halconMotionCardUnion.getContourList(i, contourList);

			CPoint *cp;
			int count = 1;
			for (vector<CPoint>::iterator ite = contourList.begin(); ite != contourList.end(); ite++)
			{

				cp = &*ite;
				motionCard.moveToPoint(*cp);
				while (!motionCard.isAllStop());
				if (count == 1)
				{
					motionCard.moveToInHolePoint();
					while (!motionCard.isAllStop());
				}

				count++;
			}
			motionCard.moveToBaesZ();
			while (!motionCard.isAllStop());
		}
		motionCard.setMovingMode_T();
		while (!motionCard.isAllStop());
		motionCard.moveToBaseCPointAll();
		while (!motionCard.isAllStop());
	}
	paramUtil.locked = false;
	paramUtil.isGrabbing = false;
	return 0;
}