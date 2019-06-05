This library includes an array of useful statistical functions, including functions for generating various numerical distributions.


***

Todo List:

Specific cases that need to be handled:

	Gaussian
	Perlin
	Bimodal
	Benfords law
	Bernoulli distribution

Arbitrary Probability Distribution Generator

	"Filter" Method: Estimation of a given probability distribution. 
		Filter based Arbitrary Distribustion (FAD) Generator
	Rejection Method: Ziggurat Algorithm adapted for arbitrary distributions
	Normalized Bin Vector Function: Compute probability block vectors for the FAD generator


***


Build Instructions:



	cd /../YOUR_BUILD_DIRECTORY
	cmake /../YOUR_SOURCE_DIRECTORY
	make
	./unittests



***

Use Instructions:

For now, just copy distlib.cpp and distlib.h to your project folder and include it, i.e:

	#include "distlib.h"


For now, the functions included only work with vectors consisting of doubles, ie:

	#include <vector>
	...
	std::vector<double> MYVAR;


Pass vectors of doubles into the functions, and you should get either a double or vector out depending on the function in question.


