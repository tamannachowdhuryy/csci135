/*
Author: Tamanna Chowdhury
Course: CSCI-125
Github: tamannachowdhuryy
Instructor: Mike Zamansky
Assignment: Printing Shapes, Lab4

This file has all the back code on what is happening on the main.cpp file
*/
#include <iostream>
#include <string>
#include "func.h"


// TASK A: BOX
std::string box(int width, int height) { //telling the computer the width and height of the box
  std::string final = "";
  for (int row = 0; row < height; row++) { // will print the row and the height
    for (int column = 0; column < width; column++) { //this will tell the code to tell which way to put the stars
      final = final + " *"; //character that will print out the box
    }
    final = final + "\n"; // will put space between the stars 
  }
  return final; // will print everything out 
}
// TASK B: CHECKERBOARD
std::string checkerboard(int width, int height) { // will print out the checkerboard 

  std::string checkerboard = ""; //this is a empty string for the checkerboard 

  for (int row = 0; row < height; row++) { // used a for loop to define the height and width of shape 
    for (int column = 0; column < width; column++) { //option when the row and column is both equal to 0 or when row and colum not equal to 0 it will then print out the star but it it doesn't fit with in the if statement it will print out empty space 
      if (row % 2 == 0 && column % 2 == 0 || row % 2 != 0 & column % 2 != 0) // used a if statement to tell the computer what to do when there is a different answer 
        checkerboard += "*"; //print out a star
      else
        checkerboard += " "; // empty space 
    }
    checkerboard += "\n"; // print out in new line
  }
  return checkerboard; // goes through the for loop and prints out shape 
}

// TASK C: CROSS
std::string cross(int height) { // making a cross we will only initialize hieght 

  std::string cross = "";

  for (int row = 1; row <= height; row++) { // we made row equal to one to skip 0 for row and height
    for (int column = 1; column <= height; column++) { // we did the same thing accept for column 
      if ((row == column) || (column == (height + 1) - row)) { // if statemnet when the star is equal to the same rown and column or we do a differnt operation 
        cross += "*"; //if the if statement groes through it will print star
      } else {
        cross += " "; // if not it will print a empty string 
      }
    }
    cross += "\n"; // newline
  }
  return cross;
}
// TASK D: LOWER TRIANGLE
std::string lower(int length) { // this will print a lower traingle and we will be using lendth

  std::string lower = ""; // string line that will be called later in the code 

  for (int row = 0; row < length; row++) { // used a for loop to initialize the length, row and colunm 
    for (int column = 0; column + row < length; column++) {
      lower += "*"; // goes through the for loop and if it fits will will print star 
    }
    lower += "\n"; // newline 
  }

  return lower; // then return a shape 
}

// TASK E: UPPER TRIANGLE
std::string upper(int length){ // used length to initialize which way the upper triangle will look like
  std::string upper = "";// string will be called later on in the code 
  for(int row = 0; row < length; row++){  // using row and column equal to 0 to then state what length will be less then 
    for(int column = 0; column + row < length; column++){ // we will add the column and low to make the upper triangle 
      upper += "*"; // goes through will print a star
    }
      upper += "\n"; // then a new line
    for(int space = 0; space < row + 1; space++){  // differnt from the lower because we will flip this using space
      upper += " "; //empty string
    }
  }
  return upper; // ptint shape out 
}

//TASK F: UPSIDE-DOWN TRAPEZOID

std::string trapezoid(int width, int height) { // used width and height to make this shape 
  std::string trapezoid = ""; // string that will be called later on 
  if(height > width / 2){ // in order for the shape to be print it first has to go through this if statement where the height is greater the the width which is getting divide by 2
    return "IMPOSSIBLE SHAPE! \n"; // if this doesn't pass then it will print impossible shape
  } 
  int space = 0; // now we are initializing space and making it equal to 0
  int stars = width; // stars equal too width 

  for(int row = 0; row < height; row++){ //put it in a row look for both row and cplumn 
    for (int column = 0; column < space; column++) {
      trapezoid += " "; // space between the string when it is being printed 
    }
    for (int column = 0; column < stars; column++){ // for loop used for star
      trapezoid += "*"; // goes through the for and prints out star 
    }
    trapezoid += "\n"; // then will go through a newline
    space += 1; // there will be a space added to each column 
    stars -= 2; // and the star will be subtract two each column 
  }
  return trapezoid; //prints out the shape 
}

// TASK G: CHECKERBOARD (3X3)
std::string checkerboard3x3(int width, int height){ //this will print out the whole checkerboard but by 3x3
  std::string checkerboard3x3 = ""; // empty string for checkerboard
  for(int row = 0; row < height; row++){ // made two for loops for column, row and gave width and height specify details 
    for(int column = 0; column < width; column++){ 
      if(((row / 3) + column / 3) % 2 == 0){ // if statement to used the numbers given to print out stars for column and row 
        checkerboard3x3 += "*"; // prints stars 
      } else {
        checkerboard3x3 += " "; // makes space bewteen star if it doesn't pass through the if statement 
      }
    }
    checkerboard3x3 += "\n"; //goes to newlinw
  }
  return checkerboard3x3;  // prints shape out 
}
