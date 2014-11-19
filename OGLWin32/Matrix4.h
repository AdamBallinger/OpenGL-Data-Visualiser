#ifndef matrix4_h
#define matrix4_h

class Matrix4
{
private:

	float m[4][4];

public:

	Matrix4();
	Matrix4(const Matrix4& rhs);
	~Matrix4();

};

#endif