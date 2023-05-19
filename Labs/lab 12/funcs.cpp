/*
Author: Tamanna Chowdhury 
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Vectors: A Song of Push and Pop, Lab11 A,B,C,D

This is where I will show what I have learned about vectors.
*/

#include <iostream> 
#include <vector> 
#include "funcs.h" 


//TASK A
std::vector<int> makeVector(int n){
    std::vector<int> num;
    for(int i = 0; i < n; i++){
       num.push_back(i);
    }
    return num;
}

//TASK B

std::vector<int> goodVibes(const std::vector<int>& v){
    std::vector<int> num; // we will use what we had from before
    //we want the vector to return all the numbers in the same order but it has to be postive
    // lets use a for loop to get postive numbers
    for(int i = 0; i < v.size(); i++){
       if( v[i] >= 0 ) {
         num.push_back(v[i]);
       }
       
    }
    return num;
}  
//TASK C
void gogeta(std::vector<int> &goku, std::vector<int> &vegeta){
    std::vector<int> num;
    for(int i = 0; i < vegeta.size(); i++){ // put in a for loop to access the information
        goku.push_back(vegeta.at(i)); // this wil return the elsement back to position 0
    }
    vegeta.clear(); //removes all elements in vector 
}



//TASK D
std::vector<int> sumPairWise(const std::vector<int> &v1, const std::vector<int> &v2) {
    int n = std::max(v1.size(), v2.size()); //we are taking the max number in the list given 
    std::vector<int> result(n); //then takes the result
    for (int i = 0; i < n; i++) { //puts it in a for loop
        int a = (i < v1.size()) ? v1[i] : 0; // replaces the size of a and b 
        int b = (i < v2.size()) ? v2[i] : 0; // then add the two letter -> numbers
        result[i] = a + b;
    }
    return result; //gives the result
}  







