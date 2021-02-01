#pragma once
#ifndef CAR_H  
#define CAR_H  

#include <iostream>  
#include <string>  

using namespace std;

//Declaration of class car.   
//Instances of class car need to store the license plate  
//and the number of times the car has been moved while it has been parked in the lot.   
class car {

private:
	string license;
	int movedTimes;
public:
	car(string, int);
	string getLicense()const;
	int getMovedTimes()const;
	void move();
	virtual ~car();

};

#endif  
