#ifndef piechart_h
#define piechart_h

#include "PieSectorData.h"

#include <vector>
#include <string>

class PieChart
{
private:

	std::vector<PieSectorData> data;
	int dataTotal = 0;

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