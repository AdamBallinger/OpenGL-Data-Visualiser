#include "PieChart.h"
#include "FileUtils.h"

#include <Windows.h>
#include <GL\GL.h>

#include <iostream>

PieChart::PieChart()
{
	std::cout << "Init pie data" << std::endl;
	PieSectorData test1 = PieSectorData();
	test1.SetColor(Vector3f(1.0, 0.0, 0.0));
	test1.SetData(120);
	data.push_back(test1);

	PieSectorData test2 = PieSectorData();
	test2.SetColor(Vector3f(0.0, 1.0, 0.0));
	test2.SetData(120);
	data.push_back(test2);

	PieSectorData test3 = PieSectorData();
	test3.SetColor(Vector3f(0.0, 0.0, 1.0));
	test3.SetData(120);
	data.push_back(test3);
}

void PieChart::Draw(float centerX, float centerY, float radius)
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(centerX, centerY);

	float triangles = 360.0f;
	int segCount = 0;

	for (int i = 0; i < data.size(); ++i)
	{
		glColor3f(data[i].GetColor().GetX(), data[i].GetColor().GetY(), data[i].GetColor().GetZ());
		data[i].SetAngle((360.0f / GetDataTotal()) * data[i].GetData());

		std::cout << "Data[" << i << "] data: " << data[i].GetData() << "  Angle: " << data[i].GetAngle() << std::endl;
		
		for (int j = 9; j <= data[i].GetAngle(); j++)
		{
			float theta = 2.0f * 3.1415926f * float(j) / float(data[i].GetAngle()); // Get current angle
			float x = radius * cosf(theta); // Calculate X component
			float y = radius * sinf(theta); // Calculate Y component
			glVertex2f(x, y);
		}
		std::cout << "segCount: " << segCount << std::endl;
		segCount += data[i].GetAngle();
	}

	glEnd();



	//glBegin(GL_TRIANGLE_FAN);
	//glVertex2f(centerX, centerY);

	//float triangles = 360.0f;
	//int segCount = 0;

	//for (int i = 0; i < data.size(); ++i)
	//{
	//	glColor3f(data[i].GetColor().GetX(), data[i].GetColor().GetY(), data[i].GetColor().GetZ());
	//	data[i].SetAngle(360.0f / GetDataTotal() * data[i].GetData());

	//	for (int j = segCount; j <= data[i].GetAngle() * 3; j++)
	//	{
	//		float theta = 2.0f * 3.1415926f * float(j) / float(data[i].GetData()); // Get current angle
	//		float x = radius * cosf(theta); // Calculate X component
	//		float y = radius * sinf(theta); // Calculate Y component
	//		glVertex2f(x, y);
	//	}
	//	segCount += data[i].GetAngle();
	//}

	//glEnd();
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