#include "BarChart.h"
#include "FileUtils.h"
#include "FontRenderer.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>
#include <fstream>
#include <sstream>

BarChart::BarChart()
{
	
}

BarChart::BarChart(std::string _title) : BarChart::BarChart()
{
	title = _title;
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

	FontRenderer::RenderText(title, 0.5f, startX, endY + 90.0f, Vector3f(0.0f, 1.0f, 1.0f), true);

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

	FontRenderer::RenderText("X", 0.1f, startX - 15.0f, startY + 5.0f, Vector3f(1.0f, 0.0f, 0.0f));
	FontRenderer::RenderText("Y", 0.1f, startX - 3.0f, startY - 7.0f, Vector3f(0.0f, 1.0f, 0.0f));
}

/*
* Draws the axis and bars to the screen.
*/
void BarChart::Draw()
{
	DrawAxis(1000.0f, 500.0f);

	for (size_t i = 0; i < bars.size(); ++i)
	{
		bars[i].Draw();
	}
}

/*
* Reads data from a file.
*/
void BarChart::ReadData()
{ 
	std::string fileDir = "adult_test_data.csv";

	if (FileUtils::FileExists(fileDir))
	{
		std::cout << "Loading: " << fileDir << std::endl;
	}
	else
	{
		std::cout << "Failed to load csv file: " << fileDir << std::endl;
	}

	std::vector<std::string> testdata;

	for (size_t i = 0; i < 100; ++i)
		testdata.push_back("Male");

	for (size_t i = 0; i < 4; ++i)
		testdata.push_back("Female");

	int maleCount = 0, femaleCount = 0;

	for (size_t i = 0; i < testdata.size(); ++i)
	{
		if (testdata[i] == "Male")
			maleCount++;
		else if (testdata[i] == "Female")
			femaleCount++;
	}

	Bar2D maleBar = Bar2D();
	BarChartData maleData = BarChartData("Males");
	maleData.SetColor(Vector3f(1.0f, 0.0f, 0.0f));
	maleData.SetData(maleCount);
	maleBar.SetWidth(500 / 2 - 2.0f);
	maleBar.SetHeight(maleCount * 500.0f / testdata.size());
	maleBar.SetBottomLeft(Vector2f(-399.0f, -199.0f));
	maleBar.SetBarData(maleData);
	bars.push_back(maleBar);

	Bar2D femaleBar = Bar2D();
	BarChartData femaleData = BarChartData("Females");
	femaleData.SetColor(Vector3f(1.0f, 1.0f, 0.0f));
	femaleData.SetData(femaleCount);
	femaleBar.SetWidth(500.0f / 2 - 2.0f);
	femaleBar.SetHeight(femaleCount * 500.0f / testdata.size());
	femaleBar.SetBottomLeft(Vector2f(bars[bars.size() - 1].GetBottomLeft().GetX() + bars[bars.size() - 1].GetWidth() + 2.0f, -199.0f));
	femaleBar.SetBarData(femaleData);
	bars.push_back(femaleBar);

	Bar2D altBar = Bar2D();
	BarChartData altData = BarChartData("Alt");
	altData.SetColor(Vector3f(1.0f, 0.0f, 1.0f));
	altData.SetData(maleCount);
	altBar.SetWidth(500.0f / 2.0f - 2.0f);
	altBar.SetHeight(maleCount * 500.0f / testdata.size());
	altBar.SetBottomLeft(Vector2f(bars[bars.size() - 1].GetBottomLeft().GetX() + bars[bars.size() - 1].GetWidth() + 2.0f, -199.0f));
	altBar.SetBarData(altData);
	bars.push_back(altBar);

	//Bar2D maleBar = Bar2D();
	//maleBar.SetHeight(maleCount * 500 / testdata.size()); // multiply the value of maleCount by the height of the graph then divide by the total number of data entries. This scales the bar nicely.
	//maleBar.SetWidth(500 / 2 - 2.0f); // divide width of chart by number of categories (in this case male and female so 2) then minus 2.0f as the seperator offset
	//maleBar.SetBottomLeft(Vector2f(-399.0f, -199.0f));
	//bars.push_back(maleBar);

	//Bar2D femaleBar = Bar2D();
	//femaleBar.SetHeight(femaleCount * 500 / testdata.size());
	//femaleBar.SetWidth(500 / 2 - 2.0f);
	//femaleBar.SetBottomLeft(Vector2f(maleBar.GetBottomLeft().GetX() + maleBar.GetWidth() + 2.0f, -199.0f));
	//bars.push_back(femaleBar);
}