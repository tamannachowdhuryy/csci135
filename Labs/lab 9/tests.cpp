#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "coord3d.h"

TEST_CASE("A")
{
    Coord3D point1 = {50, 67, 78};
    CHECK(((length(&point1) - 114.337) < 0.01));
    Coord3D point2 = {87, 9, 81};
    CHECK(((length(&point1) - 119.21) < 0.01));
}

TEST_CASE("B")
{
    Coord3D point1 = {15, 16, 17};
    Coord3D point2 = {18, 18, 18};
    CHECK_LE(fartherFromOrigin(&point1, &point2), &point2);

    Coord3D point3 = {30, 40, 50};
    Coord3D point4 = {75, 50, 75};
    CHECK_LE(fartherFromOrigin(&point3, &point4), &point3);
}

TEST_CASE("C")
{
    Coord3D pos = {3, -5, 152};
    Coord3D vel = {-1, 2, 0.74};
    move(&pos, &vel, 5.0);
    CHECK(pos.x == -2);
    CHECK(pos.y == 5);
    CHECK(pos.z == 155.7);
}

TEST_CASE("E")
{
    Coord3D *ppos = createCoord3D(15, 16, 17); 
    CHECK(ppos -> x == 15);
    CHECK(ppos -> y == 16);
    CHECK(ppos -> z == 17);
    deleteCoord3D(ppos);

    Coord3D *pvel = createCoord3D(4.5, 5.6, 6.7); 
    CHECK(pvel -> x == 4.5);
    CHECK(pvel -> y == 5.6);
    CHECK(pvel -> z == 6.7);
    deleteCoord3D(pvel);
}
 
