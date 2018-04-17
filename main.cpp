/*
abduvohid.com
wahid@sju.ac.kr

Wahid Coding Labs LTD. inc;
This software belongs to me,
any illegal use is prohibited,
don't distribute this software,
this software is Sejong licensed,

ALL RIGHTS RESERVED.

@COPYRIGHT, 2018.

https://github.com/abdulwahid2802/OpenGLDrawing.git
*/

#include "Game.h"


extern int X;
extern int Y;
extern bool move;
extern GLfloat dx;
extern GLfloat dy;




void display_callback();
void init();
void reshape_callback(int, int);
void timer_callback(int);
void passiveMouseMove_callback(int, int);
void mouse_callback(int, int, int, int);


int main(int argc, char** argv) {
	glutInit(&argc, argv);              
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Game");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutPassiveMotionFunc(passiveMouseMove_callback);
	glutMouseFunc(mouse_callback);
	glutTimerFunc(0, timer_callback, 0);
	init();
	glutMainLoop();                   
	return 0;
}


void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawBall();
	drawStripes(X, Y);
	drawWalls();
	drawTarget();

	glutSwapBuffers();
}

void init()
{
	glClearColor(0.827, 0.827, 0.827, 1);
}

void reshape_callback(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(.0, W, .0, H, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}

void passiveMouseMove_callback(int x, int y)
{

	//std::cout << x << " " << y << std::endl;
	X = x;
	Y = y;
}

void mouse_callback(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (move == false)
		{
			GLfloat x1 = 300;
			GLfloat y1 = 0;

			GLfloat x2 = (float)(W - (W - x));
			GLfloat y2 = (float)(H - y);

			dx = x2 - x1;
			dy = y2 - y1;

			if (state == GLUT_UP)
				move = true;
		}
		
	}
}