#pragma once
#include "Vector3.h"
class BaseObject {
protected :
	Vector3 position;
	Vector3 rotation;
	float scale;
public :
	Vector3 getPosition();
	Vector3 getRotation();
	void setPosition(Vector3 pPosition);
	void setPosition(float pX, float pY, float pZ);
	void setRotation(Vector3 pRotation);
	void setRotation(float pX, float pY, float pZ);
	void setScale(float pScale);

	void translate(float x, float y, float z);
	void rotate(float x, float y, float z);

};