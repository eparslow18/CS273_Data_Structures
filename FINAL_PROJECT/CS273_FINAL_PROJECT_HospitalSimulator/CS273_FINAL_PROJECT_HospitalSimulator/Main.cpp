//////////////////////////////////////////
//Elisha Parslow 
//CS 273 Data Structures 
//Final Project
//Greys Anatomy Emergency Room Simulator 

#include "EmergencyRoom.h"
EmergencyRoom seattleGreys;

int main() {
	seattleGreys.enterData();
	seattleGreys.runGreysAnatomySimulation();
	seattleGreys.showStats();
	return 0;
}