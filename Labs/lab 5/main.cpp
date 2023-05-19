#include <iostream>
#include "funcs.h"

// TASK A
int main(){
  std::cout << "isDivisibleBy (100, 25) == " << isDivisibleBy(100, 25) << "\n";
  std::cout << "isDivisibleBy (35, 17) == " << isDivisibleBy(35, 17) << "\n";

// TASK B
  std::cout << "isPrime (3): " << isPrime(3) << "\n"; 
  std::cout << "isPrime (6): " << isPrime(6) << "\n"; 

// TASK C
  std::cout << "nextPrime (14) == " << nextPrime (14) << "\n";
  std::cout << "nextPrime (17) == " << nextPrime (17) << "\n";

// TASK D
  std::cout << "countPrimes(4, 40): " << countPrimes(4, 40) << "\n";
  std::cout << "countPrimes(2, 47): " << countPrimes(2, 47) << "\n";

// TASK E
  std::cout << "isTwinPrime (14): " << isTwinPrime (14) << "\n";
  std::cout << "isTwinPrime (17): " << isTwinPrime (17) << "\n";

// TASK F
  std::cout << "nextTwinPrime (19): " << nextTwinPrime (19) << "\n";
  std::cout << "nextTwinPrime (29): " << nextTwinPrime (29) << "\n";

// TASK G
  std::cout << "largestTwinPrime(1, 31): " << largestTwinPrime(1, 31) << "\n";
  std::cout << "largestTwinPrime(14, 16): " << largestTwinPrime(14, 16) << "\n";
}



