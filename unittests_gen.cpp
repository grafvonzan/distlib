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
		
		system("./histInter.sh test1");
		
		REQUIRE(result.size() == 1000);
		REQUIRE(calc_std_deviation(result, true) == Approx(1));
		
		
	}
}
