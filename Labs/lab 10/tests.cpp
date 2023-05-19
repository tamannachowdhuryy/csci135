#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

TEST_CASE("Time")
{
	Time one = {12,00};
	Time two = {14,00};
	Time three = {17,30};
	CHECK(minutesSinceMidnight(one)==720);
	CHECK(minutesUntil(two,three)==210);
}

TEST_CASE("Movie")
{
	Movie oneM = {"Back to the Future", COMEDY , 116};
	CHECK(oneM.title=="Back to the Future");
	CHECK(oneM.duration==116);
}

TEST_CASE("Time Slot")
{
        Movie movie1 = {"Back to the Future", COMEDY, 15};
    	Movie movie2 = {"Black Panther", ACTION, 134};
    	TimeSlot morning = {movie1, {9, 15}};  
    	TimeSlot daytime = {movie2, {12, 15}}; 
    	TimeSlot evening = {movie2, {16, 45}};
    	CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (15 min) [starts at 9:15, ends by 9:30]");
    	CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]");
    	CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]");

}

TEST_CASE("Schedule")
{
	Movie oneM = {"Back to the Future", COMEDY , 116};
	Movie twoM = {"Black Panter", ACTION, 134};
	TimeSlot tsTwo = {oneM, {15,15}};
	TimeSlot tsThree = scheduleAfter(tsTwo, twoM);
	Time check = tsThree.startTime;
	int time = (check.h*60)+check.m;
	CHECK(time==1031);
}

TEST_CASE("Overlap")
{
	Movie movie2 = {"Black Panter", ACTION, 134};
	TimeSlot daytime = {movie2, {12,15}};
	TimeSlot evening = {movie2, {12,45}};
	TimeSlot afternoon = {movie2, {19,00}};
	CHECK(timeOverlap(daytime, evening)==true);
	CHECK(timeOverlap(daytime, afternoon)==false);
}
