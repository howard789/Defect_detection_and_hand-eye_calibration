#pragma once
#include "ParamUtil.h"

// CDlg5 对话框

class CDlg5 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg5)

public:
	CDlg5(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc &doc, MotionControlCardUtil &motionCard, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg5();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	ParamUtil &paramUtil;
	MotionControlCardUtil &motionCard;
	Doc &doc;
	CameraUtil &cameraUtil;
	HalconUtil &halconUtil;

public:
	virtual BOOL OnInitDialog();
	void myOnInitDialog();


	afx_msg void OnPaint();
	void setPictureColorGreen(int mfcId, CStatic& m_static);

   //0 green 1 red

	CStatic m_STATUS_X1;//EL+
	//检测x轴正限位
	//int r1 = Dmc2410.d2410_axis_io_status(0);
	//int res1 = r1 >> 12 & 1;
	

	CStatic m_STATUS_X2;//EL-
	//检测x轴的负限位
	//int r2 = Dmc2410.d2410_axis_io_status(0);
	//int res2 = r2 >> 13 & 1;




	CStatic m_STATUS_X3;//EZ




	CStatic m_STATUS_X4;//ORG
	//检测x轴原点
	//int r = Dmc2410.d2410_axis_io_status(0);
	//int res = r >> 14 & 1;



	CStatic m_STATUS_X5;//PA
	CStatic m_STATUS_X6;//PB



	CStatic m_STATUS_X7;//ALM
	//检测x轴伺服报警信号
	//int r3 = Dmc2410.d2410_axis_io_status(0);
	//int res3 = r3 >> 11 & 1;



	CStatic m_STATUS_X8;//LTC
	CStatic m_STATUS_X9;//EMG 紧急
	//uint res14 = Dmc2410.d2410_get_rsts(0);
	//uint res15 = res14 >> 7 & 1;



	CStatic m_STATUS_Y1;//EL+
	//y轴的正限位
	//int r5 = Dmc2410.d2410_axis_io_status(1);
	//int res5 = r5 >> 12 & 1;



	CStatic m_STATUS_Y2;//EL-
	//y轴的负限位
	//int r6 = Dmc2410.d2410_axis_io_status(1);

	//int res6 = r6 >> 13 & 1;



	CStatic m_STATUS_Y3;//EZ



	CStatic m_STATUS_Y4;//ORG
	 //检测y轴的原点
	//int r4 = Dmc2410.d2410_axis_io_status(1);
	//int res4 = r4 >> 14 & 1;



	CStatic m_STATUS_Y5;//PA
	CStatic m_STATUS_Y6;//PB
	CStatic m_STATUS_Y7;//ALM
	//检测y轴伺服报警信号
	//int r7 = Dmc2410.d2410_axis_io_status(0);

	//int res7 = r7 >> 11 & 1;



	CStatic m_STATUS_Y8;//LTC
	CStatic m_STATUS_Z1;//EL+
	 //z轴的正限位
	//int r9 = Dmc2410.d2410_axis_io_status(2);

	//int res9 = r9 >> 12 & 1;


	CStatic m_STATUS_Z2;//EL-
	//z轴的负限位
	//int r10 = Dmc2410.d2410_axis_io_status(2);

	//int res10 = r10 >> 13 & 1;

		

	CStatic m_STATUS_Z3;//EZ
	CStatic m_STATUS_Z4;//ORG
	 //检测z轴的原点
	//int r8 = Dmc2410.d2410_axis_io_status(2);

	//int res8 = r8 >> 14 & 1;



	CStatic m_STATUS_Z5;//PA
	CStatic m_STATUS_Z6;//PB
	CStatic m_STATUS_Z7;//ALM
	//检测伺服报警信号
	//int r11 = Dmc2410.d2410_axis_io_status(2);

	//int res11 = r11 >> 11 & 1;


	CStatic m_STATUS_Z8;//LTC
	CStatic m_STATUS_U1;//EL+
	CStatic m_STATUS_U2;//EL-
	CStatic m_STATUS_U3;//EZ
	CStatic m_STATUS_U4;//ORG
	CStatic m_STATUS_U5;//PA
	CStatic m_STATUS_U6;//PB
	CStatic m_STATUS_U7;//ALM
	CStatic m_STATUS_U8;//LTC


	CStatic m_OUT1;
	//第1位 急停
	//int res12 = Dmc2410.d2410_read_inbit(0, 1);



	CStatic m_OUT2;
	CStatic m_OUT3;
	CStatic m_OUT4;
	CStatic m_OUT5;
	CStatic m_OUT6;
	CStatic m_OUT7;
	CStatic m_OUT8;
	CStatic m_OUT9;
	CStatic m_OUT10;
	CStatic m_OUT11;
	CStatic m_OUT12;
	CStatic m_OUT13;
	CStatic m_OUT14;
	CStatic m_OUT15;
	CStatic m_OUT16;
	CStatic m_OUT17;
	CStatic m_OUT18;
	CStatic m_OUT19;
	CStatic m_OUT20;
	CStatic m_OUT21;
	CStatic m_OUT22;
	CStatic m_OUT23;
	CStatic m_OUT24;
	CStatic m_OUT25;
	CStatic m_OUT26;
	CStatic m_OUT27;
	CStatic m_OUT28;
	CStatic m_OUT29;
	//29位 急停
	//int res13 = Dmc2410.d2410_read_inbit(0, 29);


	CStatic m_OUT30;
	CStatic m_OUT31;
	CStatic m_OUT32;



	afx_msg void OnBnClickedCheck1();


private:
	MfcUtil mfcUtil;
	bool check_m_STATUS_X1();
	bool check_m_STATUS_X2();
	//bool check_m_STATUS_X3();
	bool check_m_STATUS_X4();
	//bool check_m_STATUS_X5();
	//bool check_m_STATUS_X6();
	bool check_m_STATUS_X7();
	//bool check_m_STATUS_X8();
	bool check_m_STATUS_X9();
	bool check_m_STATUS_Y1();
	bool check_m_STATUS_Y2();
	//bool check_m_STATUS_Y3();
	bool check_m_STATUS_Y4();
	//bool check_m_STATUS_Y5();
	//bool check_m_STATUS_Y6();
	bool check_m_STATUS_Y7();
	//bool check_m_STATUS_Y8();
	bool check_m_STATUS_Z1();
	bool check_m_STATUS_Z2();
	//bool check_m_STATUS_Z3();
	bool check_m_STATUS_Z4();
	//bool check_m_STATUS_Z5();
	//bool check_m_STATUS_Z6();
	bool check_m_STATUS_Z7();
	//bool check_m_STATUS_Z8();
	//bool check_m_STATUS_U1();
	//bool check_m_STATUS_U2();
	//bool check_m_STATUS_U3();
	//bool check_m_STATUS_U4();
	//bool check_m_STATUS_U5();
	//bool check_m_STATUS_U6();
	//bool check_m_STATUS_U7();
	//bool check_m_STATUS_U8();


	bool checkPositveLimit(int axis);//正限位
	bool checkNegativeLimit(int axis);//负限位
	bool checkORG(int axis);//原点
	bool checkALM(int axis);
	bool checkEMG();
	bool checkOut();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void checkIOStatus();
	void writeOutBitLow(int no);
	
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck9();
};
