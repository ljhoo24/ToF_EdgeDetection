#include "stdafx.h"
#include "azure_kinect.h"

azure_kinect::azure_kinect()
{
	Initialize_Device(1);
}

azure_kinect::azure_kinect(int num)
{
	Initialize_Device(num);
}

azure_kinect::~azure_kinect()
{
	Finalize_Device();
}

k4a::image azure_kinect::getPointCloudFromSingleDevice()
{
	k4a::image rt;
	getPointCloudFromSingleDevice(rt);
	return rt;
}

vector<k4a::image> azure_kinect::getPointCloudFromMultiDevice()
{
	vector<k4a::image> rt;
	rt.assign(2, nullptr);
	getPointCloudFromMultiDevice(rt[0], rt[1]);
	return rt;
}

#ifdef BODYTRACK
k4abt::frame azure_kinect::getBodyFrameFromSingleDevice()
{
	setBodyFrame();
	return m_MasterBTFrame;
}

vector<k4abt::frame> azure_kinect::getBodyFrameFromMultiDevice()
{
	setBodyFrame();
	vector<k4abt::frame> ret;
	ret.push_back(m_MasterBTFrame);
	ret.push_back(m_SubordinateBTFrame);
	return ret;
}
#endif

k4a::image azure_kinect::D2PCTransformbyMaster(k4a::image depthImage)
{
	k4a::image ret;
	if(depthImage.handle() != nullptr)
		ret = m_MasterTransformation.depth_image_to_point_cloud(depthImage, K4A_CALIBRATION_TYPE_DEPTH);
	return ret;
}

k4a::image azure_kinect::D2PCTransformbySubordinate(k4a::image depthImage)
{
	k4a::image ret;
	if (depthImage.handle() != nullptr)
		ret = m_SubordinateTransformation.depth_image_to_point_cloud(depthImage, K4A_CALIBRATION_TYPE_DEPTH);
	return ret;
}

k4a::image azure_kinect::getColorFromSingleDevice()
{
	k4a::image ret;
	m_MasterDevice.get_capture(&m_MasterCaputre);
	if(m_MasterCaputre)
		ret = m_MasterCaputre.get_color_image();
	return ret;
}

k4a::image azure_kinect::getDepthFromSingleDevice()
{
	k4a::image ret;
	m_MasterDevice.get_capture(&m_MasterCaputre);
	if (m_MasterCaputre.handle() != nullptr)
		ret = m_MasterCaputre.get_depth_image();
	return ret;
}

void azure_kinect::Initialize_Device(int num)
{
	m_DeviceCount = num;
	if (m_DeviceCount == 1)
		Initialize_SingleDevice();
	else if (m_DeviceCount == 2)
		Initialize_MultiDevice();
}

void azure_kinect::Initialize_SingleDevice()
{
	uint32_t count = k4a::device::get_installed_count();
	if (count == 0)
	{
		cout << "Can Not Find Device !" << endl;
		return;
	}

	k4a_device_configuration_t Configuration;
	Configuration = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
	Configuration.camera_fps = CAMERA_FRAME;
	Configuration.depth_mode = DEPTH_MODE;
	Configuration.color_format = COLOR_FORMAT;
	Configuration.color_resolution = COLOR_RESOLUTION;
	Configuration.synchronized_images_only = false;
	Configuration.wired_sync_mode = K4A_WIRED_SYNC_MODE_STANDALONE;

	m_MasterDevice = k4a::device::open(0);

	m_MasterDevice.start_cameras(&Configuration);

	auto calib = m_MasterDevice.get_calibration(DEPTH_MODE, COLOR_RESOLUTION);
	m_MasterTransformation = k4a::transformation(calib);
#ifdef BODYTRACK
	m_MasterTracker = k4abt::tracker::create(calib);
#endif
}

