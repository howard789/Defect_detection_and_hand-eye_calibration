#pragma once
#include "stdafx.h"
#include "Doc.h"
#include <map>
#include <deque>
# include "myStruct.h"
# include "ParamUtil.h"

#include "../include/dmc1380.h"
#pragma comment(lib,"../lib/x64/Dmc1380.lib")


#define PULSE_TRIGER_CAMERA1_MIN 900 //基础资料,Triger到相机一
#define PULSE_TRIGER_CAMERA1_MAX 1200//基础资料
#define PULSE_CAMERA1_CAMERA2 6176//基础资料
#define PULSE_CAMERA2_GASS1 7861//基础资料
#define PULSE_GASS1_GASS2 3307//基础资料
#define PULSE_GASS2_GASS3 3588//基础资料



#define PULSE_TRIGER_CAMERA1 (PULSE_TRIGER_CAMERA1_MIN+PULSE_TRIGER_CAMERA1_MAX)*0.5
#define PULSE_TRIGER_GassingOne (PULSE_TRIGER_CAMERA1_MAX+PULSE_CAMERA1_CAMERA2+PULSE_CAMERA2_GASS1)
#define PULSE_TRIGER_GassingTwo (PULSE_TRIGER_GassingOne+PULSE_GASS1_GASS2)




//#define CAMERA1_NG_PULSE PULSE_CAMERA1_CAMERA2+PULSE_CAMERA2_GASS1
//#define CAMERA1_OK_PULSE CAMERA1_NG_PULSE+PULSE_GASS1_GASS2



class dmc1380Util
{
public:
	dmc1380Util();
	~dmc1380Util();
	void Move();
	//紧急停止
	void emergentStop();
	//停止
	void generalStop();

	//位置清零
	void setCurrentPositionZero();


	//以下是项目定制 
	// 1：2号吹起机
	// 2：1号吹气机
	// 3：吹气机电源
	// 4：震动盘电源
	// 5：转盘电源
	void enpowerEngine(bool enpower);//转盘电机使能
	void enableGassing(bool enpower);//吹起使能
	void gassing_no1(bool gassing);//1号吹气
	void gassing_no2(bool gassing);//2号吹气
	void enableVibrationPlate(bool enable);//振动盘
	bool isItemsComing();//是否有物料过来

    int getCurrentPulse();//获得转盘的脉冲数

   //运动参数
	int nStart; //开始速度
	int nMSpeed;//max speed
	double nTAcc;//acc time
	int nPulse;//定量脉冲
	int nPos;//定量位置


	bool moveMode_T; //T型运动
	int  moveModeFixPosFixDisSpeed; //运动模式 0 到特定点，1 定长 2 持续运动
	
	void dealTrigerDeque();
	void dealGass1Deque();
	void dealGass2Deque();

	void clearDeques();
	bool runThread;

	void resetCount();

public:
	deque<InfoUnit> Camera1Deque;
	deque<InfoUnit> Gass1Deque;//ng
	deque<InfoUnit> Gass2Deque;//ok
	deque<int> resultQue;//ok

public:
	HWND hWnd;//提示初始化板卡失败用的
	int BoardInit();

	


	void Stop(bool isEmerge);


	int	 m_nAxis; //运动轴选择 0-3
	int boardsNum;
	bool successInit;//初始化成功

	CString getDequesSize();

	int lasePulseTriger;

	

	

	void setResult(InfoUnit & info, bool ng, bool cameraOneDown);

public:
	int m_count_camera;
	int m_count_trigger;
	int m_count_ok;
	int m_count_ng;
	int m_count_gassing1;
	int m_count_gassing2;
	
};

