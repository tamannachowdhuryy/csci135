/*
Author: Tamanna Chowdhury
Course: CSCI-125
Github: tamannachowdhuryy
Instructor: Mike Zamansky
Assignment: Printing Shapes, Lab4

This will print out all the shapes that are stated 
*/

#include <iostream>
#include <string>
#include "func.h"

int main(){
//TASK A: BOX
  std::cout << "TASK A: BOX \n"; 
  std::cout << "Width: 3 \n";
  std::cout << "Height: 5 \n";
  std::cout << "Shape: \n";
  std::cout << box(3, 5);
  std::cout << "\n------------------\n";

  std::cout << "TASK A: BOX \n";
  std::cout << "Width: 7 \n";
  std::cout << "Height: 4 \n";
  std::cout << "Shape: \n";
  std::cout << box(7, 4);
  std::cout << "\n------------------\n";
  
//TASK B: CHECKERBOARD
  std::cout << "TASK B: CHECKERBOARD \n";
  std::cout << "Width: 11 \n";
  std::cout << "Height: 6 \n";
  std::cout << "Shape: \n";
  std::cout << checkerboard(11, 6);
  std::cout << "\n------------------\n";

  std::cout << "TASK B: CHECKERBOARD \n";
  std::cerr << "Width: 13 \n";
  std::cerr << "Height: 7 \n";
  std::cerr << "Shape: \n";
  std::cerr << checkerboard(13, 7);
  std::cerr << "\n------------------\n";
  
//TASK C: CROSS
  std::cout << "TASK C: CROSS \n";
  std::cout << "Size: 8 \n";
  std::cout << "Shape: \n";
  std::cout << cross(8);
  std::cout << "\n------------------\n";

  std::cout << "TASK C: CROSS \n";
  std::cerr << "Size: 10 \n";
  std::cerr << "Shape: \n";
  std::cerr << cross(10);
  std::cerr << "\n------------------\n";

//TASK D: LOWER
  std::cout << "TASK D: LOWER \n";
  std::cout << "Size: 6 \n";
  std::cout << "Shape: \n";
  std::cout << lower(6);
  std::cout << "\n------------------\n";

  std::cout << "TASK D: LOWER \n";
  std::cout << "Size: 10 \n";
  std::cout << "Shape: \n";
  std::cout << lower(15);
  std::cout << "\n------------------\n";

//TASK E: UPPER
  std::cout << "TASK E: UPPER \n";
  std::cout << "Size: 5 \n";
  std::cout << "Shape: \n";
  std::cout << upper(5);
  std::cout << "\n------------------\n";

  std::cout << "TASK E: UPPER \n"; 
  std::cout << "Size: 8 \n";
  std::cout << "Shape: \n";
  std::cout << upper(8);
  std::cout << "\n------------------\n";
  
//TASK F: UPSIDE-DOWN TRAPEZOID
  std::cout << "TASK F: UPSIDE-DOWN TRAPEZOID \n";
  std::cout << "Width: 12 \n";
  std::cout << "Height: 5 \n";
  std::cout << "Shape: \n";
  std::cout << trapezoid(12, 5);
  std::cout << "\n------------------\n";

  std::cout << "TASK F: UPSIDE-DOWN TRAPEZOID \n";
  std::cout << "Width: 12 \n";
  std::cout << "Height: 7 \n";
  std::cout << "Shape: \n";
  std::cout << trapezoid(12, 7);
  std::cout << "\n------------------\n";
  
// TASK G: CHECKERBOARD (3X3)
  std::cout << "TASK G: CHECKERBOARD(3X3) \n";
  std::cout << "Width: 16 \n";
  std::cout << "Height: 11 \n"; 
  std::cout << "Shape: \n";
  std::cout << checkerboard3x3(16, 11);
  std::cout << "\n------------------\n";

  std::cout << "TASK G: CHECKERBOARD(3x3) \n";
  std::cout << "Width: 27 \n";
  std::cout << "Height: 27 \n"; 
  std::cout << "Shape: \n";
  std::cout << checkerboard3x3(27, 27);
  std::cout << "\n------------------\n";
return 0; 
}
