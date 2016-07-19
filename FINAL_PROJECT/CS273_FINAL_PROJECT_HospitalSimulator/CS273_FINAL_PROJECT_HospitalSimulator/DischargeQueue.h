#ifndef DISCHARGEQUEUE_H_
#define DISCHARGEQUEUE_H_
#include "WaitingRoomQueue.h"
#include "TreatmentQueue.h"
#include <queue>
#include "Patient.h"
#include "EmergencyRoom.h"

class DischargeQueue {
private:
	std::priority_queue<Patient *> dischargeQueue;



public:
	DischargeQueue() {}

	void removeFromQueue(int clock) {

	}

	friend class TreatmentQueue;
};

#endif
