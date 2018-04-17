#pragma once

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include<iostream>

#define PI 3.1415926535897932384626433832795
#define H 600
#define W 600
#define FPS 50
#define WALL_H 30
#define R 15

void drawBall();

void drawStripes(int, int);

void drawWalls();

void HitWalls();

void drawTarget();

void hitTarget();