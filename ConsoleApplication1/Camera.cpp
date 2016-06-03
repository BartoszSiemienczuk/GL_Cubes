#include "Camera.h"

void Camera::setLastPost(Vector3 lastPos)
{
	this->lastPos = lastPos;
}

Vector3 Camera::getLastPost()
{
	return this->lastPos;
}

void Camera::setVertAngle(float angle)
{
	this->vertAngle = angle;
}

float Camera::getVertAngle()
{
	return this->vertAngle;
}

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
	//position is the eye position
	//rotation here is really the point to look at
	//third vector is "up"
	gluLookAt(position.x, 1.0f, position.z,
		position.x+rotation.x, rotation.y, position.z+rotation.z,
		0.0f, 1.0f, 0.0f);
}
