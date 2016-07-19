//////////////////////////////////////////
//Elisha Parslow 
//CS 273 Data Structures 
//Final Project
//Greys Anatomy Emergency Room Simulator 

#include "EmergencyRoom.h"
#include "AllPatients.h"
EmergencyRoom seattleGreys;
AllPatients allPatients;

int main() {
	allPatients.addPeopleToVector();
	seattleGreys.enterData();
	//seattleGreys.runGreysAnatomySimulation();
	seattleGreys.showStats();
	return 0;
}