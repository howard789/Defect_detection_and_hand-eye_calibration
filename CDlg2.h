#pragma once
#include "ParamUtil.h"



// CDlg2 对话框


using namespace HalconCpp;

class CDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg2)

public:
	CDlg2(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc &doc, MotionControlCardUtil &motionCard, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg2 };
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
	void showPixMap();
	CWnd* pParent;

public:
	afx_msg void OnBnClickedButton1();
	void showPulseMap();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();

	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton11();
	CString m_SelectFile;
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedTakenine2();
};



