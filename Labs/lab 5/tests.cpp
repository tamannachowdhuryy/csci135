#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// TASK A
TEST_CASE("isDivisibleBy() outputs") {
	CHECK(isDivisibleBy(100,25) == true);
	CHECK(isDivisibleBy(35,17) == false);
	CHECK(isDivisibleBy(64,8) == true);
	CHECK(isDivisibleBy(125, 25) == true);
}

// TASK B
TEST_CASE("isPrime() outputs") {
	CHECK(isPrime(2) == true);
	CHECK(isPrime(3) == true);
	CHECK(isPrime(5) == true);
	CHECK(isPrime(7) == true);
	CHECK(isPrime(11) == true);
	CHECK(isPrime(13) == true);
	CHECK(isPrime(17) == true);
	CHECK(isPrime(19) == true);
}

// TASK C
TEST_CASE("nextPrime() outputs") {
	CHECK(nextPrime(14) == 17);
	CHECK(nextPrime(20) == 23);
	CHECK(nextPrime(41) == 43);
	CHECK(nextPrime(5) == 7);
}

// TASK D
TEST_CASE("countPrimes() outputs") {
	CHECK(countPrimes(0, 10) == 4);
	CHECK(countPrimes(10, 20) == 4);
	CHECK(countPrimes(0, 15) == 6);
	CHECK(countPrimes(4, 40) == 10);
}

// TEST E
TEST_CASE("isTwinPrime() outputs") {
	CHECK(isTwinPrime(19) == true);
	CHECK(isTwinPrime(11) == true);
	CHECK(isTwinPrime(23) == false);
	CHECK(isTwinPrime(29) == true);
	CHECK(isTwinPrime(2) == false);
}

// TEST F
TEST_CASE("nextTwinPrime() outputs") {
	CHECK(nextTwinPrime(3) == 5);
	CHECK(nextTwinPrime(10) == 11);
	CHECK(nextTwinPrime(19) == 29);
	CHECK(nextTwinPrime(14) == 17);
}

// TEST G
TEST_CASE("largestTwinPrime() outputs") {
	CHECK(largestTwinPrime(5, 18) == 17);
	CHECK(largestTwinPrime(1, 31) == 31);
	CHECK(largestTwinPrime(14, 16) == -1);
	CHECK(largestTwinPrime(3, 11) == 11);
	CHECK(largestTwinPrime(10, 20) == 19);
}
