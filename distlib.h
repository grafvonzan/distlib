#include <vector>
/*
	File: 
		distlib.h
	Description: 
		This is the main header file for the distlib library.
	Author: 
		Zander S. Ackerman
	Date:
		June 05 2019
*/

#include <algorithm>
#include <cmath>
#include <map>
#include <iostream>
#include <random>

//computes the average of a dataset
double calc_average(const std::vector<double> &dataSet);

//computes the median of a dataset
double calc_median(const std::vector<double> &dataSet);

//computes the mode of a dataset
std::vector<double> calc_mode(const std::vector<double> &dataSet);

//computes the variance of a dataset
//true == population, false == sample
double calc_variance(const std::vector<double> &dataSet, bool type);

//computes the standard deviation of a dataset
//true == population, false == sample
double calc_std_deviation(const std::vector<double> &dataSet, bool type);

//generates an arbitrary distribution of numbers using a rejection algorithm
std::vector<double> gen_arbitrary_r(const std::vector<double> &probSet, double std_deviation, int seed, double range, int popSize);

//generates an arbitrary distribution of numbers using a filter algorithm
std::vector<double> gen_arbitrary_f(const std::vector<double> &probSet, double std_deviation, int seed, int range, int popSize);

//generates a probability vector for FAD generator
std::vector<double> gen_prob_vector(const std::vector<double> &dataSetX, const std::vector<double> &dataSetY, int numBins);

//compares two pairs of doubles under the assumption they are coordinates.
//returns true if the first pair has a higher x value than the second value
bool comp_coordinate_xdec(std::pair<double, double> a, std::pair<double, double> b);

//compares two pairs of doubles under the assumption they are coordinates.
//returns true if the a has a lower x value than b 
bool comp_coordinate_xasc(std::pair<double, double> a, std::pair<double, double> b);