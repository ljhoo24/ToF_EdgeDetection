#include "stdafx.h"
#include "data_mng.h"

data_mng::data_mng()
{
	m_fileNumber = 1;
}


data_mng::~data_mng()
{
}


void data_mng::setData(k4a::image data)
{
	m_DataSet.push_back(data);
}


int data_mng::getDataCount()
{
	return m_DataSet.size();
}


void data_mng::saveDataSet()
{
	ofstream fst;

	for (register int i = 0; i < m_DataSet.size(); i++)
	{
		string str(FILEPATH);
		str.append(TESTDATA_FILENAME);
		str.append(to_string(m_fileNumber++));
		str.append(".obj");
		
		fst.open(str);

		k4a::image rs;
		rs = m_DataSet[i];

		int16_t* data = (int16_t*)rs.get_buffer();
		size_t cnt = rs.get_size();

		for (register int j = 0; j < (cnt / 3); j++)
		{
			int16_t x, y, z;

			x = data[3 * j + 0];
			y = data[3 * j + 1] * -1;
			z = data[3 * j + 2] * -1;

			fst << "v " << (int16_t)x << " " << (int16_t)y << " " << (int16_t)z << endl;
		}

		fst.close();
	}
}

pcl::PointCloud<pcl::PointXYZRGB>::Ptr data_mng::ConvertKinect2PCL(k4a::image pointCloud)
{
	int16_t* data = (int16_t*)pointCloud.get_buffer();
	int height = pointCloud.get_height_pixels(), width = pointCloud.get_width_pixels();

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr ptc = make_shared <pcl::PointCloud<pcl::PointXYZRGB>>();

	for (register int j = 0; j < height * width; j++)
	{
		ptc->points.push_back(pcl::PointXYZRGB(data[3 * j + 0], data[3 * j + 1] * -1, data[3 * j + 2] * -1, 255, 255, 255));
	}

	return ptc;
}

pcl::PointCloud<pcl::PointXYZRGB>::Ptr data_mng::ConvertVertex2PCL(vector<Vertex> vecVTX)
{
	unsigned int cnt = vecVTX.size();

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr ptc = make_shared <pcl::PointCloud<pcl::PointXYZRGB>>();

	for (register unsigned int i = 0; i < cnt; i++)
	{
		ptc->points.push_back(pcl::PointXYZRGB(vecVTX[i].x, vecVTX[i].y, vecVTX[i].z, 255, 255, 255));
	}

	return ptc;
}

bool data_mng::setTransformation(k4a::calibration calib)
{
	m_Transformation = k4a::transformation(calib);
	return true;
}


k4a::image data_mng::ConvertDepth2PointCloud(k4a::image depthImage)
{
	return m_Transformation.depth_image_to_point_cloud(depthImage, K4A_CALIBRATION_TYPE_DEPTH);
}