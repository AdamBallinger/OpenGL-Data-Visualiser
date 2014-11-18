#include "LineChartData.h"

LineChartData::LineChartData()
{

}

void LineChartData::SetData(double _data)
{
	data = _data;
}

double LineChartData::GetData()
{
	return data;
}

void LineChartData::SetDataTime(std::string _dataTime)
{
	dataTime = _dataTime;
}

std::string LineChartData::GetDataTime()
{
	return dataTime;
}