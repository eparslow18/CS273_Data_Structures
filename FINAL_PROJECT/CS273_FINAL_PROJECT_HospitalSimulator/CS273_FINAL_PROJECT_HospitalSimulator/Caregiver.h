#ifndef CAREGIVER_H_
#define CAREGIVER_H_
#include "EmergencyRoom.h"

class Caregiver{
private: 
	int numberOfCaregivers;
	int treatmentTime;

public: 
	//no arg constructor
	Caregiver() {}

	//polymorphism
	virtual int getNumberOfCaregivers() = 0;
	virtual int getTreatmentTime() = 0;
	virtual int setTreatmentTime() = 0;
	virtual void setNumberOfCaregivers(int numberOfCaregivers) = 0;

};

#endif
