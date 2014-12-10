#ifndef scatterplotdata3d_h
#define scatterplotdata3d_h

class ScatterPlotData3D
{
private:

	// Store the data value for the X axis.
	double xData;

	// Store the data value for the Y axis.
	double yData;

	// Store the data value for the Z axis.
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