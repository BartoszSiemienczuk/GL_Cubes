#pragma once
#include "BaseObject.h"
#include "GL\freeglut.h"

class Camera : public BaseObject{
private:
	float angle;

public:
	void setAngle(float angle);
	float getAngle();
	void update();
};