void azure_kinect::Initialize_MultiDevice()
{
	uint32_t count = k4a::device::get_installed_count();
	if (count == 0)
	{
		cout << "Can Not Find Device !" << endl;
		return;
	}
	
	k4a_device_configuration_t Configuration;
	Configuration = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
	Configuration.camera_fps = CAMERA_FRAME;
	Configuration.depth_mode = DEPTH_MODE;
	Configuration.color_format = COLOR_FORMAT;
	Configuration.color_resolution = COLOR_RESOLUTION;
	Configuration.synchronized_images_only = false;
	Configuration.wired_sync_mode = K4A_WIRED_SYNC_MODE_SUBORDINATE;

	m_SubordinateDevice = k4a::device::open(0);
	m_MasterDevice = k4a::device::open(1);

	m_SubordinateDevice.start_cameras(&Configuration);
	Configuration.wired_sync_mode = K4A_WIRED_SYNC_MODE_MASTER;
	m_MasterDevice.start_cameras(&Configuration);

	auto calib = m_SubordinateDevice.get_calibration(DEPTH_MODE, COLOR_RESOLUTION);
	m_SubordinateTransformation = k4a::transformation(calib);
#ifdef BODYTRACK
	m_SubordinateTracker = k4abt::tracker::create(calib);
#endif
	calib = m_MasterDevice.get_calibration(DEPTH_MODE, COLOR_RESOLUTION);
	m_MasterTransformation = k4a::transformation(calib);
#ifdef BODYTRACK
	m_MasterTracker = k4abt::tracker::create(calib);
#endif
}

void azure_kinect::Finalize_Device()
{
	if (m_DeviceCount == 1)
		Finalize_SingleDevice();
	else if (m_DeviceCount == 2)
		Finalize_MultiDevice();
}

void azure_kinect::Finalize_SingleDevice()
{
	if (m_MasterDevice.is_valid())
	{
		m_MasterDevice.stop_cameras();
		m_MasterDevice.close();
		m_MasterCaputre.reset();
#ifdef BODYTRACK
		m_MasterTracker.shutdown();
		m_MasterTracker.destroy();
#endif
	}
}

void azure_kinect::Finalize_MultiDevice()
{
	if (m_MasterDevice.is_valid())
	{
		m_MasterDevice.stop_cameras();
		m_MasterDevice.close();
		m_MasterCaputre.reset();
#ifdef BODYTRACK
		m_MasterTracker.shutdown();
		m_MasterTracker.destroy();
#endif
	}
	if (m_SubordinateDevice.is_valid())
	{
		m_SubordinateDevice.stop_cameras();
		m_SubordinateDevice.close();
		m_SubordinateCapture.reset();
#ifdef BODYTRACK
		m_SubordinateTracker.shutdown();
		m_SubordinateTracker.destroy();
#endif
	}
}

void azure_kinect::getPointCloudFromSingleDevice(k4a::image & oPC)
{
	m_MasterDevice.get_capture(&m_MasterCaputre);
	auto depthImage = m_MasterCaputre.get_depth_image();
	oPC = m_MasterTransformation.depth_image_to_point_cloud(depthImage, K4A_CALIBRATION_TYPE_DEPTH);
}

void azure_kinect::getPointCloudFromMultiDevice(k4a::image & oPC1, k4a::image & oPC2)
{
	m_MasterDevice.get_capture(&m_MasterCaputre);
	m_SubordinateDevice.get_capture(&m_SubordinateCapture);

	auto depthImage = m_MasterCaputre.get_depth_image();
	oPC1 = m_MasterTransformation.depth_image_to_point_cloud(depthImage, K4A_CALIBRATION_TYPE_DEPTH);

	depthImage = m_SubordinateCapture.get_depth_image();
	oPC2 = m_SubordinateTransformation.depth_image_to_point_cloud(depthImage, K4A_CALIBRATION_TYPE_DEPTH);
}

void  azure_kinect::setBodyFrame()
{
#ifdef BODYTRACK
	if (m_DeviceCount == 1)
	{
		m_MasterDevice.get_capture(&m_MasterCaputre);
		if (m_MasterCaputre)
		{
			m_MasterTracker.enqueue_capture(m_MasterCaputre);
			m_MasterTracker.pop_result(&m_MasterBTFrame);
		}
	}
	else if (m_DeviceCount == 2)
	{
		m_SubordinateDevice.get_capture(&m_SubordinateCapture);
		if (m_SubordinateCapture)
		{
			m_SubordinateTracker.enqueue_capture(m_SubordinateCapture);
			m_SubordinateTracker.pop_result(&m_SubordinateBTFrame);
		}
		m_MasterDevice.get_capture(&m_MasterCaputre);
		if (m_MasterCaputre)
		{
			m_MasterTracker.enqueue_capture(m_MasterCaputre);
			m_MasterTracker.pop_result(&m_MasterBTFrame);
		}
	}
#endif
}
