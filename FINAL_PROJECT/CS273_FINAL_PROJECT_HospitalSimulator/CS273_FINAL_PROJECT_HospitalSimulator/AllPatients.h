#ifndef ALLPATIENTS_H_
#define ALLPATIENTS_H_
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


class AllPatients {
private:
	std::vector<std::string> firstNamesVector;
	std::vector<std::string> sirNamesVector;


public:
	AllPatients() {} //no arge constuctor
	

	void addPeopleToVector() {
		//open text files
		std::ifstream firstNames("residents_of_273ville.txt");
		std::ifstream sirNames("surnames_of_273ville.txt");

		//if files wont open throw message 
		if (firstNames.fail()) {
			cout << "can't open file" << endl;
			return;
		}
		if (sirNames.fail()) {
			cout << "can't open file" << endl;
			return;
		}


		//pushing text files into the vector
		std::string line;
		int count = 0;
		int count2 = 0;
		while (std::getline(firstNames, line)) {
			firstNamesVector.push_back(line);
		//	cout << firstNamesVector.at(count);
		//	count++;
		}
		std::string line2;//while getline succceeds 
		while (std::getline(sirNames, line2)) {
			sirNamesVector.push_back(line2);
		//cout<< sirNamesVector.at(count2);
		//count2++;
		}
	}


//getters to get random names 
	std::string getFirstName(int num) {	
		return firstNamesVector[num];
	}
	std::string getSirName(int num) {
		return sirNamesVector[num];
	}

};

#endif 