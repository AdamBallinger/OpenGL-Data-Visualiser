#include "Vector2f.h"

// Constructors

Vector2f::Vector2f(void)
{
	Init(0.0f, 0.0f);
}

Vector2f::Vector2f(float x, float y)
{
	Init(x, y);
}

Vector2f::Vector2f(const Vector2f& v)
{
	Copy(v);
}

Vector2f::~Vector2f(void)
{
}

// Accessors and mutators

float Vector2f::GetX(void) const
{
	return _x;
}

void Vector2f::SetX(float x)
{
	_x = x;
}

float Vector2f::GetY(void) const
{
	return _y;
}

void Vector2f::SetY(float y)
{
	_y = y;
}

// Operator overloads

Vector2f& Vector2f::operator= (const Vector2f &rhs)
{
	if (this != &rhs)
	{
		// Only copy if we are not assigning to ourselves. 
		// (remember that a = b is the same as a.operator=(b))
		Copy(rhs);
	}
	return *this;
}

const Vector2f Vector2f::operator+(const Vector2f &other) const
{
	Vector2f result;
	result.SetX(_x + other.GetX());
	result.SetY(_y + other.GetY());
	return result;
}

const Vector2f Vector2f::operator-(const Vector2f &other) const
{
	Vector2f result;
	result.SetX(_x - other.GetX());
	result.SetY(_y - other.GetY());
	return result;
}


// Private methods

void Vector2f::Init(float x, float y)
{
	_x = x;
	_y = y;
}

void Vector2f::Copy(const Vector2f& v)
{
	_x = v.GetX();
	_y = v.GetY();
}
