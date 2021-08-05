#pragma once
#include "Kinect/azure_kinect.h"
#include "stdafx.h"

class FeatureDetect
{
public :
	FeatureDetect() { Initialize(); };
	~FeatureDetect() { Finalize(); };
	void Initialize();
	void Finalize();
	PCptr RunSingleShoot(unique_ptr<azure_kinect>& kinDevice, int knn);
	PCptr RunSinglOBJ(const vector<Vertex>& data, int knn);
private :
	void NormalAlign(PCptr& pclPC, int knn);
};

