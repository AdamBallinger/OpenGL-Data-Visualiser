#ifndef spiderchartdata_h
#define spiderchartdata_h

#include <string>

class SpiderChartData
{
private:

	// Store the data value for this specific branch.
	int data;

	std::string name;

public:

	SpiderChartData();

	void SetData(int);
	int GetData();

	void SetName(std::string);
	std::string GetName();
};

#endif