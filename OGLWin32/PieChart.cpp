#include "PieChart.h"
#include "FileUtils.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

#include <iostream>

PieChart::PieChart()
{
	std::cout << "Init pie data" << std::endl;
	PieSectorData test1 = PieSectorData();
	test1.SetColor(Vector3f(1.0, 0.0, 0.0));
	test1.SetData(680);
	data.push_back(test1);

	PieSectorData test2 = PieSectorData();
	test2.SetColor(Vector3f(0.0, 1.0, 0.0));
	test2.SetData(450);
	data.push_back(test2);

	PieSectorData test3 = PieSectorData();
	test3.SetColor(Vector3f(0.0, 0.0, 1.0));
	test3.SetData(700);
	data.push_back(test3);

	PieSectorData test4 = PieSectorData();
	test4.SetColor(Vector3f(0.0, 1.0, 1.0));
	test4.SetData(1000);
	data.push_back(test4);

	PieSectorData test5 = PieSectorData();
	test5.SetColor(Vector3f(1.0, 0.0, 1.0));
	test5.SetData(310);
	data.push_back(test5);

	PieSectorData test6 = PieSectorData();
	test6.SetColor(Vector3f(0.4, 0.3, 1.0));
	test6.SetData(1300);
	data.push_back(test6);

	PieSectorData test7 = PieSectorData();
	test7.SetColor(Vector3f(0.2, 0.8, 1.0));
	test7.SetData(2000);
	data.push_back(test7);
}

void PieChart::Draw(float centerX, float centerY, float radius, double scale)
{
	float lastAngle = 0.0f;

	glScaled(scale, scale, 0.0);

	for (int i = 0; i < data.size(); ++i)
	{
		glColor3f(data[i].GetColor().GetX(), data[i].GetColor().GetY(), data[i].GetColor().GetZ());

		data[i].SetAngle((360.0f / GetDataTotal()) * data[i].GetData());
		gluPartialDisk(gluNewQuadric(), 0, radius, 90, data.size(), lastAngle, data[i].GetAngle());

		lastAngle += data[i].GetAngle();
	}
}

int PieChart::GetDataTotal()
{
	dataTotal = 0;
	for (int i = 0; i < data.size(); ++i)
	{
		dataTotal += data[i].GetData();
	}
	return dataTotal;
}

void PieChart::ReadData()
{

}