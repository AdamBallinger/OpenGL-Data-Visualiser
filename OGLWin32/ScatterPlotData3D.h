#ifndef scatterplotdata3d_h
#define scatterplotdata3d_h

class ScatterPlotData3D
{
private:

	double xData;
	double yData;
	double zData;

public:

	ScatterPlotData3D();

	void SetXData(double);
	double GetXData();

	void SetYData(double);
	double GetYData();

	void SetZData(double);
	double GetZData();

};

#endif