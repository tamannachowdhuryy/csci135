/*
Author: your name
Course: CSCI-136
Instructor: their name
Assignment: title, e.g., Lab1A

Here, briefly, at least in one or a few sentences
describe what the program does.
*/
#include <iostream>
#include "coord3d.h"
#include <cmath>
#include "funcs.h"

int main()
{
  std::cout << "Task A:" << std::endl;
  Coord3D pointP = {10, 20, 30};
  std::cout << length(&pointP) << std::endl; // would print 37.4166

  std::cout << "Task B:" << std::endl;
  pointP = {10, 20, 30};
  Coord3D pointQ = {-20, 21, -22};

  std::cout << "Address of P: " << &pointP << std::endl;
  std::cout << "Address of Q: " << &pointQ << std::endl;

  Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
  std::cout << "ans = " << ans << std::endl;

  std::cout << "Task C:" << std::endl;
  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1, -5, 0.2};

  move(&pos, &vel, 2.0); // object pos gets changed
  std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
  // prints: 2 -10 100.4

  std::cout << "Task E:" << std::endl;
  Coord3D *ppos = createCoord3D(10,20,30);
  Coord3D *pvel = createCoord3D(5.5,-1.4,7.77);

  move(ppos, pvel, 10.0);

  std::cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;

  deleteCoord3D(ppos); // release memory
  deleteCoord3D(pvel);

  return 0;
}
