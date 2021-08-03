#pragma once
#include "stdafx.h"

#include "Kinect\azure_kinect.h"
#include "DataManagement\ObjManager.h"
#include "DataManagement\data_mng.h"
#include "DataManagement\SWTest.h"
#include "Util\timer.h"


// scene draw for realtime kinect
void drawSceneKinect(pcl::visualization::PCLVisualizer& viewer)
{
	if (!updateFlag)
		return;

	// update every frame
	auto ptc = kinectDevice->getPointCloudFromSingleDevice();

	auto pclPTC = data_mng::ConvertKinect2PCL(ptc);

	// processing function call

	SWTest swtest;
	swtest.Initialize();

	pcl::KdTreeFLANN<pcl::PointXYZRGB> kdtree;
	kdtree.setInputCloud(pclPTC);

	int k = 9;
	if (algFlag)
	{

		for (int i = 0; i < pclPTC->points.size(); i++)
		{
			std::vector<int> pointIdxKNNSearch;
			std::vector<Vertex> shapiroIn;
			std::vector<float> pointKNNSquaredDistance;

			if (kdtree.nearestKSearchT(pclPTC->points[i], k, pointIdxKNNSearch, pointKNNSquaredDistance) > 0)
			{
				for (int j = 0; j < pointIdxKNNSearch.size(); j++)
				{
					int idx = pointIdxKNNSearch[j] - 1;
					shapiroIn.push_back(Vertex(pclPTC->points[idx].x, pclPTC->points[idx].y, pclPTC->points[idx].z));
				}
				float flag = swtest.ShapiroWilkTest(shapiroIn);

				pclPTC->points[i].r = flag * 255, pclPTC->points[i].g = flag * 255, pclPTC->points[i].b = flag * 255;

				if (saveFlag)
				{
					saveFlag = false;
					ObjManager::SaveXYZWithRGB("Result.xyz", pclPTC);
				}
			}
		}
	}

	// draw scene - update point cloud
	viewer.removePointCloud();

	if (!viewer.addPointCloud(pclPTC))
		viewer.updatePointCloud(pclPTC);
}

/// todo : keyboard controller update
int main()
{
	// azure kinect device
	unique_ptr<azure_kinect> kinectDevice;

	int menu = 0;

	cout << "Choose Menu" << endl;
	cout << "1 - Kinect Single Shot" << endl;
	cout << "2 - Load Obj" << endl;
	cout << "else - exit" << endl << "input : ";

	cin >> menu;

	switch (menu)
	{
	case 1:
	{
		// azure kinect setup
		kinectDevice = make_unique<azure_kinect>(1);

	}
		break;
	case 2:
	{
		/*ObjManager objMng;
		objMng.ReadOBJ(".\\Data\\data.obj");

		auto data = objMng.getOBJ();

		auto pclPC = data_mng::ConvertVertex2PCL(data);*/

	}
		break;
	default:
		break;
	}

	return 0;
}