#include "LineChart.h"
#include "FontRenderer.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>

LineChart::LineChart()
{
	highestDataValue = 0;
}

LineChart::LineChart(std::string _title) : LineChart::LineChart()
{
	SetTitle(_title);
}

void LineChart::SetTitle(std::string _title)
{
	title = _title;
}

std::string LineChart::GetTitle()
{
	return title;
}

void LineChart::DrawAxis(float width, float height)
{
	// end points for each axis.
	endX = START_X + width;
	endY = START_Y + height;

	FontRenderer::RenderText(GetTitle(), 0.5f, START_X, endY + 90.0f, Vector3f(0.0f, 1.0f, 1.0f), true);

	glLineWidth(1.3f);
	glBegin(GL_LINES);

	// Draw X Axis
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(START_X, START_Y);
	glVertex2f(endX, START_Y);

	// Draw Y Axis
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(START_X, START_Y + 0.5f);
	glVertex2f(START_X, endY);

	glEnd();
}

double LineChart::GetHighestDataValue()
{
	return highestDataValue;
}

void LineChart::Draw()
{
	DrawAxis(WIDTH, HEIGHT);

	glLineWidth(2.0f);
	glColor3f(0.75f, 0.75f, 0.75f);
	glBegin(GL_LINE_STRIP);

	for (size_t i = 0; i < data.size(); ++i)
	{
		glVertex2d(i * WIDTH / data.size() + START_X, data[i].GetData() / GetHighestDataValue() * HEIGHT + START_Y); 
		// FOR X GET THE STARTING X + THE CURRENT INDEX * BY THE WIDTH OF THE AXIS / BY THE AMOUNT OF DATA IN THE DATA ARRAY
		// FOR Y DIVIDE THE CURRENT DATA BY THE HIGHEST VALUE OF DATA * THE HEIGHT OF THE Y AXIS + THE START Y OF THE AXIS
	}

	glEnd();
}

void LineChart::ReadData()
{
	LineChartData test1 = LineChartData();
	test1.SetData(10);
	test1.SetDataTime("17:24:00");
	data.push_back(test1);

	LineChartData test2 = LineChartData();
	test2.SetData(30);
	test2.SetDataTime("17:25:00");
	data.push_back(test2);

	LineChartData test3 = LineChartData();
	test3.SetData(110);
	test3.SetDataTime("17:26:00");
	data.push_back(test3);

	LineChartData test4 = LineChartData();
	test4.SetData(25);
	test4.SetDataTime("17:27:00");
	data.push_back(test4);

	LineChartData test5 = LineChartData();
	test5.SetData(60);
	test5.SetDataTime("17:28:00");
	data.push_back(test5);

	LineChartData test6 = LineChartData();
	test6.SetData(1900);
	test6.SetDataTime("17:28:00");
	data.push_back(test6);

	LineChartData test7 = LineChartData();
	test7.SetData(5);
	test7.SetDataTime("17:28:00");
	data.push_back(test7);

	LineChartData test8 = LineChartData();
	test8.SetData(45);
	test8.SetDataTime("17:28:00");
	data.push_back(test8);

	LineChartData test9 = LineChartData();
	test9.SetData(190);
	test9.SetDataTime("17:28:00");
	data.push_back(test9);

	LineChartData test10 = LineChartData();
	test10.SetData(295);
	test10.SetDataTime("17:28:00");
	data.push_back(test10);

	LineChartData test11 = LineChartData();
	test11.SetData(360);
	test11.SetDataTime("17:28:00");
	data.push_back(test11);

	LineChartData test12 = LineChartData();
	test12.SetData(120);
	test12.SetDataTime("17:28:00");
	data.push_back(test12);

	// Get and store the highest value of data loaded
	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i].GetData() > highestDataValue)
			highestDataValue = data[i].GetData();
	}
}