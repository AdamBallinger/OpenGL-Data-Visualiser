#ifndef vector3f_h
#define vector3f_h

class Vector3f
{
private:
	float x, y, z;

public:

	Vector3f();
	Vector3f(float, float, float);

	void SetX(float);
	void SetY(float);
	void SetZ(float);

	float GetX();
	float GetY();
	float GetZ();

};


#endif