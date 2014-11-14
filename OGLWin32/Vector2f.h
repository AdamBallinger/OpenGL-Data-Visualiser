#ifndef vector2f_h
#define vector2f_h

#include <string>

class Vector2f
{
	public:
		Vector2f(void);
		Vector2f(float x, float y);
		Vector2f(const Vector2f& v);
		~Vector2f(void);

		float GetX(void) const;
		void SetX(float x);
		float GetY(void) const;
		void SetY(float y);

		Vector2f& operator= (const Vector2f &rhs);
		const Vector2f operator+(const Vector2f &other) const;
		const Vector2f operator-(const Vector2f &other) const;

	private:
		float _x;
		float _y;

		void Init(float x, float y);
		void Copy(const Vector2f& v);
		
};
#endif