#ifndef graph_h
#define graph_h

#include "Vector2D.h"

class Graph
{

private:

	int width, height;

public:

	virtual void DrawAxis(float, float) = 0;
	virtual void ReadData() = 0;
};

#endif