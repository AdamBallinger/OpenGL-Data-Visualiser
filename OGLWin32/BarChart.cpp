#include "BarChart.h"

#include <Windows.h>
#include <GL/GL.h>

#include"DataProcessor.h"

BarChart::BarChart()
{
	
}

void BarChart::DrawAxis()
{
	glLineWidth(1.3f);
	glBegin(GL_LINES);

	// Draw X Axis
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-400.0f, -200.0f);
	glVertex2f(400.0f, -200.0f);

	// Draw Y Axis
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-400.0f, -199.0f);
	glVertex2f(-400.0f, 301.0f);

	glEnd();
}

void BarChart::ReadData()
{
	DataProcessor dp = DataProcessor();
	dp.ReadCsv("G:\\data_samples_01\\adult_test_data.csv");
}