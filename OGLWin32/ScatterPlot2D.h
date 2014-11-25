#ifndef scatterplot_h
#define scatterplot_h

#include "ScatterPlotData2D.h"

#include <vector>

class ScatterPlot2D
{
private:

	// Store the value of the highest sale
	double highestSalesValue;

	// Store the value of the highest temperature.
	double highestTemperatureValue;

	std::vector<ScatterPlotData2D> data;

	// Size of axis
	const float WIDTH = 500.0f;
	const float HEIGHT = 500.0f;

	// Position of axis 0,0
	const float START_X = -400.0f;
	const float START_Y = -200.0f;

public:

	ScatterPlot2D();

	void DrawAxis(float, float);
	void Draw();
	void ReadData();

	void SetHighestSalesValue(double);
	double GetHighestSale();

	void SetHighestTemperatureValue(double);
	double GetHighestTemperatureValue();

};

#endif