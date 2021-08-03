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
#include <map>

#pragma region pcl lib

#include <pcl\visualization\cloud_viewer.h>
#include <pcl\io\obj_io.h>
#include <pcl\kdtree\kdtree_flann.h>
#include <pcl\io\pcd_io.h>
#include <pcl\features\normal_3d_omp.h>
#include <pcl/common/transforms.h>

#pragma endregion

#define DEPTH_MODE K4A_DEPTH_MODE_NFOV_2X2BINNED
#define COLOR_RESOLUTION K4A_COLOR_RESOLUTION_OFF//K4A_COLOR_RESOLUTION_720P
#define CAMERA_FRAME K4A_FRAMES_PER_SECOND_30
#define COLOR_FORMAT K4A_IMAGE_FORMAT_COLOR_BGRA32

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

#define FILEPATH "./output/"
#define DATAPATH "./data/"

using PCptr = pcl::PointCloud<pcl::PointXYZRGB>::Ptr;

using namespace std;

struct Vertex
{
	Vertex(double X, double Y, double Z)
	{
		x = X; y = Y; z = Z;
	}
	Vertex() {};
	double x;
	double y;
	double z;
};