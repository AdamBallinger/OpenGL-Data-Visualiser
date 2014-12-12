#ifndef barchart3d_h
#define barchart3d_h

#include "Bar3D.h"

#include <string>
#include <vector>

class BarChart3D
{
private:

	std::vector<Bar3D> bars;

	std::string chartTitle;

	int dataTotal;

	float endX;
	float endY;
	float endZ;

	const float START_X = 0.0f;
	const float START_Y = 0.0f;
	const float START_Z = 0.0f;

	const float WIDTH = 250.0f;
	const float HEIGHT = 250.0f;
	const float DEPTH = 100.0f;

public:

	BarChart3D();
	BarChart3D(std::string);

	void Draw();
	void DrawAxis(float, float, float);
	void ReadData();

	int GetDataTotal();

};

#endif