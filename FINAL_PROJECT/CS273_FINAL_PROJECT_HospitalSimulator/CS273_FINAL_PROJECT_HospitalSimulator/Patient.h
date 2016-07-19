#ifndef PATIENT_H_
#define PATIENT_H_
#include "Doctor.h"
#include "Nurse.h"
#include <fstream> 
#include "PatientRecords.h"


class Patient {
private:
	std::string firstName;
	std::string sirName;
	
	PatientRecords records; 
	Random randomNum;
protected:
	int illnessLevel;
	int numOfVisitsCounter;
	int clock;

public:
//no arg constructor 
	Patient(){}

//constructor 
	Patient(int clock, std::string firstName, std::string sirName, int illnessLevel) {
		numOfVisitsCounter = 0;
		this->firstName = firstName;
		this->sirName = sirName;
		this->clock = clock;
		this->illnessLevel = illnessLevel;
	}

//getters
	int getIllnessLevel() {
		return illnessLevel;}
	int getNumOfVisits() {
		return numOfVisitsCounter;}



//setters
	int setIllnessLevel() { 
		this->illnessLevel = randomNum.randomIllnessLevel(); //get a random priority number based off of illness level 
		numOfVisitsCounter++; //a patient will never get assigned an illness level without visiting 
		return illnessLevel;
	}


};

#endif 
