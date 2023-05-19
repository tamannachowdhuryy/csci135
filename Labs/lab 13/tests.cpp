#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("PRINT RANGE")
{
	std::string test1= "5 6 7 8 9 10 ";
	CHECK(printRange(5,10)==test1);
}

TEST_CASE("SUM RANGE")
{
	CHECK(sumRange(1,3)==6);
	CHECK(sumRange(-2,10)==52);
}

TEST_CASE("SUM ARRAY")
{
	int size = 10;
        int *arr = new int[size];
        arr[0]=12;
        arr[1]=17;
        arr[2]=-5;
        arr[3]=3;
        arr[4]=7;
        arr[5]=-15;
        arr[6]=27;
        arr[7]=5;
        arr[8]=13;
        arr[9]=-21;
        int sum1 = sumArray(arr,size);
	CHECK(sum1==43);
	sum1 = sumArray(arr,5);
	CHECK(sum1==34);
}

TEST_CASE("ALPHANUMERIC")
{
	CHECK(isAlphanumeric("ABCD"));
	CHECK(!isAlphanumeric("-abc 123"));
}

TEST_CASE("PARENTHESES")
{
	CHECK(nestedParens("(())"));
	CHECK(!nestedParens("(()"));
}
