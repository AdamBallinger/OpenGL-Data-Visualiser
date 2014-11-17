#ifndef barchartdata_h
#define barchartdata_h

#include "Vector3f.h"

#include <string>

class BarChartData
{
private:

	std::string dataName;
	int dataValue;
	Vector3f dataColor;

public:

	BarChartData();
	BarChartData(std::string);

	void SetDataName(std::string);
	std::string GetDataName();

	void SetData(int);
	int GetData();

	void SetColor(Vector3f);
	Vector3f GetColor();

};

#endif