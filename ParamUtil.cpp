#include "ParamUtil.h"



ParamUtil::ParamUtil()
{
	isClearQue = false;
	isGrabbing = false;
	openIOcheck = false;
	rotate180 = true;
	rotate180Second = true;
	cameraMode = 5;
	cameraModeSecond = 2;

	maxGray = 145;//预设值
	minGray = 0;
	selectShapMaxArea= 20000;
	selectShapMinArea= 5000;
	showModeSynWithMainWin = 0;


	//upPulse= 19887;//项目的固定高度
	//downPulse= -19887;//项目的固定高度

	isTakeCalibrationPic = false;
	generateRectengle=false;
	generateCircle = false;
	gotTemplate = false;
	gotROI = false;
	minContrast = "auto";
	minScore = 0.7;
	numMatches =0;
	areaPintsMin = 400;
	areaPintsMax = 1000;
	circularityMin=0.6;//XLD参数，圆度
	circularityMax=1.0;//XLD参数，圆度
	picTarget = false;


	//mlp
	mlp_minGray=85;
	mlp_maxGray=255;
	mlp_useDefaultSamplePics= false;
	mlp_takeSample1= false;
	mlp_takeSample2= false;
	mlp_takeSample3= false;
	mlp_takeSample4= false;
	mlp_startTrain= false;
	mlp_completeTrain= false;
	mlp_startDetect = false;
	mlp_openingCircleRadius = 2.5;

	caseSixMode = 1;//mlp
	mlp_gotSample1 = false;
	mlp_gotSample2 = false;
	mlp_gotSample3 = false;
	mlp_gotSample4 = false;
	
	
	completeCalibration = false;
	showGrayImg = true;

	locked = false;
	dlg3ThreadMode=0;
	fileNameCount = 1;
	fileNameCount_NG = 0;
	fileNameCount_OK = 0;

	conveyorTakeNine = false;
	conveyorTakeNineSuccess = false;
	GoOriginal = false;

	fileNameCount_SysErr = 0;
}


ParamUtil::~ParamUtil()
{
	
}

string ParamUtil::getNewFilePath() {
	string path = "D:/tmp/" + std::to_string(fileNameCount) + ".bmp";
	fileNameCount++;
	return path;
}

string ParamUtil::getPreviousFilePath() {
	int pre = fileNameCount - 1;
	string path = "D:/tmp/" + std::to_string(pre) + ".bmp";
	return path;
}


HTuple ParamUtil::getNewFilePath_HTuple()
{
	string path= getNewFilePath();
	const char *buf = path.data();
	//fileName = (HTuple)buf;
	HTuple fileName = path.c_str();
	return fileName;
}


HTuple ParamUtil::getPreviousFilePath_HTuple()
{
	string path = getPreviousFilePath();
	const char *buf = path.data();
	//fileName = (HTuple)buf;
	HTuple fileName = path.c_str();
	return fileName;
}


HTuple ParamUtil::getCalibrationFilePath_HTuple()
{
	string path = "D:/tmp/offLine/calibration.bmp";
	const char *buf = path.data();
	//fileName = (HTuple)buf;
	HTuple fileName = path.c_str();
	return fileName;
}

HTuple ParamUtil::getTargetFilePath_HTuple()
{
	string path = "D:/tmp/target.bmp";
	const char *buf = path.data();
	//fileName = (HTuple)buf;
	HTuple fileName = path.c_str();
	return fileName;
}

HTuple ParamUtil::getFilePath_SysErr_Write()
{
	fileNameCount_SysErr++;
	string path = "D:/tmp/mlp/SysErr/" + std::to_string(fileNameCount_SysErr) + ".bmp";

	const char *buf = path.data();
	HTuple fileName = path.c_str();
	return fileName;
}

HTuple ParamUtil::getFilePath_NG_Write()
{
    
	string path = "D:/tmp/mlp/NG/" + std::to_string(fileNameCount_NG) + ".bmp";
	
	const char *buf = path.data();
	HTuple fileName = path.c_str();
	return fileName;
}

HTuple ParamUtil::getFilePath_OK_Write()
{

	string path = "D:/tmp/mlp/OK/" + std::to_string(fileNameCount_OK) + ".bmp";
	
	const char *buf = path.data();
	HTuple fileName = path.c_str();
	return fileName;
}



HTuple ParamUtil::getFilePath_NG_Blank_Write()
{

	string path = "D:/tmp/mlp/NG_blank/" + std::to_string(fileNameCount_NG) + ".bmp";

	const char *buf = path.data();
	HTuple fileName = path.c_str();
	return fileName;
}

HTuple ParamUtil::getFilePath_OK_Blank_Write()
{

	string path = "D:/tmp/mlp/OK_blank/" + std::to_string(fileNameCount_OK) + ".bmp";

	const char *buf = path.data();
	HTuple fileName = path.c_str();
	return fileName;
}



CString ParamUtil::getCStringFilePath_NG_Read(int num)
{
	string path = "D:/tmp/mlp/NG/" + std::to_string(num) + ".bmp";
	return CString(path.c_str());
}

CString ParamUtil::getCStringFilePath_OK_Read(int num)
{
	string path = "D:/tmp/mlp/OK/" + std::to_string(num) + ".bmp";
	return CString(path.c_str());
}




HTuple ParamUtil::getFilePath_NG_Read()
{

	string path = "D:/tmp/mlp/NG/" + std::to_string(fileNameCount_NG-1) + ".bmp";
	const char *buf = path.data();
	HTuple fileName = path.c_str();
	return fileName;
}




HTuple ParamUtil::getFilePath_OK_Read()
{
	string path = "D:/tmp/mlp/OK/" + std::to_string(fileNameCount_OK-1) + ".bmp";
	const char *buf = path.data();
	HTuple fileName = path.c_str();
	return fileName;
}







HTuple ParamUtil::getCalibration_Test_HTuple(int id)
{
	string path;
	if(id==1)
		path = "D:/tmp/calibration_test.bmp";
	else if (id==2)
		path = "D:/tmp/calibration_test2.bmp";
	
	const char *buf = path.data();
	//fileName = (HTuple)buf;
	HTuple fileName = path.c_str();
	return fileName;
}

