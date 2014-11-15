#ifndef piechart_h
#define piechart_h

#include "PieSectorData.h"

#include <vector>

class PieChart
{
private:

	std::vector<PieSectorData> data;

public:

	PieChart();

	void Draw(float, float, float, int);
	void ReadData();
	
};
#endif