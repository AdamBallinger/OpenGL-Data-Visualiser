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
* For the bar chart, we will be displaying the total number of males and females from the file adult_test_data.csv
*/
void BarChart::ReadData()
{ 
	std::string fileDir = "adult_test_data.csv";

	if (FileUtils::FileExists(fileDir))
	{
		std::cout << "Loading: " << fileDir << std::endl;

		std::ifstream fs(fileDir);

		std::string categories;

		// Get the categories of the csv file first.
		getline(fs, categories);

		// isstringstream allows us to break down the categories line after each ','
		std::istringstream categoriesStream(categories);

		// store temporarily each category broken down from the categoriesStream
		std::string category;

		// Store the number of males read from the file.
		int maleCount = 0;

		// Store the number of females read from the file.
		int femaleCount = 0;

		while (categoriesStream)
		{
			// Loop through each category until we fine the "Gender" category.
			getline(categoriesStream, category, ',');
			if (category == "Gender")
			{
				break;
			}
		}

		// Now loops through every line in the csv file to count up how many males / females there are.
		while (fs)
		{
			std::string line;
			getline(fs, line);
			std::istringstream lineStream(line);

			while (lineStream)
			{
				std::string value;
				getline(lineStream, value, ',');

				if (value == " Male")
				{
					maleCount++;
				}
				else if (value == " Female")
				{
					femaleCount++;
				}
			}
		}
		fs.close();
		std::cout << "Males: " << maleCount << "  Females: " << femaleCount << std::endl;
		std::cout << "Data finished loading" << std::endl;

		// Store the total amount of males and females so the height of the bars can be scaled to fit the screen.
		int total = maleCount + femaleCount;

		Bar2D bar = Bar2D();
		BarChartData barData = BarChartData();
		barData.SetDataName("Males");
		barData.SetData(maleCount);
		barData.SetColor(Vector3f(1.0f, 0.0f, 1.0f));
		bar.SetBarData(barData);
		bar.SetHeight(maleCount * HEIGHT / total);
		bars.push_back(bar);

		barData.SetDataName("Females");
		barData.SetData(femaleCount);
		barData.SetColor(Vector3f(0.0f, 1.0f, 1.0f));
		bar.SetBarData(barData);
		bar.SetHeight(femaleCount * HEIGHT / total);
		bars.push_back(bar);
	}
	else
	{
		std::cout << "Failed to load csv file: " << fileDir << std::endl;
	}

	// Set both the width and position of each bar and get the total amount of data
	for (size_t i = 0; i < bars.size(); ++i)
	{
		bars[i].SetWidth(WIDTH / bars.size() - 2.0f);

		// Check if its the 1st bar so we can set the X of it to the starting x of the axis so other bars position correctly after it.
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
}