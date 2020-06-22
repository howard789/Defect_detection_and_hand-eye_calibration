// CDlg2.cpp: 实现文件
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "CDlg2.h"
#include "afxdialogex.h"


// CDlg2 对话框

IMPLEMENT_DYNAMIC(CDlg2, CDialogEx)

CDlg2::CDlg2(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc & doc, MotionControlCardUtil & motionCard, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LEADSHINE, pParent), doc(doc), motionCard(motionCard), cameraUtil(cameraUtil), halconUtil(halconUtil), paramUtil(paramUtil), pParent(pParent)
	, m_SelectFile(_T(""))
{
	

}

CDlg2::~CDlg2()
{
}


void CDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_SelectFile);
}


BEGIN_MESSAGE_MAP(CDlg2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg2::OnBnClickedButton1)
	ON_WM_TIMER()

	ON_BN_CLICKED(IDC_BUTTON5, &CDlg2::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg2::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlg2::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlg2::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlg2::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlg2::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON10, &CDlg2::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlg2::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON11, &CDlg2::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CDlg2::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_TAKENINE2, &CDlg2::OnBnClickedTakenine2)
END_MESSAGE_MAP()


// CDlg2 消息处理程序



//提取九点坐标
void CDlg2::OnBnClickedButton1()

{

	bool result=halconUtil.doTakeNinePointsCenter(halconUtil.hv_RowTmp, halconUtil.hv_ColumnTmp, &doc);
	if(result==false)
		MessageBox(_T("提取9点失败"));

	int i = halconUtil.takePointsNum;

	string iSt = MfcUtil::IntToString(i, 10);

	if (halconUtil.takePointsNum == 9) {
		//显示pixMap
		showPixMap();
		//showPulseMap();
		MessageBox(_T("提取9点成功"));
	}
	else {
		string s = "points got not 9,but " + iSt + " .";


		MessageBox(MfcUtil::stringToLPCWSTR(s));
		
	}



	return;









#if 0





	if (paramUtil.showModeSynWithMainWin != 3) {
		MessageBox(_T("请调整显示模式"));
	}



#ifdef _TestOffLine
	HTuple fileName = paramUtil.getCalibration_Test_HTuple(1);

#else
	//HTuple fileName = paramUtil.getCalibrationFilePath_HTuple();
#endif // _TestOffLine

	

	HObject  ho_Image, ho_ImageIlluminate, ho_GrayImage;
	HObject  ho_Regions, ho_ConnectedRegions, ho_SelectedRegions;
	HObject  ho_RegionFillUp;

	HTuple  hv_Width, hv_Height;
	HTuple  hv_Area, hv_Row, hv_Column, hv_I, hv_y, hv_x, hv_mes;

	try {
		//ReadImage(&ho_Image, fileName);
		//Illuminate(ho_Image, &ho_ImageIlluminate, 101, 101, 0.7);
		ho_Image = halconUtil.calibrationImage;
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


	halconUtil.doTakeNinePointsCenter(hv_Row, hv_Column, &doc);

	int i = halconUtil.takePointsNum;
	
	string iSt = MfcUtil::IntToString(i,10);

	if (halconUtil.takePointsNum==9) {
		//显示pixMap
		showPixMap();
		showPulseMap();
		MessageBox(_T("提取9点成功"));
	}
	else {
		string s = "points got not 9,but "+iSt+" .";
		

		MessageBox(MfcUtil::stringToLPCWSTR(s));
		return;
	}
		
	//halconUtil.resetStatus();
#endif
}


void CDlg2::showPixMap()
{
	

	CString str;
	int x = doc.getPixelMapValue_X(1);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PIX_X_1, str);

	x = doc.getPixelMapValue_X(2);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PIX_X_2, str);

	x = doc.getPixelMapValue_X(3);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PIX_X_3, str);

	x = doc.getPixelMapValue_X(4);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PIX_X_4, str);

	x = doc.getPixelMapValue_X(5);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PIX_X_5, str);

	x = doc.getPixelMapValue_X(6);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PIX_X_6, str);

	x = doc.getPixelMapValue_X(7);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PIX_X_7, str);

	x = doc.getPixelMapValue_X(8);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PIX_X_8, str);

	x = doc.getPixelMapValue_X(9);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PIX_X_9, str);


	int y = doc.getPixelMapValue_Y(1);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PIX_Y_1, str);

	 y = doc.getPixelMapValue_Y(2);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PIX_Y_2, str);

	 y = doc.getPixelMapValue_Y(3);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PIX_Y_3, str);

	 y = doc.getPixelMapValue_Y(4);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PIX_Y_4, str);

	 y = doc.getPixelMapValue_Y(5);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PIX_Y_5, str);

	 y = doc.getPixelMapValue_Y(6);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PIX_Y_6, str);

	 y = doc.getPixelMapValue_Y(7);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PIX_Y_7, str);

	 y = doc.getPixelMapValue_Y(8);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PIX_Y_8, str);

	 y = doc.getPixelMapValue_Y(9);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PIX_Y_9, str);

}



