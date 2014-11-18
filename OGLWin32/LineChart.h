#ifndef linechart_h
#define linechart_h

#include <vector>

class LineChart
{
private:
	std::vector<float> points;

public:

	LineChart();

	void DrawAxis(float, float);
	void Draw();
	void ReadData();

};

#endif