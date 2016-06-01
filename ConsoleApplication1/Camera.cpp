#include "Camera.h"

void Camera::setAngle(float angle)
{
	this->angle = angle;
}

float Camera::getAngle()
{
	return this->angle;
}

void Camera::update()
{
	glLoadIdentity();
	gluLookAt(position.x, 1.0f, position.z,
		position.x+rotation.x, 1.0f, position.z+rotation.z,
		0.0f, 1.0f, 0.0f);
}
