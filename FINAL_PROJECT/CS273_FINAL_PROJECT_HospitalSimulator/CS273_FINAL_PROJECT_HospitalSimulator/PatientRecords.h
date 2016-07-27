#ifndef PATIENTRECORDS_H_
#define PATIENTRECORDS_H_
#include "Patient.h"
#include <vector>

struct PatientRecords {
 
	std::vector<Patient*>records;
	std::vector<int> illnessPerVisit;

	//constructpr 
	PatientRecords() {}

	//contructpr
	PatientRecords(std::vector<Patient*>records, std::vector<int> illnessPerVisit)
	{
		this->records = records;
		this->illnessPerVisit = illnessPerVisit;
	}

	//add records 
	void addRecords(Patient* patient, int illnessLevel) {
		records.push_back(patient);
		illnessPerVisit.push_back(illnessLevel);
	}
};

#endif