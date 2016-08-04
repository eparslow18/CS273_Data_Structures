#ifndef DISCHARGEQUEUE_H_
#define DISCHARGEQUEUE_H_
#include "WaitingRoomQueue.h"
//#include "TreatmentQueue.h"
#include <queue>
#include "Patient.h"
//#include "EmergencyRoom.h"

class DischargeQueue {
private:
	int dischargeTime;
	int visitTime;
	int patientsTreated;
	std::queue<Patient *> doctorQueue;
	std::queue<Patient *> nurseQueue;


public:

	//contructor
	DischargeQueue() {
		visitTime = 0;
		patientsTreated = 0;}

	//getters
	int getVisitTime() {
		return visitTime;}
	int getPatientsTreated() {
		return patientsTreated;}

	//setters
	void setVisitTime(Patient *patient) {
		visitTime = +patient->dischargeTime - patient->arrivalTime;}
	void setPatientsTreated() {
		patientsTreated++;}


	//update queue
	void update(int clock) {

		//for doctor queue
		if (!doctorQueue.empty()) {
			Patient *patient = doctorQueue.front();
			patient->dischargeTime = clock;
			doctorQueue.pop();
			setVisitTime(patient);
			setPatientsTreated();
		}
		//for nurse queue
		if (!nurseQueue.empty()) {
			Patient *patient = nurseQueue.front();
			patient->dischargeTime = clock;
			nurseQueue.pop();
			setVisitTime(patient);
			setPatientsTreated();
		}
	}






	friend class TreatmentQueue;
};

#endif
