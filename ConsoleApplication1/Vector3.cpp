#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float px, float py, float pz)
{
	x = px;
	y = py;
	z = pz;
}

Vector3::Vector3(const Vector3 &pVector)
{
	x = pVector.x;
	y = pVector.y;
	z = pVector.z;
}

void Vector3::setPosition(float px, float py, float pz)
{
	x = px;
	y = py;
	z = pz;
}
