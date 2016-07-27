#ifndef NURSE_H_
#define NURSE_H_
#include "Caregiver.h"

class Nurse :public Caregiver {
private:
	int numberOfCaregivers;
	int treatmentTime;


public:
	//no arg constructor
	Nurse() : Caregiver() {}

	//getters
	int getNumberOfCaregivers() {
		return numberOfCaregivers;
	}
	int getTreatmentTime() {
		return treatmentTime;
	}

	//setters
	void setNumberOfCaregivers(int numberOfCargeivers) {
		this->numberOfCaregivers = numberOfCaregivers;
	}
	int setTreatmentTime() {
		return rand() % 20 + 1;
	} //nurses will take between 1 amd 10 minutes

};

#endif 