#ifndef PATIENTRECORDS_H_
#define PATIENTRECORDS_H_
#include "Patient.h"
#include <vector>
#include <map>
#include <iterator>
#include <iostream>

struct PatientRecords {
 
	std::vector<Patient*>records;
	std::vector<int> illnessPerVisit;
	std::map < std::string, std::vector<int >> patientRecordsMap;
	std::string name;
	//no arg constructor 
	PatientRecords() {}

	//contructor
	PatientRecords(std::vector<Patient*>records, std::vector<int> illnessPerVisit)
	{
		this->records = records;
		this->illnessPerVisit = illnessPerVisit;
	}

	//add records 
	void addRecords(Patient* patient, std::string name, int illnessLevel) { //add patients to records in waiting room queue class
		records.push_back(patient);
		this->name = name;
		illnessPerVisit.push_back(illnessLevel);
		patientRecordsMap.insert(std::pair <std::string, std::vector<int>>(name, illnessLevel));
	}

	void listAllPatients() { //called in menu function option 2 
		std::map<std::string, std::vector<int>>::iterator it;
		int count = 0;
		for (it = patientRecordsMap.begin(); it != patientRecordsMap.end(); it++) {
			std::cout << count << " ";
			std::cout << "First Name: " << it->first << " Illness Level: " << it->second << std::endl; //iterate through the contents of the map 
			//first display the name then the illness level 
			count++; //add a count to visualize total patients treated
		}
	}
};

#endif