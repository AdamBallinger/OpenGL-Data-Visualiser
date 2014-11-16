#ifndef piesectordata_h
#define piesectordata_h

#include "Vector3f.h"

class PieSectorData
{
private:

	// Store color for the pie sector in Vector3f.
	Vector3f sectorColor;

	// number of segments this data uses.
	int data;
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