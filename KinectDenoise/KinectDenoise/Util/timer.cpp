#include "stdafx.h"
#include "timer.h"

timer::timer()
{
}


timer::~timer()
{
}

void timer::StartTimer()
{
	m_startPoint = chrono::system_clock::now();
}

float timer::getDuration()
{
	chrono::duration<double> duration = chrono::system_clock::now() - m_startPoint;
	return duration.count();
}
