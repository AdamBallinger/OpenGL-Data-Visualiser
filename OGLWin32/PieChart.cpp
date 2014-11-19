#include "PieChart.h"
#include "FileUtils.h"
#include "FontRenderer.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

#include <iostream>

PieChart::PieChart()
{
	std::cout << "Init pie data" << std::endl;
	PieSectorData test1 = PieSectorData();
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
	data.push_back(test7);
}

void PieChart::Draw(float centerX, float centerY, float radius)
{
	FontRenderer::RenderText("I'm a Pie Chart!", 0.5f, -175.0f, radius + 100.0f, Vector3f(0.0f, 1.0f, 1.0f), true);

	float lastAngle = 0.0f;
	const int slicesPerSegment = 90;

	for (size_t i = 0; i < data.size(); ++i)
	{
		// Set color for the current data slice being drawn.
		glColor3f(data[i].GetColor().GetX(), data[i].GetColor().GetY(), data[i].GetColor().GetZ()); 

		// Calculate the angle the data slice uses.
		data[i].SetAngle((360.0f / GetDataTotal()) * data[i].GetData());

		// Draw the data slice
		gluPartialDisk(gluNewQuadric(), 0, radius, slicesPerSegment, data.size(), lastAngle, data[i].GetAngle());

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

void PieChart::ReadData()
{

}