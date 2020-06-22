#include "HalconUtil.h"



HalconUtil::HalconUtil() 
{


	takePointsNum = 0;
	isHomMat2D_Valid=false;//准备好可以转换

}


HalconUtil::~HalconUtil()
{
}

void HalconUtil::resetStatus()
{

	
}

bool HalconUtil::doTakeNinePointsCenter(HTuple hv_Row, HTuple hv_Column, Doc *doc) {
	list<double> *row = new list<double>;
	HTupleToList(hv_Row, row);
	list<double> *column = new list<double>;
	HTupleToList(hv_Column, column);
    
	takePointsNum = 0;
	if (row->size() != column->size() || column->size() != 9)
	{
		return false;
	}

	int sizeNum = row->size();
	double *rowA=new double[sizeNum];
	double *columnA=new double[sizeNum];
	int i = 0;
	for(list<double>::iterator ite=row->begin();ite!=row->end();ite++){
		rowA[i] = *ite;
		i++;
	}
	i = 0;
	for (list<double>::iterator ite = column->begin(); ite != column->end(); ite++) {
		columnA[i] = *ite;
		i++;
	}

	for (int i = 0; i < sizeNum; i++) {

		CPoint cp(columnA[i], rowA[i]);
		doc->setPixelMap(i + 1, cp);
	}

    takePointsNum = sizeNum;
	return true;
}

bool HalconUtil::doTakeNinePointsCenter_Project4(HTuple hv_Row, HTuple hv_Column, Doc * doc, int CameraNum)
{
	list<double> *row = new list<double>;
	HTupleToList(hv_Row, row);
	list<double> *column = new list<double>;
	HTupleToList(hv_Column, column);

	takePointsNum = 0;
	if (row->size() != column->size() || column->size() != 9)
	{
		return false;
	}

	int sizeNum = row->size();
	double *rowA = new double[sizeNum];
	double *columnA = new double[sizeNum];
	int i = 0;
	for (list<double>::iterator ite = row->begin(); ite != row->end(); ite++) {
		rowA[i] = *ite;
		i++;
	}
	i = 0;
	for (list<double>::iterator ite = column->begin(); ite != column->end(); ite++) {
		columnA[i] = *ite;
		i++;
	}

	for (int i = 0; i < sizeNum; i++) {
		CPoint cp(columnA[i], rowA[i]);
		doc->setPixelMap_Project4(CameraNum,i + 1, cp);
	}
	CameraNum==1?takePointsNum_Project4_C1 = sizeNum: takePointsNum_Project4_C2 = sizeNum;;
	return true;
}




//不用
//bool HalconUtil::mVectorToHomMat2d(map<int, CPoint> map1, map<int, CPoint> map2)
//{
	

	//if (map1.size() != map2.size()|| map1.size()==0)
	//{
	//	return false;
	//}

	//	HTuple  hv_r, hv_c, hv_r1, hv_c1, hv_row, hv_col;
	//	for (int i = 0; i < map1.size(); i++)
	//	{
	//		hv_r[i] = map1[i + 1].y;
	//		hv_c[i] = map1[i + 1].x;
	//		hv_r1[i] = map2[i + 1].y;
	//		hv_c1[i] = map2[i + 1].x;
	//	}
	//	VectorToHomMat2d(hv_r, hv_c, hv_r1, hv_c1, &hv_HomMat2D);
	//	HomMat2dInvert(hv_HomMat2D, &hv_HomMat2DInvert);

	//	HomMat2dInvert(hv_HomMat2D, &hv_HomMat2DInvert);
		
	//	return true;

//}

bool HalconUtil::mVectorToHomMat2d(HTuple * hv_HomMat2D, map<int, CPoint> map1, map<int, CPoint> map2)
{


	if (map1.size() != map2.size()|| map1.size()==0)
	{
		return false;
	}

	HTuple  hv_row_y, hv_column_x, hv_row_y1, hv_column_x1;
	for (int i = 0; i < map1.size(); i++)
	{
		CPoint cp = map1[i + 1];
		hv_row_y[i] =cp.y;
		hv_column_x[i] = cp.x;

		CPoint cp2 = map2[i + 1];
		hv_row_y1[i] = cp2.y;
		hv_column_x1[i] = cp2.x;
	}
	VectorToHomMat2d(hv_row_y, hv_column_x, hv_row_y1, hv_column_x1, hv_HomMat2D);
	//HomMat2dInvert(*hv_HomMat2D, hv_HomMat2DInvert);
	isHomMat2D_Valid = true;
	return true;
}

