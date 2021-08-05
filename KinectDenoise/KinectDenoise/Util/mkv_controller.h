#pragma once
#include "stdafx.h"

class mkv_controller
{
public:
	mkv_controller();
	~mkv_controller();
	void setFilePath(string fileName) { m_fileName = fileName; };
	void openPlayback(string fileName);
	int getFrameCount() { return m_iFrameCount; };
	bool getColorFrame(k4a::image& oImage);
	bool getColorFrame(int frameNumber, k4a::image& oImage);
	bool getDepthFrame(k4a::image& oImage);
	bool getDepthFrame(int frameNumber, k4a::image& oImage);
	bool saveBetweenFrame(int startFrame, int endFrame, string fileName);
	int getTotalFrameCount() { return m_iTotalFrameCount; };
	void FrameRewind();
	void SetTracker();
	//bool getBodyFrame(k4abt::frame& oFrame);
	bool getCalib(k4a::calibration& oCalib);
private:
	void calcTotalFrameCount();
	k4a::playback m_Playback;
	//k4abt::tracker m_Tracker;
	k4a::calibration m_Calibration;
	string m_fileName;
	bool m_bOpen;
	bool m_bTracker;
	int m_iFrameCount;
	int m_iTotalFrameCount;
};

