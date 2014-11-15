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
	
	float startX = -400.0f;
	float startY = -200.0f;

	for (int i = 0; i < points.size() - 1; ++i)
	{
		
	}

	glEnd();
}

void LineChart::ReadData()
{
	
}