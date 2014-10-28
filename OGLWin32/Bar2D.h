#ifndef bar2d_h
#define bar2d_h

#include "Vector2D.h"
#include "Vector3f.h"

class Bar2D
{

private:
	Vector2D topLeft, bottomRight;

public:

	Bar2D();
	Bar2D(Vector2D, Vector2D);

	void Draw(Vector2D, Vector2D);
	void Fill(Vector3f);

	Vector2D GetTopLeft();
	Vector2D GetBottomRight();

	void SetTopLeft(Vector2D);
	void SetBottomRight(Vector2D);

};

#endif