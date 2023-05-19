#include <iostream>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "funcs.h"

int main()
{
  
  //TASK B
  
  std::cout << "Task B: encrptCaesar(\"Way to Go!\", 5) = " << encryptCaesar("Way to Go!", 5) << std::endl;
  std::cout << "TASK B: encrptCaesar(\"Hello, World!\", 10) = " << encryptCaesar("Rovvy, Gybvn!", 10) <<  std::endl;
  
  //TASK C
  std::cout << "Task C: encryptVigenere(\"Hello, World!\", \"cake\") = " << encryptVigenere("Hello, World!", "cake") << std::endl;
  std::cout << "Task C: encryptVigenere(\"Jackdaws love my big sphinx of quartz\", \"amazing\") = " << encryptVigenere("Jmcjlncs xoum ze bug rxuonj oe yhgrfz", "amazing")  << std::endl;  
  //TASK D
  std::cout << "Task D: decryptCaesar(Bfd yt Lt!, 5) = " << decryptCaesar("Bfd yt Lt!", 5) << std::endl;
  std::cout << "Task D: decryptVigenere(Jevpq, Wyvnd!, 5) = " << decryptVigenere("Jevpq, Wyvnd!", "cake") << std::endl;
  
  
 //EXTRA LAB
  std::cout << "Extra Lab:" << std::endl;
  std::string encrypted_string = "Olssv, P ohcl h iyvdu kvn uhtlk Illdi. Opz kpla jvuzpzaz vm zaypjasf ivulz huk tpsr, huk ol ohz av zsllw 23 ovbyz h khf.";
  std::cout<<"ENCRYPTED STRING: "<< encrypted_string << std::endl;
  std::cout<<"SOLVED STRING: "<< solve(encrypted_string) << std::endl;
  return 0;
}

