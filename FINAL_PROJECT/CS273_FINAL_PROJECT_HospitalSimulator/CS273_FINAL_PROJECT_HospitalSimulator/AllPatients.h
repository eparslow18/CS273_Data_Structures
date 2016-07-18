#ifndef ALLPATIENTS_H_
#define ALLPATIENTS_H_
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


class AllPatients {
private:
	std::vector<std::string> allPatientsFirstNames;
	std::vector<std::string> allPatientsSirNames;


public:
	void addPeopleToVector() {
		//open text files
		std::fstream firstNames("residents_of_273ville.txt", ios::in | ios::out);
		std::fstream sirNames("surnames_of_273ville.txt", ios::in | ios::out);

		//if files wont open throw message 
		if (firstNames.fail()) {
			cout << "can't open file" << endl;
			return 0;
		}
		if (sirNames.fail()) {
			cout << "can't open file" << endl;
			return 0;
		}


		//pushing text files into the vector
		for (i = 0; i < 2000; i++) {
			allPatientsFirstNames.push_back(getline(firstName(i)));
			allPatientsSirNames.push_back(getline(sirName(i)));
		}
	}


};

#endif 