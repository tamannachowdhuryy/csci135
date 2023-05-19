//Write a program smaller3.cpp that asks the user to input three integer numbers, and prints out the smallest of the three.

#include <iostream>
int main(){
int x,y,z;
  std::cout << "Enter the first number: ";
  std::cin >> x;
  std::cout << "Enter the second number: " ; 
  std::cin >> y; 
  std::cout << "Enter the third number: " ; 
  std::cin >> z; 
  
  if (x <= y && x <= z)
        std::cout << x << " is the smallest";
 
    else if (y <= x && y <= z)
        std::cout << y << " is the smallest";
 
    else
        std::cout << z << " is the smallest";
 
    return 0;

}
