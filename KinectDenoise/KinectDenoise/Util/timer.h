#pragma once
#include "stdafx.h"

class timer
{
public:
	timer();
	~timer();
	void StartTimer();
	float getDuration();
private :
	chrono::system_clock::time_point m_startPoint;
};

