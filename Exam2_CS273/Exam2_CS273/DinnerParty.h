#ifndef _DINNER_PARTY_H_
#define _DINNER_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "DinnerPartyTicket.h"

/**
* DinnerParty is derived from Party
*/
class DinnerParty : public Party
{
private:
	std::list<std::string> room; // Data structure for containing the party goers in this dinner party

								 /**
								 * Constructor for creating a DinnerParty
								 */
	DinnerParty() {}

	friend class PartyFactory;

public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name) {
		/**
		* FIXME 1a:
		*   Pseudo-code
		*    1. add name to the front of room
		*    2. get iterator to the front of the room (this points to the recently added party goer)
		*    3. create a new dinner party ticket (DinnerPartyTicket) with its constructor
		*            Pass to the constructor "this" party, and the iterator from step 2
		*    4. return this new party ticket
		*/
		room.push_front(name); //adding the name on the ticket to the front of room list 
		std::list<std::string>::iterator front = room.begin(); //at the most recently added party goer
		PartyTicket* dinnerPartyTicket = new DinnerPartyTicket(this, front);//passing this party and the iterator previously created through the new dinnerPartyTicket
		return dinnerPartyTicket; //returning the new dinnerPartyTicket
	}

	/**
	* List all the persons currently in the party
	*/
	void list() {
		// FIXME 1b: iterate through all the persons here.
		std::list<std::string>::iterator it = room.begin();//lists all of the people in the room list from the front of the list 
		while (it != room.end()){
			std::cout << *it << std::endl;
			it++;
		}

	}

	/**
	* Remove the person identified by the iterator from the party
	*/
	void remove(std::list<std::string>::iterator it) {
		//FIXME 1c: someone's getting out of hand. Let's ask them to leave.
		std::list<std::string>::iterator it2 = room.begin();
		for (it2 != room.end();;) {//while not the end of the list
			if (*it2 == *it) {//if they match
				
				room.erase(it2);//erase the party goer at that position
				break; //exit loop once found 
			}
			else
				++it2;//increment the entire list
		}
	}
		
};
#endif
