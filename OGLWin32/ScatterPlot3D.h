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

	// Store the highest value on the X axis from the imported data.
	double highestValueX;

	// Stores the highest value on the Y axis from the imported data.
	double highestValueY;

	// Stores the highest value on the Z axis from the imported data.
	double highestValueZ;

	// Defines the width of the chart axis.
	const float WIDTH = 250.0f;

	// Defines the height of the chart axis.
	const float HEIGHT = 250.0f;

	// Defines the depth of the chart axis.
	const float DEPTH = 250.0f;

	// Defines the stating X coordinate of the chart axis.
	const float START_X = 0.0f;

	// Defines the starting Y coordinate of the chart axis.
	const float START_Y = 0.0f;

	// Defines the starting Z coordinate of the chart axis.
	const float START_Z = 0.0f;

public:

	ScatterPlot3D();
	ScatterPlot3D(std::string);

	void DrawAxis(float, float, float);
	void Draw();
	void ReadData();
	void MouseClick(int, int);

	void SetHighestValueX(double);
	double GetHighestValueX();

	void SetHighestValueY(double);
	double GetHighestValueY();

	void SetHighestValueZ(double);
	double GetHighestValueZ();

	std::string GetTitle();

};

#endif