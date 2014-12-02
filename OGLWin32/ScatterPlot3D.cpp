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
* Draw 3D axis
*/
void ScatterPlot3D::DrawAxis(float width, float height, float depth)
{
	float endX = START_X + width;
	float endY = START_Y + height;
	float endZ = START_Z + depth;

	glLineWidth(2.5f);
	glBegin(GL_LINES);

	// Draw X Axis
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(START_X, START_Y);
	glVertex2f(endX, -endY / 2);

	// Draw Y Axis
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(START_X, START_Y);
	glVertex2f(START_X, endY);

	// Draw Z Axis
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(START_Z, START_Y);
	glVertex2f(-endZ, -endY / 2);

	// Draw connecting lines between axis'
	// Draw line from top of Y along X axis
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(START_X, endY);
	glVertex2f(endX, endY / 2);

	// Draw line connecting from above to end of the X axis
	glVertex2f(endX, endY - endY / 2);
	glVertex2f(endX, -endY / 2);

	// Draw line from top of Y along the Z axis
	glVertex2f(START_X, endZ);
	glVertex2f(-endZ, endY / 2);

	// Draw line connecting from above to end of Z axis
	glVertex2f(-endZ, endY / 2);
	glVertex2f(-endZ, -endY / 2);

	// Draw line from end of Z axis heading down the X axis
	glVertex2f(-endZ, -endY / 2);
	glVertex2f(START_X, -endY);

	// Draw line from end of Z axis heading down the Z axis
	glVertex2f(endX, -endY / 2);
	glVertex2f(START_X, -endY);

	glEnd();
}

void ScatterPlot3D::Draw()
{
	DrawAxis(WIDTH, HEIGHT, DEPTH);
}

void ScatterPlot3D::ReadData()
{

}