#ifndef bar3d_h
#define bar3d_h

#include "BarChartData.h"
#include "Vector3f.h"

class Bar3D
{

private:

	BarChartData data;
	Vector3f bottomLeft;

	float height;
	float width;
	float depth;

public:

	Bar3D();
	Bar3D(Vector3f);

	void Draw();

	void SetBarData(BarChartData);
	BarChartData GetBarData();

	void SetBottomLeft(Vector3f);
	Vector3f GetBottomLeft();

	void SetHeight(float);
	float GetHeight();

	void SetWidth(float);
	float GetWidth();

	void SetDepth(float);
	float GetDepth();

};

#endif