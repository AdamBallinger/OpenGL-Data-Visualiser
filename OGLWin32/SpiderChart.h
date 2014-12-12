#ifndef spiderchart_h
#define spiderchart_h

#include "SpiderChartData.h"

#include <vector>
#include <string>

class SpiderChart
{
private:

	std::vector<SpiderChartData> data;

	// Store the title of the chart.
	std::string title;

	// Store the highest value.
	int highestValue;

	// Defines the size of each line branch for the chart.
	const float AXIS_SIZE = 400.0f;
	
public:

	SpiderChart();
	SpiderChart(std::string);

	void DrawAxis(float);
	void Draw();
	void ReadData();

	int GetHighestValue();

};

#endif