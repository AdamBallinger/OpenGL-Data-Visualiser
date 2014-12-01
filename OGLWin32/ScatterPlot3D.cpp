#include "ScatterPlot3D.h"
#include "OGLWindow.h"

#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>

ScatterPlot3D::ScatterPlot3D()
{

}

ScatterPlot3D::ScatterPlot3D(std::string _title)
{
	title = _title;
}

std::string ScatterPlot3D::GetTitle()
{
	return title;
}

/*
* Draw 3d axis. Draw an inverted cube to give the illusion of a 3d space for the scatter plot.
*/
void ScatterPlot3D::DrawAxis(float width, float height, float depth)
{
	float endX = START_X + width;
	float endY = START_Y + height;
}

void ScatterPlot3D::Draw()
{
	DrawAxis(WIDTH, HEIGHT, DEPTH);
}

void ScatterPlot3D::ReadData()
{

}