#pragma once
#include "ParamUtil.h"
#include <map>


// LeadShine 对话框



class CDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg1)

public:

	CDlg1(ParamUtil &paramUtil,HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc &doc, MotionControlCardUtil &motionCard, CWnd* pParent = nullptr);   // 标准构造函数


	virtual ~CDlg1();

// 对话框数据

	enum { IDD = IDD_Dlg1 };


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()


//
public:
	void SaveNinePointPulseLocation(int pointNum);

	void SaveDefaultNinePointPulseLocation();

	void setZeroNinePointPulseLocation();

	void myOnInitDialog();

private:
	ParamUtil &paramUtil;
	CameraUtil &cameraUtil;
	MotionControlCardUtil &motionCard;
	Doc &doc;
	HalconUtil &halconUtil;
	void myOnCreate();

public:

	afx_msg void OnBnClickedLocation1();
	afx_msg void OnBnClickedLocation2();
	afx_msg void OnBnClickedLocation3();
	afx_msg void OnBnClickedLocation4();
	afx_msg void OnBnClickedLocation5();
	afx_msg void OnBnClickedLocation6();
	afx_msg void OnBnClickedLocation7();
	afx_msg void OnBnClickedLocation8();
	afx_msg void OnBnClickedLocation9();
	afx_msg void OnBnClickedSetZero();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
	// x轴的位置	// x轴的位置	// x轴的位置	// x轴的位置
	int position_x;
	// y轴的位置
	int position_y;
	// z的位置
	int position_z;
	// u轴位置
	int position_u;
	// 状态
	CString status;
	

	// 起始速度
	double m_nSpeedst;

	// 运行速度
	double m_nSpeedmax;
	// 加速时间
	double m_fAccel;


	int axisHome;//单轴回零

    MyRealButton *m_yUp;
	MyRealButton *m_yDown;
	MyRealButton *m_xDown;
	MyRealButton *m_xUp;
	MyRealButton *m_zUp;
	MyRealButton *m_zDown;
	MyRealButton *m_uClock;
	MyRealButton *m_uUnclock;

	afx_msg void OnBnClickedS();
	afx_msg void OnBnClickedT();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioHighspeed();
	afx_msg void OnBnClickedRadioLowspeed();
	afx_msg void OnBnClickedRadioHomeHighspeed();
	afx_msg void OnBnClickedRadioHomeLowspeed();
	afx_msg void OnBnClickedRadioHomePositive();
	afx_msg void OnBnClickedRadioHomeNegative();
	
	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	
	afx_msg void OnBnClickedBackBasePoint();
	afx_msg void OnBnClickedBackBasePoint2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedBackBasePoint3();


	afx_msg void OnBnClickedCheckUsedefault();
	afx_msg void OnBnClickedZUp2();
	afx_msg void OnBnClickedZDown2();
	afx_msg void OnBnClickedZUp3();
	afx_msg void OnBnClickedZUp4();
	afx_msg void OnBnClickedLocation10();
	afx_msg void OnBnClickedLocation11();
	afx_msg void OnBnClickedLocation12();
	afx_msg void OnBnClickedLocation13();
	afx_msg void OnBnClickedLocation14();
	afx_msg void OnBnClickedLocation15();
	afx_msg void OnBnClickedLocation16();
	afx_msg void OnBnClickedLocation17();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	int testCircleWarehouseNum;
	int testSquareWarehouseNum;
};
