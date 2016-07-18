#ifndef PATIENT_H_
#define PATIENT_H_
#include "Doctor.h"
#include "Nurse.h"
#include <fstream> 
#include "PatientRecords.h"
#include "RandomsGenerator.h"
extern Random randomNum;


class Patient {
private:
	std::string firstName;
	std::string sirName;
	
	PatientRecords records; 
	
protected:
	int illnessLevel;
	int numOfVisitsCounter;

public:
//no arg constructor 
	Patient() {
		firstName = "";
		sirName = "";}


//getters
	int getIllnessLevel() {
		return illnessLevel;}
	int getNumOfVisits() {
		return numOfVisitsCounter;}


//setters
	void setIllnessLevel() { 
		this->illnessLevel = randomNum.randomIllnessLevel(); //get a random priority number based off of illness level 
		numOfVisitsCounter++; //a patient will never get assigned an illness level without visiting 
	}


};

#endif 
