#include "Game.h"

int delta = 0;
int i = 1;

int pbX = 300;
int pbY = 0;
bool move = false;

// for stripes
int X;
int Y;

// for direction of ball
GLfloat dx = 0;
GLfloat dy = 0;

// for walls
int wall1[2] = { 0, 150 };
int wall2[2] = { 350, 300 };
int wall3[2] = { 200, 450 };

// for food
int TBottom_X = 285;
int TTop_X = 315;
int TBottom_Y = 530;
int TTop_Y = 560;


void drawBall()
{
	glBegin(GL_POLYGON);
	glColor3f(0.961, 0.961, 0.961);
	for (GLfloat i = 0.0; i <= 2 * PI; i += 0.001)
		glVertex3f(cos(i) * 15 + pbX, sin(i) * 15 + pbY, 0.0);
	glEnd();

	if (move)
	{
		pbX += (float)dx/15;
		pbY += (float)dy/15;


		if (pbY <= 0)
		{
			int res = MessageBox(NULL, "You Loser!", "Game Over",
				MB_DEFBUTTON2 | MB_ICONEXCLAMATION);
			exit(1);
		}

		if (pbX >= W || pbX <= 0)
			dx *= -1;

		if (pbY >= H)
			dy *= -1;

		HitWalls();
		hitTarget();

	}
}

void drawStripes(int x, int y)
{
	glPushAttrib(GL_ENABLE_BIT);
	// glPushAttrib is done to return everything to normal after drawing

	glLineStipple(5, 0xAAAA);  //# [1]
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex3f(300, 0, 0);
	glVertex3f(W - (W-x), (H-y), 0);
	glEnd();

	glPopAttrib();
}

void drawWalls()
{
	if (delta == 70 || delta == -70)
		i *= -1;

	delta += i;

	glColor3f(0.763, 0.663, 0.663);

	glRectd(wall1[0], wall1[1], wall1[0] + 300, wall1[1] + WALL_H);
	glRectd(wall2[0], wall2[1], wall2[0] + 250, wall2[1] + WALL_H);
	glRectd(wall3[0] + delta, wall3[1], wall3[0] + 250 + delta, wall3[1] + WALL_H);
}

void HitWalls()
{
	if (pbX - R == wall1[0] + 300 && ((pbY >= wall1[1] + R) && (pbY <= wall1[1] + WALL_H - R)))
		dx *= -1;

	
	if (pbY >= (wall1[1] - R) && pbY <= (wall1[1] + WALL_H + R) && pbX <= (wall1[0] + 300 + R))
	{
		if(pbX <= (wall1[0] + 300 + R) && pbX >= (wall1[0] + 300))
			dx *= -1;
		else
			dy *= -1;
	}

	else if (pbY >= (wall2[1] - R) && pbY <= (wall2[1] + WALL_H + R) && pbX >= (wall2[0] - R))
	{
		if (pbX >= (wall2[0] - R) && pbX <= (wall2[0]))
			dx *= -1;
		else
			dy *= -1;
	}

	else if (pbY >= (wall3[1] - R) && pbY <= (wall3[1] + WALL_H + R) && pbX >= (wall3[0] - R) && pbX <= (wall3[0] + 250 + R))
	{
		if (pbX >= (wall3[0] - R) && pbX <= (wall3[0]))
			dx *= -1;
		else if(pbX <= (wall3[0] + 250 + R) && pbX >= (wall3[0]) + 250)
			dx *= -1;
		else
			dy *= -1;
	}

}

void drawTarget()
{

	glColor3f(0.855, 0.647, 0.125);
	glRectd(TBottom_X, TBottom_Y, TTop_X, TTop_Y);
}

void hitTarget()
{
	if ((pbY >= TBottom_Y) && (pbY <= TTop_Y ) && (pbX >= TBottom_X ) && (pbX <= TTop_X ))
	{
		int res = MessageBox(NULL, "You Winner!", "Game Success",
			MB_DEFBUTTON2 | MB_ICONEXCLAMATION);
		exit(1);

	}	
}