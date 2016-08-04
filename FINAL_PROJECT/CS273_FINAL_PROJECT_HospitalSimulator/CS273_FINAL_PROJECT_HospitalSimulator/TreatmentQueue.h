#ifndef TREATMENTQUEUE_H_
#define TREATMENTQUEUE_H_
#include <queue>
#include "Patient.h"
#include "DischargeQueue.h"
#include "WaitingRoomQueue.h"
#include "Caregiver.h"
#include "RandomsGenerator.h"
#include <iostream>

class TreatmentQueue {
private:
	int startTreatmentTime;
	int totalTreatmentTime;
	WaitingRoomQueue *waitingRoomQueue;
	DischargeQueue *dischargeQueue;
	TreatmentQueue *treatmentQueue;
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
		if (!doctorQueue.empty()) { //of there is a patietnt in the treatment doctor queue..
			Patient *patient = doctorQueue.front(); //creat an object that points to the front of the patients queue

			if ((clock - patient->getStartTreatmentTime()) > patient->totalTreatmentTime) { //if there is extra time, pop a patients from the queue
				doctorQueue.pop();
				waitingRoomQueue->numberOfDoctors++; //add a dotor to the num of doctors 
				patient->dischargeTime = clock - patient->startTreatmentTime;
				dischargeQueue->doctorQueue.push(patient);}
		}

		//if the doctor queue is empty of there are patients in the waiting room, bring them into the treatment queue
		if (waitingRoomQueue->numberOfDoctors >0) {
			while (!waitingRoomQueue->doctorQueue.empty()) {
				Patient *patient = waitingRoomQueue->doctorQueue.front();
				waitingRoomQueue->doctorQueue.pop();
				waitingRoomQueue->numberOfDoctors--;
				patient->startTreatmentTime = clock;
				doctorQueue.push(patient);}
		}
	}



	void updateNurse(int clock) {
		if (!nurseQueue.empty()) { //of there is a nurse in the queue..
			Patient *patient = nurseQueue.front(); //creat an object that points to the front of the patients queue

			if ((clock - patient->getStartTreatmentTime()) > patient->totalTreatmentTime) { //if there is extra time, pop a patient from the queue
				nurseQueue.pop();
				waitingRoomQueue->numberOfNurses++; //add a nurse to the num of doctors 
				patient->dischargeTime = clock - patient->startTreatmentTime;
				dischargeQueue->nurseQueue.push(patient);
			}
		}

		//if the nurse queue is empty of there are patients in the waiting room, bring them into the treatment queue
		if (waitingRoomQueue->numberOfNurses >0) {
			while (!waitingRoomQueue->nurseQueue.empty()) {
				Patient *patient = waitingRoomQueue->nurseQueue.front();
				waitingRoomQueue->nurseQueue.pop();
				waitingRoomQueue->numberOfNurses--;
				patient->startTreatmentTime = clock;
				nurseQueue.push(patient);
			}
		}
	}
};

#endif
