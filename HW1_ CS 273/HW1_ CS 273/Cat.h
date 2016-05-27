#pragma once
#ifndef Cat_H_
#define Cat_H_

#include <iostream>
#include <string>
using namespace std;

class Animal {
private: 
	string animalType;
public:
	Animal(string animalType)
	{
		this->animalType = animalType;
	}
	string getName()
	{
		return animalType;
	}
};

class Cat :public Animal { //is a relationship 
private: 

public:
	Cat(string animalType) : Animal(animalType) {}//inhearits Animal(string animalType)
	//Mouth kittyMouth;//has a 
	
	
};

class Mouth { //has a relationship
public:
	void open() 
	{ cout<<"Mouth is open." << endl; }
};

#endif