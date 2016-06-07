#include <iostream>
#include <stdexcept>
#include "readint.h"
using namespace std;

int main()
{
	int low, high;
	cout << "Enter the range of values to read.\n";
	cout << "high: ";
	cin >> high;
	cout << "low: ";
	cin >> low;

	

	try	{
		cin.exceptions(ios::failbit | ios::badbit);//for cin catch below 
		if (low >= high)//checking for empty range 
		{
			throw out_of_range("This is an empty range because the low is greater than the high integer. ");
		}

		int number = read_int("Please enter a number within the range: ", low, high); //goes into function in readint.cpp
		cout << "You entered " << number << endl; 
	}


	catch (invalid_argument &e) {
		cerr << "Exception: You supplied an invalid argument for read_int!\n";
	}
	

	catch (out_of_range &oor) { //runs when the string is thrown in readint.cpp 
		cout << oor.what() << endl;
	}

	catch (ios_base::failure &ex) {//exception if the user enters a non interger value
		cout << "You entered a charcter or a symbol for a range number. " << endl;
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
	}

	
}