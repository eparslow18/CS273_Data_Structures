#ifndef WAITINGROOMQUEUE_H_
#define WAITINGROOMQUEUE_H_
#include <queue>
#include "RandomsGenerator.h"
#include "EmergencyRoom.h"
#include "Patient.h"
#include "AllPatients.h"
//#include "DischargeQueue.h"
#include "PatientRecords.h"

class WaitingRoomQueue : public PatientRecords {
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
	//DischargeQueue *dischargeQueue;
	std::vector<std::string> firstNamesVector;
	std::vector<std::string> sirNamesVector;

public:

//no arg constructor 
	WaitingRoomQueue() {
		visitTime = 0;
		patientsTreated = 0;
	}



//set the patients per hour to be used in the queue
	void setNumPatientsPerHour(double patientsPerHour) {
		this->patientsPerHour = patientsPerHour;}
	double getP() {
		return patientsPerHour;}
	//void setDischargeQueue(DischargeQueue *dischargeQueue) {
	//	this->dischargeQueue = dischargeQueue;}



//getters to get random names 
	std::string getFirstName(int num) {
		return firstNamesVector[num];}
	std::string getSirName(int num) {
		return sirNamesVector[num];}



//getters
	int getNumberOfDoctors(int numberOfDoctors) {
		return numberOfDoctors;}
	int gertNumberOfNurses(int numberOfNurses) {
		return numberOfNurses;	}




//passing in the vectors of first names
	void setFNVector(std::vector<std::string> firstNamesVector) {
		this->firstNamesVector = firstNamesVector;}
	void setSNVector(std::vector<std::string> sirNamesVector) {
		this->sirNamesVector = sirNamesVector;}


//update queue 
	void addToQueue(int clock) {
		double patientsPerMinute = patientsPerHour / 60.0;
		if (randomNum.nextDouble() < patientsPerMinute) {

			int num = randomNum.nextInt(2000);//to get a random person with same first and last name 
			int illnessLevel = p.setIllnessLevel(); //total treatment time
			int totalDoctorTreatment = doctor.setTreatmentTime(); //set treatment time for doc
			int totalNurseTreatment = nurse.setTreatmentTime();//for nurse

			if (numberOfDoctors > 0 || numberOfNurses > 0) {
				if (illnessLevel > 10 && numberOfDoctors > 0) {
					doctorQueue.push(new Patient(clock, getFirstName(num), getSirName(num), totalDoctorTreatment));

					addRecords(new Patient(clock, getFirstName(num), getSirName(num), totalDoctorTreatment ), illnessLevel);
				}
			}

				else if (illnessLevel < 11 ){
					nurseQueue.push(new Patient(clock, getFirstName(num), getSirName(num), totalNurseTreatment));

					addRecords(new Patient(clock, getFirstName(num), getSirName(num), totalNurseTreatment), illnessLevel);
				}
			}

		}
	

	friend class TreatmentQueue;
};
#endif
