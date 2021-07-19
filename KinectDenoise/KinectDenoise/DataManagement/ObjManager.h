#pragma once
#include "stdafx.h"

class ObjManager
{
public:
	ObjManager();
	~ObjManager();
	void ReadOBJ(char* fileName);
	void SaveOBJ(char* fileName);
	void SaveOBJwithTex(char* fileName);
	vector<Vertex> getOBJ();
	vector<Vertex> getData();
	vector<Vertex> getNormal();
	vector<int> getFrameIndex() {
		return m_frameIndex;
	}
	void setNormal(vector<Vertex> normal);
	void setOBJ(vector<Vertex> pt);
	void setFrameIndex(vector<int> Index) {
		m_frameIndex = Index;
	}
	void ReadXYZNoGrid(char* fileName);
	void ReadXYZ(char* fileName);
	void ReadNormal(char* fileName);
private:
	vector<Vertex> m_Vertices;
	vector<Vertex> m_Data;
	vector<Vertex> m_Normal;
	vector<int> m_frameIndex;
	int m_frameIndexMax;
	void findIndexMax();
	int m_textureIndex;
};

