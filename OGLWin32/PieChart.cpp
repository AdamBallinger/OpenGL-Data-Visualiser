#include "PieChart.h"
#include "FileUtils.h"
#include "FontRenderer.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

PieChart::PieChart()
{
	/*PieSectorData test1 = PieSectorData();
	test1.SetColor(Vector3f(1.0f, 0.0f, 0.0f));
	test1.SetData(680);
	data.push_back(test1);

	PieSectorData test2 = PieSectorData();
	test2.SetColor(Vector3f(0.0f, 1.0f, 0.0f));
	test2.SetData(450);
	data.push_back(test2);

	PieSectorData test3 = PieSectorData();
	test3.SetColor(Vector3f(0.0f, 0.0f, 1.0f));
	test3.SetData(700);
	data.push_back(test3);

	PieSectorData test4 = PieSectorData();
	test4.SetColor(Vector3f(0.0f, 1.0f, 1.0f));
	test4.SetData(1000);
	data.push_back(test4);

	PieSectorData test5 = PieSectorData();
	test5.SetColor(Vector3f(1.0f, 0.0f, 1.0f));
	test5.SetData(310);
	data.push_back(test5);

	PieSectorData test6 = PieSectorData();
	test6.SetColor(Vector3f(0.4f, 0.3f, 1.0f));
	test6.SetData(1300);
	data.push_back(test6);

	PieSectorData test7 = PieSectorData();
	test7.SetColor(Vector3f(0.2f, 0.8f, 1.0f));
	test7.SetData(2000);
	data.push_back(test7);*/
}

PieChart::PieChart(std::string _title)
{
	title = _title;
}

std::string PieChart::GetTitle()
{
	return title;
}

void PieChart::Draw(float centerX, float centerY, float radius)
{
	FontRenderer::RenderText(GetTitle(), 0.5f, -175.0f, radius + 100.0f, Vector3f(0.0f, 1.0f, 1.0f), true);

	float lastAngle = 0.0f;
	const int slicesPerSegment = 90;

	for (size_t i = 0; i < data.size(); ++i)
	{
		// Set color for the current data slice being drawn.
		glColor3f(data[i].GetColor().GetX(), data[i].GetColor().GetY(), data[i].GetColor().GetZ()); 

		// Calculate the angle the data slice uses.
		data[i].SetAngle((360.0f / GetDataTotal()) * data[i].GetData());

		// Draw the data slice
		gluPartialDisk(gluNewQuadric(), 0, radius - 1, slicesPerSegment, data.size(), lastAngle, data[i].GetAngle());

		// Set the lastangle for the starting point of the next data slice.
		lastAngle += data[i].GetAngle();
	}
}

int PieChart::GetDataTotal()
{
	dataTotal = 0;
	for (size_t i = 0; i < data.size(); ++i)
	{
		dataTotal += data[i].GetData();
	}
	return dataTotal;
}

/*
* Reads data from a CSV file.
* PieChart reads adult_test_data.csv and displays the amount of people with different marital-status'
*/
void PieChart::ReadData()
{
	std::string fileDir = "adult_test_data.csv";

	if (FileUtils::FileExists(fileDir))
	{
		std::cout << "[PieChart] Loading: " << fileDir << std::endl;

		std::ifstream fs(fileDir);
		std::string categories;

		// Get the categories of the csv file first as it isn't needed.
		getline(fs, categories);

		// Store the total number of different marital-status'
		int neverMarried = 0;
		int marriedCivSpouse = 0;
		int widowed = 0;
		int divorced = 0;
		int separated = 0;
		int marriedSpouseAbsent = 0;

		// Now loops through every remaining line in the csv file to count up the total of different marital-status'
		while (fs)
		{
			std::string line;
			getline(fs, line);
			std::istringstream lineStream(line);

			// Go through each part of the line until we reach the marigal status column and then increment the appropriate count.
			while (lineStream)
			{
				std::string value;
				getline(lineStream, value, ',');

				if (value == " Never-married")
				{
					neverMarried++;
					dataTotal++;
				}
				else if (value == " Married-civ-spouse")
				{
					marriedCivSpouse++;
					dataTotal++;
				}
				else if (value == " Widowed")
				{
					widowed++;
					dataTotal++;
				}
				else if (value == " Divorced")
				{
					divorced++;
					dataTotal++;
				}
				else if (value == " Separated")
				{
					separated++;
					dataTotal++;
				}
				else if (value == " Married-spouse-absent")
				{
					marriedSpouseAbsent++;
					dataTotal++;
				}
			}
		}
		fs.close();

		std::cout << "Never Married: " << neverMarried << "  Married-civ-spouse: " << marriedCivSpouse << "  Widowed: " << widowed << std::endl;
		std::cout << "Divorced: " << divorced << "  Separated: " << separated << "  Married-spouse-absent: " << marriedSpouseAbsent << std::endl;
		std::cout << "Total: " << dataTotal << std::endl;
		std::cout << "[PieChart] Data finished loading" << std::endl;

		// Insert the different marital status counts into PieSectorData classes to turn the data into visible sectors of the pie chart.
		PieSectorData pieData = PieSectorData();
		
		// Set a random color for each pie slice.
		Vector3f randColor = Vector3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
		pieData.SetColor(randColor);
		pieData.SetData(neverMarried);
		data.push_back(pieData);

		randColor = Vector3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
		pieData.SetColor(randColor);
		pieData.SetData(marriedCivSpouse);
		data.push_back(pieData);

		randColor = Vector3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
		pieData.SetColor(randColor);
		pieData.SetData(widowed);
		data.push_back(pieData);

		randColor = Vector3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
		pieData.SetColor(randColor);
		pieData.SetData(divorced);
		data.push_back(pieData);

		randColor = Vector3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
		pieData.SetColor(randColor);
		pieData.SetData(separated);
		data.push_back(pieData);

		randColor = Vector3f((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX);
		pieData.SetColor(randColor);
		pieData.SetData(marriedSpouseAbsent);
		data.push_back(pieData);
	}
	else
	{
		std::cout << "[PieChart] Failed to load csv file: " << fileDir << std::endl;
	}
	
}