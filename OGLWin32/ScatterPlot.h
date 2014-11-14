#ifndef scatterplot_h
#define scatterplot_h

#include "Graph.h"

class ScatterPlot : public Graph
{
private:



public:

	ScatterPlot();

	void DrawAxis(float, float);
	void Draw();
	void Draw3D();
	void ReadData();

};

#endif