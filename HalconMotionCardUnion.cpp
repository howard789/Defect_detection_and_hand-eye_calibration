#include "HalconMotionCardUnion.h"



HalconMotionCardUnion::HalconMotionCardUnion()
{
	
	
	
	warehoseStatus[11] = true;
	warehoseStatus[12] = true;
	warehoseStatus[13] = true;
	warehoseStatus[14] = true;
	warehoseStatus[21] = true;
	warehoseStatus[22] = true;
	warehoseStatus[23] = true;
	warehoseStatus[24] = true;

	startCollectContourPoint = false;
	CompleteCollectContourPoint = false;
}


HalconMotionCardUnion::~HalconMotionCardUnion()
{
}

void HalconMotionCardUnion::step_1_resetTargetData()
{
	pointDataVector.clear();
	radianVector.clear();
	fromCPoints.clear();
	shapesVector.clear();
	toCPoints.clear();
	step_2_status_startGotFromData = false;
	step_4_status_endGotFromData = false;
}

bool HalconMotionCardUnion::step_3_addTargetDataWorld(CPoint cp, int mode, double radian)
{
	fromCPoints.push_back(cp);
	shapesVector.push_back(mode);
	radianVector.push_back(radian);

	return true;
}


//bool HalconMotionCardUnion::step_3_addTargetDataWorld(double row_Y, double column_X, int mode, double radian)
//{
//
//	CPoint cp(column_X, row_Y);
//
//
//
//	fromCPoints.push_back(cp);
//	shapesVector.push_back(mode);
//	radianVector.push_back(radian);
//
//
//
//}


//bool HalconMotionCardUnion::step_3_addTargetData(HTuple row, HTuple column, int mode, double radian)
//{
//	double temp = -9999999999;
//	try {
//		temp = row.D();
//	}
//	catch (...) {
//		return false;
//	}
//	if (temp == -9999999999)
//		return false;
//
//
//	double temp2 = -9999999999;
//	try {
//		temp2 = column.D();
//	}
//	catch (...) {
//		return false;
//	}
//	if (temp2 == -9999999999)
//		return false;
//
//	CPoint cp(temp2,temp);
//	
//
//
//	fromCPoints.push_back(cp);
//	shapesVector.push_back(mode);
//	radianVector.push_back(radian);
//
//}

bool HalconMotionCardUnion::addToPoint(Doc &doc)
{
	if (fromCPoints.size() != shapesVector.size()|| fromCPoints.size() != radianVector.size())
		return false;
	for (int i = 0; i < fromCPoints.size(); i++)
	{
		int warehouseNo = getAvailableWarehouse(shapesVector[i]);
		toCPoints.push_back(takeAndUpdateWareHouse(warehouseNo,doc));
	}

}

void HalconMotionCardUnion::assembleHalconPointData()
{
	for (int i = 0; i < fromCPoints.size(); i++)
	{
		CPoint fromP = fromCPoints[i];
		CPoint toP = toCPoints[i];
		double radian = radianVector[i];

		HalconPointDataInt data;
		data.from_column_X =(int) fromP.x;
		data.from_row_Y = (int)fromP.y;
		data.to_column_X = (int)toP.x;
		data.to_row_Y = (int)toP.y;
		data.from_U_pulse = _U_ZERO_POINT;
		data.to_U_pulse = radianToPulse(radian);
		pointDataVector.push_back(data);

	}
	




}

int HalconMotionCardUnion::radianToPulse(double radian)
{
	//先转成角度
	double degree = radian / (2 * pi);

	//转成正负90度的
	if (degree > 270)
		degree = degree - 360;
	else if (degree > 180)
		degree = degree - 180;
	else if (degree > 90)
		degree = degree - 180;

	//转成目标脉冲数
	int pulse = (degree / 360 * 10000)+ _U_ZERO_POINT;

	


	return pulse;
}









CPoint HalconMotionCardUnion::takeAndUpdateWareHouse(int warehoseNo,Doc &doc)
{

	const CPoint *warehouse = nullptr;

		switch (warehoseNo) 
		{
			case 11:
				warehouse = &doc.fixed_location_circle1;
				break;
			case 12:
				warehouse = &doc.fixed_location_circle2;
				break;
			case 13:
				warehouse = &doc.fixed_location_circle3;
				break;
			case 14:
				warehouse = &doc.fixed_location_circle4;
				break;
			case 21:
				warehouse = &doc.fixed_location_spuare1;
				break;
			case 22:
				warehouse = &doc.fixed_location_spuare2;
				break;
			case 23:
				warehouse = &doc.fixed_location_spuare3;
				break;
			case 24:
				warehouse = &doc.fixed_location_spuare4;
				break;
		}
		
		return *warehouse;
}

void HalconMotionCardUnion::step_5_doAction(Doc &doc)
{
	addToPoint(doc);

	//组装资料
	assembleHalconPointData();

	//start move
	for (int i = 0; i < pointDataVector.size(); i++)
	{
		HalconPointDataInt data = pointDataVector[i];
		motionCard.grabToLocation(CPoint(data.from_column_X,data.from_row_Y),CPoint(data.to_column_X,data.to_row_Y),data.to_U_pulse);
	}

	//end move
	
}

void HalconMotionCardUnion::cleanConTourList()
{
	contourList.clear();
	contourListMap.clear();
}

void HalconMotionCardUnion::initContourListMap(int num)
{
	for (int i = 1; i <= num; i++)
	{
		vector<CPoint> list;
		contourListMap[i] = list;
	}
}

void HalconMotionCardUnion::addContourList(int num,CPoint cp)
{

	vector<CPoint> list;
	getContourList(num,list);
	list.push_back(cp);
	contourListMap[num] = list;
}

void HalconMotionCardUnion::getContourList( int num,vector<CPoint> &list)
{
	list= contourListMap[num];
}

int HalconMotionCardUnion::contourListSize(int num)
{
	vector<CPoint> list;
	getContourList(num, list);
	return list.size();
}

int HalconMotionCardUnion::contourMapSize()
{
	return contourListMap.size();
}



int  HalconMotionCardUnion::getAvailableWarehouse(int mode)
{
	int warehouseID=0;
	if (mode==0|| mode == 2) {
		if (warehoseStatus[11]) {
			warehouseID = 11;
		}
		else if (warehoseStatus[12]) {
			warehouseID = 12;
		}
		else if (warehoseStatus[13]) {
			warehouseID = 13;
		}
		else if (warehoseStatus[14]) {
			warehouseID = 14;
		}
	}
	else if (mode == 1 || mode == 2)
	{

		if (warehoseStatus[21]) {
			warehouseID = 21;
		}
		else if (warehoseStatus[22]) {
			warehouseID = 22;
		}
		else if (warehoseStatus[23]) {
			warehouseID = 23;
		}
		else if (warehoseStatus[24]) {
			warehouseID = 24;
		}

	}
	if (warehouseID > 0)
	{
		warehoseStatus[warehouseID] = false;
		return warehouseID;
	}
	else {
		return 11; //辨识的目标超过实际应该有的
	}

}



