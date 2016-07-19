#ifndef PATIENT_H_
#define PATIENT_H_
#include "Doctor.h"
#include "Nurse.h"
#include <fstream> 
#include <string>


class Patient {
private:
	std::string firstName;
	std::string sirName;
	
	 
	Random randomNum;
protected:
	int illnessLevel;
	int numOfVisitsCounter;
	int arrivalTime;

public:
//no arg constructor 
	Patient(){}

//constructor 
	Patient(int clock, std::string firstName, std::string sirName, int illnessLevel) {
		numOfVisitsCounter = 0;
		this->firstName = firstName;
		this->sirName = sirName;
		arrivalTime= clock;
		this->illnessLevel = illnessLevel;
	}

//getters
	int getIllnessLevel() {
		return illnessLevel;}
	int getNumOfVisits() {
		return numOfVisitsCounter;}
	std::string getFirstName() {
		return firstName;}
	std::string getSirName() {
		return sirName;}

	


//setters
	int setIllnessLevel() { 
		this->illnessLevel = randomNum.randomIllnessLevel(); //get a random priority number based off of illness level 
		numOfVisitsCounter++; //a patient will never get assigned an illness level without visiting 
		return illnessLevel;
	}


};

#endif 
