/*
	File: 
		unittests_gen.cpp
	Description: 
		Contains the test code for functions with the 'gen' prefix.
		'gen' prefix functions generate data.
	Author: 
		Zander S. Ackerman
	Date:
		June 05 2019
*/

#include "catch.hpp"
#include "distlib.h"
#include <fstream>
#include <iostream>

TEST_CASE("Test arbitrary distribution generator (filter)", "[generation]") {
	
	{//basic test for FAD generation algorithm
		//rough estimation of a normal distribution
		
		std::vector<double> testVec{.1, .15, .25, .25, .15, .1};
		
		std::vector<double> result = gen_arbitrary_f(testVec, 1, 1, 6, 100000);
		
		std::ofstream outputFile;
		outputFile.open("histScriptIn.dat");
		
		for(int i = 0; i < result.size(); i++) {
			outputFile << result[i] << "\n"; 
		}
		
		outputFile.close();
		
		system("./histInter.sh testLowResBell");
		
		REQUIRE(result.size() == 100000);
		//REQUIRE(calc_std_deviation(result, true) == Approx(1));
		
		
	}
	
	//RANGE BUG IS FIXED
	{//test for FAD bug where the range needs to be equal to or larger than the size of the probability vector or bad things happen.
		//rough estimation of a normal distribution
		
		std::vector<double> testVec{.1, .15, .25, .25, .15, .1};
		
		//note that the size of the probability is 6, whereas the range is 4
		std::vector<double> result = gen_arbitrary_f(testVec, 1, 1, 4, 100000);
		
		std::ofstream outputFile;
		outputFile.open("histScriptIn.dat");
		
		for(int i = 0; i < result.size(); i++) {
			outputFile << result[i] << "\n";
		}
		
		outputFile.close();
		
		system("./histInter.sh testRangeBug");
		
		REQUIRE(result.size() == 100000);
		//REQUIRE(calc_std_deviation(result, true) == Approx(1));
		
		
	}
}

TEST_CASE("Test generating probability vector from input dataset", "[generation]") {
	
	{//basic test for probability vector generator
		//rough estimation of a normal distribution
		
		std::vector<double> testVecX{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
		std::vector<double> testVecY{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
		std::vector<double> probVec = gen_prob_vector(testVecX, testVecY);
		
		REQUIRE(probVec.size() == testVecX.size() - 1);
		
		double unity = 0;
		
		for(int i = 0; i < probVec.size(); i++) {
			unity = unity + probVec[i];
		}
		
		std::vector<double> result = gen_arbitrary_f(probVec, 1, 1, 10, 100000);
		
		std::ofstream outputFile;
		outputFile.open("histScriptIn.dat");
		
		for(int i = 0; i < result.size(); i++) {
			outputFile << result[i] << "\n"; 
		}
		
		outputFile.close();
		
		system("./histInter.sh testLinear");
		
		REQUIRE(unity == Approx(1.0));
		
		REQUIRE(result.size() == 100000);
		//REQUIRE(calc_std_deviation(result, true) == Approx(1));
		
		
	}
}
