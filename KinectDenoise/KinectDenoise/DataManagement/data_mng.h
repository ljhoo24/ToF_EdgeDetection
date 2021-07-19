#pragma once
#include "defines.h"

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
	static vector<Vertex> ConvertPointCloud2Vertex(k4a::image pointCloud);
	static bool ExtractJointPosition(k4abt::frame BTFrame, vector<Vertex>& oJointPosition);
	static bool SeperateBDNBG(k4abt::frame BTFrame, bool tag, k4a::image& oResult);
	static cv::Mat ConvertKinect2CVColor(k4a::image image);
	static cv::Mat ConvertKinect2CVDepth(k4a::image image);
	bool setTransformation(k4a::calibration calib);
	k4a::image ConvertDepth2PointCloud(k4a::image depthImage);
	bool SeperateByMask(k4abt::frame BTFrame, cv::Mat mask, k4a::image& oResult);
	k4a::image ExtractDepthImage(k4abt::frame BTFrame);
};

