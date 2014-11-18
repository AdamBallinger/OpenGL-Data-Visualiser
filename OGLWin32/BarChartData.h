#ifndef barchartdata_h
#define barchartdata_h

#include "Vector3f.h"

#include <string>

class BarChartData
{
private:

	std::string dataName;
	int dataValue;
	Vector3f dataColor;

public:

	BarChartData();

	// Initialize the data with the name of the data displayed under each bar in the chart.
	BarChartData(std::string);

	// Sets the name rendered under each bar.
	void SetDataName(std::string);
	std::string GetDataName();

	void SetData(int);
	int GetData();

	void SetColor(Vector3f);
	Vector3f GetColor();

};

#endif