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

public:

	PieChart();
	PieChart(std::string);

	std::string GetTitle();

	void Draw(float, float, float);
	void ReadData();
	
	int GetDataTotal();
};
#endif