#include "BarChartData.h"

BarChartData::BarChartData()
{

}

void BarChartData::SetDataName(std::string _dataName)
{
	dataName = _dataName;
}

std::string BarChartData::GetDataName()
{
	return dataName;
}

void BarChartData::SetData(int _dataValue)
{
	dataValue = _dataValue;
}

int BarChartData::GetData()
{
	return dataValue;
}

void BarChartData::SetColor(Vector3f color)
{
	dataColor = color;
}

Vector3f BarChartData::GetColor()
{
	return dataColor;
}