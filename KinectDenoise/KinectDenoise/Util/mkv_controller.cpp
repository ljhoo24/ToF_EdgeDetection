#include "stdafx.h"
#include "mkv_controller.h"


mkv_controller::mkv_controller()
{
	m_bOpen = false;
	m_bTracker = false;
	m_iFrameCount = 0;
}


mkv_controller::~mkv_controller()
{
	if (m_bOpen)
		m_Playback.close();
	/*if (m_bTracker)
		m_Tracker.destroy();*/
}

void mkv_controller::openPlayback(string fileName)
{
	setFilePath(fileName);
	m_Playback = k4a::playback::open(m_fileName.c_str());
	if(m_Playback)
		m_bOpen = true;
	m_Playback.set_color_conversion(K4A_IMAGE_FORMAT_COLOR_BGRA32);
	m_Calibration = m_Playback.get_calibration();
	//calcTotalFrameCount();
	//FrameRewind();
}

bool mkv_controller::getColorFrame(k4a::image& oImage)
{
	bool ret = false;

	if (!m_bOpen)
		return ret;

	k4a::capture* capture = new k4a::capture;
	ret = m_Playback.get_next_capture(capture);
	if (!ret)
		return ret;
	oImage = capture->get_color_image();
	capture->reset();
	m_iFrameCount++;
	delete capture;

	return ret;
}

bool mkv_controller::getColorFrame(int frameNumber, k4a::image & oImage)
{
	bool ret = false;

	if (!m_bOpen)
		return ret;

	k4a::capture* capture = new k4a::capture;
	while (1)
	{
		if (frameNumber > m_iFrameCount)
		{
			ret = m_Playback.get_next_capture(capture);
			m_iFrameCount++;
		}
		else if (frameNumber < m_iFrameCount)
		{
			ret = m_Playback.get_previous_capture(capture);
			m_iFrameCount--;
		}
		else
			break;
	}
	oImage = capture->get_color_image();
	capture->reset();
	delete capture;

	return ret;
}

bool mkv_controller::getDepthFrame(k4a::image & oImage)
{
	bool ret = false;

	if (!m_bOpen)
		return ret;

	k4a::capture* capture = new k4a::capture;
	ret = m_Playback.get_next_capture(capture);
	oImage = capture->get_depth_image();
	capture->reset();
	m_iFrameCount++;
	delete capture;
	
	return ret;
}

bool mkv_controller::getDepthFrame(int frameNumber, k4a::image & oImage)
{
	bool ret = false;

	if (!m_bOpen)
		return ret;

	k4a::capture* capture = new k4a::capture;
	while (1)
	{
		if (frameNumber > m_iFrameCount)
		{
			ret = m_Playback.get_next_capture(capture);
			m_iFrameCount++;
		}
		else if (frameNumber < m_iFrameCount)
		{
			ret = m_Playback.get_previous_capture(capture);
			m_iFrameCount--;
		}
		else
			break;
	}
	oImage = capture->get_depth_image();
	capture->reset();
	delete capture;

	return ret;
}

bool mkv_controller::saveBetweenFrame(int startFrame, int endFrame, string fileName)
{
	bool ret = false;

	if (!m_bOpen)
		return ret;

	k4a::capture capture;
	while (1)
	{
		capture.reset();
		if (startFrame > m_iFrameCount)
		{
			ret = m_Playback.get_next_capture(&capture);
			m_iFrameCount++;
		}
		else if (startFrame < m_iFrameCount)
		{
			ret = m_Playback.get_previous_capture(&capture);
			m_iFrameCount--;
		}
		else
			break;
	}
	k4a_device_configuration_t config;
	auto rconfig = m_Playback.get_record_configuration();
	config.camera_fps = rconfig.camera_fps;
	config.color_format = rconfig.color_format;
	config.color_resolution = rconfig.color_resolution;
	config.depth_delay_off_color_usec = rconfig.depth_delay_off_color_usec;
	config.depth_mode = rconfig.depth_mode;
	config.subordinate_delay_off_master_usec = rconfig.subordinate_delay_off_master_usec;
	config.wired_sync_mode = rconfig.wired_sync_mode;

	k4a::record recording;
	recording.create(fileName.c_str(), nullptr, config);
	recording.write_header();
	recording.write_capture(capture);
	capture.reset();
	while (1)
	{
		if (m_iFrameCount < endFrame)
		{
			m_Playback.get_next_capture(&capture);
			m_iFrameCount++;
			recording.write_capture(capture);
			capture.reset();
		}
		else
			break;
	}
	recording.flush();
	recording.close();

	return ret;
}

void mkv_controller::FrameRewind()
{
	if (!m_bOpen)
		return ;

	k4a::capture capture;
	while (m_Playback.get_previous_capture(&capture))
	{
		capture.reset();
		m_iFrameCount--;
	}
}

void mkv_controller::SetTracker()
{
	/*if (!m_bOpen)
		return;
	m_Tracker = k4abt::tracker::create(m_Calibration);
	m_bTracker = true;*/
}

/*bool mkv_controller::getBodyFrame(k4abt::frame& oFrame)
{
	bool ret = false;

	if (!m_bOpen)
		return ret;
	if (!m_bTracker)
		return ret;

	k4a::capture* capture = new k4a::capture;
	
	ret = m_Playback.get_next_capture(capture);
	m_iFrameCount++;
	if (!capture)
	{
		capture->reset();
		delete capture;
		return ret;
	}
	m_Tracker.enqueue_capture(*capture);
	oFrame = m_Tracker.pop_result();
	if (oFrame == nullptr)
	{
		ret = false;
		m_iFrameCount++;
		capture->reset();
		delete capture;
		return ret;
	}
	capture->reset();
	delete capture;
	return ret;
}*/

void mkv_controller::calcTotalFrameCount()
{
	if (!m_bOpen)
		return;

	k4a::capture capture;
	while (m_Playback.get_next_capture(&capture))
	{
		capture.reset();
		m_iFrameCount++;
	}
	m_iTotalFrameCount = m_iFrameCount;
}


bool mkv_controller::getCalib(k4a::calibration& oCalib)
{
	if (!m_bOpen)
		return false;
	oCalib = m_Calibration;
	return true;
}
