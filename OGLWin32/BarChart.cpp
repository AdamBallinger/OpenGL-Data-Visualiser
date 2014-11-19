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

int BarChart::GetDataTotal()
{
	return dataTotal;
}

/*
* Draws the x and y axis of the graph with a given width and height for each axis
*/
void BarChart::DrawAxis(float width, float height)
{
	// end points for each axis.
	endX = START_X + width;
	endY = START_Y + height;

	FontRenderer::RenderText(title, 0.5f, START_X, endY + 90.0f, Vector3f(0.0f, 1.0f, 1.0f), true);

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

	// Draw lowest value (0) for the Y axis
	FontRenderer::RenderText("Y : 0", 0.3f, START_X - 80.0f, START_Y + 15.0f, Vector3f(0.0f, 1.0f, 0.0f));
	// Draw highest value for the Y axis
	FontRenderer::RenderText("Y : " + std::to_string(GetDataTotal()), 0.3f, START_X - 80.0f, endY + 40.0f, Vector3f(0.0f, 1.0f, 0.0f));
}

/*
* Draws the axis and bars to the screen.
*/
void BarChart::Draw()
{
	DrawAxis(WIDTH, HEIGHT);

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

	for (size_t i = 0; i < 300; ++i)
		testdata.push_back("Male");

	for (size_t i = 0; i < 100; ++i)
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
	maleBar.SetHeight(maleCount * HEIGHT / testdata.size());
	maleBar.SetBarData(maleData);
	bars.push_back(maleBar);

	Bar2D femaleBar = Bar2D();
	BarChartData femaleData = BarChartData("Females");
	femaleData.SetColor(Vector3f(1.0f, 1.0f, 0.0f));
	femaleData.SetData(femaleCount);
	femaleBar.SetHeight(femaleCount * HEIGHT / testdata.size());
	femaleBar.SetBarData(femaleData);
	bars.push_back(femaleBar);

	// Set both the width and position of each bar and get the total amount of data
	for (size_t i = 0; i < bars.size(); ++i)
	{
		bars[i].SetWidth(WIDTH / bars.size() - 2.0f);

		// Check if its the 1st bar so we can set it the X of it to the starting x of the axis so other bars position correctly after it.
		if (i == 0)
		{
			bars[i].SetBottomLeft(Vector2f(START_X + 1.0f, START_Y + 1.0f));
		}
		else
		{
			bars[i].SetBottomLeft(Vector2f(bars[i - 1].GetBottomLeft().GetX() + bars[i - 1].GetWidth() + 2.0f, START_Y + 1.0f));
		}
		dataTotal += bars[i].GetBarData().GetData();
	}

	//Bar2D maleBar = Bar2D();
	//maleBar.SetHeight(maleCount * 500 / testdata.size()); // multiply the value of maleCount by the height of the graph then divide by the total number of data entries. This scales the bar nicely.
	//maleBar.SetWidth(WIDTH / bars.size() - 2.0f); // divide width of chart by number of bars (in this case male and female so 2) then minus 2.0f as the seperator offset
	//maleBar.SetBottomLeft(Vector2f(-399.0f, -199.0f));
	//bars.push_back(maleBar);

	//Bar2D femaleBar = Bar2D();
	//femaleBar.SetHeight(femaleCount * 500 / testdata.size());
	//femaleBar.SetWidth(WIDTH / bars.size() - 2.0f);
	//femaleBar.SetBottomLeft(Vector2f(maleBar.GetBottomLeft().GetX() + maleBar.GetWidth() + 2.0f, -199.0f));
	//bars.push_back(femaleBar);
}