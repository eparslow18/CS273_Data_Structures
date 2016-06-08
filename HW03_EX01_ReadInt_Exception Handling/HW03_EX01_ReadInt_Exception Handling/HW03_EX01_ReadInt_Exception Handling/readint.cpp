#include "readint.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int read_int(const string &prompt, int low, int high)
{
	cin.exceptions(ios::failbit | ios::badbit);//only need this once 
	//check low and high
	if (low >= high) 
	{
		throw (invalid_argument("Low is greater than or equal to high."));
	}

	while (true) {
		try {
			cout << prompt;
			int numInR;
			cin >> numInR;

			if (numInR < low || numInR > high)//check numInR is between low and high
			{
				throw range_error("Num entered is outside of the range:");
			}
			return numInR;//similar to setting while loop to false and exits 
		}
		catch (const range_error& e) {
			cout << "The number entered was out of range. " << endl;

		}

		catch (ios_base::failure &ex) {//exception if the user enters a non interger value
			cout << "You entered an invalid input. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}
	

	//rangeerror from library
	
	
}