#include "stdafx.h"
#include "FeatureDetect.h"
#include "DataManagement/data_mng.h"
#include "DataManagement/ObjManager.h"
#include "DataManagement/SWTest.h"

void FeatureDetect::Initialize()
{
}

void FeatureDetect::Finalize()
{
}

PCptr FeatureDetect::RunSingleShoot(unique_ptr<azure_kinect>& kinDevice, int knn)
{
	// update every frame
	auto ptc = kinDevice->getPointCloudFromSingleDevice();

	auto pclPTC = data_mng::ConvertKinect2PCL(ptc);

	// normal align to cam view
	NormalAlign(pclPTC, knn);

	// processing function call
	SWTest swtest;
	swtest.Initialize();

	pcl::KdTreeFLANN<pcl::PointXYZRGB> kdtree;
	kdtree.setInputCloud(pclPTC);

	int k = knn;
	int cnt = pclPTC->points.size();

	for (int i = 0; i < cnt; i++)
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
		}
	}

	return pclPTC;
}

PCptr FeatureDetect::RunSinglOBJ(const vector<Vertex>& data, int knn)
{
	auto pclPTC = data_mng::ConvertVertex2PCL(data);
	auto rts = data_mng::ConvertVertex2PCL(data);
	// normal align to cam view
	//NormalAlign(pclPTC, knn);

	// processing function call
	SWTest swtest;
	swtest.Initialize();

	pcl::KdTreeFLANN<pcl::PointXYZRGB> kdtree;
	kdtree.setInputCloud(pclPTC);

	int k = knn;
	int cnt = pclPTC->points.size();

	for (int i = 0; i < cnt; i++)
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
			float flag = swtest.ShapiroWilkTest(shapiroIn) * 255;
			
			rts->points[i].r = flag, pclPTC->points[i].g = flag, pclPTC->points[i].b = flag;
		}
	}

	return rts;
}

void FeatureDetect::NormalAlign(PCptr& pclPC, int knn)
{
	pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne;
	ne.setInputCloud(pclPC);

	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>());
	ne.setSearchMethod(tree);

	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);

	ne.setKSearch(25);

	ne.compute(*cloud_normals);

	int cnt = pclPC->points.size();

	for (int i = 0; i < cnt; i++)
	{
		Eigen::Affine3f transform_2 = Eigen::Affine3f::Identity();
		Eigen::Vector3f camAxis(0.0, 0.0, -1.0);
		Eigen::Vector3f normalAxis(cloud_normals->points[i].normal_x, cloud_normals->points[i].normal_y, cloud_normals->points[i].normal_z);
		Eigen::Vector3f axis = camAxis.cross(normalAxis);
		float theta = (float)(acos(-cloud_normals->points[i].normal_z) * 180 / M_PI);
		if (theta > 90)
		{
			theta = 180 - theta;
			axis = -axis;
		}
		transform_2.rotate(Eigen::AngleAxisf(theta, axis));

		pcl::PointCloud<pcl::PointXYZRGB> temp;
		pcl::PointCloud<pcl::PointXYZRGB> transformedPC;
		pcl::PointXYZRGB tempPoint;
		tempPoint = pclPC->points[i];
		temp.points.push_back(tempPoint);
		temp.width = 1;

		pcl::transformPointCloud(temp, transformedPC, transform_2);

		pclPC->points[i] = transformedPC.points[0];
	}
}
