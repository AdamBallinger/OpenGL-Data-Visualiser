#ifndef scatterplot3d_h
#define scatterplot3d_h

#include <string>

class ScatterPlot3D
{
private:

	// Set the title of the chart
	std::string title;

	// Set the dimensional values of the 3D axis.
	const float WIDTH = 500.0f;
	const float HEIGHT = 500.0f;
	const float DEPTH = 500.0f;

	const float START_X = 0.0f;
	const float START_Y = 0.0f;
	const float START_Z = 0.0f;

public:

	ScatterPlot3D();
	ScatterPlot3D(std::string);

	void DrawAxis(float, float, float);
	void Draw();
	void ReadData();

	std::string GetTitle();

};

#endif