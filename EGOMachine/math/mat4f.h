#ifndef MAT4F
#define MAT4F

#include "vec4f.h"

#define _USE_MATH_DEFINES
#include <cmath>

#define M	4
#define ToRadian(x)(x*M_PI/180.0f)
#define ToDegree(x)(x*180.0f/M_PI)

class mat4f
{
private:
	float mass[M][M];
public:
	mat4f();
	~mat4f();
	void Identety();
	void Value(float value);
	void InitTransforScale(float ScaleX, float ScaleY, float ScaleZ);
	void InitTransformRotate(float RotateX, float RotateY, float RotateZ);
	void InitTransformWorldPosition(float PositionX, float PositionY, float PositionZ);

	mat4f& add(const mat4f& matrix);
	mat4f& dif(const mat4f& matrix);
	mat4f& mul(const mat4f& matrix);
	
	mat4f operator*=(float number);
	mat4f operator*=(const mat4f& right);
	mat4f operator+=(const mat4f& right);
	mat4f& operator+=(float number);

	friend mat4f operator+(const mat4f& left, const mat4f& right);
	friend mat4f operator*(const mat4f& left, const mat4f& right);
	friend mat4f operator-(const mat4f& left, const mat4f& rigth);

	friend vec4f operator*(const vec4f& left,const mat4f& matrix);
	friend vec4f operator*(const mat4f& matrix, const vec4f& right);
};

#endif // !MAT4F
