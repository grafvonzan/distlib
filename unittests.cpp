#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "distlib.h"
#include <limits>


//tests for basic stats
TEST_CASE("Test average calculation", "[primitive]") {
	{
		std::vector<double> testVec = {2.5, 3.7, 8.9, 1.3, 0, 7, 4};
		REQUIRE(calc_average(testVec) == Approx(3.914285714285714));
	}
	
	{
		std::vector<double> testVec = {1, 0};	
		REQUIRE(calc_average(testVec) == Approx(0.5));
	}
	
	{
		std::vector<double> testVec = {1, 2, 3};	
		REQUIRE(calc_average(testVec) == Approx(2));
	}
}

TEST_CASE("Test median calculation", "[primitive]") {
	{
		std::vector<double> testVec = {2.5, 3.7, 8.9, 1.3, 0, 7, 4};
		REQUIRE(calc_median(testVec) == Approx(3.7));
	}
	
	{
		std::vector<double> testVec = {1, 0};	
		REQUIRE(calc_median(testVec) == Approx(0.5));
	}
	
	{
		std::vector<double> testVec = {1,2, 3};	
		REQUIRE(calc_median(testVec) == Approx(2));
	}
}

TEST_CASE("Test mode calculation", "[primitive]") {
	{
		std::vector<double> testVec = {1, 2, 3, 4, 5};
		std::vector<double> result = calc_mode(testVec);
		REQUIRE(result.size() == 5);
		REQUIRE(result[0] == Approx(1));
		REQUIRE(result[1] == Approx(2));
		REQUIRE(result[2] == Approx(3));
		REQUIRE(result[3] == Approx(4));
		REQUIRE(result[4] == Approx(5));
	}
	
	{
		std::vector<double> testVec = {1, 1, 2, 2};	
		std::vector<double> result = calc_mode(testVec);
		REQUIRE(result.size() == 2);
		REQUIRE(result[0] == Approx(1));
		REQUIRE(result[1] == Approx(2));
	}
	
	{
		std::vector<double> testVec = {1, 2, 3, 3, 3};	
		std::vector<double> result = calc_mode(testVec);
		REQUIRE(result.size() == 1);
		REQUIRE(result[0] == Approx(3));
	}
}

TEST_CASE("Test variance calculation", "[primitive]") {
	{
		std::vector<double> testVec = {2.5, 3.7, 8.9, 1.3, 0, 7, 4};
		REQUIRE(calc_variance(testVec, true) == Approx(8.36979591));
	}
	
	{
		std::vector<double> testVec = {1, 0};	
		REQUIRE(calc_variance(testVec, true) == Approx(0.25));
	}
	
	{
		std::vector<double> testVec = {1, 2, 3, 4, 5};	
		REQUIRE(calc_variance(testVec, true) == Approx(2));
	}
	
	{
		std::vector<double> testVec = {2.5, 3.7, 8.9, 1.3, 0, 7, 4};
		REQUIRE(calc_variance(testVec, false) == Approx(9.76476));
	}
	
	{
		std::vector<double> testVec = {1, 0};	
		REQUIRE(calc_variance(testVec, false) == Approx(0.5));
	}
	
	{
		std::vector<double> testVec = {1, 2, 3, 4, 5};	
		REQUIRE(calc_variance(testVec, false) == Approx(2.5));
	}
}
TEST_CASE("Test standard deviation calculation", "[primitive]") {
	{
		std::vector<double> testVec = {2.5, 3.7, 8.9, 1.3, 0, 7, 4};
		REQUIRE(calc_std_deviation(testVec, true) == Approx(2.8930599));
	}
	
	{
		std::vector<double> testVec = {1, 0};	
		REQUIRE(calc_std_deviation(testVec, true) == Approx(.5));
	}
	
	{
		std::vector<double> testVec = {1, 2, 3, 4, 5};	
		REQUIRE(calc_std_deviation(testVec, true) == Approx(1.41421356));
	}
	
	{
		std::vector<double> testVec = {2.5, 3.7, 8.9, 1.3, 0, 7, 4};
		REQUIRE(calc_std_deviation(testVec, false) == Approx(3.12486));
	}
	
	{
		std::vector<double> testVec = {1, 0};	
		REQUIRE(calc_std_deviation(testVec, false) == Approx(.707106781186548));
	}
	
	{
		std::vector<double> testVec = {1, 2, 3, 4, 5};	
		REQUIRE(calc_std_deviation(testVec, false) == Approx(1.58113883008419));
	}
}

