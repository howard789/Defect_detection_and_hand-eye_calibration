// CDlg6.cpp: 实现文件
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "CDlg6.h"
#include "afxdialogex.h"
#  include "HalconCpp.h"
#  include "HDevThread.h"

// CDlg6 对话框

IMPLEMENT_DYNAMIC(CDlg6, CDialogEx)
CDlg6::CDlg6(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc & doc, MotionControlCardUtil & motionCard, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LEADSHINE, pParent), doc(doc), motionCard(motionCard), cameraUtil(cameraUtil), halconUtil(halconUtil), paramUtil(paramUtil)
{

}


CDlg6::~CDlg6()
{
}

void CDlg6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg6, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlg6::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK36, &CDlg6::OnBnClickedCheck36)
	ON_BN_CLICKED(IDC_C1P1, &CDlg6::OnBnClickedC1p1)
	ON_BN_CLICKED(IDC_C1P2, &CDlg6::OnBnClickedC1p2)
	ON_BN_CLICKED(IDC_C1P3, &CDlg6::OnBnClickedC1p3)
	ON_BN_CLICKED(IDC_C1P4, &CDlg6::OnBnClickedC1p4)
	ON_BN_CLICKED(IDC_C1P5, &CDlg6::OnBnClickedC1p5)
	ON_BN_CLICKED(IDC_C1P6, &CDlg6::OnBnClickedC1p6)
	ON_BN_CLICKED(IDC_C1P7, &CDlg6::OnBnClickedC1p7)
	ON_BN_CLICKED(IDC_C1P8, &CDlg6::OnBnClickedC1p8)
	ON_BN_CLICKED(IDC_C1P9, &CDlg6::OnBnClickedC1p9)
	ON_BN_CLICKED(IDC_C2P1, &CDlg6::OnBnClickedC2p1)
	ON_BN_CLICKED(IDC_C2P2, &CDlg6::OnBnClickedC2p2)
	ON_BN_CLICKED(IDC_C2P3, &CDlg6::OnBnClickedC2p3)
	ON_BN_CLICKED(IDC_C2P4, &CDlg6::OnBnClickedC2p4)
	ON_BN_CLICKED(IDC_C2P5, &CDlg6::OnBnClickedC2p5)
	ON_BN_CLICKED(IDC_C2P6, &CDlg6::OnBnClickedC2p6)
	ON_BN_CLICKED(IDC_C2P7, &CDlg6::OnBnClickedC2p7)
	ON_BN_CLICKED(IDC_C2P8, &CDlg6::OnBnClickedC2p8)
	ON_BN_CLICKED(IDC_C2P9, &CDlg6::OnBnClickedC2p9)
	ON_BN_CLICKED(IDC_BUTTON33, &CDlg6::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON34, &CDlg6::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON35, &CDlg6::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON21, &CDlg6::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlg6::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON10, &CDlg6::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlg6::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON11, &CDlg6::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg6::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg6::OnBnClickedButton2)
END_MESSAGE_MAP()



void CDlg6::OnBnClickedButton4()
{
	if (paramUtil.showModeSynWithMainWin != 7) {
		MessageBox(_T("请调整显示模式"));
	}

	paramUtil.caseFourCalibration_CameraOne = true;

}

void CDlg6::OnBnClickedButton33()
{
	if (paramUtil.cameraModeSecond!= 1) {
		MessageBox(_T("请调整显示模式"));
	}

	paramUtil.caseFourCalibration_CameraTwo = true;
}








void CDlg6::OnBnClickedCheck36()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveDefaultNinePointPulseLocation();
	showPulseMap();
}



void CDlg6::SaveDefaultNinePointPulseLocation()
{
	doc.setPulseMap_Project4(1,1,*doc.project4_camera1_world_point1);
	doc.setPulseMap_Project4(1,2,*doc.project4_camera1_world_point2);
	doc.setPulseMap_Project4(1,3,*doc.project4_camera1_world_point3);
	doc.setPulseMap_Project4(1,4,*doc.project4_camera1_world_point4);
	doc.setPulseMap_Project4(1,5,*doc.project4_camera1_world_point5);
	doc.setPulseMap_Project4(1,6,*doc.project4_camera1_world_point6);
	doc.setPulseMap_Project4(1,7,*doc.project4_camera1_world_point7);
	doc.setPulseMap_Project4(1,8,*doc.project4_camera1_world_point8);
	doc.setPulseMap_Project4(1,9,*doc.project4_camera1_world_point9);

	doc.setPulseMap_Project4(2, 1, *doc.project4_camera2_world_point1);
	doc.setPulseMap_Project4(2, 2, *doc.project4_camera2_world_point2);
	doc.setPulseMap_Project4(2, 3, *doc.project4_camera2_world_point3);
	doc.setPulseMap_Project4(2, 4, *doc.project4_camera2_world_point4);
	doc.setPulseMap_Project4(2, 5, *doc.project4_camera2_world_point5);
	doc.setPulseMap_Project4(2, 6, *doc.project4_camera2_world_point6);
	doc.setPulseMap_Project4(2, 7, *doc.project4_camera2_world_point7);
	doc.setPulseMap_Project4(2, 8, *doc.project4_camera2_world_point8);
	doc.setPulseMap_Project4(2, 9, *doc.project4_camera2_world_point9);


}


