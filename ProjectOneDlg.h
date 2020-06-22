
// ProjectOneDlg.h: 头文件
//

#pragma once
#include "CameraUtil.h"
#include "Doc.h"
#include <map>
#include <vector>
#include "CameraUtil.h"
#include "HalconUtil.h"
#include "MotionControlCardUtil.h"
#include "CDlg1.h"
#include "CDlg2.h"
#include "CDlg3.h"
#include "CDlg4.h"
#include "CDlg5.h"
#include "CDlg6.h"
#include "CDlg7.h"
#include "CDlg8.h"
#include "CDlg9.h"
#include "CDlg10.h"
#include "CDlg11.h"

#include "Doc.h"
#include "HalconTemplateUtil.h"
#include "HalconMotionCardUnion.h"
#include "MyCamera.h"

#define STATUS_ERROR            -1
#define IMAGE_NAME_LEN          64

using namespace HalconCpp;


// CProjectOneDlg 对话框
class CProjectOneDlg : public CDialogEx
{
// 构造
public:
	CProjectOneDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTONE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	void myOnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();



//Tab
private:
    CDlg3 *m_page3;
	CDialog *pDialog[255];  //用来保存对话框对象指针
    
	CDlg1 *m_page1;
	CDlg2 *m_page2;
	
	//CDlg4 *m_page4;
	CDlg5 *m_page5;
	CDlg6 *m_page6;
	CDlg7 *m_page7;
	CDlg8 *m_page8;
	CDlg9 *m_page9;
	CDlg10 *m_page10;
	CDlg11 *m_page11;


	int m_CurSelTab;
	

	void onTabInit();
	void ResizeWindow();
	void myInitDlg();

	void myStartPictureControl();


public:

	CameraUtil cameraUtil;
	MotionControlCardUtil motionCard;
	HalconUtil halconUtil;
	Doc doc;
	ParamUtil paramUtil;
	MfcUtil mfcUtil;
	HalconTemplateUtil templateUtil;
	HalconMotionCardUnion halconMotionCardUnion;
	dmc1380Util dmcUtil;

   

	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int showMode;////摄像机显示模式  1原图 2 二维码 3 blob 4 模板 5 xld

	//摄像头相关
	HTuple  hv_WindowHandle;
	HObject  ho_Image;
	HObject  ho_Image2; //2号机
	HObject  ho_NG; //2号机
	HObject  ho_OK; //2号机
	HObject ho_DumpImg; //
	HTuple HWindowID;//Picture Control 控件
	HTuple HWindowID2;//Picture Control 控件
	HTuple m_HWindowID; //第一个显示屏
	HTuple m_HWindowID2;//第2个显示屏


	CWnd * pWnd;
	HTuple  hv_AcqHandle;//采集句柄
	bool StartImageState;//是否采集
	bool StartImageState2;//2号机是否采集
	bool StartImageStateSecond;//2号机是否采集
	static UINT StartCameraThread(LPVOID pParam);

	//新的采集线程

	bool takePic;//拍照
	bool takePic2;//2号机拍照
	bool saveBlobData;//保存blob定位资料



	afx_msg void OnBnClickedCamera();

	static UINT StartMvsCameraThread(LPVOID pParam);

	UINT runMvsCamera(LPVOID pParam);
	

	static UINT StartCameraThreadSecond(LPVOID pParam);


	afx_msg void OnBnClickedTakepic();
	afx_msg void OnBnClickedStopcamera();

	void MvsStopGrabbing();

	
	CString m_info;

