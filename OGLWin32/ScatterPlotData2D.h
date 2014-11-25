#ifndef scatterplotdata_h
#define scatterplotdata_h

class ScatterPlotData2D
{
private:

	// Store the temperature data
	double temperatureData;

	// Store the sales value data
	double salesData;

public:

	ScatterPlotData2D();

	void SetTemperatureData(double);
	double GetTemperatureData();

	void SetSalesData(double);
	double GetSalesData();

};

#endif