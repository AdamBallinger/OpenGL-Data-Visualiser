#ifndef bar2d_h
#define bar2d_h

#include "Vector2D.h"

class Bar2D
{

private:
	Vector2D bottomLeft;

public:

	Bar2D();
	Bar2D(Vector2D);

	void Draw(float);

	Vector2D GetBottomLeft();

	void SetBottomLeft(Vector2D);

	float GetWidth();

};

#endif