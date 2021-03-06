#ifndef EMERGENCYROOM_H_
#define EMERGENCYROOM_H_
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue> //priority_queue
#include <limits>
#include <stdexcept>
#include "RandomsGenerator.h"
#include "WaitingRoomQueue.h"
#include "DischargeQueue.h"
#include "AllPatients.h"
#include "TreatmentQueue.h"
#include "PatientRecords.h"


class EmergencyRoom {
private:
	int clock;
	int numOfDoctors;
	int numOfNurses;
	double numOfPatientsPerHour;
	int oneWeeksTime;

	WaitingRoomQueue *waitingRoomQueue;
	DischargeQueue *dischargeQueue;
	TreatmentQueue *treatmentQueue;
	Random randomNum;
	AllPatients *allPatients;
	PatientRecords *patientRecords;

protected:

public:
	//no arg constructor
	EmergencyRoom() {
		waitingRoomQueue = new WaitingRoomQueue();
		dischargeQueue = new DischargeQueue();
		allPatients = new AllPatients();
		treatmentQueue = new TreatmentQueue();
		clock = 0;
		numOfDoctors = -1;
		numOfNurses = -1;
		numOfPatientsPerHour = -1;
		oneWeeksTime = 10080; //a weeks time in minutes
	}


	//getters
	int getNumOfDoctors() {
		return numOfDoctors;
	}
	int getNumOfNurses() {
		return numOfNurses;
	}
	int getNumOfPatientsPerHour() {
		return numOfPatientsPerHour;
	}


	//setters
	void setNumOfDoctors(int numOfDoctors) {
		this->numOfDoctors = numOfDoctors;
	}
	void setNumOfNurses(int numOfNurses) {
		this->numOfNurses = numOfNurses;
	}
	void setNumOfPatientsPerHour(double numOfPatientsPerHour) {
		this->numOfPatientsPerHour = numOfPatientsPerHour;
	}


	//exception handling
	int readInt(const std::string &prompt, int low, int high)
	{
		if (low >= high) // check for invalid range
			throw std::invalid_argument("Whoops! That was an invalid range. We can help a max of 60 people and a min of 1 and have 100 doctors and 100 nurses on staff. ");

		std::cin.exceptions(std::ios_base::failbit);
		int num = 0;
		while (true) {
			try {
				while (true) {
					std::cout << prompt;
					std::cin >> num;
					if (num >= low && num <= high) { // within the specified range
						std::cout << std::endl;
						return num;
					}
				}
			}
			catch (std::ios_base::failure) {
				std::cout << "Bad numeric string -- try again\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}
	}


	//asking the user to input their desired hospital simulation numbers
	void enterData() {
		this->allPatients->addPeopleToVector();
		std::cout << "Welcome to Seattle Greys Emergency Room located in CS273ville. We are a small hosital with a big heart <3.\n" << std::endl;
		numOfPatientsPerHour = readInt("How many patients are arriving at Seattle Greys per hour?: ", 1, 60); //max of 60 patients per hour FIX THE 60!!! if error
		numOfDoctors = readInt("How many McDreamys and McSteamys will be on staff?: ", 1, 100); //max of 100 doctors in a week
		numOfNurses = readInt("How many nurses will be on staff?: ", 1, 100); //max of 100 nurses in a week


		//set number of patients per hour 
		this->waitingRoomQueue->setNumPatientsPerHour(numOfPatientsPerHour);
		//std::cout <<" ------------------  " << waitingRoomQueue->getP() << std::endl;
		//waitingRoomQueue->setDischargeQueue(dischargeQueue);
		this->waitingRoomQueue->setFNVector(allPatients->getFNVector());
		this->waitingRoomQueue->setSNVector(allPatients->getSNVector());
	}




	//run simulator
	void runGreysAnatomySimulation() {
		while (clock < oneWeeksTime) {//loop a weeks time in seconds 
			waitingRoomQueue->addToQueue(clock);//add new patient to queue if randomly chosen to 
			treatmentQueue->update(clock);
			dischargeQueue->update(clock);
			clock++;
		}
	}





	//show the emergency room stats
	void showStats() {
		std::cout << "\nSeattle Greys treated " << dischargeQueue->getPatientsTreated() << " patients this week.\n";
		std::cout << "\nThe average visit time was: " << dischargeQueue->getVisitTime() << std::endl;
		std::cout << std::endl << "Please select from the menu below to view more stats from your Seattle Greys simulation: \n";
		menu();

	}

	//after simulation, user can access the list of all the patients treated and retrieve record of resident by "name"
	void menu() {
		int option = 0;//user cins an option 
		option = readInt("1. List all the residents treated at Seattle Greys\n2. Retrieve a patient record by name\n3. End simulation. \n ", 1, 3);

		switch (option % 4) {
		case 1:
			// CREAT FUNCTION list treated patients from patient records vector!
			std::cout << "Patients Treated: ";
			patientRecords->listAllPatients(); 
			menu(); //a little bit of recursion ;) 
			break;
		case 2:
			// CREAT FUNCTION retrieve patient record by name using binary search tree?? 
			std::cout << "Please enter the patient's name: ";
			/*std::string name;
			std::cin >> name;*/
			//if (std::find(patientRecords->records.begin(), patientRecords->records.end(), name) != patientRecords->records.end()) {
			//	std::cout << patientRecords->records.at(name) << std::endl; //search through records to see if name of patient was treated 
			//}
			//else
				std::cout << " Patient name could not be found. \n";
			menu();
			break;
		case 3:
			//end program
			std::cout << "End of program." << std::endl;
			exit(0);
			break;
		default: break;
		}
	}


};

#endif