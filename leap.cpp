
#include <iostream>
#include <string> 
using namespace std;
int main(){
  int year;
  cout << "Enter year: ";
  cin >> year; 
  if (year % 4 != 0){
    cout << "common year" ;
  } else if(year % 100 != 0){
    cout << "it is a leap year "; 
  } else if (year % 400 !=0){
    cout << "it it a common year";
  } else{
    cout << "it is a leap year";
  }
  return 0;
}
