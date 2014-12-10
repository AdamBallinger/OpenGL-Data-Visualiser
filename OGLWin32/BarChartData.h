#ifndef barchartdata_h
#define barchartdata_h

#include "Vector3f.h"

#include <string>

class BarChartData
{
private:

	// Stores the name of the data this bar represents.
	std::string dataName;

	// Stores the data value this bar represents.
	int dataValue;

	// Stores the color of the bar.
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