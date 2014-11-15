#include "PieChart.h"
#include "FileUtils.h"

#include <Windows.h>
#include <GL\GL.h>

#include <iostream>

PieChart::PieChart()
{
	std::cout << "Init pie data" << std::endl;
	PieSectorData test1 = PieSectorData();
	test1.SetColor(Vector3f(1.0, 0.0, 1.0));
	test1.SetSegments(100);
	data.push_back(test1);

	PieSectorData test2 = PieSectorData();
	test2.SetColor(Vector3f(1.0, 1.0, 0.0));
	test2.SetSegments(80);
	data.push_back(test2);

	PieSectorData test3 = PieSectorData();
	test3.SetColor(Vector3f(0.0, 1.0, 1.0));
	test3.SetSegments(180);
	data.push_back(test3);
}

void PieChart::Draw(float centerX, float centerY, float radius, int segments)
{
	int sectorCount = 0;
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < data.size(); ++i)
	{
		for (int j = 0; j < data[i].GetSegments(); ++j, ++sectorCount)
		{
			float theta = 2.0f * 3.1415926f * float(j + sectorCount) / float(data[i].GetSegments()); // Get current angle

			float x = radius * cosf(theta); // Calculate X component
			float y = radius * sinf(theta); // Calculate Y component
			glColor3f(data[i].GetColor().GetX(), data[i].GetColor().GetY(), data[i].GetColor().GetZ());
			glVertex2f(x + centerX, y + centerY);
		}
	}

	glEnd();
}

void PieChart::ReadData()
{

}