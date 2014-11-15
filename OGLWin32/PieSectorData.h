#ifndef piesectordata_h
#define piesectordata_h

#include "Vector3f.h"

class PieSectorData
{
private:

	// Store color for the pie sector in Vector3f.
	Vector3f sectorColor;

public:

	PieSectorData();

	void SetColor(Vector3f);
	Vector3f GetColor();

};
#endif