#ifndef barchart_h
#define barchart_h

#include "Bar2D.h"

#include <vector>
#include <string>

class BarChart
{
private:

	// Stores each bar of data.
	std::vector<Bar2D> bars;

	// Stores the title for the chart that is rendered at the top of the chart.
	std::string title;

	// Store the total amount of data imported.
	int dataTotal = 0;

	float endX;
	float endY;

	// Defines the 0, 0 origin for the axis of the chart.
	const float START_X = -550.0f;
	const float START_Y = -400.0f;

	const float HEIGHT = 500.0f;
	const float WIDTH = 1000.0f;

public:

	BarChart();
	BarChart(std::string);

	int GetDataTotal();

	void DrawAxis(float, float);
	void Draw();
	void ReadData();

};

#endif