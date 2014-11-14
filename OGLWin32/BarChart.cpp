#include "BarChart.h"
#include "FileUtils.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>
#include <fstream>
#include <sstream>

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

	for (int i = 0; i < bars.size(); ++i)
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

	for (int i = 0; i < 100; ++i)
		testdata.push_back("Male");

	for (int i = 0; i < 4; ++i)
		testdata.push_back("Female");

	int maleCount = 0, femaleCount = 0;

	for (int i = 0; i < testdata.size(); ++i)
	{
		if (testdata[i] == "Male")
			maleCount++;
		else if (testdata[i] == "Female")
			femaleCount++;
	}

	Bar2D maleBar = Bar2D();
	maleBar.SetHeight(maleCount * 500 / testdata.size()); // multiply the value of maleCount by the height of the graph then divide by the total number of data entries. This scales the bar nicely.
	maleBar.SetWidth(500 / 2 - 2.0f); // divide width of chart by number of categories (in this case male and female so 2) then minus 2.0f as the seperator offset
	maleBar.SetBottomLeft(Vector2f(-399.0f, -199.0f));
	bars.push_back(maleBar);

	Bar2D femaleBar = Bar2D();
	femaleBar.SetHeight(femaleCount * 500 / testdata.size());
	femaleBar.SetWidth(500 / 2 - 2.0f);
	femaleBar.SetBottomLeft(Vector2f(maleBar.GetBottomLeft().GetX() + maleBar.GetWidth() + 2.0f, -199.0f));
	bars.push_back(femaleBar);
}