CPoint CDlg6::getCurrentPulsePosition()
{
	return CPoint();
}

void CDlg6::OnBnClickedC1p1()
{
	doc.setPulseMap_Project4(1, 1, getCurrentPulsePosition());
}


void CDlg6::OnBnClickedC1p2()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(1, 2, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC1p3()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(1, 3, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC1p4()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(1, 4, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC1p5()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(1, 5, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC1p6()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(1, 6, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC1p7()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(1, 7, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC1p8()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(1, 8, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC1p9()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(1, 9, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC2p1()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(2, 1, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC2p2()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(2, 2, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC2p3()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(2, 3, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC2p4()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(2, 4, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC2p5()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(2, 5, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC2p6()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(2, 6, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC2p7()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(2, 7, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC2p8()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(2, 8, getCurrentPulsePosition());

}


void CDlg6::OnBnClickedC2p9()
{
	// TODO: 在此添加控件通知处理程序代码
	doc.setPulseMap_Project4(2, 9, getCurrentPulsePosition());

}

void CDlg6::OnBnClickedButton34()
{
	Calirate(1);
}

void CDlg6::OnBnClickedButton35()
{
	Calirate(2);
}



void CDlg6::Calirate(int CameraNum)
{//提取九点坐标，Camera One


	HObject  ho_Image, ho_ImageIlluminate, ho_GrayImage;
	HObject  ho_Regions, ho_ConnectedRegions, ho_SelectedRegions;
	HObject  ho_RegionFillUp;

	HTuple  hv_Width, hv_Height;
	HTuple  hv_Area, hv_Row, hv_Column, hv_I, hv_y, hv_x, hv_mes;

	try {
		CameraNum == 1 ?
			ho_Image = halconUtil.calibrationImage_projectFour_CameraOne :
			ho_Image = halconUtil.calibrationImage_projectFour_CameraTwo;

		Illuminate(ho_Image, &ho_ImageIlluminate, 101, 101, 0.7);
	}
	catch (...)
	{
		MessageBox(_T("请先拍照"));
		return;
	}

    
	Rgb1ToGray(ho_ImageIlluminate, &ho_GrayImage);

	Threshold(ho_GrayImage, &ho_Regions, paramUtil.minGray, paramUtil.maxGray);
	Connection(ho_Regions, &ho_ConnectedRegions);


	SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", paramUtil.selectShapMinArea, paramUtil.selectShapMaxArea);
	FillUp(ho_SelectedRegions, &ho_RegionFillUp);

	SortRegion(ho_RegionFillUp, &ho_RegionFillUp, "character", "true", "row");



	AreaCenter(ho_RegionFillUp, &hv_Area, &hv_Row, &hv_Column);


	halconUtil.doTakeNinePointsCenter_Project4(hv_Row, hv_Column, &doc, CameraNum);

	int i;

	CameraNum == 1 ? i = halconUtil.takePointsNum_Project4_C1 : i = halconUtil.takePointsNum_Project4_C2;
		

	string iSt = MfcUtil::IntToString(i, 10);

	if (i == 9) {
		//显示pixMap
		showPixMap();
		showPulseMap();
		MessageBox(_T("提取9点成功"));
	}
	else {
		string s = "提取点数不为9,实际提取 " + iSt + " 点.";
		MessageBox(MfcUtil::stringToLPCWSTR(s));
		return;
	}
}


void CDlg6::showPixMap()
{
	//IDC_C1_Pixel_1Y
	//IDC_C1_Pixel_1X
	CString str;
	CPoint cp;
	int CameraNum = 1;

	cp = doc.getPixelMapValue_Project4(CameraNum,1);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pixel_1X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pixel_1Y, str);

	cp = doc.getPixelMapValue_Project4(CameraNum, 2);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pixel_2X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pixel_2Y, str);


	cp = doc.getPixelMapValue_Project4(CameraNum, 3);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pixel_3X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pixel_3Y, str);


	cp = doc.getPixelMapValue_Project4(CameraNum, 4);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pixel_4X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pixel_4Y, str);

	cp = doc.getPixelMapValue_Project4(CameraNum, 5);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pixel_5X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pixel_5Y, str);

	cp = doc.getPixelMapValue_Project4(CameraNum, 6);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pixel_6X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pixel_6Y, str);

	cp = doc.getPixelMapValue_Project4(CameraNum, 7);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pixel_7X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pixel_7Y, str);

	cp = doc.getPixelMapValue_Project4(CameraNum,8);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pixel_8X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pixel_8Y, str);

	cp = doc.getPixelMapValue_Project4(CameraNum, 9);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pixel_9X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pixel_9Y, str);


	 CameraNum = 2;

	 cp = doc.getPixelMapValue_Project4(CameraNum, 1);
	 str.Format(_T("%d"), cp.x);
	 SetDlgItemText(IDC_C2_Pixel_1X, str);
	 str.Format(_T("%d"), cp.y);
	 SetDlgItemText(IDC_C2_Pixel_1Y, str);

	 cp = doc.getPixelMapValue_Project4(CameraNum, 2);
	 str.Format(_T("%d"), cp.x);
	 SetDlgItemText(IDC_C2_Pixel_2X, str);
	 str.Format(_T("%d"), cp.y);
	 SetDlgItemText(IDC_C2_Pixel_2Y, str);


	 cp = doc.getPixelMapValue_Project4(CameraNum, 3);
	 str.Format(_T("%d"), cp.x);
	 SetDlgItemText(IDC_C2_Pixel_3X, str);
	 str.Format(_T("%d"), cp.y);
	 SetDlgItemText(IDC_C2_Pixel_3Y, str);


	 cp = doc.getPixelMapValue_Project4(CameraNum, 4);
	 str.Format(_T("%d"), cp.x);
	 SetDlgItemText(IDC_C2_Pixel_4X, str);
	 str.Format(_T("%d"), cp.y);
	 SetDlgItemText(IDC_C2_Pixel_4Y, str);

	 cp = doc.getPixelMapValue_Project4(CameraNum, 5);
	 str.Format(_T("%d"), cp.x);
	 SetDlgItemText(IDC_C2_Pixel_5X, str);
	 str.Format(_T("%d"), cp.y);
	 SetDlgItemText(IDC_C2_Pixel_5Y, str);

	 cp = doc.getPixelMapValue_Project4(CameraNum, 6);
	 str.Format(_T("%d"), cp.x);
	 SetDlgItemText(IDC_C2_Pixel_6X, str);
	 str.Format(_T("%d"), cp.y);
	 SetDlgItemText(IDC_C2_Pixel_6Y, str);

	 cp = doc.getPixelMapValue_Project4(CameraNum, 7);
	 str.Format(_T("%d"), cp.x);
	 SetDlgItemText(IDC_C2_Pixel_7X, str);
	 str.Format(_T("%d"), cp.y);
	 SetDlgItemText(IDC_C2_Pixel_7Y, str);

	 cp = doc.getPixelMapValue_Project4(CameraNum, 8);
	 str.Format(_T("%d"), cp.x);
	 SetDlgItemText(IDC_C2_Pixel_8X, str);
	 str.Format(_T("%d"), cp.y);
	 SetDlgItemText(IDC_C2_Pixel_8Y, str);

	 cp = doc.getPixelMapValue_Project4(CameraNum, 9);
	 str.Format(_T("%d"), cp.x);
	 SetDlgItemText(IDC_C2_Pixel_9X, str);
	 str.Format(_T("%d"), cp.y);
	 SetDlgItemText(IDC_C2_Pixel_9Y, str);

}



void CDlg6::showPulseMap()
{
	CString str;
	CPoint cp;
	int CameraNum = 1;


	cp = doc.getPulseMapValue_Project4(CameraNum, 1);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pusle_1X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pusle_1Y, str);


	cp = doc.getPulseMapValue_Project4(CameraNum, 2);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pusle_2X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pusle_2Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 3);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pusle_3X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pusle_3Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 4);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pusle_4X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pusle_4Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 5);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pusle_5X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pusle_5Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 6);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pusle_6X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pusle_6Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 7);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pusle_7X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pusle_7Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 8);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pusle_8X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pusle_8Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 9);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C1_Pusle_9X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C1_Pusle_9Y, str);


	CameraNum = 2;


	cp = doc.getPulseMapValue_Project4(CameraNum, 1);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C2_Pusle_1X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C2_Pusle_1Y, str);


	cp = doc.getPulseMapValue_Project4(CameraNum, 2);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C2_Pusle_2X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C2_Pusle_2Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 3);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C2_Pusle_3X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C2_Pusle_3Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 4);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C2_Pusle_4X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C2_Pusle_4Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 5);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C2_Pusle_5X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C2_Pusle_5Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 6);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C2_Pusle_6X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C2_Pusle_6Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 7);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C2_Pusle_7X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C2_Pusle_7Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 8);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C2_Pusle_8X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C2_Pusle_8Y, str);

	cp = doc.getPulseMapValue_Project4(CameraNum, 9);
	str.Format(_T("%d"), cp.x);
	SetDlgItemText(IDC_C2_Pusle_9X, str);
	str.Format(_T("%d"), cp.y);
	SetDlgItemText(IDC_C2_Pusle_9Y, str);





}


