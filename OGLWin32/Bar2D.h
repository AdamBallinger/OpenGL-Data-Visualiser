#ifndef bar2d_h
#define bar2d_h

#include "BarChartData.h"
#include "Vector2f.h"

class Bar2D
{

private:

	BarChartData data;
	Vector2f bottomLeft;
	float height;
	float width;

public:

	Bar2D();
	Bar2D(Vector2f);

	void Draw();

	void SetBarData(BarChartData);
	BarChartData GetBarData();

	void SetBottomLeft(Vector2f);
	Vector2f GetBottomLeft();

	void SetHeight(float);
	float GetHeight();

	void SetWidth(float);
	float GetWidth();

};

#endif