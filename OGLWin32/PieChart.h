#ifndef piechart_h
#define piechart_h

#include "Graph.h";
#include "PieSectorData.h"

#include <vector>

class PieChart : public Graph
{
private:

	std::vector<PieSectorData> data;

public:

	PieChart();

	void Draw();
	void ReadData();
	
};
#endif