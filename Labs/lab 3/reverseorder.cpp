#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include "reverseorder.h"

// we are using void so nothing is being return a value 
void reverse_oreder(std::string date1, std::string date2){
  std::string reverse = ""; // we are using a string so we can later on in the code delare a bool for a true or false so it can print out the values when it is being compared 
// this is how you call a tsv file on c++  
  std::ifstream fin("Current_Reservoir_Levels.tsv"); 
    if (fin.fail()){
      std::cerr << "File cannot be opened for reading." << "\n"; // will print out if there is an error
      exit(1); // exit if failed to open the file
    }

    std::string junk; // new string variable
    getline(fin,junk); // read one line from the file 

    std::string storageDate; // data in the storange we just gave it a name 
    double eastSt; // east storage
    double eastEl; // east elevation 
    std::string westSt; // this is a string because we are trying to add the two dates togther. this is the 
    std::string westEl; // west elevation

  bool reversed = false;
    while (fin >> storageDate >> eastSt >> eastEl >> westSt >> westEl)
    {
    fin.ignore(INT_MAX, '\n'); 
      if(!reversed){
         if(storageDate==date1){ // this is connecting to void data set one
            reversed = true; // this will only appear if not in the data 
        }
      }
// this statement will happen if the first one is true and will write out the data 1 time for west elevation       
      if(reversed){
          reverse = storageDate + " : " + westEl + "\n" + reverse;

// but if none of that happens then it will just print out data2 
            if (storageDate == date2){
                reversed = false;
            }
        }
        
    }

    std::cout << reverse;

}
