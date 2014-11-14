#ifndef linechart_h
#define linechart_h

#include "Graph.h"
#include "Vector2f.h"

#include <vector>

class LineChart : public Graph
{
private:
	std::vector<Vector2f> points;

public:

	LineChart();

	void DrawAxis(float, float);
	void Draw();
	void PlotPoint(float);
	void ReadData();

};

#endif