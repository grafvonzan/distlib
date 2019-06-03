This library includes an array of useful statistical functions, including functions for generating various numerical distributions.

Todo List:
Specific cases that need to be handled:
	Gaussian
	Perlin
	Bimodal
	Benfords law
	Bernoulli distribution

Arbitrary Probability Distribution Generator
	"Filter" Method: Estimation of a given probability distribution
		This is what I am currently working on to get a rough solution done for many circumstances at once. 
	Rejection Method: Ziggurat Algorithm adapted for arbitrary distributions



Build Instructions:


cd /../YOUR_BUILD_DIRECTORY
cmake /../YOUR_SOURCE_DIRECTORY
make
./unittests

Use Instructions:
For now, just copy distlib.cpp and distlib.h to your project folder and include it, i.e:
#include "distlib.h"

For now, the functions included only work with vectors consisting of doubles, ie:
#include <vector>
...
std::vector<double> MYVAR;

Pass vectors of doubles into the functions, and you should get either a double or vector out depending on the function in question.


