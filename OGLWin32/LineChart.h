#ifndef linechart_h
#define linechart_h

#include "LineChartData.h"

#include <string>
#include <vector>

class LineChart
{
private:

	// Stores the data for the chart to be plotted.
	std::vector<LineChartData> data;

	// Stores the title of the chart.
	std::string title;

	// Stores the ending X coordinate of the chart axis.
	float endX;

	// Stores the ending Y coordinate of the chart axis.
	float endY;

	// Stores the value of the highest piece of data read.
	double highestDataValue;

	// Defines the starting X coordinate for the chart axis.
	const float START_X = -550.0f;

	// Defines the starting Y coordinate for the chart axis.
	const float START_Y = -400.0f;

	// Defines the axis width.
	const float WIDTH = 1800.0f;

	// Defines the axis height.
	const float HEIGHT = 800.0f;

public:

	LineChart();
	LineChart(std::string);

	void SetTitle(std::string);
	std::string GetTitle();

	double GetHighestDataValue();

	void DrawAxis(float, float);
	void Draw();
	void ReadData();

};

#endif