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

std::string SpiderChart::GetTitle()
{
	return title;
}

int SpiderChart::GetHighestValue()
{
	return highestValue;
}

void SpiderChart::DrawAxis(float axis_size)
{
	float axisAngle = 360.0f / (float)data.size();

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

	FontRenderer::RenderText(GetTitle(), 0.5f, -AXIS_SIZE / 2, AXIS_SIZE + 100.0f, Vector3f(0.0f, 1.0f, 1.0f));
}

void SpiderChart::Draw()
{
	DrawAxis(AXIS_SIZE);

	float angle = 360.0f / (float)data.size();
	
	for (size_t i = 0; i < data.size(); ++i)
	{
		float x = data[i].GetData() * AXIS_SIZE / GetHighestValue();
		float y = 0.0f;

		glPushMatrix();
		glTranslatef(AXIS_SIZE + 30.0f, 0.0f, 0.0f);
		glRotatef(-angle * i, 0.0f, 0.0f, 1.0f); // Rotate the font around the negative angle multiplied by the current i value to correct the text's orientation.
		FontRenderer::RenderText(data[i].GetName(), 0.3f, 0.0f, 20.0f, Vector3f(1.0f, 0.0f, 0.0f));
		glPopMatrix();

		glColor3f(1.0f, 0.0f, 1.0f);
		glPointSize(8.0f);
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
		glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotate on the Z axis for the next point to be drawn.
	}
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