#include "SpiderChartData.h"

SpiderChartData::SpiderChartData()
{

}

void SpiderChartData::SetData(int _data)
{
	data = _data;
}

int SpiderChartData::GetData()
{
	return data;
}

void SpiderChartData::SetName(std::string _name)
{
	name = _name;
}

std::string SpiderChartData::GetName()
{
	return name;
}