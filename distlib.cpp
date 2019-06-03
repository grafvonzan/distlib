#include "distlib.h"

//computes the average of a dataset
double calc_average(const std::vector<double> &dataSet) {
	//set the sum to start with the first element, then add subsequent elements.
	double sum = 0;
	double result = 0;
	
	//make sure we dont have problems if someone uses an empty vector
	if(dataSet.size() > 0) {
		for(int i = 0; i < dataSet.size(); i++) {
			sum = sum + dataSet[i];
		}
		result = sum / dataSet.size();
	}
	
	return result;
}

//computes the median of a dataset
double calc_median(const std::vector<double> &dataSet) {
	double result;
	std::vector<double> dataClone = dataSet;
	
	//handle empty input vector
	if(dataClone.size() > 0) {
		//sort input vector
		std::sort(dataClone.begin(), dataClone.end());
		
		//find the middle
		double end = dataClone.size() - 1;
		double mid = end / 2;
		
		//check if whole number using a hacky floor function
		if(mid == double((int)mid)) {
			result = (dataClone[(int)mid]);
		}
		else {
			result = (dataClone[(int)mid] + dataClone[((int)mid) + 1]) / 2;
		}
		
	}
	else {
		result = 0;
	}
	
	return result;
}

//computes the mode of a dataset;
//defines mode as the set of numbers that are most common in the dataset
//if several numbers appear the same number of times, they will all be identified as the mode.
std::vector<double> calc_mode(const std::vector<double> &dataSet) {
	std::vector<double> result;
	int max = 0;
	
	if(dataSet.size() > 0) {
		std::map<double, double> numRec;
		
		for(int i = 0; i < dataSet.size(); i++) {
			if(numRec.find(dataSet[i]) == numRec.end()) {
				numRec[dataSet[i]] = 0;
			}
			else {
				numRec[dataSet[i]] = numRec[dataSet[i]] + 1;
			}
			
			if(numRec[dataSet[i]] > max) {
				max = numRec[dataSet[i]];
				result.clear();
				result.push_back(dataSet[i]);
			}
			else if(numRec[dataSet[i]] == max) {
				result.push_back(dataSet[i]);
			}
		}
		
		//sort result for consistent output
		std::sort(result.begin(), result.end());
	}
	
	//if dataset is empty or there is no mode, an empty vector will be returned
	return result;
}



//computes the variance of a dataset
//true == population, false == sample
double calc_variance(const std::vector<double> &dataSet, bool type) {
	double result = 0;
	if(dataSet.size() > 0) {
		double avg = calc_average(dataSet);
		double sum = 0;
		
		
		for(int i = 0; i < dataSet.size(); i++) {
			sum += pow(dataSet[i] - avg, 2);
		}
		
		if(type == true) {
			result = sum / dataSet.size();
		}
		else {
			result = sum / (dataSet.size() - 1);
		}
	}
	
	return result;
}

double calc_std_deviation(const std::vector<double> &dataSet, bool type) {
	double result = 0;
	if(dataSet.size() > 0) {
		double variance = calc_variance(dataSet, type);
		result = std::sqrt(variance);
	}
	
	return result;
}

//rejection algorithm
std::vector<double> gen_arbitrary_r(const std::vector<double> &probSet, double std_deviation, int seed, int range, int popSize) {
	
	srand(seed);
	
	//this is used to determine which probability block to use for a given generated number.
	double keyMult = range / probSet.size();
	
}

//This is easier to do, but isn't as statistically rigorus as far as I can tell.
std::vector<double> gen_arbitrary_f(const std::vector<double> &probSet, double std_deviation, int seed, int range, int popSize) {
	
	srand(seed);
	
	std::vector<double> result;
	
	//this is used to pick the bounds on the uniform generator used in each block
	double keyMult = range / probSet.size();
	
	//pick a block using a random generated number and then sample uniformly within that block.
	for(int i = 0; i < popSize; i++) {
		
		//should generate values between 100 and 1
		int interRand = rand() % 100 + 1;
		
		//should generate values between 0 and 1 with
		double randNum = 1/double(interRand);
		
		double probAdd = 0;
		
		std::cout << randNum << "\n";
		
		for(int j = 0; j < probSet.size(); j++) {
			//found the right column
			if(randNum <= probAdd) {
				//should generate values between 100 and 1
				int interRand = rand() % 100 + 1;
		
				//should generate values between 0 and 1 with 6 significant figures
				double randNum = 1/double(interRand);
				
				//generate a number in the block uniformly as an estimation
				//this should uniformly generate a number between keyMult*j and keyMult*j + keyMult, which is then scaled by the standard deviation;
				result.push_back(std_deviation * ((keyMult*j) + (keyMult * (1/interRand))));
				break;
			}
			//go to the next column if not the right column.
			probAdd += probSet[j];
		}
	}
	
	for(int i = 0; i < result.size(); i++) {
		int coin = rand() % 100 + 1;
		if(coin < 50) {
			result[i] = 0 - result[i];
		}
	}
	
	return result;
	
}