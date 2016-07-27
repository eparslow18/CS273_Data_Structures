#ifndef TREATMENTQUEUE_H_
#define TREATMENTQUEUE_H_
#include <queue>
#include "Patient.h"
#include "DischargeQueue.h"
#include "WaitingRoomQueue.h"
#include "Caregiver.h"
#include "RandomsGenerator.h"

class TreatmentQueue {
private:
	std::priority_queue<Patient *> treatmentQueue;
	int startTreatmentTime;
	int totalTreatmentTime;
	WaitingRoomQueue *waitingRoomQueue;
	DischargeQueue *dischargeQueue;
	Caregiver *caregiver;
	std::queue<Patient *> doctorQueue;
	std::queue<Patient *> nurseQueue;

public:
	//no arg constructor
	TreatmentQueue() {}

	//setters
	void setWaitingRoomQueue(WaitingRoomQueue *waitingRoomQueue) {
		this->waitingRoomQueue = waitingRoomQueue;}
	void getDischargeQueue(DischargeQueue *dischargeQueue) {
		this->dischargeQueue = dischargeQueue;}
	void setTotalTreatmentTime(int totalTreatmentTime) {
		this->totalTreatmentTime = totalTreatmentTime;}


	//getters
	int getTotalTreatmentTime() {
		return totalTreatmentTime;}

	//update the clock and call the nurse and doctor functions
	void update(int clock) {
		updateDoctor(clock);
		updateNurse(clock);}

	

	void updateDoctor(int clock) {
		if (!doctorQueue.empty()) { //of there is a doctor in the queue..
			Patient *patient = doctorQueue.front(); //creat an object that points to the front of the patients queue

			if ((clock - patient->getStartTreatmentTime()) > patient->totalTreatmentTime) { //if there is extra time, pop a doctor from the queue
				doctorQueue.pop();
				waitingRoomQueue->numberOfDoctors++; //add a dotor to the num of doctors 
				patient->dischargeTime = clock - patient->startTreatmentTime;
				dischargeQueue->doctorQueue.push(patient);}
		}

		//if the doctor queue is empty of there are doctors in the waiting room, bring them into the treatment queue
		if (doctorQueue.empty() || waitingRoomQueue->numberOfDoctors > 0) {
			while (!waitingRoomQueue->doctorQueue.empty()) {
				Patient *patient = waitingRoomQueue->doctorQueue.front();
				waitingRoomQueue->numberOfDoctors++;
				patient->startTreatmentTime = clock;
				doctorQueue.push(patient);}
		}
	}



	void updateNurse(int clock) {
		if (!nurseQueue.empty()) { //of there is a doctor in the queue..
			Patient *patient = nurseQueue.front(); //creat an object that points to the front of the patients queue

			if ((clock - patient->getStartTreatmentTime()) > patient->totalTreatmentTime) { //if there is extra time, pop a doctor from the queue
				nurseQueue.pop();
				waitingRoomQueue->numberOfNurses++; //add a dotor to the num of doctors 
				patient->dischargeTime = clock - patient->startTreatmentTime;
				dischargeQueue->nurseQueue.push(patient);
			}
		}

		//if the doctor queue is empty of there are doctors in the waiting room, bring them into the treatment queue
		if (nurseQueue.empty() || waitingRoomQueue->numberOfNurses > 0) {
			while (!waitingRoomQueue->nurseQueue.empty()) {
				Patient *patient = waitingRoomQueue->nurseQueue.front();
				waitingRoomQueue->numberOfNurses++;
				patient->startTreatmentTime = clock;
				nurseQueue.push(patient);
			}
		}
	}
};

#endif
