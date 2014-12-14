#include "ScatterPlotData2D.h"

ScatterPlotData2D::ScatterPlotData2D()
{
	temperatureData = 0;
	salesData = 0;
}

void ScatterPlotData2D::SetTemperatureData(float _data)
{
	temperatureData = _data;
}

float ScatterPlotData2D::GetTemperatureData()
{
	return temperatureData;
}

void ScatterPlotData2D::SetSalesData(float _data)
{
	salesData = _data;
}

float ScatterPlotData2D::GetSalesData()
{
	return salesData;
}