#ifndef scatterplot_h
#define scatterplot_h

#include "ScatterPlotData2D.h"

#include <vector>
#include <string>

class ScatterPlot2D
{
private:

	// Store the title of the chart.
	std::string title;

	// Store the value of the highest sale
	float highestSalesValue;

	// Store the value of the highest temperature.
	float highestTemperatureValue;

	// Store the value of the lowest temperature.
	float lowestTemperatureValue;

	// Store the different points of the graph
	std::vector<ScatterPlotData2D> data;

	// Defines the width of the chart axis.
	const float WIDTH = 500.0f;

	// Defines the height of the chart axis.
	const float HEIGHT = 500.0f;

	// Defines the starting X coordinate for the chart axis.
	const float START_X = -400.0f;

	// Defines the starting Y coordinate for the chart axis.
	const float START_Y = -200.0f;

public:

	ScatterPlot2D();
	ScatterPlot2D(std::string);

	void DrawAxis(float, float);
	void Draw();
	void ReadData();

	void SetHighestSalesValue(float);
	float GetHighestSale();

	void SetHighestTemperatureValue(float);
	float GetHighestTemperatureValue();

	void SetLowestTemperatureValue(float);
	float GetLowestTemperatureValue();

	std::string GetTitle();

};

#endif