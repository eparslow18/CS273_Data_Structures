//Elisha Parslow
//cs 273 Data Structures
//HW1 Q#28
//The Circle Class

#include "Circle.h"

int main()
{
	Circle c1(15);
	Circle c2(4);

	cout << "The area of circle1 is " << c1.getArea() << " with a radius of " << c1.getRadius() << endl;
	cout << "The area of circle2 is " << c2.getArea() << " with a radius of " << c2.getRadius() << endl;


	return 0;
}