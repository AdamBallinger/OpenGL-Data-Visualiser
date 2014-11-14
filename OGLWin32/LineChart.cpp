#include "LineChart.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>

LineChart::LineChart()
{

}

void LineChart::DrawAxis(float width, float height)
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

void LineChart::Draw()
{
	DrawAxis(800.0f, 500.0f);

	glBegin(GL_LINES);

	for (int i = 0; i < points.size() - 1; ++i)
	{
		/*PlotPoint(points[i]);*/
		glVertex2f(points[i], points[i + 1]);
	}

	glEnd();
}

void LineChart::PlotPoint(float point)
{
	
}

void LineChart::ReadData()
{
	points.push_back(-400.0f + 20.0f);
	points.push_back(42.0f);
	points.push_back(105.0f);
	points.push_back(192.0f);
	points.push_back(288.0f);
	points.push_back(499.0f);
	points.push_back(611.0f);
}