void CDlg6::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	if (halconUtil.takePointsNum_Project4_C1 != 9 || halconUtil.takePointsNum_Project4_C2 != 9)
	{
		MessageBox(_T("请先提取九点坐标"));
		return;
	}

	bool c1_ok = halconUtil.mVectorToHomMat2d(&(halconUtil.savedHomMat2D_P4C1), doc.pixelMap_project4_camera1, doc.pulseMap_project4_camera1);
	bool c2_ok = halconUtil.mVectorToHomMat2d(&(halconUtil.savedHomMat2D_P4C2), doc.pixelMap_project4_camera2, doc.pulseMap_project4_camera2);

	if (!c2_ok|| !c1_ok) {
		MessageBox(_T("标定失败"));
		return;
	}
	else

	{
		MessageBox(_T("标定成功"));
	}
	








}


void CDlg6::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString columnX;
	CString rowY;

	GetDlgItem(IDC_TEST_X3)->GetWindowTextW(columnX);
	double x1_double = MfcUtil::CStringToDouble(columnX);
	GetDlgItem(IDC_TEST_Y3)->GetWindowTextW(rowY);
	double y1_double = MfcUtil::CStringToDouble(rowY);

	double worldX1 = 0;
	double worldY1 = 0;

	halconUtil.pixToWorld_motionCardAtBase(&halconUtil.savedHomMat2D_P4C1, x1_double, y1_double, worldX1, worldY1);
	CString worldX1_Str = MfcUtil::DoubleToCString(worldX1, 0);
	CString worldY1_Str = MfcUtil::DoubleToCString(worldY1, 0);
	CString result = TEXT("结果是") + worldX1_Str + ";" + worldY1_Str;
	MessageBox(result);
}


