#include "ScatterPlot2D.h"
#include "FileUtils.h"
#include "FontRenderer.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>
#include <fstream>
#include <sstream>

ScatterPlot2D::ScatterPlot2D()
{
	SetHighestSalesValue(0);
	SetHighestTemperatureValue(0);
}

void ScatterPlot2D::SetHighestSalesValue(double _data)
{
	highestSalesValue = _data;
}

double ScatterPlot2D::GetHighestSale()
{
	return highestSalesValue;
}

void ScatterPlot2D::SetHighestTemperatureValue(double _data)
{
	highestTemperatureValue = _data;
}

double ScatterPlot2D::GetHighestTemperatureValue()
{
	return highestTemperatureValue;
}

void ScatterPlot2D::DrawAxis(float width, float height)
{
	// end points for each axis.
	float endX = START_X + width;
	float endY = START_Y + height;

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

/*
* Draws the graph to the screen.
*/
void ScatterPlot2D::Draw()
{
	DrawAxis(WIDTH, HEIGHT);

	glPointSize(5.0f);
	glBegin(GL_LINES);

	// Loop through each piece of data
	for (size_t i = 0; i < data.size(); ++i)
	{
		double x = i * WIDTH / data.size() + START_X;
		double y = data[i].GetSalesData() / GetHighestSale() * HEIGHT + START_Y;

		glColor3f(1.0f, 0.5f, 0.5f);
		glVertex2d(x, y);
		glVertex2d(x + 8, y + 8);
		glVertex2d(x, y);
		glVertex2d(x - 8, y + 8);
		glVertex2d(x, y);
		glVertex2d(x + 8, y - 8);
		glVertex2d(x, y);
		glVertex2d(x - 8, y - 8);
	}

	glEnd();
}

/*
* Read data from CSV file. 2D scatter plot represents the relationship between sales of ice cream based on the temperature of the day.
*/
void ScatterPlot2D::ReadData()
{
	std::string fileDir = "scatter2d.csv";

	if (FileUtils::FileExists(fileDir))
	{
		std::cout << "[Scatter Plot] Loading file: " << fileDir << std::endl;

		std::ifstream fs(fileDir);

		// Store the categories of the csv file in a temp string since we don't want to read them.
		std::string categories;
		getline(fs, categories);

		ScatterPlotData2D scatterData = ScatterPlotData2D();

		while (fs)
		{
			if (fs.eof())
			{
				break;
			}

			std::vector<std::string> lineSplit;
			std::string line;
			getline(fs, line);
			std::istringstream lineStream(line);		
			std::string linePiece;

			while (getline(lineStream, linePiece, ','))
			{
				lineSplit.push_back(linePiece);
			}

			scatterData.SetTemperatureData(stod(lineSplit[0]));
			scatterData.SetSalesData(stod(lineSplit[1]));
			data.push_back(scatterData);
		}

		fs.close();
		std::cout << "[Scatter Plot] Finished loading data" << std::endl;

		// Set the value of the highest sales and temperature values.
		for (size_t i = 0; i < data.size(); ++i)
		{
			if (data[i].GetSalesData() > GetHighestSale())
			{
				SetHighestSalesValue(data[i].GetSalesData());
			}

			if (data[i].GetTemperatureData() > GetHighestTemperatureValue())
			{
				SetHighestTemperatureValue(data[i].GetTemperatureData());
			}
		}
	}
	else
	{
		std::cout << "[Scatter Plot] Failed to load data file: " << fileDir << std::endl;
	}
}