#pragma once
#include "coord3d.h"

// add prototypes here
double length(Coord3D *p); // TASK A
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2); //TASK B
void move(Coord3D *ppos, Coord3D *pvel, double dt); //TASK C
Coord3D* createCoord3D(double x, double y, double z); // TASK D
void deleteCoord3D(Coord3D *p); // TASK E


