#ifndef piechart_h
#define piechart_h

#include "PieSectorData.h"

#include <vector>
#include <string>

class PieChart
{
private:

	// Stores the data for each individual pie slice.
	std::vector<PieSectorData> data;

	// Stores the total sum of data read.
	int dataTotal;

	// Stores the title of the chart.
	std::string title;

	// Defines the starting X coordinate for the pie legend.
	const float LEGEND_START_X = 400.0f;

	// Defines the starting Y coordinate for the pie legend.
	const float LEGEND_START_Y = 250.0f;

public:

	PieChart();
	PieChart(std::string);

	std::string GetTitle();

	void Draw(float, float, float);
	void DrawLegend();
	void ReadData();
	
	int GetDataTotal();
};
#endif