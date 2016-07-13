#include <iostream>
#include <string>
// TODO: Include Vector.h
#include "Vector.h"
using namespace std;

/**
* Template function for displaying the contents of a vector.
* Type is the template parameter, and can represent a vector of any type
*
* @param header	A string to display before printing the content of the vector
* @param array	The vector to display
*/
template <typename Type>
void display(string header, Type array) {
	cout << header << endl;
	for (int i = 0; i < array.size(); ++i) {
		cout << "Name : " << array[i] << endl;
	}
}

int main()
{
	// TODO: Define a CS273::vector of string types called names
	CS273::vector<string> names;

	names.push_back("Joshua");
	names.push_back("Vanessa");
	names.push_back("Andrew");
	names.push_back("Vicky");

	names.insert(2, "Nathan");

	names.push_back("Forrest");
	names.push_back("Katie");

	names.insert(1, "Mark");

	display("Part 1: ", names);

	names.erase(1);
	names.erase(2);

	names[0] = "Wes";
	names[3] = "John";

	display("Part 2: ", names);
}