#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reservoir.h" //file where our function is in

double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv"); 
    if (fin.fail()){
      std::cerr << "File cannot be opened for reading." << "\n";
      exit(1); // exit if failed to open the file
    }

    std::string junk;
    getline(fin,junk);

    std::string storageDate;
    double eastSt; // east storage 
    double eastEl; // east elevation 
    double westSt; // west storage 
    double westEl; // west storage 

    while (fin >> storageDate >> eastSt >> eastEl >> westSt >> westEl)
    {
    fin.ignore(INT_MAX, '\n'); 
        if(date==storageDate){
            return eastSt;
        }
    }
    return 0;
}
// this will be getting the min for the east 
double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
      std::cerr << "File cannot be opened for reading." << "\n"; // this will acuure if the computer can't read the file
        exit(1); // exit if failed to open the file
    }
    std::string junk; // new string variable
    getline(fin, junk); // read one line from the file 

    std::string storageDate;
    double eastSt; // east storage 
    double eastEl; // east elevation 
    double westSt; // west storage 
    double westEl; // west storage 

    double minSt; // double might have a decimal point which is why we are using that to help find the minimum 

    bool storage = true; // help use see if it is true and false 
    while (fin >> storageDate >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MAX, '\n'); 

        if (storage) { // storage is true when looking in the east file that there is a number that is small then it will continue but if that is not true it will be false 
            minSt = eastSt;
            storage = false;
        }

        if (eastSt < minSt) // this will find the smallest value in eastSt
        {
            minSt = eastSt; // this shows that if there is a number less then, then it is equal too each other and will return it to the screen
        }
    }

    return minSt; //return your answer
}
// this will go over the max value in east and west 
double get_max_east(){
  std::ifstream fin("Current_Reservoir_Levels.tsv"); // this is our file and we are calling it through ifsteam 
    if (fin.fail()){
      std::cerr << "File cannot be opened for reading." << "\n"; // this will acuure if the computer can't read the file
        exit(1); // exit if failed to open the file
    }
  std::string junk; // new string variable
    getline(fin, junk); // read one line from the file 
// these are all the columes it will be bring the max or min from 
    std::string storageDate; 
    double eastSt; // east storage 
    double eastEl; // east elevation 
    double westSt; // west storage 
    double westEl; // west storage 

    double maxSt; // this decalaring that there will be a max

    bool storage = true;
    while (fin >> storageDate >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MAX, '\n'); 

        if (storage) { // storage is true when looking in the east file that there is a number that is big then it will continue but if that is not true it will be false 
            maxSt = eastSt;
            storage = false;
        }

        if (eastSt > maxSt) // this will find the biggest value in eastSt
        {
            maxSt = eastSt; // this shows that if there is a number bigger number then it is equal too each other and will return it to the screen
        }
    }

    return maxSt;
}
//this is comparing the two dats in west and east
std::string compare_basins(std::string date){
  std::ifstream fin("Current_Reservoir_Levels.tsv"); //this includes the data 
    if (fin.fail()){
      std::cerr << "File cannot be opened for reading." << "\n"; //will show error if it can't be read
      exit(1); // exit if failed to open the file
    }
    std::string result;  // new string variable
    std::string junk;  // new string variable
    getline(fin,junk);// read one line from the file 

  // these are all the columns that will be read 
    std::string storageDate; // this is a string that helps us compare the file 
    double eastSt; // east storage 
    double eastEl; // east elevation 
    double westSt; // west storage 
    double westEl; // west storage 

    while (fin >> storageDate >> eastSt >> eastEl >> westSt >> westEl){
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 

    if(date==storageDate)
		{
			if(eastEl > westEl) //this is saying that if east basin is geater them west basin
			{
				result = "East"; // then it will print out east 
			}
			else if(westEl > eastEl) // but if west is greater then east then it will print out west
			{
				result = "West"; 
			}
			else
			{
				result = "Equal"; // but if there are the same then it will print out equal 
			}
		}
	}

	return result;
	fin.close();
}
    
