#ifndef piechart_h
#define piechart_h

#include "PieSectorData.h"

#include <vector>

class PieChart
{
private:

	std::vector<PieSectorData> data;
	int dataTotal;

public:

	PieChart();

	void Draw(float, float, float, double);
	void ReadData();
	
	int GetDataTotal();
};
#endif