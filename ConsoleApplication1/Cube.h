#pragma once
#include "Vector3.h"
#include "BaseObject.h"

class Cube : public BaseObject {
private:
	bool selected = false;

public:
	Cube(void);

	bool getSelected() const;
	void setSelected(bool selected);

	void drawCube();
};