#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <k4a\k4a.hpp>
#include <k4arecord\playback.hpp>
#include <k4arecord\record.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <algorithm>
#include <list>
#include <deque>
#include <cmath>

#pragma region pcl lib

#include <pcl\visualization\cloud_viewer.h>

#pragma endregion

#define DEPTH_MODE K4A_DEPTH_MODE_NFOV_2X2BINNED
#define COLOR_RESOLUTION K4A_COLOR_RESOLUTION_OFF//K4A_COLOR_RESOLUTION_720P
#define CAMERA_FRAME K4A_FRAMES_PER_SECOND_30
#define COLOR_FORMAT K4A_IMAGE_FORMAT_COLOR_BGRA32

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

#define FILEPATH "./result/"
#define DATAPATH "./result/nomask/"


using namespace std;

struct Vertex
{
	double x;
	double y;
	double z;
};