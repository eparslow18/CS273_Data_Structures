//Elisha Parslow
//05/26/16
//CS 273 Data Structures
//HW1 #27


#include <iostream>
#include "Cat.h"
using namespace std;

int main() {

	Cat c1("Joise");//these are my cat's names 
	Cat c2("Derby");

	cout << "The older cat's name is " << c1.getName() << endl;//inheritance
	cout << "The younger cat's name is " << c2.getName() << endl;//inheritance 
	cout << c2.getName() << "'s";
	//c2.kittyMouth.open();
	return 0;
}