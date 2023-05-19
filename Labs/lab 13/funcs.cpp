/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Recursion., Lab13 A,B,C,D,E

Using our knowledge of recursion.
*/


#include <iostream>
#include <string>
#include <cctype> 
#include "funcs.h"

//TASK A

std::string printRange(int left, int right) {
	if(left<=right){ // used an if statement range left <= x <= right
	std::string s = std::to_string(left) + " " + printRange(left + 1,right);
	     return s;
	} else {
	    std::string s = ""; //empty string
	}
	return ""; //-2 -1 0 1 2 3 4 5 6 7 8 9 10
}

//TASK B
int sumRange(int left, int right){ // given information
     int sum = 0; // sum starts from 0
     if (left <= right){ // used the range left <= x <= right
        sum = left + sumRange(left +1, right); //taking the sume of the left and right
	}
	return sum; // then returns the answer 
}


//TASK C
int sumArray(int *arr, int size){ // recuration taking one 
    return sumArrayInRange(arr, 0, size - 1);
}

int sumArrayInRange(int *arr, int left, int right){ // sum of the range 
    if(left <= right) {
       int num = arr[left] + sumArrayInRange(arr,left +1, right);
	 return num; //return the number 
    } else {
	return 0; //return full value 
	}
}

//TASK D
bool isAlphanumeric(std::string s){
	bool valid = true; // uses a bool so the function can flag whe it is correct 
	int size = s.length(); // this will take the size length 
	if (size > 0){ // less then 0 
	    valid = isalnum(s[0]);
	       if (valid){
		  valid = isAlphanumeric(s.substr(1,size-1));
		}
	}
	return valid;
}

//TASK E
bool nestedParens(std::string s){
	if(s.substr(0,1)=="("&&s.substr(s.length()-1,1)==")"){
		return nestedParens(s.substr(1,s.length()-2));
	}
	else if(s.length()<2){
		if(s!="("&&s!=")"){
			return true;
		}
		return false;
	}
	else{
		return false;
	}
	return false;
}