bool HalconUtil::getImageFromFilePath(HObject &ho_Image,string path)
{
	HTuple fileName = path.c_str();
	ReadImage(&ho_Image, fileName);
	return true;
}


void HalconUtil::createHomMat2d(HTuple *hv_HomMat2D, double pixX[], double pixY[], double worldX[], double worldY[])
{
	
	int size1 = sizeof(pixX) / sizeof(double);
	int size2 = sizeof(pixY) / sizeof(double);
	int size3 = sizeof(worldX) / sizeof(double);
	int size4 = sizeof(worldY) / sizeof(double);

	if (size1!=size2 || size2 != size3 || size3!= size4 || size1<3)
	{
		return;
	}

	HTuple  hv_r, hv_c, hv_r1, hv_c1, hv_row, hv_col;
	for (int i = 0; i < size1; i++)
	{
		hv_r[i] = pixX[i];
		hv_c[i] = pixY[i];
		hv_r1[i] = worldX[i];
		hv_c1[i] = worldY[i];
	}
	VectorToHomMat2d(hv_r, hv_c, hv_r1, hv_c1, hv_HomMat2D);
}

void HalconUtil::createInvertHomMat2d(HTuple * hv_HomMat2D, HTuple * hv_HomMat2DInvert)
{
	HomMat2dInvert(*hv_HomMat2D, hv_HomMat2DInvert);


}

bool HalconUtil::writeHomMat2D(HTuple *hv_HomMat2D, string filePath)
{

	const HTuple& FileName = (HTuple)filePath.c_str();
    HTuple hv_SerializedItemHandle, hv_FileHandle;
	
	SerializeHomMat2d(*hv_HomMat2D, &hv_SerializedItemHandle);
	OpenFile(FileName, "output_binary", &hv_FileHandle);
	FwriteSerializedItem(hv_FileHandle, hv_SerializedItemHandle);
	CloseFile(hv_FileHandle);
	return true;

}

bool HalconUtil::readHomMat2D(HTuple *hv_HomMat2D, string filePath)
{
	try
	{
		const HTuple& FileName = (HTuple)filePath.c_str();
		HTuple hv_FileHandle, hv_SerializedItemHandle;
		OpenFile(FileName, "input_binary", &hv_FileHandle);
		FreadSerializedItem(hv_FileHandle, &hv_SerializedItemHandle);
		DeserializeHomMat2d(hv_SerializedItemHandle, hv_HomMat2D);
		//createInvertHomMat2d(hv_HomMat2D, hv_HomMat2DInvert);//创建反矩阵

		CloseFile(hv_FileHandle);
		return true;
	}
	catch (...)
	{
		return false;
	}
}



void HalconUtil::pixToWorld_motionCardAtBase(HTuple *hv_HomMat2D, double &pixX, double &pixY, double& worldX,double& worldY)
{
	HTuple  hv_r_y, hv_c_x, hv_r_y1, hv_c_x1;
	HTuple hv_Column_Qx, hv_Row_Qy;
	doubleToHTuple(hv_c_x, pixX);
	doubleToHTuple(hv_r_y, pixY);
	if (isHomMat2D_Valid) {
		AffineTransPoint2d(*hv_HomMat2D, hv_r_y, hv_c_x, &hv_Row_Qy, &hv_Column_Qx);
		worldX = HTupleToDouble(hv_Column_Qx);
		worldY = HTupleToDouble(hv_Row_Qy);
	}
	else
	{
		
	}

}

void HalconUtil::worldToPix_motionCardAtBase(HTuple * hv_HomMat2D, double& worldX, double& worldY, double& pixX, double& pixY)
{
	HTuple* hv_HomMat2DInvert=new HTuple;
	createInvertHomMat2d(hv_HomMat2D, hv_HomMat2DInvert);
	return pixToWorld_motionCardAtBase(hv_HomMat2DInvert, worldX, worldY, pixX, pixY);
}



double HalconUtil::radToDegree(double rad)
{
	return pi/180*rad;
}

int HalconUtil::radToPulse(double rad)
{
	return (int)(rad / pi * 180 * Leishine360DegreePuluse);
}

