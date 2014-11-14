#ifndef bar2d_h
#define bar2d_h

#include "Vector2D.h"

class Bar2D
{

private:
	Vector2D bottomLeft;
	float height;
	float width;

public:

	Bar2D();
	Bar2D(Vector2D);

	void Draw();

	Vector2D GetBottomLeft();

	void SetBottomLeft(Vector2D);

	void SetHeight(float);
	float GetHeight();

	void SetWidth(float);
	float GetWidth();

};

#endif