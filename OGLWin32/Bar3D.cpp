#include "Bar3D.h"
#include "FontRenderer.h"

#include <Windows.h>
#include <GL/GL.h>

#include <iostream>

Bar3D::Bar3D()
{
	SetBottomLeft(Vector3f(0.0f, 0.0f, 0.0f));
}

Bar3D::Bar3D(Vector3f bottomLeft)
{
	SetBottomLeft(bottomLeft);
}

void Bar3D::SetBarData(BarChartData _data)
{
	data = _data;
}

BarChartData Bar3D::GetBarData()
{
	return data;
}

void Bar3D::SetBottomLeft(Vector3f _bottomLeft)
{
	bottomLeft = _bottomLeft;
}

Vector3f Bar3D::GetBottomLeft()
{
	return bottomLeft;
}

void Bar3D::SetHeight(float _height)
{
	height = _height;
}

float Bar3D::GetHeight()
{
	return height;
}

void Bar3D::SetWidth(float _width)
{
	width = _width;
}

float Bar3D::GetWidth()
{
	return width;
}

void Bar3D::SetDepth(float _depth)
{
	depth = _depth;
}

float Bar3D::GetDepth()
{
	return depth;
}

// Draw a 2D bar to a bar graph.
void Bar3D::Draw()
{
	glLineWidth(1.0f);
	glColor3f(GetBarData().GetColor().GetX(), GetBarData().GetColor().GetY(), GetBarData().GetColor().GetZ());

	glBegin(GL_POLYGON);
	// Top
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ() - GetDepth());
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ() - GetDepth());

	glEnd();

	glBegin(GL_POLYGON);
	// Bottom
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY(), GetBottomLeft().GetZ());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY(), GetBottomLeft().GetZ());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY(), GetBottomLeft().GetZ() - GetDepth());
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY(), GetBottomLeft().GetZ() - GetDepth());

	glEnd();

	glBegin(GL_POLYGON);
	// Left
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY(), GetBottomLeft().GetZ());
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY(), GetBottomLeft().GetZ() - GetDepth());
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ() - GetDepth());
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ());

	glEnd();

	glBegin(GL_POLYGON);
	// Right
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY(), GetBottomLeft().GetZ());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY(), GetBottomLeft().GetZ() - GetDepth());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ() - GetDepth());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ());

	glEnd();

	glBegin(GL_POLYGON);
	// Front
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY(), GetBottomLeft().GetZ());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY(), GetBottomLeft().GetZ());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ());
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ());

	glEnd();

	glBegin(GL_POLYGON);
	// Back
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY(), GetBottomLeft().GetZ() - GetDepth());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY(), GetBottomLeft().GetZ() - GetDepth());
	glVertex3f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ() - GetDepth());
	glVertex3f(GetBottomLeft().GetX(), GetBottomLeft().GetY() + GetHeight(), GetBottomLeft().GetZ() - GetDepth());

	glEnd();

	// Render the name of the data the bar is representing under it.
	FontRenderer::RenderText(GetBarData().GetDataName(), 0.2f, GetBottomLeft().GetX() + GetWidth() / 2 - 30.0f, GetBottomLeft().GetY() - 10.0f, Vector3f(0.75f, 0.75f, 0.75f));
}