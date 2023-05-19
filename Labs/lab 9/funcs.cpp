#include <iostream>
#include <cmath>
#include "funcs.h"
#include "coord3d.h"
// add functions here
double length(Coord3D *p){ // according to the website we were told to use double so we can write the equation 
    double result = sqrt(pow(p -> x, 2) + pow(p -> y, 2) + pow(p -> z, 2)); // this is how you write the equation to the length of the vector OP
    return result; // this will then return the value
}
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){ // this will pass the perameters farther from the orginal point 
    if(length(p1) < length(p2)){ //it will comeback the orginal perameter and the second  peramater to see which one is the fatherest
        return p1; // if it p1 then it will return its value
    }
    return p2; // or it will return value p2

}
void move(Coord3D *ppos, Coord3D *pvel, double dt){ // we will be using the void to move object (basically it won't print anything till it is called) velocity 
    ppos->x += pvel->x * dt; // took from the website 
    ppos->y += pvel->y * dt; // -> another way of writing pointers 
    ppos->z += pvel->z * dt;

}

Coord3D* createCoord3D(double x, double y, double z){ // this will create a new pass by reference for CoordED
    Coord3D *coord = new Coord3D; //this is declareing a pinter string 
    *coord = {x, y, z}; //dynamically allocate memory 
    return coord; //return the address where the coord is 
}
void deleteCoord3D(Coord3D *p){ // will be used when called 
     delete p; // once its not needed, delete it 

}
