#ifndef PATIENT_H_
#define PATIENT_H_
#include "Doctor.h"
#include "Nurse.h"
#include <fstream> 
#include <string>


struct Patient {

//variables
	std::string firstName;
	std::string sirName; 
	Random randomNum;
	int illnessLevel;
	int numOfVisitsCounter;
	int arrivalTime;
	int dischargeTime;
	int startTreatmentTime;
	int totalTreatmentTime;

//no arg constructor 
	Patient(){}

//constructor 
	Patient(int clock, std::string firstName, std::string sirName, int totalTreatmentTime) {
		numOfVisitsCounter = 0;
		this->firstName = firstName;
		this->sirName = sirName;
		arrivalTime= clock;
		dischargeTime = -1;
		this->illnessLevel = illnessLevel;
		this->startTreatmentTime = -1;
		this->totalTreatmentTime = totalTreatmentTime;
		
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
	int getStartTreatmentTime() {
		return startTreatmentTime;}
	int getTotalTreatmentTime() {
		return totalTreatmentTime;}
	int getDischargeTime() {
		return dischargeTime;}
	


//setters
	int setIllnessLevel() { 
		this->illnessLevel = randomNum.randomIllnessLevel(); //get a random priority number based off of illness level 
		numOfVisitsCounter++; //a patient will never get assigned an illness level without visiting 
		return illnessLevel;}
	void setStartTreatmentTime(int startTreatmentTime) {
		this->startTreatmentTime = startTreatmentTime;
	}


};

#endif 
