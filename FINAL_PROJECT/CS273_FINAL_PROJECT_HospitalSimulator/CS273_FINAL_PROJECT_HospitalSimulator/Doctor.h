#ifndef DOCTOR_H_
#define DOCTOR_H_
#include "Caregiver.h"

class Doctor: public Caregiver {
private:
	int numberOfCaregivers;
	int treatmentTime;
public:
	//no arg constructor
	Doctor() : Caregiver() {}

	//getters
	int getNumberOfCaregivers() {
		return numberOfCaregivers;}
	int getTreatmentTime() {
		return treatmentTime;}

	//setters
	void setNumberOfCaregivers(int numberOfCargeivers) {
		this->numberOfCaregivers = numberOfCaregivers;}
	int setTreatmentTime() {
		return rand() % 20 + 1;} //doctors will take between 1 amd 20 minutes

};

#endif