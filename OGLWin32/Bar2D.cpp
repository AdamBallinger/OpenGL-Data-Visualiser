#include "Bar2D.h"
#include "FontRenderer.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>

Bar2D::Bar2D()
{
	SetBottomLeft(Vector2f(0.0f, 0.0f));
}

Bar2D::Bar2D(Vector2f bottomLeft)
{
	SetBottomLeft(bottomLeft);
}

void Bar2D::SetBarData(BarChartData _data)
{
	data = _data;
}

BarChartData Bar2D::GetBarData()
{
	return data;
}

void Bar2D::SetBottomLeft(Vector2f _bottomLeft)
{
	bottomLeft = _bottomLeft;
}

Vector2f Bar2D::GetBottomLeft()
{
	return bottomLeft;
}

void Bar2D::SetHeight(float _height)
{
	height = _height;
}

float Bar2D::GetHeight()
{
	return height;
}

void Bar2D::SetWidth(float _width)
{
	width = _width;
}

float Bar2D::GetWidth()
{
	return width;
}

//Draw a 2D bar to a bar graph.
void Bar2D::Draw()
{
	glLineWidth(1.0f);
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(GetBarData().GetColor().GetX(), GetBarData().GetColor().GetY(), GetBarData().GetColor().GetZ());

	glVertex2f(GetBottomLeft().GetX(), GetBottomLeft().GetY());
	glVertex2f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY());;

	glVertex2f(GetBottomLeft().GetX(), GetBottomLeft().GetY() + GetHeight());
	glVertex2f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY() + GetHeight());

	glEnd();

	// Render the name of the data the bar is representing under it.
	FontRenderer::RenderText(GetBarData().GetDataName(), 0.2f, GetBottomLeft().GetX() + GetWidth() / 2 - 30.0f, GetBottomLeft().GetY() - 10.0f, Vector3f(0.75f, 0.75f, 0.75f));
}