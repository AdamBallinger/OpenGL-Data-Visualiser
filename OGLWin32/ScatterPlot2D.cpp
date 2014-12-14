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
	SetLowestTemperatureValue(0);
}

ScatterPlot2D::ScatterPlot2D(std::string _title) : ScatterPlot2D::ScatterPlot2D()
{
	title = _title;
}

void ScatterPlot2D::SetHighestSalesValue(float _data)
{
	highestSalesValue = _data;
}

float ScatterPlot2D::GetHighestSale()
{
	return highestSalesValue;
}

void ScatterPlot2D::SetHighestTemperatureValue(float _data)
{
	highestTemperatureValue = _data;
}

float ScatterPlot2D::GetHighestTemperatureValue()
{
	return highestTemperatureValue;
}

void ScatterPlot2D::SetLowestTemperatureValue(float _data)
{
	lowestTemperatureValue = _data;
}

float ScatterPlot2D::GetLowestTemperatureValue()
{
	return lowestTemperatureValue;
}

std::string ScatterPlot2D::GetTitle()
{
	return title;
}

void ScatterPlot2D::DrawAxis(float width, float height)
{
	// end points for each axis.
	float endX = START_X + width;
	float endY = START_Y + height;

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

	// Check if data exists before rendering the axis information (Invalid values are rendered otherwise).
	if (data.empty())
		return;

	// Draw lowest Y value at y 0 for the axis
	FontRenderer::RenderText("Y : $0", 0.3f, START_X - 95.0f, START_Y + 15.0f, Vector3f(0.0f, 1.0f, 0.0f));

	std::ostringstream highestValue;
	highestValue << GetHighestSale();
	// Draw highest Y value at top of y for the axis
	FontRenderer::RenderText("Y: $" + highestValue.str(), 0.3f, START_X - 120.0f, endY + 15.0f, Vector3f(0.0f, 1.0f, 0.0f));

	// Draw start X value at x 0 for the axis
	std::ostringstream lowestTemp;
	lowestTemp << GetLowestTemperatureValue();
	FontRenderer::RenderText("X : " + lowestTemp.str(), 0.3f, START_X - 9.0f, START_Y - 7.0f, Vector3f(1.0f, 0.0f, 0.0f));

	// Draw end X value at end of the x axis
	std::ostringstream highestTemp;
	highestTemp << GetHighestTemperatureValue();
	FontRenderer::RenderText("X : " + highestTemp.str(), 0.3f, endX - 10.0f, START_Y - 7.0f, Vector3f(1.0f, 0.0f, 0.0f));
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
		float x = i * WIDTH / data.size() + START_X;
		float y = data[i].GetSalesData() / GetHighestSale() * HEIGHT + START_Y;

		glColor3f(1.0f, 0.5f, 0.5f);
		// Draw a cross
		glVertex2f(x, y);
		glVertex2f(x + 8, y + 8);
		glVertex2f(x, y);
		glVertex2f(x - 8, y + 8);
		glVertex2f(x, y);
		glVertex2f(x + 8, y - 8);
		glVertex2f(x, y);
		glVertex2f(x - 8, y - 8);
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
			// break if there are no lines left to read.
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

			scatterData.SetTemperatureData(stof(lineSplit[0]));
			scatterData.SetSalesData(stof(lineSplit[1]));
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

		SetLowestTemperatureValue(GetHighestTemperatureValue());

		// Set the value of the lowest temperature
		for (size_t i = 0; i < data.size(); ++i)
		{
			if (data[i].GetTemperatureData() < GetLowestTemperatureValue())
			{
				SetLowestTemperatureValue(data[i].GetTemperatureData());
			}
		}
	}
	else
	{
		std::cout << "[Scatter Plot] Failed to load data file: " << fileDir << std::endl;
	}
}