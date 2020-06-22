#include "stdafx.h"
#include "Doc.h"


Doc::Doc()
{
	//fixed_location_circle1 = new CPoint(-45772, -34035);
	//fixed_location_circle2 = new CPoint(-7393, -34035);
	//fixed_location_circle3 = new CPoint(-45975, -73601);
	//fixed_location_circle4 = new CPoint(-7115, -73601);


	//fixed_location_spuare1 = new CPoint(149252, -16723);
	//fixed_location_spuare2 = new CPoint(187581, -16723);
	//fixed_location_spuare3 = new CPoint(151825, -56226);
	//fixed_location_spuare4 = new CPoint(186545, -56226);

	//fixed_location_circle1 = nullptr;
	//fixed_location_circle2 = nullptr;
	//fixed_location_circle3 = nullptr;
	//fixed_location_circle4 = nullptr;
	//						
	//fixed_location_spuare1 = nullptr;
	//fixed_location_spuare2 = nullptr;
	//fixed_location_spuare3 = nullptr;
	//fixed_location_spuare4 = nullptr;


}


Doc::~Doc()
{
}


void Doc::setDefaultLocation()
{







	fixed_location_circle1.x = 3055;
	fixed_location_circle1.y = -3465;

	fixed_location_circle2.x = 42400;
	fixed_location_circle2.y = -3465;


	fixed_location_circle3.x = 1399;
	fixed_location_circle3.y = -41349;


	fixed_location_circle4.x = 45373;
	fixed_location_circle4.y = -41349;

	fixed_location_spuare1.x = 197500;
	fixed_location_spuare1.y = -36716;

	fixed_location_spuare2.x = 232195;
	fixed_location_spuare2.y = 12064;

	fixed_location_spuare3.x = 197346;
	fixed_location_spuare3.y = -28639;
	
	fixed_location_spuare4.x = 231494;
	fixed_location_spuare4.y = -28639;



}




//脉冲数据
void Doc::setPulseMap(int pointNum, int x, int y)
{
	CPoint cp;
	cp.x = x;
	cp.y = y;
	setPulseMap(pointNum,cp);
}


void Doc::setPulseMap(int pointNum, CPoint cp)
{

	//pulseMap.insert(pair<int, CPoint>(pointNum, cp));
	pulseMap[pointNum] = cp;
}


int Doc::getPulseMapValue_X(int pointNum)
{
	return pulseMap[pointNum].x;
}

int Doc::getPulseMapValue_Y(int pointNum)
{
	return pulseMap[pointNum].y;
}

void Doc::setPixelMap(int pointNum, CPoint cp)
{
	pixelMap[pointNum] = cp;
}



int Doc::getPixelMapValue_X(int pointNum)
{
	return pixelMap[pointNum].x;
}

int Doc::getPixelMapValue_Y(int pointNum)
{
	return pixelMap[pointNum].y;
}

bool Doc::readyToCalibrate()
{
	//当两个map都有值且数量相同的时候可以开始标定
	if (pulseMap.size() > 0 && pixelMap.size() > 0 && pulseMap.size() == pixelMap.size()) {
		return true;
	}
	else {
		return false;
	}


	
}

CPoint Doc::getSquareWarehouseLocation(int num)
{
	switch (num) {
	case 1:
		return fixed_location_spuare1;
	case 2:

		return fixed_location_spuare2;
	case 3:

		return fixed_location_spuare3;

	case 4:

		return fixed_location_spuare4;

	}
	return CPoint();
}

CPoint Doc::getCircleWarehouseLocation(int num)
{
	switch (num) {
	case 1:
		return fixed_location_circle1;
	case 2:

		return fixed_location_circle2;
	case 3:

		return fixed_location_circle3;

	case 4:

		return fixed_location_circle4;

	}
	return CPoint();
}


CPoint Doc::getPulseMapValue_Project4(int cameraNum, int pointNum)
{
	CPoint cp;
	cameraNum == 1?
		cp = pulseMap_project4_camera1[pointNum]:
		cp = pulseMap_project4_camera2[pointNum];
	return cp;
	
}

CPoint Doc::getPixelMapValue_Project4(int cameraNum, int pointNum)
{
	CPoint cp;
	cameraNum == 1 ?
		cp = pixelMap_project4_camera1[pointNum] :
		cp = pixelMap_project4_camera2[pointNum];

	return cp;
}

void Doc::setPixelMap_Project4(int cameraNum, int pointNum, CPoint cp)
{
	if (cameraNum == 1)
	{
		pixelMap_project4_camera1[pointNum] = cp;
	}
	else
	{
		pixelMap_project4_camera2[pointNum] = cp;
	}

}


void Doc::setPulseMap_Project4(int cameraNum, int pointNum, CPoint cp)
{
	if (cameraNum == 1)
	{
		pulseMap_project4_camera1[pointNum] = cp;
	}
	else
	{
		pulseMap_project4_camera2[pointNum] = cp;
	}

}

void Doc::Conveyor_setPulseMapFixed()
{
	setPulseMap(1, *conveyor_world_point1);
	setPulseMap(2, *conveyor_world_point2);
	setPulseMap(3, *conveyor_world_point3);
	setPulseMap(4, *conveyor_world_point4);
	setPulseMap(5, *conveyor_world_point5);
	setPulseMap(6, *conveyor_world_point6);
	setPulseMap(7, *conveyor_world_point7);
	setPulseMap(8, *conveyor_world_point8);
	setPulseMap(9, *conveyor_world_point9);
}
