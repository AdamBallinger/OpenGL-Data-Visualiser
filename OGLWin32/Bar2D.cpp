#include "Bar2D.h"
#include <Windows.h>
#include <GL/GL.h>

Bar2D::Bar2D()
{
	SetBottomLeft(Vector2f(0.0f, 0.0f));
}

Bar2D::Bar2D(Vector2f bottomLeft)
{
	SetBottomLeft(bottomLeft);
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

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex2f(GetBottomLeft().GetX(), GetBottomLeft().GetY());
	glVertex2f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY());;

	glVertex2f(GetBottomLeft().GetX(), GetBottomLeft().GetY() + GetHeight());
	glVertex2f(GetBottomLeft().GetX() + GetWidth(), GetBottomLeft().GetY() + GetHeight());

	glEnd();
}