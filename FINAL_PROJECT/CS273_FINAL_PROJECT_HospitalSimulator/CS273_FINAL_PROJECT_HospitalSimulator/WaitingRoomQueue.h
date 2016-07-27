#ifndef WAITINGROOMQUEUE_H_
#define WAITINGROOMQUEUE_H_
#include <queue>
#include "RandomsGenerator.h"
#include "EmergencyRoom.h"
#include "Patient.h"
#include "AllPatients.h"
#include "DischargeQueue.h"

class WaitingRoomQueue {
private:
	std::priority_queue<Patient *> waitingRoomQueue;
	double patientsPerHour;
	Random randomNum;
	AllPatients aP;
	Patient p;
	DischargeQueue *dischargeQueue;
	std::vector<std::string> firstNamesVector;
	std::vector<std::string> sirNamesVector;

public:
	//no arg constructor 
	WaitingRoomQueue() {}

	//set the patients per hour to be used in the queue
	void setNumPatientsPerHour(double patientsPerHour) {
		this->patientsPerHour = patientsPerHour;
	}
	double getP() {
		return patientsPerHour;
	}
	void setDischargeQueue(DischargeQueue *dischargeQueue) {
		this->dischargeQueue = dischargeQueue;
	}



	//passing in the vectors of first names
	void setFNVector(std::vector<string> firstNamesVector) {
		this->firstNamesVector = firstNamesVector;
	}
	void setSNVector(std::vector<string> sirNamesVector) {
		this->sirNamesVector = sirNamesVector;
	}



	//add a new patient to queue
	void addToQueue(int clock) {
		//_sleep(1000); have a syncornization error 
		//std::cout << "Ndouble: --------" << randomNum.nextDouble() << "\n\nPatients: " << patientsPerHour << std::endl;
		double nextDub = randomNum.nextDouble();
		std::cout << nextDub << std::endl;
		if (nextDub < patientsPerHour) {//randomly adding patients when the clock determines so		
			int num = randomNum.randNumto2000(); //to get a random person with same first and last name 
			//int num = randomNum.nextInt(2000);
			waitingRoomQueue.push(new Patient(clock, getFirstName(num), getSirName(num), p.setIllnessLevel()));
			//creating a patient with a first and sir name at the same place in each vector
			std::cout << getFirstName(num) << " " << clock << " " << getSirName(num) << " " << num << std::endl;
		}
	}

	//getters to get random names 
	std::string getFirstName(int num) {
		return firstNamesVector[num];
	}
	std::string getSirName(int num) {
		return sirNamesVector[num];
	}


	friend class TreatmentQueue;
};
#endif
