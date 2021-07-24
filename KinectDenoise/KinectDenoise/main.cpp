#pragma once
#include "stdafx.h"

#include "Kinect\azure_kinect.h"
#include "DataManagement\ObjManager.h"
#include "Util\timer.h"

// azure kinect device
unique_ptr<azure_kinect> kinectDevice;

// scene draw part
void drawScene(pcl::visualization::PCLVisualizer& viewer)
{
	// update every frame
	auto ptc = kinectDevice->getPointCloudFromSingleDevice();

	//viewer.addPointCloud();
}

int main()
{
	// azure kinect setup
	kinectDevice = make_unique<azure_kinect>(1);

	// pcl viewer setup
	pcl::visualization::CloudViewer viewer("Tester");

	//This will only get called once
	//viewer.runOnVisualizationThreadOnce(once);

	//This will get called once per visualization iteration
	viewer.runOnVisualizationThread(drawScene);

	while (!viewer.wasStopped())
	{
	}


	return 0;
}