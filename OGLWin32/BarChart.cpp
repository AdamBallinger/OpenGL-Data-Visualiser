#include "BarChart.h"
#include "FileUtils.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>
#include <fstream>

BarChart::BarChart()
{
	
}

/*
* Draws the x and y axis of the graph with a given width and height for each axis
*/
void BarChart::DrawAxis(float width, float height)
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

/*
* Draws the axis and bars to the screen.
*/
void BarChart::Draw()
{
	DrawAxis(500.0f, 500.0f);
}

/*
* Reads data from a file.
*/
void BarChart::ReadData()
{ 
	std::cout << "Reading data" << std::endl;
	std::string fileDir = "adult_test_data.csv";

	if (FileUtils::FileExists(fileDir))
		std::cout << "GOOD" << std::endl;
	else
		std::cout << "BAD" << std::endl;
}