#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "funcs.h"
#include <string> 


//TASK B
TEST_CASE("TASK B: Caesar Cipher Encryption"){
CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
CHECK(encryptCaesar("Way to Go!", 5)== "Bfd yt Lt!");
}
//TASK C
TEST_CASE("TASK C: Vigenere Cipher Encryption"){
CHECK(encryptVigenere("Hello, World!","cake") == "Jevpq, Wyvnd!");
CHECK(encryptVigenere("Jackdaws love my big sphinx of quartz", "amazing") == "Jmcjlncs xoum ze bug rxuonj oe yhgrfz");  
}
//TASK D
TEST_CASE("TASK D: Decryption"){
CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
}
//EXTRA LAB


// add your tests here
TEST_CASE("CAESAR CIPHER SOLVER") {
    SUBCASE("Basic Tests"){
        std::string test1 = "P svcl Illdi. P svcl illdi h sva. Illdi pz tf iyvdu kvn!";
        //string test2 = 
        std::string ans1 = "I love Beewb. I love beewb a lot. Beewb is my brown dog!";

        std::string test2 = "Aol xbpjr iyvdu kvn qbtwlk vcly aol tpsrf ibu. ";

        std::string ans2 = "The quick brown dog jumped over the milky bun. ";

        std::string test3 = "Wyvmlzzvy Ghthuzrf pz h nylha JZ wyvmlzzvy!";

        std::string ans3 = "Professor Zamansky is a great CS professor!";

        std::string test4 = "Olssv dvysk. Aopz pz nvpun av il npiilypzo, zv ilhy dpao tl. Svylt pwzbt svclz av lha jhrl.";

        std::string ans4 = "Hello world. This is going to be gibberish, so bear with me. Lorem ipsum loves to eat cake.";

        std::string test5 = "jhlzhy jpwoly hal h sva vm wpjrlz zv kpzjvyk.wf jvbsk lha h sva vm jhrl huk wfaovu pz aol ilza jvkpun shunbhnl, iba p ullk av kv tvyl";

        std::string ans5 = "caesar cipher ate a lot of pickes so discord.py could eat a lot of cake and python is the best coding language, but i need to do more";
        CHECK(solve(test1) == ans1);
        CHECK(solve(test2) == ans2);
        CHECK(solve(test3) == ans3);
        CHECK(solve(test4) == ans4);
        CHECK(solve(test5) == ans5);
    }
    
}
