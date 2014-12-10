#ifndef piesectordata_h
#define piesectordata_h

#include "Vector3f.h"

class PieSectorData
{
private:

	// Store color for the pie slice.
	Vector3f sectorColor;

	// Stores the value of the data this pie sector represents.
	int data;

	// Store the angle of the pie sector.
	float angle;

public:

	PieSectorData();

	void SetColor(Vector3f);
	Vector3f GetColor();

	void SetData(int);
	int GetData();

	void SetAngle(float);
	float GetAngle();

};
#endif