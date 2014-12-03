#ifndef scatterplot3d_h
#define scatterplot3d_h

#include "ScatterPlotData3D.h"

#include <vector>
#include <string>

class ScatterPlot3D
{
private:

	// Store the different points of data for the chart.
	std::vector<ScatterPlotData3D> data;

	// Set the title of the chart
	std::string title;

	// Store the highest values for the X, Y and Z axis from the imported data.
	double highestValueX;
	double highestValueY;
	double highestValueZ;

	// Set the dimensional values of the 3D axis.
	const float WIDTH = 250.0f;
	const float HEIGHT = 250.0f;
	const float DEPTH = 250.0f;

	const float START_X = 0.0f;
	const float START_Y = 0.0f;
	const float START_Z = 0.0f;

public:

	ScatterPlot3D();
	ScatterPlot3D(std::string);

	void DrawAxis(float, float, float);
	void Draw();
	void ReadData();

	void SetHighestValueX(double);
	double GetHighestValueX();

	void SetHighestValueY(double);
	double GetHighestValueY();

	void SetHighestValueZ(double);
	double GetHighestValueZ();

	std::string GetTitle();

};

#endif