#ifndef barchart_h
#define barchart_h

#include "Graph.h"
#include "Bar2D.h"

#include <vector>
#include <string>

class BarChart : public Graph
{

private:
	std::vector<Bar2D> bars;
	std::string title;

public:

	BarChart();
	BarChart(std::string);

	void DrawAxis(float, float);
	void Draw();
	void ReadData();

};

#endif