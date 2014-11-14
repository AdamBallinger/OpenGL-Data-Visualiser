#ifndef bar2d_h
#define bar2d_h

#include "Vector2f.h"

class Bar2D
{

private:
	Vector2f bottomLeft;
	float height;
	float width;

public:

	Bar2D();
	Bar2D(Vector2f);

	void Draw();

	Vector2f GetBottomLeft();

	void SetBottomLeft(Vector2f);

	void SetHeight(float);
	float GetHeight();

	void SetWidth(float);
	float GetWidth();

};

#endif