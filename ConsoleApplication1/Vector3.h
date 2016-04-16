#pragma once

class Vector3 {
public:
	float x;
	float y;
	float z;
	Vector3();
	Vector3(float px, float py, float pz);
	Vector3(const Vector3 &pVector);

	void setPosition(float x, float y, float z);
};