#pragma once
#include "BaseObject.h"
#include "GL\freeglut.h"

class Camera : public BaseObject{
private:
	float angle;
	float vertAngle;
	Vector3 lastPos;

public:
	float deltaAngle = 0.0f;

	void setLastPost(Vector3 lastPos);
	Vector3 getLastPost();

	void setVertAngle(float angle);
	float getVertAngle();
	void setAngle(float angle);
	float getAngle();
	void update();

};