void CDlg6::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	CString columnX;
	CString rowY;

	GetDlgItem(IDC_TEST_X5)->GetWindowTextW(columnX);
	double x1_double = MfcUtil::CStringToDouble(columnX);
	GetDlgItem(IDC_TEST_Y5)->GetWindowTextW(rowY);
	double y1_double = MfcUtil::CStringToDouble(rowY);

	double worldX1 = 0;
	double worldY1 = 0;

	halconUtil.pixToWorld_motionCardAtBase(&halconUtil.savedHomMat2D_P4C2, x1_double, y1_double, worldX1, worldY1);
	CString worldX1_Str = MfcUtil::DoubleToCString(worldX1, 0);
	CString worldY1_Str = MfcUtil::DoubleToCString(worldY1, 0);
	CString result = TEXT("结果是") + worldX1_Str + ";" + worldY1_Str;
	MessageBox(result);
}


void CDlg6::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString columnX;
	CString rowY;

	GetDlgItem(IDC_TEST_X4)->GetWindowTextW(columnX);
	double x1_double = MfcUtil::CStringToDouble(columnX);
	GetDlgItem(IDC_TEST_Y4)->GetWindowTextW(rowY);
	double y1_double = MfcUtil::CStringToDouble(rowY);

	double worldX1 = 0;
	double worldY1 = 0;

	halconUtil.worldToPix_motionCardAtBase(&halconUtil.savedHomMat2D_P4C1, x1_double, y1_double, worldX1, worldY1);
	CString worldX1_Str = MfcUtil::DoubleToCString(worldX1, 0);
	CString worldY1_Str = MfcUtil::DoubleToCString(worldY1, 0);
	CString result = TEXT("结果是") + worldX1_Str + ";" + worldY1_Str;
	MessageBox(result);
}


void CDlg6::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	CString columnX;
	CString rowY;

	GetDlgItem(IDC_TEST_X6)->GetWindowTextW(columnX);
	double x1_double = MfcUtil::CStringToDouble(columnX);
	GetDlgItem(IDC_TEST_Y6)->GetWindowTextW(rowY);
	double y1_double = MfcUtil::CStringToDouble(rowY);

	double worldX1 = 0;
	double worldY1 = 0;

	halconUtil.worldToPix_motionCardAtBase(&halconUtil.savedHomMat2D_P4C2, x1_double, y1_double, worldX1, worldY1);
	CString worldX1_Str = MfcUtil::DoubleToCString(worldX1, 0);
	CString worldY1_Str = MfcUtil::DoubleToCString(worldY1, 0);
	CString result = TEXT("结果是") + worldX1_Str + ";" + worldY1_Str;
	MessageBox(result);
}


void CDlg6::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlg6::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码



}
