#pragma once
#include "stdafx.h"

class data_mng
{
private:
	vector<k4a::image> m_DataSet;
	int m_fileNumber;
	k4a::transformation m_Transformation;
public:	
	data_mng();
	~data_mng();
	void setData(k4a::image data);
	int getDataCount();
	void saveDataSet();
	void clearDataSet() { m_DataSet.clear(); };
	static pcl::PointCloud<pcl::PointXYZRGB>::Ptr ConvertKinect2PCL(k4a::image pointCloud);
	static pcl::PointCloud<pcl::PointXYZRGB>::Ptr ConvertVertex2PCL(vector<Vertex> vecVTX);
	bool setTransformation(k4a::calibration calib);
	k4a::image ConvertDepth2PointCloud(k4a::image depthImage);
};

