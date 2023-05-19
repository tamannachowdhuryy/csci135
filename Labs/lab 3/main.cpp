/*
Author: Tamanna Chowdhury
Github: tamannachowdhuryy
Course: CSCI-135
Instructor:
Assignment: Lab 3
This will show how to take data from a tsv file get the max and min. A specific
storage data and will compare data from a certain time period with in the year
*/

#include "reservoir.h"    //includes storage, min and max
#include "reverseorder.h" //includes comparing the data
#include <iostream>

int main() {
  //TASK A
  std::cout << "East Storage Date 05/20/2018: "
            << get_east_storage("05/20/2018")
            << std::endl; // this wont take user input. it will just just pull
  std::cout << "East Storage Date 06/20/2018: "
            << get_east_storage("06/20/2018")
            << std::endl; // this wont take user input. it will just just pull
  //TASK B
// the data from 5/20/2018
  std::cout << "Minimum East Basin Storage: " << get_min_east()
            << std::endl; // will show the minimum of the east basin
  std::cout << "Maximum East Basin Storage: " << get_max_east()
            << std::endl; // will show the maximun of the east basin
  //TASK C 
  std::string compare = compare_basins("09/15/2018");
  std::cout << "Comparing Basins Data 09/15/2018: " << compare
            << std::endl; // this will compare the basins data

  //TASK D
  reverse_oreder("05/29/2018", "06/02/2018");

  return 0;
}
