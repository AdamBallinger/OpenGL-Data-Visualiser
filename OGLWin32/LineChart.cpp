#include "LineChart.h"
#include "FontRenderer.h"
#include "FileUtils.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>
#include <fstream>
#include <sstream>

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

	// Check if data exists before rendering the axis information (Will crash if no data exists)
	if (data.empty())
		return;

	// Draw lowest Y value at y 0 for the axis
	FontRenderer::RenderText("Y : 0", 0.3f, START_X - 80.0f, START_Y + 15.0f, Vector3f(0.0f, 1.0f, 0.0f));

	std::ostringstream highestValue;
	highestValue << GetHighestDataValue();
	// Draw highest Y value at top of y for the axis
	FontRenderer::RenderText("Y: " + highestValue.str(), 0.3f, START_X - 120.0f, endY + 15.0f, Vector3f(0.0f, 1.0f, 0.0f));

	// Draw start X value at x 0 for the axis
	FontRenderer::RenderText("X : " + data[0].GetDataTime(), 0.3f, START_X - 9.0f, START_Y - 7.0f, Vector3f(1.0f, 0.0f, 0.0f));

	// Draw end X value at end of the x axis
	FontRenderer::RenderText("X : " + data[data.size() - 1].GetDataTime(), 0.3f, endX - 10.0f, START_Y - 7.0f, Vector3f(1.0f, 0.0f, 0.0f));
	
}

double LineChart::GetHighestDataValue()
{
	return highestDataValue;
}

void LineChart::Draw()
{
	DrawAxis(WIDTH, HEIGHT);
	
	glLineWidth(2.0f);
	glBegin(GL_LINE_STRIP);

	for (size_t i = 0; i < data.size(); ++i)
	{	
		double x = i * WIDTH / data.size() + START_X;
		double y = (data[i].GetData() / GetHighestDataValue() * HEIGHT) + START_Y;

		glColor3f(0.75f, 0.75f, 0.75f);
		glVertex2d(x, y); 

		// Draw a cross over each point of data.
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2d(x + 8, y + 8);
		glVertex2d(x - 8, y - 8);
		glVertex2d(x, y);
		glVertex2d(x - 8, y + 8);
		glVertex2d(x + 8, y - 8);
		glVertex2d(x, y);	
	}
	glEnd();
}

void LineChart::ReadData()
{

	std::string fileDir = "household_power_consumption.csv";

	if (FileUtils::FileExists(fileDir))
	{
		std::cout << "[LineChart] Loading csv file: " << fileDir << std::endl;

		std::ifstream fs(fileDir);

		std::string categories;

		getline(fs, categories);

		std::istringstream categoriesStream(categories);

		int timeIndex = 0;
		int dataIndex = 0;

		bool timeFound = false;

		// Get the index's for the two categories we need. Time and global_active_power
		while (categoriesStream)
		{
			std::string value;
			getline(categoriesStream, value, ';');

			while (!timeFound)
			{
				if (value != "Time")
				{
					timeIndex++;
				}
				else if (value == "Time")
				{
					timeFound = true;
					dataIndex = timeIndex;
					break;
				}
				getline(categoriesStream, value, ';');
			}

			if (value != "Global_active_power")
			{
				dataIndex++;
			}
			else if (value == "Global_active_power")
			{
				break;
			}

		}

		// Limit the number of lines to read from the file. 2million is a bit much 
		int lineLimit = 60;
		int currentLine = 0;

		LineChartData dataPoint = LineChartData();

		// Now go through each line and get the values of time and global_active_power and store then in linechartdata
		while (fs)
		{
			std::vector<std::string> lineSplit;

			if (currentLine > lineLimit)
			{
				break;
			}
			else
			{
				currentLine++;
				
				std::string line;
				getline(fs, line);
				std::istringstream lineStream(line);

				// split each line up
				while (lineStream)
				{
					std::string linePiece;
					getline(lineStream, linePiece, ';');

					lineSplit.push_back(linePiece);
				}

				// Set the corresponding data from the split string
				dataPoint.SetDataTime(lineSplit[timeIndex]);
				dataPoint.SetData(stod(lineSplit[dataIndex]));

				data.push_back(dataPoint);
			}		
		}

		fs.close();
		std::cout << "[LineChart] Data finished loading" << std::endl;
	}
	else
	{
		std::cout << "[LineChart] Could not load csv file: " << fileDir << std::endl;
	}

	// Get and store the highest value of data loaded
	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i].GetData() > highestDataValue)
		{
			highestDataValue = data[i].GetData();
		}
	}
}