#ifndef RANDOMGENERATOR_H_
#define RANDOMGENERATOR_H_
#include <ctime>
#include <cstdlib>

struct Random {
	Random() { // no arg constructor 
		srand((unsigned int)std::time(0));
	}

	Random(int seed) {
		srand(seed);
	}

	//returns a random integer used for patient probability of walking in 
	int nextInt(int n) {
		return int(nextDouble() * n);
	}

	//return random double for nextInt to utilize
	double nextDouble() {
		return double(rand()) / RAND_MAX;
	}

	//return random number between 1 and 20 with specific percentages of probability 
	int randomIllnessLevel() {
		int level = rand() % 10 + 1;
		int priority = 0;

		if (level > 9) { //10% chance of illness with priority 16 to 20 
			priority = rand() % 5 + 16; //start at 16 plus number that is randomly generated to get in the range of 16 to 20 
			return priority;	}
	else if (level > 7){ //20% chance of illness with priority 11 to 15 
			priority = rand() % 5 + 11; 
			return priority;}
	else { //70% chance of illness with priority 1 to 10
			priority = rand() % 10 + 1; 
			return priority;}
	}


};

#endif 
