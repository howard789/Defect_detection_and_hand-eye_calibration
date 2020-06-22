#pragma once
#include <map>

using namespace std;

//用于保存动态数据的类
class Doc
{
public:

	

	Doc();
	~Doc();
	void setDefaultLocation();
	//case 1
	void setPulseMap(int pointNum, int x, int y);
	void setPulseMap(int pointNum, CPoint cp);
	int getPulseMapValue_X(int pointNum);
	int getPulseMapValue_Y(int pointNum);

	void setPixelMap(int pointNum, CPoint cp);

	int getPixelMapValue_X(int pointNum);
	int getPixelMapValue_Y(int pointNum);
	   	  
	bool readyToCalibrate();

	map<int, CPoint> pulseMap;
	map<int, CPoint> pixelMap;

	CPoint getSquareWarehouseLocation(int num);
	CPoint getCircleWarehouseLocation(int num);

	

	 CPoint fixed_location_circle1 ;
	 CPoint fixed_location_circle2 ;
	 CPoint fixed_location_circle3 ;
	 CPoint fixed_location_circle4 ;
							   
							   
	 CPoint fixed_location_spuare1 ;
	 CPoint fixed_location_spuare2 ;
	 CPoint fixed_location_spuare3 ;
	 CPoint fixed_location_spuare4 ;


	 const int Y1 = 131195;
	 const int Y2 = 100645;
	 const int Y3 = 72043;

	const CPoint * const fixed_location_point1 = new CPoint(141967, Y1);
	const CPoint * const fixed_location_point2 = new CPoint(171856, Y1);
	const CPoint * const fixed_location_point3 = new CPoint(201767, Y1);
	const CPoint * const fixed_location_point4 = new CPoint(139591, Y2);
	const CPoint * const fixed_location_point5 = new CPoint(173998, Y2);
	const CPoint * const fixed_location_point6 = new CPoint(202735, Y2);
	const CPoint * const fixed_location_point7 = new CPoint(140680, Y3);
	const CPoint * const fixed_location_point8 = new CPoint(172478, Y3);
	const CPoint * const fixed_location_point9 = new CPoint(201635, Y3);



	//case 4

	map<int, CPoint> pulseMap_project4_camera1;
	map<int, CPoint> pulseMap_project4_camera2;

	map<int, CPoint> pixelMap_project4_camera1;
	map<int, CPoint> pixelMap_project4_camera2;


	CPoint getPulseMapValue_Project4(int cameraNum,int pointNum);
	CPoint getPixelMapValue_Project4(int cameraNum,int pointNum);


	void setPixelMap_Project4(int cameraNum,int pointNum,CPoint cp);
	void setPulseMap_Project4(int cameraNum, int pointNum, CPoint cp);

	const CPoint * const project4_camera1_world_point1 = new CPoint(93987, 97907);
	const CPoint * const project4_camera1_world_point2 = new CPoint(122722, 97907);
	const CPoint * const project4_camera1_world_point3 = new CPoint(154692, 97907);
	const CPoint * const project4_camera1_world_point4 = new CPoint(93034, 67623);
	const CPoint * const project4_camera1_world_point5 = new CPoint(121550, 67623);
	const CPoint * const project4_camera1_world_point6 = new CPoint(154597, 67623);
	const CPoint * const project4_camera1_world_point7 = new CPoint(92859, 38730);
	const CPoint * const project4_camera1_world_point8 = new CPoint(123406, 38730);
	const CPoint * const project4_camera1_world_point9 = new CPoint(154688, 38730);


	const CPoint * const project4_camera2_world_point1 = new CPoint(103987, 97907);
	const CPoint * const project4_camera2_world_point2 = new CPoint(132722, 97907);
	const CPoint * const project4_camera2_world_point3 = new CPoint(164692, 97907);
	const CPoint * const project4_camera2_world_point4 = new CPoint(103034, 67623);
	const CPoint * const project4_camera2_world_point5 = new CPoint(131550, 67623);
	const CPoint * const project4_camera2_world_point6 = new CPoint(164597, 67623);
	const CPoint * const project4_camera2_world_point7 = new CPoint(102859, 38730);
	const CPoint * const project4_camera2_world_point8 = new CPoint(133406, 38730);
	const CPoint * const project4_camera2_world_point9 = new CPoint(164688, 38730);




	//case 5
	void Conveyor_setPulseMapFixed();


	const CPoint * const conveyor_world_point1 = new CPoint(103987, 97907);
	const CPoint * const conveyor_world_point2 = new CPoint(132722, 97907);
	const CPoint * const conveyor_world_point3 = new CPoint(164692, 97907);
	const CPoint * const conveyor_world_point4 = new CPoint(103034, 67623);
	const CPoint * const conveyor_world_point5 = new CPoint(131550, 67623);
	const CPoint * const conveyor_world_point6 = new CPoint(164597, 67623);
	const CPoint * const conveyor_world_point7 = new CPoint(102859, 38730);
	const CPoint * const conveyor_world_point8 = new CPoint(133406, 38730);
	const CPoint * const conveyor_world_point9 = new CPoint(164688, 38730); 


	const CPoint * const conveyor_pixel_point1 = new CPoint(103987, 97907);
	const CPoint * const conveyor_pixel_point2 = new CPoint(132722, 97907);
	const CPoint * const conveyor_pixel_point3 = new CPoint(164692, 97907);
	const CPoint * const conveyor_pixel_point4 = new CPoint(103034, 67623);
	const CPoint * const conveyor_pixel_point5 = new CPoint(131550, 67623);
	const CPoint * const conveyor_pixel_point6 = new CPoint(164597, 67623);
	const CPoint * const conveyor_pixel_point7 = new CPoint(102859, 38730);
	const CPoint * const conveyor_pixel_point8 = new CPoint(133406, 38730);
	const CPoint * const conveyor_pixel_point9 = new CPoint(164688, 38730);



};

