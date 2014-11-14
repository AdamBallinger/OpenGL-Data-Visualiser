#ifndef barchart_h
#define barchart_h

#include "Graph.h"
#include "Bar2D.h"

#include <vector>

class BarChart : public Graph
{

private:
	std::vector<Bar2D> bars;

public:

	BarChart();

	void DrawAxis(float, float);
	void Draw();
	void ReadData();

};

#endif