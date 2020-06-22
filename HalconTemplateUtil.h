#pragma once

#include <map>
#include <atltypes.h>
# include "HalconCpp.h"
# include "HDevThread.h"
#include <string>
# include "Doc.h"
#include <list>
# include "HalconUtil.h"
# include <vector>

using std::list;
using std::array;
using std::map;
using std::string;

using namespace HalconCpp;

class HalconTemplateUtil
{
public:
	HalconTemplateUtil();
	~HalconTemplateUtil();


	void setTemplate(HObject &imageROI);
	void setSearchImage(HObject &image);
	
	void setParam_createTemplate(bool fromPicture,string path);
	void setParam_findTarget(bool fromPicture, string path);
	void createTemplate();


	void findTarget();
    void showXld(vector<HObject>* xlds);





public:
	//以下是创建模板需要用到动变量
	HObject ho_Template;//模板图片

	HObject ho_Model;
	HTuple hv_ModelID;
	HTuple hv_AngleStart_create,hv_AngleExtent_create,hv_AngleStep_create;//角度
	HTuple hv_Optimization;//优化
	HTuple hv_Metric;
	HTuple hv_NumLevels;//层次

	HTuple hv_Contrast, hv_MinContrast;//对比度
	HTuple hv_ScaleMin,hv_ScaleMax,hv_ScaleStep;//缩放
	HTuple hv_Level;

	//以下是查找动时候需要用到动变量
	HObject ho_SearchImage;//图片
	HTuple hv_AngleStart_find,hv_AngleExtent_find; //角度
	HTuple hv_MinScore;
	HTuple hv_NumMatches;
	HTuple hv_MaxOverlap;
	HTuple hv_SubPixel;
	HTuple hv_NumLevels_find;
	HTuple hv_Greediness;

	//以下是查找结果
	HTuple out_hv_Row, out_hv_Column, out_hv_Angle, out_hv_Scale, out_hv_Score;

	//显示xld
	HObject ho_ModelTrans;
	HTuple hv_HomMat2DIdentity, hv_HomMat2DTranslate, hv_HomMat2DRotate, hv_HomMat2DScale;
	HObject ho_UnionContours;
};

