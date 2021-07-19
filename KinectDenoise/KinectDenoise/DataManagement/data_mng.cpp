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
		str.append("test");
		str.append(to_string(m_fileNumber++));
		str.append(".obj");
		
		fst.open(str);

		k4a::image rs;
		rs = m_DataSet[i];

		int16_t* data = (int16_t*)rs.get_buffer();
		int height = rs.get_height_pixels(), width = rs.get_width_pixels();

		for (register int j = 0; j < height * width; j++)
		{
			int16_t x, y, z;

			x = data[3 * j + 0];
			y = data[3 * j + 1] * -1;
			z = data[3 * j + 2] * -1;

			fst << "v " << x << " " << y << " " << z << endl;
		}

		fst.close();
	}
}

vector<Vertex> data_mng::ConvertPointCloud2Vertex(k4a::image pointCloud)
{
	vector<Vertex> rt;
	int16_t* data = (int16_t*)pointCloud.get_buffer();
	int height = pointCloud.get_height_pixels(), width = pointCloud.get_width_pixels();

	for (register int j = 0; j < height * width; j++)
	{
		if (data[3 * j + 2] != 0)
		{
			Vertex temp;
			temp.x = data[3 * j + 0] * -1;
			temp.y = data[3 * j + 1] * -1;
			temp.z = data[3 * j + 2];
			rt.push_back(temp);
		}
	}

	return rt;
}

bool data_mng::ExtractJointPosition(k4abt::frame BTFrame, vector<Vertex>& oJointPosition)
{
	if (BTFrame.handle() == nullptr)
		return false;
	if (BTFrame.get_num_bodies() == 0)
		return false;

	for (register int i = 0; i < K4ABT_JOINT_COUNT; i++)
	{
		Vertex temp;
		temp.x = BTFrame.get_body_skeleton(0).joints[i].position.xyz.x * -1.0;
		temp.y = BTFrame.get_body_skeleton(0).joints[i].position.xyz.y * -1.0;
		temp.z = BTFrame.get_body_skeleton(0).joints[i].position.xyz.z;
		oJointPosition.push_back(temp);
	}

	return true;
}


bool data_mng::SeperateBDNBG(k4abt::frame BTFrame, bool tag, k4a::image& oResult)
{
	if (BTFrame.handle() == nullptr)
		return false;
	if (BTFrame.get_num_bodies() == 0)
		return false;

	k4a::capture capture = BTFrame.get_capture();

	if (!capture)
		return false;

	uint8_t* indexmapdata = BTFrame.get_body_index_map().get_buffer();
	k4a::image img = capture.get_depth_image();
	uint16_t* data = (uint16_t*)img.get_buffer();

	int height = img.get_height_pixels(), width = img.get_width_pixels();

	for (register int i = 0; i < height * width; i++)
	{
		if (indexmapdata[i] == K4ABT_BODY_INDEX_MAP_BACKGROUND && tag)
		{
			data[i] = 0;
		}
		else if (indexmapdata[i] != K4ABT_BODY_INDEX_MAP_BACKGROUND && !tag)
		{
			data[i] = 0;
		}
	}

	oResult = img;

	return true;
}

cv::Mat data_mng::ConvertKinect2CVColor(k4a::image image)
{
	if (!image)
		return cv::Mat();
	int w = image.get_width_pixels(), h = image.get_width_pixels();
	uint8_t* temp = image.get_buffer();
	cv::Mat ret(w, h, CV_8UC4, temp);
	
	return ret;
}

cv::Mat data_mng::ConvertKinect2CVDepth(k4a::image image)
{
	if (!image)
		return cv::Mat();
	int w = image.get_width_pixels(), h = image.get_width_pixels();
	uint16_t* temp = (uint16_t*)image.get_buffer();
	cv::Mat ret(w, h, CV_16UC1, temp);

	return ret;
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


bool data_mng::SeperateByMask(k4abt::frame BTFrame, cv::Mat mask, k4a::image& oResult)
{
	if (BTFrame.handle() == nullptr)
		return false;
	if (BTFrame.get_num_bodies() == 0)
		return false;

	k4a::capture capture = BTFrame.get_capture();
	k4a::image img = capture.get_depth_image();
	uint16_t* data = (uint16_t*)img.get_buffer();
	auto maskData = mask.data;
	int height = img.get_height_pixels(), width = img.get_width_pixels();

	for (register int i = 0; i < height * width; i++)
	{
		if (maskData[i] != 255)
		{
			data[i] = 0;
		}
	}

	oResult = img;

	return true;
}

k4a::image data_mng::ExtractDepthImage(k4abt::frame BTFrame)
{
	return BTFrame.get_capture().get_depth_image();
}
