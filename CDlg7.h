#pragma once
#include "ParamUtil.h"
#include "dmc1380Util.h"


// CDlg7 对话框 Case 6

class CDlg7 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg7)

public:
	CDlg7(dmc1380Util &dmc1380Util,ParamUtil &paramUtil, HalconUtil &halconUtil, CameraUtil &cameraUtil, Doc &doc, MotionControlCardUtil &motionCard, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlg7();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	void test(Doc & doc);

	DECLARE_MESSAGE_MAP()

private:
	ParamUtil &paramUtil;
	MotionControlCardUtil &motionCard;
	Doc &doc;
	CameraUtil &cameraUtil;
	HalconUtil &halconUtil;

	dmc1380Util &dmcUtil;

	int threadMode;

	

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedButton7();
	void myOnInitDialog();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedGassing1();
	afx_msg void OnBnClickedGassing2();
	afx_msg void OnBnClickedButton6();
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg void OnPaint();
	void setPictureColorGreen();
	void setPictureColorRed();
	CStatic m_coming;
//	afx_msg void OnPaint();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void myOnTimer();
	void updateCountData();
	double getPassRate();
	afx_msg void OnBnClickedMove();
	int m_value1;
	int m_value2;
	CScrollBar m_sb1;
	CScrollBar m_sb2;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButton10();
	afx_msg
	static UINT startTrainThread(LPVOID param);
	void OnBnClickedCheck3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedMove2();
	afx_msg void OnBnClickedButton11();
	double m_value3;
	CScrollBar m_sb3;
	afx_msg void OnEnChangeEdit9();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedMove3();
	afx_msg void OnBnClickedMove4();

	static UINT runWorkThread(LPVOID param);
	static UINT runWorkThread2(LPVOID param);
	afx_msg void OnBnClickedButton13();


	int previousTrigerPulse;

};