void CDlg2::showPulseMap() 
{
	CString str;
	int x = doc.getPulseMapValue_X(1);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PUL_X_1, str);

	x = doc.getPulseMapValue_X(2);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PUL_X_2, str);

	x = doc.getPulseMapValue_X(3);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PUL_X_3, str);

	x = doc.getPulseMapValue_X(4);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PUL_X_4, str);

	x = doc.getPulseMapValue_X(5);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PUL_X_5, str);

	x = doc.getPulseMapValue_X(6);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PUL_X_6, str);

	x = doc.getPulseMapValue_X(7);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PUL_X_7, str);

	x = doc.getPulseMapValue_X(8);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PUL_X_8, str);

	x = doc.getPulseMapValue_X(9);
	str.Format(_T("%d"), x);
	SetDlgItemText(IDC_PUL_X_9, str);


	int y = doc.getPulseMapValue_Y(1);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PUL_Y_1, str);

	y = doc.getPulseMapValue_Y(2);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PUL_Y_2, str);

	y = doc.getPulseMapValue_Y(3);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PUL_Y_3, str);

	y = doc.getPulseMapValue_Y(4);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PUL_Y_4, str);

	y = doc.getPulseMapValue_Y(5);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PUL_Y_5, str);

	y = doc.getPulseMapValue_Y(6);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PUL_Y_6, str);

	y = doc.getPulseMapValue_Y(7);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PUL_Y_7, str);

	y = doc.getPulseMapValue_Y(8);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PUL_Y_8, str);

	y = doc.getPulseMapValue_Y(9);
	str.Format(_T("%d"), y);
	SetDlgItemText(IDC_PUL_Y_9, str);




}


void CDlg2::OnTimer(UINT_PTR nIDEvent)
{
	//showPixMap();
	//showPulseMap();
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
}



BOOL CDlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetTimer(1, 1000, NULL);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlg2::OnBnClickedButton5()
{
	if(halconUtil.takePointsNum!=9)
		MessageBox(_T("请先提取九点坐标"));


   bool result=halconUtil.mVectorToHomMat2d(&(halconUtil.savedHomMat2D),doc.pixelMap,doc.pulseMap);
	
   
	
	if (result) {
		paramUtil.completeCalibration = true;
		MessageBox(_T("标定成功"));

	}
	else
	{
		MessageBox(_T("标定失败"));
	}

}


void CDlg2::OnBnClickedButton2()
{


	bool result=halconUtil.writeHomMat2D(&(halconUtil.savedHomMat2D),"D:/tmp/currentMatFile.mat");
	if (result) {
		MessageBox(_T("保存成功"));
	}else{
		MessageBox(_T("保存失败"));
	}
}


