#pragma once
#include "ParamUtil.h"

// CDlg3 对话框

class CDlg3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg3)

public:
	CDlg3(HalconMotionCardUnion &motionWarehouse,ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc &doc, MotionControlCardUtil &motionCard, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg3 };
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
	HalconMotionCardUnion &halconMotionCardUnion;

	int mode;// 0:blob 1:template 2:xld
	int pointLocation;//0: basePoint 1:anyPoint

public:
	//minGray
	int m_value1;
	CScrollBar m_sb1;
	
	//maxGray
	int m_value2;
	CScrollBar m_sb2;

	//minArea
	CScrollBar m_sb3;
	int m_value3;

	//maxArea
	CScrollBar m_sb4;
	int m_value4;

////匹配度
	double m_value5;
	CScrollBar m_sb5;
	//最小对比度
    CString m_value6;
    CScrollBar m_sb6;
	//查找数量
	CString m_value7;
    CScrollBar m_sb7;
	//area_points
    int m_value8;
    CScrollBar m_sb8;
	int m_value9;
	CScrollBar m_sb9;

	//circularity
	double m_value10;
	double m_value11;
	CScrollBar m_sb10;
	CScrollBar m_sb11;


	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	void myOnInitDialog();



	

	afx_msg void OnBnClickedMovetolocation();
	afx_msg void OnBnClickedIdentify();

	afx_msg void OnBnClickedAutotake();
	afx_msg void OnBnClickedGenRec2();
	afx_msg void OnBnClickedGenRec3();
	afx_msg void OnBnClickedIdentify2();


	
	

	
	
	
	

	afx_msg void OnBnClickedAutotake2();
	static UINT wrokThread(LPVOID pParam);

	
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();

	

	afx_msg void OnBnClickedAutotake3();
	afx_msg void OnBnClickedButton11();
	UINT runBlobThread(LPVOID pParam);
	UINT runTemplateThread(LPVOID pParam);
	UINT runXldGrabThread(LPVOID pParam);
	UINT runXldFaceThread(LPVOID pParam);
};
