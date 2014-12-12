#include "SpiderChart.h"
#include "FileUtils.h"
#include "FontRenderer.h"

#include <Windows.h>
#include <gl/GL.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

SpiderChart::SpiderChart()
{
	highestValue = 0;
}

SpiderChart::SpiderChart(std::string _title) : SpiderChart::SpiderChart()
{
	title = _title;
}

int SpiderChart::GetHighestValue()
{
	return highestValue;
}

void SpiderChart::DrawAxis(float axis_size)
{
	float axisAngle = 360.0f / (float)data.size();

	glPushMatrix();
	for (size_t i = 0; i < data.size(); ++i)
	{
		glRotatef(axisAngle, 0.0f, 0.0f, 1.0f);

		glLineWidth(1.5f);
		glColor3f(1.0, 1.0f, 1.0f);
		glBegin(GL_LINES);

		glVertex2f(0.0f, 0.0f);
		glVertex2f(axis_size, 0.0f);

		glEnd();
	}
	glPopMatrix();
}

void SpiderChart::Draw()
{
	DrawAxis(AXIS_SIZE);

	float angle = 360.0f / (float)data.size();
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(data[0].GetData() * AXIS_SIZE / GetHighestValue(), 0.0f);
	for (size_t i = 1; i < data.size(); ++i)
	{
		float x = data[i].GetData() * AXIS_SIZE / GetHighestValue();
		float y = 10.0f;
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		glVertex2f(x, y);	
	}
	glEnd();
}

void SpiderChart::ReadData()
{
	std::string fileDir = "adult_test_data.csv";

	if (FileUtils::FileExists(fileDir))
	{
		std::cout << "[SpiderChart] Loading: " << fileDir << std::endl;

		std::ifstream fs(fileDir);

		std::string headers;
		getline(fs, headers);

		SpiderChartData _data = SpiderChartData();

		int privateCount = 0;
		int localGovCount = 0;
		int unknownCount = 0;
		int selfEmpNotIncCount = 0;
		int selfEmpIncCount = 0;
		int federalGovCount = 0;
		int stateGovCount = 0;

		while (fs)
		{
			if (fs.eof())
			{
				break;
			}

			std::string line;
			getline(fs, line);

			std::istringstream lineStream(line);

			while (lineStream)
			{
				std::string piece;
				getline(lineStream, piece, ',');

				if (piece == " Private")
				{
					privateCount++;
				}
				else if (piece == " Local-gov")
				{
					localGovCount++;
				}
				else if (piece == " ?")
				{
					unknownCount++;
				}
				else if (piece == " Self-emp-not-inc")
				{
					selfEmpNotIncCount++;
				}
				else if (piece == " Self-emp-inc")
				{
					selfEmpIncCount++;
				}
				else if (piece == " Federal-gov")
				{
					federalGovCount++;
				}
				else if (piece == " State-gov")
				{
					stateGovCount++;
				}
			}
		}

		std::cout << "[Spider Chart] Finished loading data." << std::endl;

		_data.SetData(privateCount);
		_data.SetName("Private");
		data.push_back(_data);

		_data.SetData(localGovCount);
		_data.SetName("Local-Gov");
		data.push_back(_data);

		_data.SetData(unknownCount);
		_data.SetName("Unknown");
		data.push_back(_data);

		_data.SetData(selfEmpNotIncCount);
		_data.SetName("Self-Emp-Not-Inc");
		data.push_back(_data);

		_data.SetData(selfEmpIncCount);
		_data.SetName("Self-Emp-Inc");
		data.push_back(_data);

		_data.SetData(federalGovCount);
		_data.SetName("Federal-Gov");
		data.push_back(_data);

		_data.SetData(stateGovCount);
		_data.SetName("State-Gov");
		data.push_back(_data);

		for (size_t i = 0; i < data.size(); ++i)
		{
			if (data[i].GetData() > highestValue)
			{
				highestValue = data[i].GetData();
			}
		}
	}
	else
	{
		std::cout << "[SpiderChart] Failed to load csv file: " << fileDir << std::endl;
	}
}