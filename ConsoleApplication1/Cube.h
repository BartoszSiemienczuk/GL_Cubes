#pragma once
#include "Vector3.h"

class Cube {
private:
	Vector3 position;
	Vector3 rotation;
	float scale;
	bool selected = false;

public:
	Cube(void);
	void setPosition(Vector3 pPosition);
	void setPosition(float pX, float pY, float pZ);
	void setRotation(Vector3 pRotation);
	void setRotation(float pX, float pY, float pZ);
	void setScale(float pScale);

	void translate(float x, float y, float z);

	bool getSelected() const;
	void setSelected(bool selected);

	void drawCube();
};