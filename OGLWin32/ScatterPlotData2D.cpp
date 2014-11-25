#include "ScatterPlotData2D.h"

ScatterPlotData2D::ScatterPlotData2D()
{

}

void ScatterPlotData2D::SetTemperatureData(double _data)
{
	temperatureData = _data;
}

double ScatterPlotData2D::GetTemperatureData()
{
	return temperatureData;
}

void ScatterPlotData2D::SetSalesData(double _data)
{
	salesData = _data;
}

double ScatterPlotData2D::GetSalesData()
{
	return salesData;
}