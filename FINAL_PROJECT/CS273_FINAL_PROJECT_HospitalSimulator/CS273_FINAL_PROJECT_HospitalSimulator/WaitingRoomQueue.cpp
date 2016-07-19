#ifndef WAITINGROOMQUEUE_H_
#define WAITINGROOMQUEUE_H_
#include <queue>
#include "RandomsGenerator.h"
#include "EmergencyRoom.h"
#include "Patient.h"
#include "AllPatients.h"

class WaitingRoomQueue {
private:
	std::priority_queue<Patient *> waitingRoomQueue;
	int patientsPerHour;


public:
//no arg constructor 
	WaitingRoomQueue() {

	}

//set the patients per hour to be used in the queue
	void setNumPatientsPerHour(int patientsPerHour) {
		this->patientsPerHour = patientsPerHour;}



	void addToQueue(int clock) {
		Random randomNum;
		AllPatients aP;
		Patient p;
		if (randomNum.nextDouble() < patientsPerHour) {//randomly adding patients when the clock determines so
			int num = rand() % 2000 + 1; //to get a random person with same first and last name 
			waitingRoomQueue.push(new Patient(clock, aP.getFirstName(num), aP.getSirName(num), p.setIllnessLevel())); 
			//creating a patient with a first and sir name at the same place in each vector
		}
	}

	friend class DischargeQueue;
};
#endif