#include <gl/freeglut.h>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "Cube.h"
#include <iostream>
#include <cstdio>
#include <vector>

/* Global variables */
char title[] = "3D Shapes";
float rotation = 0.0;
std::vector<Cube> cubes;

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	
	for (auto i = 0; i < cubes.size(); i++)
	{
		cubes[i].drawCube();
	}

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void selectNextCube(bool previous = false)
{
	for (size_t i = 0; i < cubes.size(); i++) //iterate over all cubes
	{
		if (cubes[i].getSelected() == true) //found the active cube
		{
			if (!previous) //if going right
			{
				cubes[i].setSelected(false);
				if (i + 1 < cubes.size())
					cubes[i + 1].setSelected(true);
				else
					cubes[0].setSelected(true);
				return;
			}
			else //if going left
			{

				cubes[i].setSelected(false);
				if (i>=1)
					cubes[i - 1].setSelected(true);
				else
					cubes[cubes.size()-1].setSelected(true);
				return;
			}
		}
	}
}

void moveCube(int direction)
{
	const float step = 0.05;
	for (size_t i = 0; i < cubes.size(); i++) //iterate over all cubes
	{
		if (cubes[i].getSelected() == true) //found the active cube
		{
			switch (direction)
			{
				case GLUT_KEY_UP:
					cubes[i].translate(0, step, 0);
				break;
				case GLUT_KEY_DOWN:
					cubes[i].translate(0, -step, 0);
				break;
				case GLUT_KEY_LEFT:
					cubes[i].translate(-step, 0, 0);
				break;
				case GLUT_KEY_RIGHT:
					cubes[i].translate(step, 0, 0);
				break;
			}

		}
	}
}

void keyboardCallback(unsigned char key, int x, int y) {
	if (key == '[')
		selectNextCube(true);
	else if(key == ']')
		selectNextCube(false);
}

void specialKeyboardCallback(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN:
		case GLUT_KEY_RIGHT:
		case GLUT_KEY_LEFT:
			moveCube(key);
		break;
	}
}


/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
											   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void initCubes()
{
	Cube c1;
	c1.setPosition(1.5f, 0.0f, -7.0f);
	c1.setRotation(0.0f, 0.0f, 0.0f);
	c1.setScale(0.5f);

	cubes.push_back(c1);

	Cube c2;
	c2.setPosition(-1.5f, 0.0f, -7.0f);
	c2.setRotation(0.0f, 45.0f, 0.0f);
	c2.setScale(0.25f);

	cubes.push_back(c2);

	cubes[0].setSelected(true);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutIdleFunc(display);			//to animate when idle
	glutKeyboardFunc(keyboardCallback);
	glutSpecialFunc(specialKeyboardCallback); 
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	initCubes();					//create some cubes
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}
