//I affirm that all code given below was written solely by me, Elisha Parslow, and that any help I received adhered to the rules stated for this exam.
//CS 173 Data Structures EXAM 1 


#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

namespace Exam1 // NAMESPACE
{
	// STEP 1: Complete the implementation of the Footwear base class 
	// as described in the UML diagram

	class FootWear
	{
	private:
		int size; 
	protected:
		//Wheel wheel; //access to inheriting classes 

	public:
		FootWear(int size) {
			// Complete the implementation
			this->size = size; 			
		}

		int getSize() { // to access size inside  the inheriting functions 
			return size;
		}

		virtual void Description() = 0;
	};


	////////////////
	class Wheel
	{
	private:
		string color;
	public:
		Wheel() {}
		void set_color(string color) {
			this->color = color;
		}
	};

	// STEP 2:  Define the Sandle and RollerSkate classes as described
	// in the UML diagram.   For this test, you do not need to separate
	// the class implementation into a cpp file.

	//////////////
	class Sandle : public FootWear {//inheriting FootWear functions 

	private:
	public: 
		Sandle(int size) : FootWear(size) {}; //accessing base class function making it specific to inheriting class 
		void Description(){
			cout << "I am a sandle of size " << getSize() << endl; //using getter function from base class 

		}
	};


	///////////////
	class RollerSkate : public FootWear {//inherting Footwear functions 
	private:
	public:
		RollerSkate(int size, string color) : FootWear(size) {}; //accessing base class function making it specific to inheriting class

		void Description() {
			cout << "I am a rollerskate of size " << getSize() << endl; //using getter function from base class 
		}
	};
}


	///////////////
int main()
{
	Exam1::FootWear * ShoeCloset[2];

	// STEP 3: Assign ONE RollerSkate AND ONE Sandle object to each of the two elements 
	// in the ShoeCloset array.  Remember the classes are defined in the namespace Exam1.
	//ShoeCloset[0] = ???
	//ShoeCloset[1] = ???


	Exam1::Sandle s1(10);//creating an object sandle accessed from the namespace function Exam1
	Exam1::RollerSkate r1(8, "green");//creating an object rollerskate accessed from the namespace function Exam1
	
	ShoeCloset[0] = &s1; //assign the defined s1 to the first slot in the array
	ShoeCloset[1] = &r1; //assign the defined r1 to the second slot in the array

	for (int i = 0; i < 2; ++i)
	{
		// The method Description() should display an output like 
		// “I am a sandle (or rollerSkate) and my size is X”,
		// where X is the shoe size of the Sandle or RollerSkate objects you constructed above.
		ShoeCloset[i]->Description();
	}
}
