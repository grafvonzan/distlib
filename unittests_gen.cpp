#include "catch.hpp"
#include "distlib.h"

//tests for basic stats
TEST_CASE("Test arbitrary distribution generator (filter)", "[generation]") {
	
	{//basic test for FAD generation algorithm
		//rough estimation of a normal distribution
		
		std::vector<double> testVec{.1, .15, .25, .25, .15, .1};
		
		std::vector<double> result = gen_arbitrary_f(testVec, 1, 1, 6, 1000);
		std::cout << "\n" << "{ ";
		for(int i = 0; i < result.size(); i++) {
			std::cout << result[i] << ", "; 
		}
		std::cout << "\n" << " }";
		
		REQUIRE(result.size() == 1000);
		REQUIRE(calc_std_deviation(result, true) == Approx(1));
		
		
	}
}
