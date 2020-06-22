#pragma once
#include "MotionControlCardUtil.h"
#include "CameraUtil.h"
#include "MyRealButton.h"
#include "HalconUtil.h"
#include "MfcUtil.h"
# include "myStruct.h"
#include "HalconMotionCardUnion.h"
#include <vector>

#define _ResizeWindow_Fixed

#define WM_UPDATEDATA 123

#define FIXED_MAINWINDOW_HIGH 820  //显示区域高
#define FIXED_MAINWINDOW_WIDE 1400  //宽

#define Z_AXIS_DOWN_PULSE -24719 //z轴下降的脉冲数位置
#define Z_AXIS_UP_PULSE 0 //z轴抬起的脉冲数位置


#define EPSON_IP "192.168.0.12"
#define EPSON_PORT "3000"


//用于定义的判断状态动类

class ParamUtil
{
public:
	ParamUtil();
	~ParamUtil();

	string getPreviousFilePath();

	HTuple getNewFilePath_HTuple();

	HTuple getPreviousFilePath_HTuple();

	HTuple getCalibrationFilePath_HTuple();

	HTuple getTargetFilePath_HTuple();

	HTuple getFilePath_SysErr_Write();

	HTuple getFilePath_NG_Write();

	CString getCStringFilePath_NG_Read(int num);

	CString getCStringFilePath_OK_Read(int num);

	HTuple getFilePath_NG_Read();

	HTuple getFilePath_OK_Write();

	HTuple getFilePath_NG_Blank_Write();

	HTuple getFilePath_OK_Blank_Write();

	HTuple getFilePath_OK_Read();

	HTuple getCalibration_Test_HTuple(int id);

	string getNewFilePath();

	//用来携带地址给其他类
	/*MotionControlCardUtil *motionCard;
	Doc *doc;
	CameraUtil *cameraUtil;
	HalconUtil *halconUtil;
	int mfcUtilAddress;*/
	int showModeSynWithMainWin;

	int cameraMode;//1内建 2 项目一 3 项目四 4项目六 Halcon  5 项目六 SDK
	int cameraModeSecond;//1项目四 2 项目六 3 无相机

	bool completeCalibration;//完成标定

	bool rotate180; //第一台相机旋转
	bool rotate180Second;//第2台相机旋转
	

	int minGray;
	int maxGray;

	int selectShapMaxArea;
	int selectShapMinArea;

	int fileNameCount;
	int fileNameCount_NG;
	int fileNameCount_OK;
	int fileNameCount_SysErr;

	//int upPulse;//项目的固定高度
	//int downPulse;//项目的固定高度
	
	bool showGrayImg;

	bool isTakeCalibrationPic;
	bool generateRectengle;
	bool generateCircle;
	bool gotTemplate;
	bool gotROI;
	bool picTarget;

	std::string minContrast;//最小对比度
	double minScore;//匹配度
	int numMatches;//查找数量
	int areaPintsMin;//XLD参数，面积点数
	int areaPintsMax;//XLD参数，面积点数
	double circularityMin;//XLD参数，圆度
	double circularityMax;//XLD参数，圆度

	//mlp
	int mlp_minGray;
	int mlp_maxGray;
	bool mlp_useDefaultSamplePics;
	bool mlp_takeSample1;
	bool mlp_takeSample2;
	bool mlp_takeSample3;
	bool mlp_takeSample4;
	bool mlp_startTrain;
	bool mlp_completeTrain;
	bool mlp_startDetect;
	bool mlp_gotSample1;
	bool mlp_gotSample2;
	bool mlp_gotSample3;
	bool mlp_gotSample4;
	double mlp_openingCircleRadius;

	int dlg3ThreadMode;//1 blob 2 multi template 3xld 4轮廓
	bool locked;//多线程锁

	bool openIOcheck;


	//case 4
	bool caseFourCalibration_CameraOne;
	bool caseFourCalibration_CameraTwo;

	//case 5
	bool conveyorTakeNine;
	bool conveyorTakeNineSuccess;


	//case 6
	int caseSixMode;//1 mlp 2 频域

	bool isClearQue;

	HObject tmpImg;


	bool GoOriginal;

	bool isGrabbing;
private:


};

