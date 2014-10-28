#include "Bar2D.h"
#include <Windows.h>
#include <GL/GL.h>

Bar2D::Bar2D()
{
	SetBottomLeft(Vector2D(0.0f, 0.0f));
}

Bar2D::Bar2D(Vector2D bottomLeft)
{
	SetBottomLeft(bottomLeft);
}

void Bar2D::SetBottomLeft(Vector2D _bottomLeft)
{
	bottomLeft = _bottomLeft;
}

Vector2D Bar2D::GetBottomLeft()
{
	return bottomLeft;
}

void Bar2D::Draw(float height)
{
	glLineWidth(1.0f);
	glBegin(GL_LINES);

	glColor3f(1.0f, 1.0f, 1.0f);
	
	// bottom side
	glVertex2d(GetBottomLeft().GetX(), GetBottomLeft().GetY());
	glVertex2d(GetBottomLeft().GetX() + 40.0f, GetBottomLeft().GetY());

	// left side
	glVertex2d(GetBottomLeft().GetX(), GetBottomLeft().GetY());
	glVertex2d(GetBottomLeft().GetX(), GetBottomLeft().GetY() + height);

	// top side
	glVertex2d(GetBottomLeft().GetX(), GetBottomLeft().GetY() + height);
	glVertex2d(GetBottomLeft().GetX() + 40.0f, GetBottomLeft().GetY() + height);

	// right side
	glVertex2d(GetBottomLeft().GetX() + 40.0f, GetBottomLeft().GetY() + height);
	glVertex2d(GetBottomLeft().GetX() + 40.0f, GetBottomLeft().GetY());

	glEnd();
}