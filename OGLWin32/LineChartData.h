#ifndef linechartdata_h
#define linechartdata_h

#include "Vector3f.h"

#include <string>

class LineChartData
{
private:

	// Stores the value of the data ( Y axis ).
	double data;

	// Stores the time value for the data ( X axis ).
	std::string dataTime;

public:

	LineChartData();

	void SetData(double);
	double GetData();

	void SetDataTime(std::string);
	std::string GetDataTime();

};

#endif