void CDlg2::OnBnClickedButton6()
{

		// Local iconic variables

		// Local control variables
		HTuple  hv_r, hv_c, hv_r1, hv_c1, hv_row, hv_col;
		HTuple  hv_HomMat2D, hv_Qx, hv_Qy, hv_HomMat2DInvert, hv_Px;
		HTuple  hv_Py, hv_HomMat2D_1, hv_SerializedItemHandle, hv_FileHandle;
		HTuple  hv_HomMat2D_2;

		//ͼ������
		hv_r.Clear();
		hv_r[0] = 431;
		hv_r[1] = 355;
		hv_r[2] = 507;
		hv_r[3] = 53;
		hv_r[4] = 507;
		hv_c.Clear();
		hv_c[0] = 505;
		hv_c[1] = 543;
		hv_c[2] = 316;
		hv_c[3] = 127;
		hv_c[4] = 883;
		//�������꣨�������������꣩
		hv_r1.Clear();
		hv_r1[0] = 0;
		hv_r1[1] = 2.0;
		hv_r1[2] = -2.0;
		hv_r1[3] = 10;
		hv_r1[4] = -2.0;
		hv_c1.Clear();
		hv_c1[0] = 0;
		hv_c1[1] = 1.0;
		hv_c1[2] = -5.0;
		hv_c1[3] = -10;
		hv_c1[4] = 10;

		hv_row = 670;
		hv_col = 789;
		VectorToHomMat2d(hv_r, hv_c, hv_r1, hv_c1, &hv_HomMat2D);

		//AffineTransPoint2d(hv_HomMat2D, hv_row, hv_col, &hv_Qx, &hv_Qy);

		HomMat2dInvert(hv_HomMat2D, &hv_HomMat2DInvert);
		AffineTransPoint2d(hv_HomMat2DInvert, hv_Qx, hv_Qy, &hv_Px, &hv_Py);




		//hom_mat2d_identity (HomMat2DIdentity)
		//hom_mat2d_rotate (HomMat2DIdentity, -0.3, 256, 256, HomMat2D_1)
		hv_HomMat2D_1 = hv_HomMat2D;

		SerializeHomMat2d(hv_HomMat2D_1, &hv_SerializedItemHandle);
		OpenFile("D:/tmp/1.mat", "output_binary", &hv_FileHandle);
		FwriteSerializedItem(hv_FileHandle, hv_SerializedItemHandle);
		CloseFile(hv_FileHandle);



		OpenFile("D:/tmp/1.mat", "input_binary", &hv_FileHandle);
		FreadSerializedItem(hv_FileHandle, &hv_SerializedItemHandle);
		DeserializeHomMat2d(hv_SerializedItemHandle, &hv_HomMat2D_2);
		CloseFile(hv_FileHandle);
	
}


void CDlg2::OnBnClickedButton7()
{
	//HTuple *hv_HomMat2D=new HTuple;
	//HTuple *hv_HomMat2DInvert = new HTuple;
	//halconUtil.readHomMat2D(hv_HomMat2D, hv_HomMat2DInvert, "D:/tmp/currentMatFile.mat");
	CString columnX;
	CString rowY;

	GetDlgItem(IDC_TEST_X1)->GetWindowTextW(columnX);
	double x1_double = MfcUtil::CStringToDouble(columnX);
	GetDlgItem(IDC_TEST_Y1)->GetWindowTextW(rowY);
	double y1_double = MfcUtil::CStringToDouble(rowY);

	double worldX1=0;
	double worldY1=0;
	



	halconUtil.pixToWorld_motionCardAtBase(&halconUtil.savedHomMat2D, x1_double, y1_double, worldX1, worldY1);
	CString worldX1_Str = MfcUtil::DoubleToCString(worldX1,0);
	CString worldY1_Str = MfcUtil::DoubleToCString(worldY1,0);
	CString result = TEXT("结果是")+worldX1_Str+";"+ worldY1_Str;
	MessageBox(result);



}



//运动到拍照位
void CDlg2::OnBnClickedButton4()
{
	//motionCard.moveToBasePointCS();
	motionCard.moveToBaseCPointAll();
	
}


