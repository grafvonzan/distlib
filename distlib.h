#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iostream>

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