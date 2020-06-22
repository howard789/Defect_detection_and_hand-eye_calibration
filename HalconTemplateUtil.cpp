#include "HalconTemplateUtil.h"



HalconTemplateUtil::HalconTemplateUtil()
{

}


HalconTemplateUtil::~HalconTemplateUtil()
{
}


void HalconTemplateUtil::setParam_createTemplate(bool fromPicture, string path)
{
	if(fromPicture)
		HalconUtil::getImageFromFilePath(ho_Template,path);//模板图片
	hv_AngleStart_create = 0;
	hv_AngleExtent_create = HTuple(360).TupleRad();
	hv_AngleStep_create = "auto";
	hv_Optimization = "auto";
	hv_Metric = "ignore_global_polarity";
	hv_NumLevels = 5;
	//对比度
	hv_Contrast = 40;
	hv_MinContrast = 10;

	//scale特殊的属性
	hv_ScaleMin = 0.5;
	hv_ScaleMax = 1.1;
	hv_ScaleStep = "auto";
	hv_Level = 1;
}

void HalconTemplateUtil::setParam_findTarget(bool fromPicture, string path)
{
	if(fromPicture)
		HalconUtil::getImageFromFilePath(ho_SearchImage, path);//模板图片
	hv_AngleStart_find = hv_AngleStart_create;
	hv_AngleExtent_find = hv_AngleExtent_create;
	hv_MinScore = 0.5;
	hv_NumMatches = 0;
	hv_MaxOverlap = 0.5;
	hv_SubPixel = "least_squares";
	hv_NumLevels = 0;
	hv_Greediness = 0.7;
	hv_NumLevels_find = hv_NumLevels;
}



void HalconTemplateUtil::createTemplate()
{


	//将hv_ModelID，ho_Model赋值
	CreateScaledShapeModel(ho_Template, hv_NumLevels, hv_AngleStart_create, hv_AngleExtent_create,
		hv_AngleStep_create, hv_ScaleMin, hv_ScaleMax, hv_ScaleStep, hv_Optimization, hv_Metric,
		hv_Contrast, hv_MinContrast, &hv_ModelID);

	GetShapeModelContours(&ho_Model, hv_ModelID, hv_Level);
}


void HalconTemplateUtil::findTarget()
{
	FindScaledShapeModel(ho_SearchImage, hv_ModelID, hv_AngleStart_find, hv_AngleExtent_find,
		hv_ScaleMin, hv_ScaleMax, hv_MinScore, hv_NumMatches, hv_MaxOverlap, hv_SubPixel,
		hv_NumLevels, hv_Greediness, &out_hv_Row, &out_hv_Column, &out_hv_Angle, &out_hv_Scale, &out_hv_Score);
}

void HalconTemplateUtil::setTemplate(HObject &imageROI)
{
	ho_Template = imageROI;
}

void HalconTemplateUtil::setSearchImage(HObject & image)
{
	ho_SearchImage = image;
}

void HalconTemplateUtil::showXld(vector<HObject> * xlds)
{

	

	HTuple end_val104 = (out_hv_Score.TupleLength()) - 1;
	HTuple hv_I, step_val104 = 1;

	double max = 0;
	if (out_hv_Score.TupleLength() > 0)
	{
		for (hv_I = 0; hv_I.Continue(end_val104, step_val104); hv_I += step_val104)
		{

		}
	}

	
	
		for (hv_I = 0; hv_I.Continue(end_val104, step_val104); hv_I += step_val104)
		{
			HomMat2dIdentity(&hv_HomMat2DIdentity);
			HomMat2dTranslate(hv_HomMat2DIdentity, HTuple(out_hv_Row[hv_I]), HTuple(out_hv_Column[hv_I]),
				&hv_HomMat2DTranslate);
			HomMat2dRotate(hv_HomMat2DTranslate, HTuple(out_hv_Angle[hv_I]), HTuple(out_hv_Row[hv_I]),
				HTuple(out_hv_Column[hv_I]), &hv_HomMat2DRotate);
			HomMat2dScale(hv_HomMat2DRotate, HTuple(out_hv_Scale[hv_I]), HTuple(out_hv_Scale[hv_I]),
				HTuple(out_hv_Row[hv_I]), HTuple(out_hv_Column[hv_I]), &hv_HomMat2DScale);
			AffineTransContourXld(ho_Model, &ho_ModelTrans, hv_HomMat2DScale);
			//UnionCollinearContoursXld(ho_ModelTrans, &ho_UnionContours, 10, 1, 2, 0.1, "attr_keep");

			xlds->push_back(ho_ModelTrans);
			//xld=&ho_UnionContours;
			//return ho_ModelTrans;
			//	DispObj(ho_ModelTrans, HDevWindowStack::GetActive());
		}
	

}


