#ifndef graph_h
#define graph_h

#include "Vector2D.h"

class Graph
{

private:

	int width, height;

public:

	virtual void DrawAxis() = 0;
	virtual void ReadData() = 0;

	void SetGraphWidth(int _width) { width = _width; }
	void SetGraphHeight(int _height) { height = _height; }

	int GetGraphWidth() { return width; }
	int GetGraphHeight() { return height; }
};

#endif