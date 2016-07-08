#ifndef LANDING_Q_H_
#define LANDING_Q_H_

#include <iostream>
#include <string>
#include <queue>
#include "Plane.h"
#include "Random.h"

extern Random my_random;  // Enables us to access the global variable declared in Simulator.h

class LandingQueue
{
private:
	double arrival_rate;            // plane arrival rate per minute
	std::queue<Plane *> the_queue;  // queue of planes in the landing queue
	int total_wait;  // total accumulated wait time in the landing queue
	int num_served;  // number of planes served through the landing queue

public:
	LandingQueue() : total_wait(0), num_served(0) {}

	void set_arrival_rate(double arrival_rate) {
		this->arrival_rate = arrival_rate;
	}

	int get_total_wait() {
		return total_wait;
	}

	int get_num_served() {
		return num_served;
	}

	void update(int clock)
	{
		/* //FIXME:  add a new plane into the landing queue based on the arrival_rate
		HINT: my_random.next_double() returns a random value between 0 and 1.
		Read how the the simulation described in the book does this
		(section 6.5 pages. 392-393).
		Look at the Passenger_Queue::check_new_arrival() method
		*/

		if (my_random.next_double() < arrival_rate) {
			the_queue.push(&Plane(clock)); //adding to a queue of pointers so use &
											//if the random number generated is less than the arrival rate between 0.0 and 1.0 push onto the queue. There is a arrival_rate #
		}									//percent possiblity of the random number being less than the arrival rate. For example; if the arrival rate is .3, the random number 
											// that is generated has a 30% of being lower than the arrival rate
	}	

	friend class ServiceQueue;
};

#endif