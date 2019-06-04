#include "catch.hpp"
#include "distlib.h"
#include <fstream>



//tests for basic stats
TEST_CASE("Test arbitrary distribution generator (filter)", "[generation]") {
	
	{//basic test for FAD generation algorithm
		//rough estimation of a normal distribution
		
		std::vector<double> testVec{.1, .15, .25, .25, .15, .1};
		
		std::vector<double> result = gen_arbitrary_f(testVec, 1, 1, 6, 10000);
		
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
