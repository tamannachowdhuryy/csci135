#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include "funcs.h"
#include "doctest.h"

TEST_CASE("TASK A") {
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    CHECK(makeVector(10) == v);
    std::vector<int> v0;
    CHECK(makeVector(0) == v0);
    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6};
    CHECK(makeVector(7) == v1);
    std::vector<int> v2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    CHECK(makeVector(18) ==  v2);
    
}

TEST_CASE("TASK B") {
    std::vector<int> v{1, 2,-1, 3, 4, -1, 6};
    std::vector<int> newV{1, 2, 3, 4, 6};
    CHECK(goodVibes(v) == newV);
    std::vector<int> v1{1, 2, 3, -4, 5, 6, -7, -8, -9, 10};
    std::vector<int> newV1{1, 2, 3, 5, 6, 10};
    CHECK(goodVibes(v1) == newV1);
    std::vector<int> v2{10, 10, 10, 10, 10, 10, 10};
    std::vector<int> newV2{10, 10, 10, 10, 10, 10, 10};
    CHECK(goodVibes(v2) == newV2);
}

TEST_CASE("TASL C") {
    std::vector<int> v;
    
    std::vector<int> v1{1,2,3};
    std::vector<int> v2{4,5};
    std::vector<int> result{1,2,3,4,5};
    gogeta(v1, v2);
    CHECK(v1 == result);
    CHECK(v2 == v);

    std::vector<int> v3{10, 8, -7, 87};
    std::vector<int> v4{30, 50, 77, 89};
    std::vector<int> result2{10, 8, -7, 87, 30, 50, 77, 89};
    gogeta(v3, v4);
    CHECK(v3 == result2);
    CHECK(v4 == v);

}

TEST_CASE("TASK D")
{
    std::vector<int> v1{1,2,3};
    std::vector<int> v2{4,5};
    std::vector<int> result{5,7,3}; 
    CHECK(sumPairWise(v1,v2) == result);
    
    std::vector<int> v3{1,2,3,4,5,6,7};
    std::vector<int> result2{2,4,6,8,10,12,14};
    CHECK(sumPairWise(v3,v3) == result2);
}
