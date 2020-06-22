#pragma once
#include "MotionControlCardUtil.h"
#include "HalconUtil.h"
#include "Doc.h"
#include "mystruct.h"
#include <vector>

using namespace HalconCpp;




class HalconMotionCardUnion
{
public:
	HalconMotionCardUnion();
	~HalconMotionCardUnion();

	//step 1 取得抓取物的坐标和形状
	void step_1_resetTargetData();
	bool step_3_addTargetDataWorld(CPoint cp, int mode, double radian);
	//bool step_3_addTargetDataWorld(double row_Y, double column_X, int mode, double radian);
	bool step_2_status_startGotFromData;//开始取得目标物资料
	//bool step_3_addTargetData(HTuple row,HTuple column,int mode,double angle);
	bool step_4_status_endGotFromData;//取得目标物完成
	//step 2 取得目标位置and 执行
	void step_5_doAction(Doc &doc);

	//走位
	bool startCollectContourPoint;
	bool CompleteCollectContourPoint;
	void cleanConTourList();
	void initContourListMap(int num);
	void addContourList(int num, CPoint cp);
	void getContourList(int num, vector<CPoint> &list);
	int contourListSize(int num);

	int contourMapSize();
private:
	
	
	vector<CPoint> fromCPoints;
	vector<int> shapesVector; //0 表示圆形，1表示方形,2表示都可以
	vector<double> radianVector; //radian
	vector<HalconPointDataInt> pointDataVector; //360度
	
	
	vector<CPoint> toCPoints;
	int getAvailableWarehouse(int mode);
	CPoint takeAndUpdateWareHouse(int warehoseNo, Doc &doc);
	bool addToPoint(Doc &doc);
	void assembleHalconPointData();

	


	int radianToPulse(double radian);;


	bool endMoving;//完成运动


	map<int, bool> warehoseStatus;//11-14 Circle 21-24 方形

    MotionControlCardUtil motionCard;

	vector<CPoint> contourList;
	map<int, vector<CPoint>> contourListMap;
};

