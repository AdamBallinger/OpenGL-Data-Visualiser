#include "Vector3f.h"

Vector3f::Vector3f()
{
	SetX(0.0f);
	SetY(0.0f);
	SetZ(0.0f);
}

Vector3f::Vector3f(float x, float y, float z)
{
	SetX(x);
	SetY(y);
	SetZ(z);
}

void Vector3f::SetX(float _x)
{
	x = _x;
}

void Vector3f::SetY(float _y)
{
	y = _y;
}

void Vector3f::SetZ(float _z)
{
	z = _z;
}

float Vector3f::GetX()
{
	return x;
}

float Vector3f::GetY()
{
	return y;
}

float Vector3f::GetZ()
{
	return z;
}