#include <iostream>
#include "funcs.h"

// TASK A
bool isDivisibleBy(int n, int d){ // the 2 number that were picked
    if(d == 0){ //if number equals to 0 then it will print out false
      return false;
    }
    if(n % d == 0){ // if n module d is equal to 0 it will be true
      return true;
    } else { // anything else it will print out false 
      return false;
    }
}

// TASK B
bool isPrime(int n){ // will find if number is prime or not 
  if( n == 0 || n == 1){ // if n is equal to 0 or 1 it will return false 
    return false;
  }
  for(int i = 2; i <= n/2; i++){ // but if it goes through this for loop and if statement it will also print false
    if(n % i == 0){
      return false;
    }
  }
  return true; // if it passes all then is will print out true 
}

// TASK C
int nextPrime(int n){
  bool prime = false; // blank space being held to find the smallest prime number
  n += 1;
  while(prime == false){
    if(isPrime(n) == false){ // goes through the while loop and if it passes it will print false if not it will print true 
      n++;
      } else {
      prime = true;
      }
  }
  return n; 

}

//TASK D
int countPrimes(int a, int b){ // prime number inbetween two intervels 
  int count = 0;
  for(int i = a; i <= b; i++){ // goes through a for loop to find the interval 
    if(isPrime(i)){
      count++;
    }
  }
  return count; 
}

//TASK E
bool isTwinPrime(int n){ // this will print ou tthe twin prime 
  if((isPrime(n - 2) || isPrime(n + 2)) && isPrime(n)){ // if prim goes through either or it will print true 
    return true;
  }
  return false; // otherwise it will print false 
}

//TASK F
int nextTwinPrime(int n){
  bool prime = false; // bool will be false of prime
  n += 1;
  while(prime == false){ // goes through a while loop 
    if(isTwinPrime(n) == false){ // if it is false it prints out false 
      n++;
      } else {
      prime = true; // if it is a prime twin it will print out true 
      }
  }
  return n;  // then will return n 
}

//TASK G
int largestTwinPrime(int a, int b){ // this will print out the largest prime number 
  for(int i = b; i >= a; i--){ // basically the same code as task c 
    if(isTwinPrime(i)){ // except we don't use a in 
      return i; // we retuen i 
    }
  }
  return -1;  // and return -1 
}


