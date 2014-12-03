#include "ScatterPlot3D.h"
#include "OGLWindow.h"
#include "FontRenderer.h"
#include "FileUtils.h"

#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

ScatterPlot3D::ScatterPlot3D()
{

}

ScatterPlot3D::ScatterPlot3D(std::string _title)
{
	title = _title;
}

std::string ScatterPlot3D::GetTitle()
{
	return title;
}

/*
* Draw 3D axis
*/
void ScatterPlot3D::DrawAxis(float width, float height, float depth)
{
	float endX = START_X + width;
	float endY = START_Y + height;
	float endZ = START_Z + depth;

	glLineWidth(2.5f);
	glBegin(GL_LINES);
	// Draw X Axis
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(START_X, START_Y, START_Z);
	glVertex3f(endX, START_Y, START_Z);

	// Draw Y Axis
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(START_X, START_Y, START_Z);
	glVertex3f(START_X, endY, START_Z);

	// Draw Z Axis
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(START_X, START_Y, START_Z);
	glVertex3f(START_X, START_Y, endZ);

	glEnd();
}

void ScatterPlot3D::Draw()
{
	DrawAxis(WIDTH, HEIGHT, DEPTH);

	glPointSize(5.0f);
	glBegin(GL_POINTS);

	for (size_t i = 0; i < data.size(); i++)
	{
		double x = data[i].GetXData() * WIDTH / GetHighestValueX();
		double y = data[i].GetYData() * HEIGHT / GetHighestValueY();
		double z = data[i].GetZData() * DEPTH / GetHighestValueZ();

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3d(x, y, z);
	}
	glEnd();

	FontRenderer::RenderText(GetTitle(), 0.3f, 20.0f, HEIGHT + 20.0f, Vector3f(0.0f, 1.0f, 1.0f), true);
	FontRenderer::RenderText("X", 0.25f, WIDTH + 10.0f, 10.0f, Vector3f(1.0f, 0.0f, 0.0f));
	FontRenderer::RenderText("Y", 0.25f, -10.0f, HEIGHT + 40.0f, Vector3f(0.0f, 1.0f, 0.0f));

	// Translate the text for the Z axis along the Z axis then rotate it 90 degrees to face inwards to the chart
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, DEPTH + 15.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	FontRenderer::RenderText("Z", 0.25f, 0.0f, 0.0f, Vector3f(0.0f, 0.0f, 1.0f));
	glPopMatrix();
}

void ScatterPlot3D::SetHighestValueX(double _highestValueX)
{
	highestValueX = _highestValueX;
}

double ScatterPlot3D::GetHighestValueX()
{
	return highestValueX;
}

void ScatterPlot3D::SetHighestValueY(double _highestValueY)
{
	highestValueY = _highestValueY;
}

double ScatterPlot3D::GetHighestValueY()
{
	return highestValueY;
}

void ScatterPlot3D::SetHighestValueZ(double _highestValueZ)
{
	highestValueZ = _highestValueZ;
}

double ScatterPlot3D::GetHighestValueZ()
{
	return highestValueZ;
}

void ScatterPlot3D::ReadData()
{
	std::string fileDir = "scatter3d.csv";
	
	if (FileUtils::FileExists(fileDir))
	{
		std::cout << "[ScatterPlot3D] Loading csv file: " << fileDir << std::endl;

		std::ifstream fs(fileDir);

		// Ignore first line (data headers)
		std::string categories;
		getline(fs, categories);

		while (fs)
		{
			if (fs.eof())
			{
				break;
			}

			std::vector<std::string> lineData;
			std::string line;
			getline(fs, line);
			std::istringstream lineStream(line);

			while (lineStream)
			{
				std::string piece;
				getline(lineStream, piece, ',');
				lineData.push_back(piece);
			}

			ScatterPlotData3D scatterData = ScatterPlotData3D();
			scatterData.SetXData(stod(lineData[0]));
			scatterData.SetYData(stod(lineData[1]));
			scatterData.SetZData(stod(lineData[2]));
			data.push_back(scatterData);
		}
		fs.close();
		std::cout << "[ScatterPlot3D] Finished reading csv file" << std::endl;
	}
	else
	{
		std::cout << "[ScatterPlot3D] Couldn't load csv file: " << fileDir << std::endl;
	}


	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i].GetXData() > GetHighestValueX())
		{
			SetHighestValueX(data[i].GetXData());
		}

		if (data[i].GetYData() > GetHighestValueY())
		{
			SetHighestValueY(data[i].GetYData());
		}

		if (data[i].GetZData() > GetHighestValueZ())
		{
			SetHighestValueZ(data[i].GetZData());
		}
	}
}