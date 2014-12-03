#include "ScatterPlotData3D.h"

ScatterPlotData3D::ScatterPlotData3D()
{
	xData = 0;
	yData = 0;
	zData = 0;
}

void ScatterPlotData3D::SetXData(double _xData)
{
	xData = _xData;
}

double ScatterPlotData3D::GetXData()
{
	return xData;
}

void ScatterPlotData3D::SetYData(double _yData)
{
	yData = _yData;
}

double ScatterPlotData3D::GetYData()
{
	return yData;
}

void ScatterPlotData3D::SetZData(double _zData)
{
	zData = _zData;
}

double ScatterPlotData3D::GetZData()
{
	return zData;
}