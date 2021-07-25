#pragma once
#include "stdafx.h"

#include "Kinect\azure_kinect.h"
#include "DataManagement\ObjManager.h"
#include "DataManagement\data_mng.h"
#include "Util\timer.h"

// azure kinect device
unique_ptr<azure_kinect> kinectDevice;

// scene draw for realtime kinect
void drawSceneKinect(pcl::visualization::PCLVisualizer& viewer)
{
	// update every frame
	auto ptc = kinectDevice->getPointCloudFromSingleDevice();

	auto pclPTC = data_mng::ConvertPointCloud2Vertex(ptc);

	// processing function call


	// draw scene - update point cloud
	
	viewer.removePointCloud();

	if (!viewer.addPointCloud(pclPTC))
		viewer.updatePointCloud(pclPTC);
}

// scene draw for load obj
void drawSceneObj(pcl::visualization::PCLVisualizer& viewer)
{
}

/// todo : keyboard controller update
int main()
{

	int menu = 0;

	cout << "Choose Menu" << endl;
	cout << "1 - Realtime Kinect" << endl;
	cout << "2 - Load Obj" << endl;
	cout << "else - exit" << endl;

	cin >> menu;

	switch (menu)
	{
	case 1:
	{
		// azure kinect setup
		kinectDevice = make_unique<azure_kinect>(1);

		// pcl viewer setup
		pcl::visualization::CloudViewer viewer("Tester");

		//This will only get called once
		//viewer.runOnVisualizationThreadOnce(once);

		//This will get called once per visualization iteration
		viewer.runOnVisualizationThread(drawSceneKinect);

		while (!viewer.wasStopped())
		{
		}
	}
		break;
	case 2:
	{

	}
		break;
	default:
		break;
	}

	return 0;
}