#include "stdafx.h"
#include "ObjManager.h"

ObjManager::ObjManager()
{
	m_textureIndex = 0;
}


ObjManager::~ObjManager()
{
}

void ObjManager::ReadOBJ(const char* fileName)
{
	FILE* fp;
	fp = fopen(fileName, "r");
	int count, v1, v2, v3, v4;
	char ch;
	float x, y, z;
	float r, g, b;

	while (!feof(fp))
	{
		count = fscanf(fp, "%c %f %f %f", &ch, &x, &y, &z);//, &r, &g, &b);
		if (count == 4 && ch == 'v')
		{
			Vertex pt;

			pt.x = x;
			pt.y = y;
			pt.z = z;
			if(z != 0)
				this->m_Vertices.push_back(pt);
		}
	}

	fclose(fp);
}

void ObjManager::SaveOBJ(const char* fileName)
{
	ofstream openFile;
	string filename(fileName);
	string filepath(FILEPATH);
	openFile.open(filepath + filename);

	for (auto pt : m_Vertices)
	{
		openFile << "v " << pt.x << " " << pt.y << " " << pt.z << endl;
	}

	for (auto n : m_Normal)
	{
		openFile << "vn " << n.x << " " << n.y << " " << n.z << endl;
	}
	
	for (auto i : m_frameIndex)
	{
		openFile << i << endl;
	}

	openFile.close();
}

void ObjManager::SaveOBJwithTex(char * fileName)
{
	ofstream openFile;
	string filename(fileName);
	string filepath(FILEPATH);
	openFile.open(filepath + filename);

	string name(fileName);
	name = name.substr(0, name.find(".obj"));
	name += ".mtl";

	openFile << "mtllib ./" << name << endl;

	findIndexMax();

	for (register int i = 0; i < m_Vertices.size(); i++)
	{
		openFile << "v " << m_Vertices[i].x << " " << m_Vertices[i].y << " " << m_Vertices[i].z << endl;
		openFile << "vn " << m_Normal[i].x << " " << m_Normal[i].y << " " << m_Normal[i].z << endl;
	}

	openFile.close();
}

void ObjManager::SaveXYZWithRGB(const char* fileName, pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud)
{
	ofstream openFile;
	string filename(fileName);
	string filepath(FILEPATH);
	openFile.open(filepath + filename);

	int cnt = cloud->points.size();
	for (int i = 0; i < cnt; i++)
	{
		openFile << cloud->points[i].x << " " << cloud->points[i].y << " " << cloud->points[i].z << " " << cloud->points[i].r << " " << cloud->points[i].g << " " << cloud->points[i].b << endl;
	}

	openFile.close();
}

void ObjManager::ReadNormal(char* fileName)
{
	m_Vertices.clear();
	Vertex temp;
	string c, tx, ty, tz;
	string delim = "//";
	ifstream openFile;

	openFile.open(fileName);
	int count = 0;
	while (openFile >> c >> tx >> ty >> tz)
	{
		if (c.compare("vn") == 0)
		{
			temp.x = atof(tx.c_str());
			temp.y = atof(ty.c_str());
			temp.z = atof(tz.c_str());
			m_Normal.push_back(temp);
		}
		if (c.compare("v") == 0)
		{
			temp.x = atof(tx.c_str());
			temp.y = atof(ty.c_str());
			temp.z = atof(tz.c_str());
			m_Vertices.push_back(temp);
		}
		if (c.compare("f") == 0)
		{
			string token = tx.substr(0, tx.find(delim));
			temp.x = atoi(token.c_str());
			token = ty.substr(0, ty.find(delim));
			temp.y = atoi(token.c_str());
			token = tz.substr(0, tz.find(delim));
			temp.z = atoi(token.c_str());
		}
	}

	openFile.close();
}

void ObjManager::findIndexMax()
{
	int temp = 0;
	for (auto i : m_frameIndex)
	{
		if (i > temp)
			temp = i;
	}
	m_frameIndexMax = temp + 1;
}

vector<Vertex> ObjManager::getOBJ()
{
	return this->m_Vertices;
}

vector<Vertex> ObjManager::getData()
{
	return this->m_Data;
}

void ObjManager::setOBJ(vector<Vertex> pt)
{
	m_Vertices.clear();
	m_Vertices = pt;
}

void ObjManager::setNormal(vector<Vertex> normal)
{
	m_Normal.clear();
	m_Normal = normal;
}

vector<Vertex> ObjManager::getNormal()
{
	return m_Normal;
}

void ObjManager::ReadXYZ(char* fileName)
{
	m_Vertices.clear();
	Vertex temp, temp_trash;
	int gridX, gridY;

	ifstream openFile;
	openFile.open(fileName);

	while (openFile >> gridX >> gridY >>temp.x >> temp.y >> temp.z >> temp_trash.x >> temp_trash.y >> temp_trash.z)
	{
		m_Vertices.push_back(temp);
		m_Data.push_back(temp_trash);
	}

	openFile.close();
}


void ObjManager::ReadXYZNoGrid(char* fileName)
{
	m_Vertices.clear();
	Vertex temp,temp_trash;

	ifstream openFile;
	openFile.open(fileName);

	while (openFile >> temp.x >> temp.y >> temp.z >> temp_trash.x >> temp_trash.y >> temp_trash.z)
	{
		m_Vertices.push_back(temp);
		m_Data.push_back(temp_trash);
	}

	openFile.close();
}