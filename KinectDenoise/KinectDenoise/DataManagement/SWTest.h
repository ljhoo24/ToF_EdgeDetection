#pragma once
#include "stdafx.h"

class SWTest
{
public :
	SWTest();
	~SWTest();

	void setPValue();
	void setPValue(map<int, float> pvalue);
	void setShapiroWilkTable();
	void setShapiroWilkTable(map<int, vector<float>> shapirowilk);
	float ShapiroWilkTest(vector<Vertex> storage);
	void Initialize();
private:
	/// for shapiro wilk test
	map<int, vector<float>> m_ShapiroWilkTable;
	map<int, float> m_PValue;
};

