#ifndef linechartdata_h
#define linechartdata_h

#include "Vector3f.h"

#include <string>

class LineChartData
{
private:

	int data;
	std::string dataTime;

public:

	LineChartData();

	void SetData(int);
	int GetData();

	void SetDataTime(std::string);
	std::string GetDataTime();

};

#endif