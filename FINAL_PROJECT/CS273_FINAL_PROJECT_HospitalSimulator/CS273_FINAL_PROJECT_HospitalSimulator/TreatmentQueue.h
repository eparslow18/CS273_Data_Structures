#ifndef TREATMENTQUEUE_H_
#define TREATMENTQUEUE_H_
#include <queue>
#include "EmergencyRoom.h"
#include "Patient.h"
#include "DischargeQueue.h"
#include "WaitingRoomQueue.h"

class TreatmentQueue {
private:
	std::priority_queue<Patient *> treatmentQueue;


public:
	TreatmentQueue() {

	}
	
};

#endif
