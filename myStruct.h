#pragma once

#define _HalconPointDataNull -999999999
struct HalconPointData
{
	bool circleShape;
	double from_column_X= _HalconPointDataNull;
	double to_column_X = _HalconPointDataNull;
	double from_row_Y = _HalconPointDataNull;
	double to_row_Y = _HalconPointDataNull;
	double from_U_degree = _HalconPointDataNull;
	double to_U_degree = _HalconPointDataNull;


};

struct HalconPointDataInt
{
	bool circleShape;
	int from_column_X = _HalconPointDataNull;
	int to_column_X = _HalconPointDataNull;
	int from_row_Y = _HalconPointDataNull;
	int to_row_Y = _HalconPointDataNull;
	int from_U_pulse = _HalconPointDataNull;
	int to_U_pulse = _HalconPointDataNull;


};


struct InfoUnit
{
	int result;//1 NG 2 OK  3 unKnow
	int cameraOnePicPulse_schedule_Min;
	int cameraOnePicPulse_schedule_Max;
	int cameraOnePicPulse_schedule_Mid;
    int cameraOnePicPulse_actual;

	int ng_pulse;
	int ok_pulse;
	bool cameraOneDown;
	

};