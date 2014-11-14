#include "ScatterPlot.h"
#include "FileUtils.h"

#include <Windows.h>
#include <GL/GL.h>

ScatterPlot::ScatterPlot()
{

}

void ScatterPlot::DrawAxis(float width, float height)
{
	// 0,0 of chart
	float startX = -400.0f;
	float startY = -200.0f;

	// end points for each axis.
	float endX = startX + width;
	float endY = startY + height;

	glLineWidth(1.3f);
	glBegin(GL_LINES);

	// Draw X Axis
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(startX, startY);
	glVertex2f(endX, startY);

	// Draw Y Axis
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(startX, startY + 0.5f);
	glVertex2f(startX, endY);

	glEnd();
}

void ScatterPlot::Draw()
{

}

void ScatterPlot::Draw3D()
{

}

void ScatterPlot::ReadData()
{

}