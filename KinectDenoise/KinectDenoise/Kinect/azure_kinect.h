#pragma once

#define DEPTH_MODE K4A_DEPTH_MODE_NFOV_2X2BINNED
#define COLOR_RESOLUTION K4A_COLOR_RESOLUTION_720P
#define CAMERA_FRAME K4A_FRAMES_PER_SECOND_30
#define COLOR_FORMAT K4A_IMAGE_FORMAT_COLOR_BGRA32
#define BODYTRACK

#include <k4a\k4a.hpp>
#ifdef BODYTRACK
#include <k4abt.hpp>
#endif	
#include <vector>
#include <iostream>

using namespace std;

class azure_kinect
{
public:
	azure_kinect();
	azure_kinect(int num);
	~azure_kinect(); 
	k4a::image getPointCloudFromSingleDevice();
	vector<k4a::image> getPointCloudFromMultiDevice();
	k4a::device getDevice() { return m_MasterDevice.handle(); };
	k4abt::frame getBodyFrameFromSingleDevice();
	vector<k4abt::frame> getBodyFrameFromMultiDevice();
	k4a::image D2PCTransformbyMaster(k4a::image depthImage);
	k4a::image D2PCTransformbySubordinate(k4a::image depthImage);
	k4a::image getColorFromSingleDevice();
	k4a::image getDepthFromSingleDevice();
private:
	void Initialize_Device(int num);
	void Initialize_SingleDevice();
	void Initialize_MultiDevice();
	void Finalize_Device();
	void Finalize_SingleDevice();
	void Finalize_MultiDevice();
	void getPointCloudFromSingleDevice(k4a::image& oPC);
	void getPointCloudFromMultiDevice(k4a::image& oPC1, k4a::image& oPC2);
	void setBodyFrame();
	k4a::device m_SubordinateDevice;
	k4a::capture m_SubordinateCapture;
	k4abt::tracker m_SubordinateTracker;
	k4a::transformation m_SubordinateTransformation;
	k4abt::frame m_SubordinateBTFrame;
	k4a::calibration m_SubordinateCalib;

	k4a::device m_MasterDevice;
	k4a::capture m_MasterCaputre;
	k4abt::tracker m_MasterTracker;
	k4a::transformation m_MasterTransformation;
	k4abt::frame m_MasterBTFrame;
	k4a::calibration m_MasterCalib;

	int m_DeviceCount;
};

