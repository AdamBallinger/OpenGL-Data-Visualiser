#ifndef scatterplot_h
#define scatterplot_h

class ScatterPlot
{
private:

	bool is3D;

public:

	ScatterPlot();

	void SetIs3D(bool);
	bool GetIs3D();

	void DrawAxis2D(float, float);
	void DrawAxis3D(float, float, float);
	void Draw();
	void Draw3D();
	void ReadData();

};

#endif