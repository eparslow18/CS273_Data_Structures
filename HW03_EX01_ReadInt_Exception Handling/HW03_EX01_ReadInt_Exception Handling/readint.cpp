#include "readint.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int read_int(const string &prompt, int low, int high)
{

	try {
		cin.exceptions(ios::failbit | ios::badbit);

		cout << prompt;
		int numInR;
		cin >> numInR;

		if (numInR < low || numInR > high)
		{
			throw range_error("Num entered is outside of the range:");
		}
	}
	catch (const range_error& e) {
		cout << "The number entered was out of range. " << endl;

	}

	catch (ios_base::failure &ex) {//exception if the user enters a non interger value
		cout << "You entered a charcter or a symbol for a number inside the range. " << endl;
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
	}
	

	//rangeerror from library
	
	
}