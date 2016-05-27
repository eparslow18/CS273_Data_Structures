#pragma once
#ifndef Circle_H_
#define Circle_H_

#include <iostream>
using namespace std;

class Circle{
private:
	double radius;
public:
	Circle(){
		radius = 0;
	}

	Circle(int radius){
		this->radius = radius;
	}

	int getArea(){
		return (3*radius*radius);
	}

	int getRadius(){
		return radius;
	}

	void setRadius(int radius){
		this->radius = radius;
	}

	/*void newCircle(Circle c, Circle d)
	{

	}*/
};



#endif 