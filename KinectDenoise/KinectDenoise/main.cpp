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

	auto pclPTC = data_mng::ConvertKinect2PCL(ptc);

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
	cout << "3 - Save Obj" << endl;
	cout << "else - exit" << endl << "input : ";

	cin >> menu;

	// pcl viewer setup
	pcl::visualization::CloudViewer viewer("Tester");

	switch (menu)
	{
	case 1:
	{
		// azure kinect setup
		kinectDevice = make_unique<azure_kinect>(1);

		//This will only get called once
		//viewer.runOnVisualizationThreadOnce(once);

		//This will get called once per visualization iteration
		viewer.runOnVisualizationThread(drawSceneKinect);
	}
		break;
	case 2:
	{
		ObjManager objMng;
		objMng.ReadOBJ(".\\Data\\data.obj");

		auto data = objMng.getOBJ();

		auto pclPC = data_mng::ConvertVertex2PCL(data);

		viewer.showCloud(pclPC);
		//This will get called once per visualization iteration
		viewer.runOnVisualizationThread(drawSceneObj);
	}
		break;
	case 3:
	{
		kinectDevice = make_unique<azure_kinect>(1);

		auto ptc = kinectDevice->getPointCloudFromSingleDevice();

		auto pclPTC = data_mng::ConvertKinect2PCL(ptc);

		pcl::PolygonMesh::Ptr poly = make_shared<::pcl::PolygonMesh>();

		string fileNmae(".\\Data\\data.obj");
		pcl::io::saveOBJFile(fileNmae, *poly);
	}
		break;
	default:
		break;
	}

	if (menu != 3)
	{

		while (!viewer.wasStopped())
		{
		}
	}

	return 0;
}