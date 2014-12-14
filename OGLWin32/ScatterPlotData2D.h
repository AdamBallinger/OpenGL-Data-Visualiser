#ifndef scatterplotdata_h
#define scatterplotdata_h

class ScatterPlotData2D
{
private:

	// Store the temperature data.
	float temperatureData;

	// Store the sales value data.
	float salesData;

public:

	ScatterPlotData2D();

	void SetTemperatureData(float);
	float GetTemperatureData();

	void SetSalesData(float);
	float GetSalesData();

};

#endif