#include "BarChart3D.h"
#include "FontRenderer.h"
#include "FileUtils.h"
#include "BarChartData.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>
#include <sstream>
#include <fstream>

BarChart3D::BarChart3D()
{
	dataTotal = 0;
}

BarChart3D::BarChart3D(std::string _chartTitle) : BarChart3D::BarChart3D()
{
	chartTitle = _chartTitle;
}

void BarChart3D::DrawAxis(float width, float height, float depth)
{
	// end points for each axis.
	endX = START_X + width;
	endY = START_Y + height;
	endZ = START_Z - depth;

	FontRenderer::RenderText(chartTitle, 0.5f, START_X, endY + 90.0f, Vector3f(0.0f, 1.0f, 1.0f), true);

	// Draw X Axis
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(START_X, START_Y, START_Z);
	glVertex3f(endX, START_Y, START_Z);
	glVertex3f(endX, START_Y, endZ);
	glVertex3f(START_X, START_Y, endZ);

	glEnd();

	// Draw Y Axis
	glBegin(GL_POLYGON);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(START_X, START_Y, START_Z);
	glVertex3f(START_X, endY, START_Z);
	glVertex3f(START_X, endY, endZ);
	glVertex3f(START_X, START_Y, endZ);

	glEnd();

	// Draw lowest value (0) for the Y axis
	FontRenderer::RenderText("Y : 0", 0.2f, START_X - 80.0f, START_Y + 15.0f, Vector3f(0.0f, 1.0f, 0.0f));
	// Draw highest value for the Y axis
	FontRenderer::RenderText("Y : " + std::to_string(GetDataTotal()), 0.2f, START_X - 80.0f, endY + 40.0f, Vector3f(0.0f, 1.0f, 0.0f));
}

void BarChart3D::Draw()
{
	DrawAxis(WIDTH, HEIGHT, DEPTH);

	for (size_t i = 0; i < bars.size(); ++i)
	{
		bars[i].Draw();
	}
}

int BarChart3D::GetDataTotal()
{
	return dataTotal;
}

void BarChart3D::ReadData()
{
	std::string fileDir = "adult_test_data.csv";

	if (FileUtils::FileExists(fileDir))
	{
		std::cout << "[Bar Chart] Loading: " << fileDir << std::endl;

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
		std::cout << "Data finished loading" << std::endl;

		// Store the total amount of males and females so the height of the bars can be scaled to fit the screen.
		int total = maleCount + femaleCount;

		Bar3D bar = Bar3D();
		bar.SetDepth(DEPTH);
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
		std::cout << "[Bar Chart3D] Failed to load csv file: " << fileDir << std::endl;
	}

	// Set both the width and position of each bar and get the total amount of data
	for (size_t i = 0; i < bars.size(); ++i)
	{
		bars[i].SetWidth(WIDTH / bars.size() - 10.0f);

		// Check if its the 1st bar so we can set the X of it to the starting x of the axis so other bars position correctly after it.
		if (i == 0)
		{
			bars[i].SetBottomLeft(Vector3f(START_X + 10.0f, START_Y + 1.0f, 0.0f));
		}
		else
		{
			bars[i].SetBottomLeft(Vector3f(bars[i - 1].GetBottomLeft().GetX() + bars[i - 1].GetWidth() + 10.0f, START_Y + 1.0f, 0.0f));
		}
		dataTotal += bars[i].GetBarData().GetData();
	}
}