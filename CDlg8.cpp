// CDlg8.cpp: 实现文件
//

#include "stdafx.h"
#include "ProjectOne.h"
#include "CDlg8.h"
#include "afxdialogex.h"


// CDlg8 对话框

IMPLEMENT_DYNAMIC(CDlg8, CDialogEx)

CDlg8::CDlg8(ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc & doc, MotionControlCardUtil & motionCard, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LEADSHINE, pParent), doc(doc), motionCard(motionCard), cameraUtil(cameraUtil), halconUtil(halconUtil), paramUtil(paramUtil)


{

}

CDlg8::~CDlg8()
{
}

void CDlg8::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DEVICE_COMBO, m_ctrlDeviceCombo);
}


BEGIN_MESSAGE_MAP(CDlg8, CDialogEx)
	ON_BN_CLICKED(IDC_SOFTWARE_TRIGGER_CHECK, &CDlg8::OnBnClickedSoftwareTriggerCheck)
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CDlg8::OnBnClickedOpenButton)
END_MESSAGE_MAP()


// CDlg8 消息处理程序


void CDlg8::OnBnClickedSoftwareTriggerCheck()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlg8::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
}