HTuple HalconUtil::getMlpExampleFilePath(int i)
{
	string basePath = _MLP_NEW_EXAMPLE_FILE_PATH;
	string name;
	switch (i)
	{
	case 1:name = "/1.bmp"; break;
	case 2:name = "/2.bmp"; break;
	case 3:name = "/3.bmp"; break;
	case 4:name = "/4.bmp"; break;

	}
	string fullPath = basePath + name;

	HTuple fileName;
	stringToHTuple(fileName, fullPath);
	//fileName = fullPath.c_str();
	return fileName;
}

//bool HalconUtil::blobForAreaCenter(string filePath)
//{
//	HObject  ho_Image, ho_ImageIlluminate, ho_GrayImage;
//	HObject  ho_Regions, ho_ConnectedRegions, ho_SelectedRegions;
//	HObject  ho_RegionFillUp;
//
//	// Local control variables
//	
//
//	//Image Acquisition 01: Code generated by Image Acquisition 01
//	ReadImage(&ho_Image,stringToHTuple(filePath));
//	Illuminate(ho_Image, &ho_ImageIlluminate, 101, 101, 0.7);
//
//	Rgb1ToGray(ho_Image, &ho_GrayImage);
//	Threshold(ho_GrayImage, &ho_Regions, 62, 200);
//
//
//	Connection(ho_Regions, &ho_ConnectedRegions);
//
//	SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", 5000, 20000);
//	FillUp(ho_SelectedRegions, &ho_RegionFillUp);
//	AreaCenter(ho_RegionFillUp, &hv_Area, &hv_Row, &hv_Column);
//
//	return true;
//}

void HalconUtil::stringToHTuple(HTuple& htuple,string str)
{
	htuple=str.c_str();

}


//void HalconUtil::CStringToHTuple(HTuple& htuple, CString str)
//{
//
//	htuple = (LPSTR)str.GetBuffer();
//
//}

void HalconUtil::doubleToHTuple(HTuple & htuple, double value)
{
	htuple = value;
}

void HalconUtil::intToHTuple(HTuple & htuple, int value)
{
	htuple = value;
}



HString HalconUtil::HTupleToHString(HTuple htuple)
{
	return htuple.S();
}

string HalconUtil::HTupleToString(HTuple htuple)
{
	HString str = htuple.S();
	const char* cha=str.Text();
	string str1 = cha;
	return str1;
}

double HalconUtil::HTupleToDouble(HTuple htuple)
{
	return htuple.D();
}

int HalconUtil::HTupleToInt(HTuple htuple)
{
	return htuple.I();
}

void HalconUtil::HTupleToList(HTuple htuple, list<double> * doubleList)
{
	HTuple  hv_I, hv_x;
	HTuple end_val23 = (htuple.TupleLength()) - 1;
	HTuple step_val23 = 1;

	int size = htuple.TupleLength();
	if (size > 0) {
		
		for (hv_I = 0; hv_I.Continue(end_val23, step_val23); hv_I += step_val23)
		{
			hv_x = HTuple(htuple[hv_I]);
			double j = HTupleToDouble(hv_x);
			doubleList->push_back(j);
		}

		/*HTuple end_val14 = (hv_Row.TupleLength()) - 1;
		HTuple step_val14 = 1;
		for (hv_I = 0; hv_I.Continue(end_val14, step_val14); hv_I += step_val14)
		{
			hv_y = HTuple(hv_Row[hv_I]);
			hv_x = HTuple(hv_Column[hv_I]);

			doc.setPixelMap(hv_I + 1, hv_x, hv_y);

		}*/

	}

}


void HalconUtil::pixToWorld(HTuple rowY, HTuple columnX, CPoint & worldCP, CPoint & currentPosition, CPoint & basePosition)
{


	CPoint cpTmp;
	pixToWorld_motionCardAtBase(rowY, columnX, cpTmp);
	double addX = (double)currentPosition.x - (double)basePosition.x;
	double addY = (double)currentPosition.y - (double)basePosition.y;
	worldCP.x = cpTmp.x + addX;
	worldCP.y = cpTmp.y + addY;

}



void HalconUtil::pixToWorld_motionCardAtBase(HTuple rowY, HTuple columnX, CPoint &worldCP)
{

	double columnX2 = HTupleToDouble(columnX);
	double rowY2 = HTupleToDouble(rowY);

	double worldX;
	double worldY;

	pixToWorld_motionCardAtBase(&savedHomMat2D,columnX2,rowY2,worldX,worldY);
	worldCP.x = worldX;
	worldCP.y = worldY;



}
