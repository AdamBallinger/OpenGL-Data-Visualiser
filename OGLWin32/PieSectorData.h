#ifndef piesectordata_h
#define piesectordata_h

#include "Vector3f.h"

#include <string>

class PieSectorData
{
private:

	// Store color for the pie slice.
	Vector3f sectorColor;

	// Store the name of the data the sector represents.
	std::string dataName;

	// Stores the value of the data this pie sector represents.
	int data;

	// Store the angle of the pie sector.
	float angle;

public:

	PieSectorData();

	void SetColor(Vector3f);
	Vector3f GetColor();

	void SetName(std::string);
	std::string GetName();

	void SetData(int);
	int GetData();

	void SetAngle(float);
	float GetAngle();

};
#endif