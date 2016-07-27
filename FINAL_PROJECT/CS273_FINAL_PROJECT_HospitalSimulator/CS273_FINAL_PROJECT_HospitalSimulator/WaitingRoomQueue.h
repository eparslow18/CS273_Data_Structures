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
	std::queue<Patient *> doctorQueue;
	std::queue<Patient *> nurseQueue;
	double patientsPerHour;
	int numberOfDoctors;
	int numberOfNurses;
	int visitTime;
	int patientsTreated; 
	Random randomNum;
	AllPatients aP;
	Doctor doctor;
	Nurse nurse;
	Patient p;
	DischargeQueue *dischargeQueue;
	std::vector<std::string> firstNamesVector;
	std::vector<std::string> sirNamesVector;
	WaitingRoomQueue *waitingRoomQueue;

public:

//no arg constructor 
	WaitingRoomQueue() {
		visitTime = 0;
		patientsTreated = 0;
	}

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

//getters to get random names 
	std::string getFirstName(int num) {
		return firstNamesVector[num];
	}
	std::string getSirName(int num) {
		return sirNamesVector[num];
	}

//getters
	int getNumberOfDoctors(int numberOfDoctors) {
		return numberOfDoctors;}
	int gertNumberOfNurses(int numberOfNurses) {
		return numberOfNurses;	}


//passing in the vectors of first names
	void setFNVector(std::vector<string> firstNamesVector) {
		this->firstNamesVector = firstNamesVector;
	}
	void setSNVector(std::vector<string> sirNamesVector) {
		this->sirNamesVector = sirNamesVector;
	}



//add a new patient to queue
	//void addToQueue(int clock) {
	//	//_sleep(1000); have a syncornization error 
	//	//std::cout << "Ndouble: --------" << randomNum.nextDouble() << "\n\nPatients: " << patientsPerHour << std::endl;
	//	double nextDub = randomNum.nextDouble();
	//	std::cout << nextDub << std::endl;
	//	if (nextDub < patientsPerHour) {//randomly adding patients when the clock determines so		
	//		int num = randomNum.randNumto2000(); 
	//		//int num = randomNum.nextInt(2000);
	//		waitingRoomQueue.push(new Patient(clock, getFirstName(num), getSirName(num), p.setIllnessLevel()));
	//		//creating a patient with a first and sir name at the same place in each vector
	//		std::cout << getFirstName(num) << " " << clock << " " << getSirName(num) << " " << num << std::endl;
	////	}
	//}


	void addToQueue(clock) {
		if (randomNum.nextDouble() < patientsPerHour) {

			int num = randomNum.nextInt(2000);//to get a random person with same first and last name 
			int illnessLevel = p.setIllnessLevel(); //total treatment time
			int totalDoctorTreatment = doctor.setTreatmentTime(); //set treatment time for doc
			int totalNurseTreatment = nurse.setTreatmentTime();//for nurse

			if (numberOfDoctors > 0 || numberOfNurses > 0) {
				if (illnessLevel > 10 && numberOfDoctors > 0) {
					doctorQueue.push(new Patient(clock, getFirstName(num), getSirName(num), totalDoctorTreatment);
					addRecords(new Patient(get FirstName(num), getSirName(num), clock, ))
				}
			}

				else if (illnessLevel < 11 ){
					nurseQueue.push(new Patient(clock, getFirstName(num), getSirName(num), totalNurseTreatment );
					addRecords(new Patient(get FirstName(num), getSirName(num), clock, ))
				}
			}

		}
	

	friend class TreatmentQueue;
};
#endif
