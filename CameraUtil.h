#pragma once

#include "../include/mindversion/CameraApi.h"

class CameraUtil
	//Mvs
{
public:
	CameraUtil();
	~CameraUtil();

	bool showAmendedPic;
	int amendMode;//0:blob 1:template 2:xld

#if 0

private:
	int init_SDK();

	
	
	//触发模式
	void set_trigger_hardware();//硬触发
	void set_trigger_software();//软触发
	void set_trigger_collect();//连续采集
	void trigger_once();//软件触发一次

	//曝光设置  


	//亮度目标

	//抗频闪

	//增益

	//曝光时间

	//ISP图像处理


	//参数组
	

	//查表映射变换

	//ISP颜色处理



	//一键白平衡
    void AWB_once();

	//抓拍设置




	
	bool   exposure_time_lineedit_status;

#endif
};


typedef struct _WIDTH_HEIGHT {
	int     display_width;
	int     display_height;
	int     xOffsetFOV;
	int     yOffsetFOV;
	int     sensor_width;
	int     sensor_height;
	int     buffer_size;
}Width_Height;

