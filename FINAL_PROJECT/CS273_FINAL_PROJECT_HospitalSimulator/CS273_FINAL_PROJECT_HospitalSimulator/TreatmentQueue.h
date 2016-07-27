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
	queue<Patient *> doctorQueue;
	queue<Patient *> nurseQueue;

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

	void updaye(int clock) {
		updateDoctor(clock);
		updateNurse(clock);}

	
	void updateDoctor(int clock) {

	}

	void updateNurse(int clock) {

	}
};

#endif
