#pragma once
#include "stdafx.h"
#include "Kinect\azure_kinect.h"
#include "Application\FeatureDetect.h"
#include "Util\timer.h"

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

	FeatureDetect alg;

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