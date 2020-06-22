#include "stdafx.h"
#include "CameraUtil.h"

int                     g_hCamera = -1;     //设备句柄
unsigned char           * g_pRawBuffer = NULL;     //raw数据
unsigned char           * g_pRgbBuffer = NULL;     //处理后数据缓存区
tSdkFrameHead           g_tFrameHead;       //图像帧头信息
tSdkCameraCapbility     g_tCapability;      //设备描述信息

int                     g_SaveParameter_num = 0;    //保存参数组
int                     g_SaveImage_type = 0;         //保存图像格式

Width_Height            g_W_H_INFO;         //显示画板到大小和图像大小
BYTE                    *g_readBuf = NULL;    //画板显示数据区
int                     g_read_fps = 0;       //统计读取帧率
int                     g_disply_fps = 0;     //统计显示帧率




CameraUtil::CameraUtil()
{
	showAmendedPic = true;
	amendMode = 0;
}


CameraUtil::~CameraUtil()
{
}

#if 0
int CameraUtil::init_SDK()
{

	int                     iCameraCounts = 4;
	int                     iStatus = -1;
	tSdkCameraDevInfo       tCameraEnumList[4];

	//sdk初始化  0 English 1中文
	CameraSdkInit(1);

	//枚举设备，并建立设备列表
	CameraEnumerateDevice(tCameraEnumList, &iCameraCounts);

	//没有连接设备
	if (iCameraCounts == 0) {
		return -1;
	}

	//相机初始化。初始化成功后，才能调用任何其他相机相关的操作接口
	iStatus = CameraInit(&tCameraEnumList[0], -1, -1, &g_hCamera);

	//初始化失败
	if (iStatus != CAMERA_STATUS_SUCCESS) {
		return -1;
	}
	//获得相机的特性描述结构体。该结构体中包含了相机可设置的各种参数的范围信息。决定了相关函数的参数
	CameraGetCapability(g_hCamera, &g_tCapability);

	g_pRgbBuffer = (unsigned char*)malloc(g_tCapability.sResolutionRange.iHeightMax*g_tCapability.sResolutionRange.iWidthMax * 3);
	g_readBuf = (unsigned char*)malloc(g_tCapability.sResolutionRange.iHeightMax*g_tCapability.sResolutionRange.iWidthMax * 3);

	/*让SDK进入工作模式，开始接收来自相机发送的图像
	数据。如果当前相机是触发模式，则需要接收到
	触发帧以后才会更新图像。    */
	CameraPlay(g_hCamera);



	/*
		设置图像处理的输出格式，彩色黑白都支持RGB24位
	*/
	if (g_tCapability.sIspCapacity.bMonoSensor) {
		CameraSetIspOutFormat(g_hCamera, CAMERA_MEDIA_TYPE_MONO8);
	}
	else {
		CameraSetIspOutFormat(g_hCamera, CAMERA_MEDIA_TYPE_RGB8);
	}
	return 0;
}




//白平衡按钮操作
void CameraUtil::AWB_once()
{
	int RPos, GPos, BPos;

	CameraSetOnceWB(g_hCamera);

	CameraGetGain(g_hCamera, &RPos, &GPos, &BPos);




}

#endif