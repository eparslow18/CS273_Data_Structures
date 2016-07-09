#ifndef SERVICE_Q_H_
#define SERVICE_Q_H_

#include <queue>
#include "Plane.h"
#include "LandingQueue.h"
#include "DepartureQueue.h"
#include "Random.h"

extern Random my_random; // Enables us to access the global variable declared in Simulator.h

						 /** The service queue takes a plane from the landing queue and adds it to its queue.
						 When a plane in service queue has finished being serviced, it will be placed in the departure queue.
						 */
class ServiceQueue
{
private:
	int min_service_time, max_service_time;  // range of service times
	LandingQueue *landing_queue;             // pointer to the landing queue
	DepartureQueue *departure_queue;         // pointer to the departure queue
	std::queue<Plane *> the_queue;           // queue of planes (just ONE) in the service queue
public:
	ServiceQueue() {}

	void set_service_times(int min_service_time, int max_service_time) {
		this->min_service_time = min_service_time;
		this->max_service_time = max_service_time;
	}

	void set_landing_queue(LandingQueue *landing_queue) {
		this->landing_queue = landing_queue;
	}

	void set_departure_queue(DepartureQueue *departure_queue) {
		this->departure_queue = departure_queue;
	}

	void update(int clock)
	{
		// there is a plane at the gate
		if (!the_queue.empty()) {//if there is pointers in the queue then...

			Plane *plane = the_queue.front(); //create an object that points to the front of the queue

			// check if a plane is ready to move from the service queue to the departure queue
			if ((clock - plane->start_service_time) > plane->service_time) { //if the clock time minus the plane service time is greater than the plane service time
																//there is extra time in the queue so remove and send out that plane and go to the next plane in the queue for service 
				//// FIXME: remove plane from the service queue
				the_queue.pop();

				//// FIXME: update the enter_departure_time attribute for the plane
				plane->enter_departure_time = (clock - plane->start_service_time); //however much time is left after servicing the plane on the clock is how long the before the departure is

				departure_queue->the_queue.push(plane);//moves the plane to the departure queue because it is no longer needing services in services queue
			}
		}

		// the gate is empty - ready to serve!
		if (the_queue.empty()) { //if the service queue is empty (because we are inside the service class) then... 

			// move a plane from the landing queue to the service queue
			if (!landing_queue->the_queue.empty()) { //only move a plane if the landing queue is not empty 

				Plane *plane = landing_queue->the_queue.front();
				landing_queue->the_queue.pop();

				//// FIXME: calculate the wait time of the plane in the landing queue
				int waitTime = 0; //created variable
				waitTime = clock - plane->arrival_time;

				//// FIXME: update total_wait and num_served for the landing queue
				landing_queue->num_served++; //adds a plane to the number of planes served 
				landing_queue->total_wait += waitTime; //for entire queue of planes. calculates the total waiting time 

				//// FIXME: update the start_service_time attribute for the plane
				plane->start_service_time = clock; //later used to subtract from clock to get serive_time

				/*/// FIXME: compute a random service time for the plane between min_service_time and max_service_time
				HINT: You can use my_random.next_int(n) to get a random value between 0 and n.  This will help
				you determine a random number within the range of service times.
				*/
				double randNum=0;
				do {
					randNum = (my_random.next_int(max_service_time)); //generate a random number using the max inputed 
				}
				
				while (randNum < min_service_time); //while the random number is greater than the min service time 
				
				plane->service_time = randNum; //the amount of time the plane will take to be serviced 
				the_queue.push(plane);
			}
				 

				// FIXME: add the plane to the service queue
			
			 
			}
		}
	

};

#endif