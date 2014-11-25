#ifndef linechart_h
#define linechart_h

#include "LineChartData.h"

#include <string>
#include <vector>

class LineChart
{
private:

	std::vector<LineChartData> data;

	std::string title;

	float endX;
	float endY;

	double highestDataValue;

	// Defines the 0, 0 origin for the axis of the chart.
	const float START_X = -550.0f;
	const float START_Y = -400.0f;

	const float WIDTH = 1800.0f;
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