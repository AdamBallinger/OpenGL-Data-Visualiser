#ifndef barchart_h
#define barchart_h

#include "Graph.h"
#include "Bar2D.h"

#include <vector>
#include <string>

class BarChart : public Graph
{

private:

	// Stores each bar of data.
	std::vector<Bar2D> bars;

	// Stores the title for the chart that is rendered at the top of the chart.
	std::string title;

public:

	BarChart();
	BarChart(std::string);

	void DrawAxis(float, float);
	void Draw();
	void ReadData();

};

#endif