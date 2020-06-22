#pragma once
#include "ParamUtil.h"

// CDlg6 对话框

class CDlg6 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg6)

public:
	CDlg6(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc &doc, MotionControlCardUtil &motionCard, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg6();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg6 };
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
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCheck36();
	afx_msg
		void SaveDefaultNinePointPulseLocation();
	CPoint getCurrentPulsePosition();
	afx_msg void OnBnClickedC1p1();
	afx_msg void OnBnClickedC1p2();
	afx_msg void OnBnClickedC1p3();
	afx_msg void OnBnClickedC1p4();
	afx_msg void OnBnClickedC1p5();
	afx_msg void OnBnClickedC1p6();
	afx_msg void OnBnClickedC1p7();
	afx_msg void OnBnClickedC1p8();
	afx_msg void OnBnClickedC1p9();
	afx_msg void OnBnClickedC2p1();
	afx_msg void OnBnClickedC2p2();
	afx_msg void OnBnClickedC2p3();
	afx_msg void OnBnClickedC2p4();
	afx_msg void OnBnClickedC2p5();
	afx_msg void OnBnClickedC2p6();
	afx_msg void OnBnClickedC2p7();
	afx_msg void OnBnClickedC2p8();
	afx_msg void OnBnClickedC2p9();
	afx_msg void OnBnClickedButton33();
	afx_msg void OnBnClickedButton34();
	void Calirate(int CameraNum);
	void showPixMap();
	void showPulseMap();
	afx_msg void OnBnClickedButton35();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
