#pragma once
#include "ParamUtil.h"
#include "../include/mvs/MvCameraControl.h"

// CDlg8 对话框  Mvs SDK

#pragma comment(lib,"../lib/x64/MvCameraControl.lib")

#define STATUS_OK               0
#define STATUS_ERROR            -1
/*函数返回码定义*/
typedef int Status;


using namespace HalconCpp;

class CDlg8 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg8)

public:
	CDlg8(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc &doc, MotionControlCardUtil &motionCard, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg8();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg8 };
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
	CComboBox m_ctrlDeviceCombo;
	afx_msg void OnBnClickedSoftwareTriggerCheck();
	afx_msg void OnBnClickedOpenButton();
};
