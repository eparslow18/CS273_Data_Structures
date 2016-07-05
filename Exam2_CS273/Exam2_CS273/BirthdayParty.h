#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room; // Data structure for containing the party goers in this dinner party
	BirthdayParty() {} //contructor for BirhdayParty

	friend class PartyFactory;

public:

	PartyTicket * add(std::string name) { //adding a person to the birthday party
		room.push_front(name); //adding the name on the ticket to the front of room list 
		std::list<std::string>::iterator front = room.begin(); //at the most recently added party goer
		PartyTicket* birthdayPartyTicket = new BirthdayPartyTicket(this, front);
		return birthdayPartyTicket;
	}


	void list() { //list people at birthdayparty
		std::list<std::string>::iterator it = room.begin();//lists all of the people in the room list from the front of the list 
		while (it != room.end()) {
			std::cout << *it << std::endl;
			it++;
		}

	}

	void remove(std::list<std::string>::iterator it) { //remove a person from the birthday party 
		std::list<std::string>::iterator it2 = room.begin();
		for (it2 != room.end();;) {
			if (*it2 == *it) {

				room.erase(it2);//erase the party goer at that position
				break; //exit loop once found 
			}
			else
				++it2;
		}
	}
	
};

#endif