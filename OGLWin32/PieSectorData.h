#ifndef piesectordata_h
#define piesectordata_h

#include "Vector3f.h"

class PieSectorData
{
private:

	// Store color for the pie sector in Vector3f.
	Vector3f sectorColor;

	// number of segments this data uses.
	int segments;

public:

	PieSectorData();

	void SetColor(Vector3f);
	Vector3f GetColor();

	void SetSegments(int);
	int GetSegments();

};
#endif