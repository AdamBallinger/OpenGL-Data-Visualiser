#include "ScatterPlot.h"
#include "FileUtils.h"

#include <Windows.h>
#include <GL/GL.h>

ScatterPlot::ScatterPlot()
{

}

void ScatterPlot::DrawAxis2D(float width, float height)
{
	// 0,0 of chart
	float startX = -400.0f;
	float startY = -200.0f;

	// end points for each axis.
	float endX = startX + width;
	float endY = startY + height;

	glLineWidth(1.3f);
	glBegin(GL_LINES);

	// Draw X Axis
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(startX, startY);
	glVertex2f(endX, startY);

	// Draw Y Axis
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(startX, startY + 0.5f);
	glVertex2f(startX, endY);

	glEnd();
}

void ScatterPlot::DrawAxis3D(float width, float height, float depth)
{

}

void ScatterPlot::Draw()
{
	DrawAxis2D(500.0f, 500.0f);
}

void ScatterPlot::Draw3D()
{

}

void ScatterPlot::ReadData()
{

}


//glMatrixMode(GL_MODELVIEW);

//xRot += 5;
//yRot += 5;
//zRot += 1;

//glRotatef(xRot, 1.0, 0.0, 0.0);
//glRotatef(yRot, 0.0, 1.0, 0.0);
//glRotatef(zRot, 0.0, 0.0, 1.0);

//glBegin(GL_QUADS);
//glColor3f(0.0f, 1.0f, 0.0f);    // Color Blue
//glVertex3f(100.0f, 100.0f, -100.0f);    // Top Right Of The Quad (Top)
//glVertex3f(-100.0f, 100.0f, -100.0f);    // Top Left Of The Quad (Top)
//glVertex3f(-100.0f, 100.0f, 100.0f);    // Bottom Left Of The Quad (Top)
//glVertex3f(100.0f, 100.0f, 100.0f);    // Bottom Right Of The Quad (Top)
//glColor3f(1.0f, 0.5f, 0.0f);    // Color Orange
//glVertex3f(100.0f, -100.0f, 100.0f);    // Top Right Of The Quad (Bottom)
//glVertex3f(-100.0f, -100.0f, 100.0f);    // Top Left Of The Quad (Bottom)
//glVertex3f(-100.0f, -100.0f, -100.0f);    // Bottom Left Of The Quad (Bottom)
//glVertex3f(100.0f, -100.0f, -100.0f);    // Bottom Right Of The Quad (Bottom)
//glColor3f(1.0f, 0.0f, 0.0f);    // Color Red    
//glVertex3f(100.0f, 100.0f, 100.0f);    // Top Right Of The Quad (Front)
//glVertex3f(-100.0f, 100.0f, 100.0f);    // Top Left Of The Quad (Front)
//glVertex3f(-100.0f, -100.0f, 100.0f);    // Bottom Left Of The Quad (Front)
//glVertex3f(100.0f, -100.0f, 100.0f);    // Bottom Right Of The Quad (Front)
//glColor3f(1.0f, 1.0f, 0.0f);    // Color Yellow
//glVertex3f(100.0f, -100.0f, -100.0f);    // Top Right Of The Quad (Back)
//glVertex3f(-100.0f, -100.0f, -100.0f);    // Top Left Of The Quad (Back)
//glVertex3f(-100.0f, 100.0f, -100.0f);    // Bottom Left Of The Quad (Back)
//glVertex3f(100.0f, 100.0f, -100.0f);    // Bottom Right Of The Quad (Back)
//glColor3f(0.0f, 0.0f, 1.0f);    // Color Blue
//glVertex3f(-100.0f, 100.0f, 100.0f);    // Top Right Of The Quad (Left)
//glVertex3f(-100.0f, 100.0f, -100.0f);    // Top Left Of The Quad (Left)
//glVertex3f(-100.0f, -100.0f, -100.0f);    // Bottom Left Of The Quad (Left)
//glVertex3f(-100.0f, -100.0f, 100.0f);    // Bottom Right Of The Quad (Left)
//glColor3f(1.0f, 0.0f, 1.0f);    // Color Violet
//glVertex3f(100.0f, 100.0f, -100.0f);    // Top Right Of The Quad (Right)
//glVertex3f(100.0f, 100.0f, 100.0f);    // Top Left Of The Quad (Right)
//glVertex3f(100.0f, -100.0f, 100.0f);    // Bottom Left Of The Quad (Right)
//glVertex3f(100.0f, -100.0f, -100.0f);    // Bottom Right Of The Quad (Right)
//glEnd();

//glFlush();