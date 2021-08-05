#pragma once
#include "stdafx.h"
#include "Kinect\azure_kinect.h"
#include "Application\FeatureDetect.h"
#include "Util\timer.h"
#include "Util\mkv_controller.h"
#include "DataManagement\data_mng.h"
#include "DataManagement\ObjManager.h"

/// todo : keyboard controller update
int main()
{
	// azure kinect device
	unique_ptr<azure_kinect> kinectDevice;

	int menu = 0;

	cout << "Choose Menu" << endl;
	cout << "1 - Kinect Single Shot" << endl;
	cout << "2 - Load Obj" << endl;
	cout << "3 - Load .mkv and Save obj" << endl;
	cout << "else - exit" << endl << "input : ";

	cin >> menu;

	FeatureDetect alg;

	//timer
	timer tim;

	switch (menu)
	{
	case 1:
	{
		// azure kinect setup
		kinectDevice = make_unique<azure_kinect>(1);
		alg.RunSingleShoot(kinectDevice, 9);

	}
	break;
	case 2:
	{
		ObjManager obj;
		
		string str = DATAPATH;
		str += "data1.obj";
		
		obj.ReadOBJ(str.c_str());
		auto data = obj.getOBJ();
		
		tim.StartTimer();
		auto pclData = alg.RunSinglOBJ(data, 25);
		cout << tim.getDuration() << endl;

		string save = "result1.obj";
		obj.SaveXYZWithRGB(save.c_str(), pclData);
	}
	break;
	case 3:
	{
		string str = DATAPATH;
		str += "data1.mkv";

		mkv_controller mkvCon;
		mkvCon.openPlayback(str);

		data_mng dMNG;

		k4a::calibration calib;
		mkvCon.getCalib(calib);

		dMNG.setTransformation(calib);

		for (register int i = 0; i < 100; i++)
		{
			k4a::image data;
			mkvCon.getDepthFrame(data);
			auto pc = dMNG.ConvertDepth2PointCloud(data);
			dMNG.setData(pc);
		}

		dMNG.saveDataSet();
	}
	break;
	default:
		break;
	}

	return 0;
}