	LRESULT OnUpdateData(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();

	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();

	double m_CURRENTSPEED;
	afx_msg void OnBnClickedRadio12();

	UINT runSecondCamera(LPVOID pParam);
	
	afx_msg void OnBnClickedRadio16();
	afx_msg void OnBnClickedRadio17();
	afx_msg void OnBnClickedRadio18();
	UINT runFirstCamera(LPVOID pParam);
	afx_msg void OnBnClickedRotate180();
	afx_msg void OnBnClickedRadio11();
	afx_msg void OnBnClickedRadio13();
	afx_msg void OnBnClickedRadio15();
	afx_msg void OnBnClickedRadio19();
	afx_msg void OnBnClickedRadio20();
	afx_msg void OnBnClickedRotatesecond();
	afx_msg void OnBnClickedButton2();
	bool ShowPic2(CString filePaTH, int ID);
	
	bool updateNGAndOK();
	afx_msg void OnBnClickedCamera2();
	afx_msg void OnBnClickedTakepic2();
	afx_msg void OnBnClickedStopcamera2();

	//mlp
	bool lucked;
	int previousPicCount_ng;
	int previousPicCount_ok;


	afx_msg void OnBnClickedRadio14();


	//mvs相机
	CButton m_ctrlOpenButton;                   // ch:打开设备 | en:Open device
	CButton m_ctrlCloseButton;                  // ch:关闭设备 | en:Close device
	/*ch:参数设置获取 | en:Get Parameter Setting*/
	CEdit   m_ctrlExposureEdit;                 // ch:曝光时间 | en:Exposure Time
	double  m_dExposureEdit;
	CEdit   m_ctrlGainEdit;                     // ch:增益 | en:Gain
	double  m_dGainEdit;
	CEdit   m_ctrlFrameRateEdit;                // ch:帧率 | en:Frame Rate
	double  m_dFrameRateEdit;
	CButton m_ctrlGetParameterButton;           // ch:获取参数 | en:Get parameter
	CButton m_ctrlSetParameterButton;           // ch:设置参数 | en:Set parameter
	   /*ch:设备显示下拉框 | en:Device display drop-down box*/
	CComboBox m_ctrlDeviceCombo;                // ch:枚举到的设备 | en:Enumerated device
	int      m_nDeviceCombo;

	/*ch:内部函数 | en:Built-in function*/

private:
	/*ch:最开始时的窗口初始化 | en:Window initialization*/
	int DisplayWindowInitial(void);          // ch:显示框初始化,最开始的初始化
											// en:Display window initialization


	void ShowErrorMsg(CString csMessage, int nErrorNum);


	/*ch:初始化相机操作 | en:Initialization*/
	int OpenDevice(void);                    // ch:打开相机 | en:Open Device

	/*ch:设置、获取参数操作 | en:Set and get parameters operation*/
	int GetExposureTime(void);               // ch:设置曝光时间 | en:Set Exposure Time
	int SetExposureTime(void);
	int GetGain(void);                       // ch:设置增益 | en:Set Gain
	int SetGain(void);
	int GetFrameRate(void);                  // ch:设置帧率 | en:Set Frame Rate
	int SetFrameRate(void);

	/*ch:关闭销毁操作 | en:Close and deatroy operation*/
	int CloseDevice(void);                   // ch:关闭设备 | en:Close Device

	

	int ImgMomeCopy(LPVOID pParam);

	int genOnTimeImg(HObject  *m_ho_Image, byte *m_pImageData, unsigned int nDataLen, MV_FRAME_OUT_INFO_EX stImageInfo);

	void NewImage(HObject * newImg, unsigned char * image, HTuple wide, HTuple hight);

/*ch:自定义变量 | en:User Defined Variable*/
private:
	/*ch:状态 | en:Status*/
	BOOL  m_bOpenDevice;                        // ch:是否打开设备 | en:Whether to open device
	BOOL  m_bStartGrabbing;                     // ch:是否开始抓图 | en:Whether to start grabbing
	int   m_nTriggerMode;                       // ch:触发模式 | en:Trigger Mode
	int   m_nTriggerSource;                     // ch:触发源 | en:Trigger Source
	MV_SAVE_IAMGE_TYPE   m_nSaveImageType;      // ch:保存图像格式 | en:Save Image Type

	/*ch:设备相关 | en:Device Related*/
	CMyCamera*      m_pcMyCamera;               // ch:CMyCamera封装了常用接口 | en:CMyCamera packed commonly used interface
	HWND  m_hwndDisplay;                        // ch:显示句柄 | en:Display Handle
	MV_CC_DEVICE_INFO_LIST m_stDevList;         // ch:设备信息列表结构体变量，用来存储设备列表
												//en:Device information list structure variable used to store device list

	unsigned char*  m_pBufForDriver;            // ch:用于从驱动获取图像的缓存 | en:Buffer to get image from driver
	unsigned int    m_nBufSizeForDriver;


	/*ch:按下控件操作 | en:Control operation*/
public:
	/*ch:初始化 | en:Initialization*/
	afx_msg void OnBnClickedEnumButton();               // ch:查找设备 | en:Find Devices
	afx_msg void OnBnClickedOpenButton();               // ch:打开设备 | en:Open Devices
	afx_msg void OnBnClickedCloseButton();              // ch:关闭设备 | en:Close Devices

	/*ch:参数设置获取 | en:Parameters Get and Set*/
	afx_msg void OnBnClickedGetParameterButton();       // ch:获取参数 | en:Get Parameter
	afx_msg void OnBnClickedSetParameterButton();       // ch:设置参数 | en:Exit from upper right corner

};


