#include "Cube.h"
#include "Vector3.h"
#include <GL/freeglut.h>
#include <GL/glut.h>


Cube::Cube(void)
{
	position.x = 0.0f;
	position.z = -10.0f;
	position.y = 0.0f;

	rotation.x = 0.0f;
	rotation.y = 0.0f;
	rotation.z = 0.0f;

	scale = 1.0f;
}

bool Cube::getSelected() const
{
	return selected;
}

void Cube::setSelected(bool selected)
{
	this->selected = selected;
}

void Cube::drawCube()
{
	//glLoadIdentity();

	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
									  // Top face (y = 1.0f*scale)
									  // Define vertices in counter-clockwise (CCW) order with normal pointing out
	glColor3f(0.0f, 1.0f, 0.0f);     // Green
	glVertex3f(1.0f*scale, 1.0f*scale, -1.0f*scale);
	glVertex3f(-1.0f*scale, 1.0f*scale, -1.0f*scale);
	glVertex3f(-1.0f*scale, 1.0f*scale, 1.0f*scale);
	glVertex3f(1.0f*scale, 1.0f*scale, 1.0f*scale);

	// Bottom face (y = -1.0f*scale)
	if(selected)
		glColor3f(0.0f, 1.0f, 0.0f);     // Green
	else
		glColor3f(1.0f, 0.5f, 0.0f);     // Orange
	glVertex3f(1.0f*scale, -1.0f*scale, 1.0f*scale);
	glVertex3f(-1.0f*scale, -1.0f*scale, 1.0f*scale);
	glVertex3f(-1.0f*scale, -1.0f*scale, -1.0f*scale);
	glVertex3f(1.0f*scale, -1.0f*scale, -1.0f*scale);

	// Front face  (z = 1.0f*scale)
	if (selected)
		glColor3f(0.0f, 1.0f, 0.0f);     // Green
	else
		glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(1.0f*scale, 1.0f*scale, 1.0f*scale);
	glVertex3f(-1.0f*scale, 1.0f*scale, 1.0f*scale);
	glVertex3f(-1.0f*scale, -1.0f*scale, 1.0f*scale);
	glVertex3f(1.0f*scale, -1.0f*scale, 1.0f*scale);

	// Back face (z = -1.0f*scale)

	if (selected)
		glColor3f(0.0f, 1.0f, 0.0f);     // Green
	else
		glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f(1.0f*scale, -1.0f*scale, -1.0f*scale);
	glVertex3f(-1.0f*scale, -1.0f*scale, -1.0f*scale);
	glVertex3f(-1.0f*scale, 1.0f*scale, -1.0f*scale);
	glVertex3f(1.0f*scale, 1.0f*scale, -1.0f*scale);

	// Left face (x = -1.0f*scale)

	if (selected)
		glColor3f(0.0f, 1.0f, 0.0f);     // Green
	else
		glColor3f(0.0f, 0.0f, 1.0f);     // Blue
	glVertex3f(-1.0f*scale, 1.0f*scale, 1.0f*scale);
	glVertex3f(-1.0f*scale, 1.0f*scale, -1.0f*scale);
	glVertex3f(-1.0f*scale, -1.0f*scale, -1.0f*scale);
	glVertex3f(-1.0f*scale, -1.0f*scale, 1.0f*scale);

	// Right face (x = 1.0f*scale)

	if (selected)
		glColor3f(0.0f, 1.0f, 0.0f);     // Green
	else
		glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3f(1.0f*scale, 1.0f*scale, -1.0f*scale);
	glVertex3f(1.0f*scale, 1.0f*scale, 1.0f*scale);
	glVertex3f(1.0f*scale, -1.0f*scale, 1.0f*scale);
	glVertex3f(1.0f*scale, -1.0f*scale, -1.0f*scale);


	glEnd();  // End of drawing color-cube
}
