#pragma once
#include "stdafx.h"

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
#ifdef BODYTRACK
	k4abt::frame getBodyFrameFromSingleDevice();
	vector<k4abt::frame> getBodyFrameFromMultiDevice();
#endif
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
#ifdef BODYTRACK
	k4abt::frame m_SubordinateBTFrame;
	k4abt::tracker m_SubordinateTracker;
#endif
	k4a::transformation m_SubordinateTransformation;
	k4a::calibration m_SubordinateCalib;

	k4a::device m_MasterDevice;
	k4a::capture m_MasterCaputre;
#ifdef BODYTRACK
	k4abt::frame m_MasterBTFrame;
	k4abt::tracker m_MasterTracker;
#endif
	k4a::transformation m_MasterTransformation;
	k4a::calibration m_MasterCalib;

	int m_DeviceCount;
};

