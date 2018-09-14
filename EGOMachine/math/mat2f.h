#pragma once

#include "vec2f.h"

class mat2f
{
private:
	float mass[2][2];
public:
	mat2f();
	void Indentety();
	void initScaleTransform(float ScaleX, float ScaleY);
	void initRotatetransform(float RotateX, float RotateY);
	void initWorldPositionTransform(float PositionX, float PositionY);
	~mat2f();
};

