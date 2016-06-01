#include "BaseObject.h"

void BaseObject::translate(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;
}

void BaseObject::rotate(float x, float y, float z)
{
	rotation.x += x;
	while (rotation.x > 360)
		rotation.x -= 360.0f;

	rotation.y += y;
	while (rotation.y > 360)
		rotation.y -= 360.0f;

	rotation.z += z;
	while (rotation.z > 360)
		rotation.z -= 360.0f;
}


Vector3 BaseObject::getPosition()
{
	return position;
}

Vector3 BaseObject::getRotation()
{
	return rotation;
}

void BaseObject::setPosition(Vector3 pPosition)
{
	position = pPosition;
}

void BaseObject::setPosition(float pX, float pY, float pZ)
{
	position.x = pX;
	position.y = pY;
	position.z = pZ;
}

void BaseObject::setRotation(Vector3 pRotation)
{
	rotation = pRotation;
}

void BaseObject::setRotation(float pX, float pY, float pZ)
{
	while (pX > 360)
		pX -= 360;
	rotation.x = pX;


	while (pY > 360)
		pY -= 360;
	rotation.y = pY;


	while (pZ > 360)
		pZ -= 360;
	rotation.z = pZ;

}

void BaseObject::setScale(float pScale)
{
	scale = pScale;
}
