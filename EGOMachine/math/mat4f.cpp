#include "mat4f.h"

mat4f::mat4f()
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			mass[i][j] = 0.0f;
}

mat4f::~mat4f()
{

}

void mat4f::Identety()
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			if (i == j) mass[i][j] = 1.0f; 
			else mass[i][j] = 0.0f;
}

mat4f& mat4f::add(const mat4f& matrix)
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			mass[i][j] += matrix.mass[i][j];

	return *this;
}

mat4f& mat4f::dif(const mat4f& matrix)
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			mass[i][j] -= matrix.mass[i][j];

	return *this;
}

mat4f& mat4f::mul(const mat4f& matrix)
{
	for (int i = 0; i < M; ++i)
		for(int j=0; j<M; ++j)
		mass[i][j] = mass[i][0] * matrix.mass[0][j] 
				   + mass[i][1] * matrix.mass[1][j] 
				   + mass[i][2] * matrix.mass[2][j] 
				   + mass[i][3] * matrix.mass[3][j]; 

	return *this;
}

vec4f operator*(const vec4f& left,const mat4f& matrix)
{
	vec4f result;

	result.x = left.x*matrix.mass[0][0] + left.y*matrix.mass[0][1] + left.z*matrix.mass[0][2] + left.w*matrix.mass[0][3];
	result.y = left.x*matrix.mass[1][0] + left.y*matrix.mass[1][1] + left.z*matrix.mass[1][2] + left.w*matrix.mass[1][3];
	result.z = left.x*matrix.mass[2][0] + left.y*matrix.mass[2][1] + left.z*matrix.mass[2][2] + left.w*matrix.mass[2][3];
	result.w = left.x*matrix.mass[3][0] + left.y*matrix.mass[3][1] + left.z*matrix.mass[3][2] + left.w*matrix.mass[3][3];

	return result;
}

mat4f mat4f::operator*=(float number) 
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			mass[i][j] *= number;

	return *this;
}

mat4f mat4f::operator*=(const mat4f& right)
{
	return this->mul(right);
}

mat4f operator*(const mat4f& left, const mat4f& right)
{
	mat4f result;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			result.mass[i][j] = left.mass[i][0] * right.mass[0][j] +
			left.mass[i][1] * right.mass[1][j] +
			left.mass[i][2] * right.mass[2][j] +
			left.mass[i][3] * right.mass[3][j];

	return result;
}

mat4f mat4f::operator+=(const mat4f& right)
{
	return this->add(right);
}

mat4f operator+(const mat4f& left, const mat4f& right)
{
	mat4f result;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			result.mass[i][j] = left.mass[i][j] + right.mass[i][j];

	return result;
}

void mat4f::Value(float value)
{
	this->Identety();
	(*this)*=value;
}

void mat4f::InitTransforScale(float ScaleX, float ScaleY, float ScaleZ)
{
	mass[0][0] = ScaleX; mass[0][1] = 0.0f;   mass[0][2] = 0.0f;   mass[0][3] = 0.0f;
	mass[1][0] = 0.0f;   mass[1][1] = ScaleY; mass[1][2] = 0.0f;   mass[1][3] = 0.0f;
	mass[2][0] = 0.0f;   mass[2][1] = 0.0f;   mass[2][2] = ScaleZ; mass[2][3] = 0.0f;
	mass[3][0] = 0.0f;   mass[3][1] = 0.0f;   mass[3][2] = 0.0f;   mass[3][3] = 1.0f;
}

void mat4f::InitTransformRotate(float RotateX, float RotateY, float RotateZ)
{
	float dx = ToRadian(RotateX);
	float dy = ToRadian(RotateY);
	float dz = ToRadian(RotateZ);

	mat4f rx, ry, rz;

	rx.mass[0][0] = 1.0f; rx.mass[0][1] = 0.0f;     rx.mass[0][2] = 0.0f;      rx.mass[0][3] = 0.0f;
	rx.mass[1][0] = 0.0f; rx.mass[1][1] = cosf(dx); rx.mass[1][2] = -sinf(dx); rx.mass[1][3] = 0.0f;
	rx.mass[2][0] = 0.0f; rx.mass[2][1] = sinf(dx); rx.mass[2][2] = cosf(dx);  rx.mass[2][3] = 0.0f;
	rx.mass[3][0] = 0.0f; rx.mass[3][1] = 0.0f;     rx.mass[3][2] = 0.0f;      rx.mass[3][3] = 1.0f;

	ry.mass[0][0] = cosf(dy); ry.mass[0][1] = 0.0f; ry.mass[0][2] = -sinf(dy); ry.mass[0][3] = 0.0f;
	ry.mass[1][0] = 0.0f;     ry.mass[1][1] = 1.0f; ry.mass[1][2] = 0.0f;      ry.mass[1][3] = 0.0f;
	ry.mass[2][0] = sinf(dy); ry.mass[2][1] = 0.0f; ry.mass[2][2] = cosf(dy);  ry.mass[2][3] = 0.0f;
	ry.mass[3][0] = 0.0f;     ry.mass[3][1] = 0.0f; ry.mass[3][2] = 0.0f;      ry.mass[3][3] = 1.0f;

	rz.mass[0][0] = cosf(dz); rz.mass[0][1] = -sinf(dz); rz.mass[0][2] = 0.0f; rz.mass[0][3] = 0.0f;
	rz.mass[1][0] = sinf(dz); rz.mass[1][1] = cosf(dz);  rz.mass[1][2] = 0.0f; rz.mass[1][3] = 0.0f;
	rz.mass[2][0] = 0.0f;     rz.mass[2][1] = 0.0f;      rz.mass[2][2] = 1.0f; rz.mass[2][3] = 0.0f;
	rz.mass[3][0] = 0.0f;     rz.mass[3][1] = 0.0f;      rz.mass[3][2] = 0.0f; rz.mass[3][3] = 1.0f;

	(*this) = rz * ry * rx;
}

void mat4f::InitTransformWorldPosition(float PositionX, float PositionY, float PositionZ)
{
	mass[0][0] = 1.0f; mass[0][1] = 0.0f; mass[0][2] = 0.0f; mass[0][3] = PositionX;
	mass[1][0] = 0.0f; mass[1][1] = 1.0f; mass[1][2] = 0.0f; mass[1][3] = PositionY;
	mass[2][0] = 0.0f; mass[2][1] = 0.0f; mass[2][2] = 1.0f; mass[2][3] = PositionZ;
	mass[3][0] = 0.0f; mass[3][1] = 0.0f; mass[3][2] = 0.0f; mass[3][3] = 1.0f;
}