void CDlg2::OnBnClickedButton8()
{
	CString columnX;
	CString rowY;

	GetDlgItem(IDC_TEST_X2)->GetWindowTextW(columnX);
	double x1_double = MfcUtil::CStringToDouble(columnX);
	GetDlgItem(IDC_TEST_Y2)->GetWindowTextW(rowY);
	double y1_double = MfcUtil::CStringToDouble(rowY);

	double worldX1 = 0;
	double worldY1 = 0;

	halconUtil.worldToPix_motionCardAtBase(&halconUtil.savedHomMat2D, x1_double, y1_double, worldX1, worldY1);
	CString worldX1_Str = MfcUtil::DoubleToCString(worldX1,0);
	CString worldY1_Str = MfcUtil::DoubleToCString(worldY1,0);
	CString result = TEXT("结果是") + worldX1_Str + ";" + worldY1_Str;
	MessageBox(result);
}


void CDlg2::OnBnClickedButton10()
{
	if (paramUtil.showModeSynWithMainWin != 3) {
		MessageBox(_T("请调整显示模式"));
	}
	paramUtil.isTakeCalibrationPic = true;

}


void CDlg2::OnBnClickedButton3()
{
	map<int,CPoint> pm=doc.pixelMap;
	map<int,CPoint> pm2=doc.pulseMap;
	HTuple hv_r, hv_c, hv_r1, hv_c1;
	double tmp;
	/*tmp = doc.getPixelMapValue_X(1);
	hv_c[0] = tmp;
	tmp = doc.getPixelMapValue_X(2);
	hv_c[1] = tmp;
	tmp = doc.getPixelMapValue_X(3);
	hv_c[2] = tmp;
	tmp = doc.getPixelMapValue_X(4);
	hv_c[3] = tmp;
	
	tmp = doc.getPixelMapValue_Y(1);
	hv_r[0] = tmp;
	tmp = doc.getPixelMapValue_Y(2);
	hv_r[1] = tmp;
	tmp = doc.getPixelMapValue_Y(3);
	hv_r[2] = tmp;


	tmp = doc.getPulseMapValue_X(1);
	hv_c1[0] = tmp;
	tmp = doc.getPulseMapValue_X(2);
	hv_c1[1] = tmp;
	tmp = doc.getPulseMapValue_X(3);
	hv_c1[2] = tmp;

	tmp = doc.getPulseMapValue_Y(1);
	hv_r1[0] = tmp;
	tmp = doc.getPulseMapValue_Y(2);
	hv_r1[1] = tmp;
	tmp = doc.getPulseMapValue_Y(3);
	hv_r1[2] = tmp;*/


	for (int i = 0; i < 3; i++) {
		hv_c[i] = doc.getPixelMapValue_X(i+1);
		hv_r[i] = doc.getPixelMapValue_Y(i + 1);
		hv_c1[i] = doc.getPulseMapValue_X(i + 1);
		hv_r1[i] = doc.getPulseMapValue_Y(i + 1);
	}


	HTuple col_x = 548;
	HTuple row_y = 366;

	VectorToHomMat2d(hv_r, hv_c, hv_r1, hv_c1, &halconUtil.savedHomMat2D);
	
	
	HTuple Col_hv_Qx;//90809
	HTuple Row_hv_Qy;//98911


	AffineTransPoint2d(halconUtil.savedHomMat2D, row_y, col_x, &Row_hv_Qy, &Col_hv_Qx);
	
	double x = Col_hv_Qx.D();
	double y = Row_hv_Qy.D();
	
	CString result = TEXT("结果是x") + MfcUtil::DoubleToCString(x,0) + "  y;" + MfcUtil::DoubleToCString(y,0);
	MessageBox(result);
}


void CDlg2::OnBnClickedButton11()
{
	CString cs = TEXT("D:\tmp");
	MfcUtil::openFileBrowser(cs, this, IDC_EDIT2);

}


void CDlg2::OnBnClickedButton12()
{

	CString rString;
	GetDlgItemTextW(IDC_EDIT2, rString);
	bool result=halconUtil.readHomMat2D(&halconUtil.savedHomMat2D, MfcUtil::CStringToString(rString));
	if (result)
		MessageBox(_T("读取成功"));
	else
		MessageBox(_T("读取失败"));
}


void CDlg2::OnBnClickedTakenine2()
{
	// TODO: 在此添加控件通知处理程序代码
	showPixMap();
	showPulseMap();
	//doc.Conveyor_setPulseMapFixed();
	//paramUtil.conveyorTakeNine = true;
}
