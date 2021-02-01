// 05_p134.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <string>  
#include <STACK>  
#include <iostream>  
#include <fstream>  
#include "car.h"  

using namespace std;

//#define EXIT_FAILURE 0
//#define EXIT_SUCCESS 1  

int main(int argc, char *argv[])
{
	//The user should specify the data file to use via the command-line.   
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " data-file\n";
		cerr << "You shoud use this program in the cmd line" << endl;
		return EXIT_FAILURE;
	}
	//Judge whether the file exists or not  
	//Then open the file for reading or writing  
	string in_fileName = argv[1];
	string out_fileName = "result.txt";
	ifstream infs(in_fileName.c_str());
	ofstream outfs(out_fileName.c_str());
	if (!infs) {
		cerr << "Can't open the file " << in_fileName << endl;
		return EXIT_FAILURE;
	}
	if (!outfs) {
		cerr << "Can't open the file " << out_fileName << endl;
		return EXIT_FAILURE;
	}

	//Declare a stack object to represent the single-aisle parking lot.   
	//This object must be of type stack<car*>   
	//To preserve the order of the other cars, a temporary stack of type pointer to car should be used.   
	stack<car*> parking_lot, tempStack;
	car *pcar;
	string license_plate, action;

	//Unless the file ends, then read it.  
	while (!infs.eof())
	{
		infs >> license_plate >> action;
		//For each arrival, instantiate an object of type car in the free store  
		if (action == "arrives")
		{
			if (parking_lot.size()<5)
			{
				pcar = new car(license_plate, 0);
				parking_lot.push(pcar);
			}
			//Output a meaningful message if the parking lot is full.   
			//The lot is full when the stack contains five elements.  
			else
				outfs << "Sorry " << license_plate << " , The lot is full ! " << endl;
		}
		//For each departure, remove the corresponding car pointer from the stack  
		else if (action == "departs")
		{
			while (!parking_lot.empty() && parking_lot.top()->getLicense() != license_plate)
			{
				tempStack.push(parking_lot.top());
				parking_lot.top()->move();
				parking_lot.pop();
			}
			//Output the number of times this car was moved while it was parked in the lot  
			if (parking_lot.top()->getLicense() == license_plate)
			{
				outfs << parking_lot.top()->getLicense() << " was moved " << parking_lot.top()->getMovedTimes() << " times while it was here" << endl;
				delete parking_lot.top();
				parking_lot.pop();
			}
			else
				outfs << "Exception!" << endl;
			while (!tempStack.empty())
			{
				parking_lot.push(tempStack.top());
				tempStack.pop();
			}
		}
	}
	//Output the number of times each car that remains in the lot (if there are any) was moved.   
	outfs << "\n\nThese cars are still in the lot \n\n";
	while (!parking_lot.empty())
	{
		outfs << parking_lot.top()->getLicense() << " was moved " << parking_lot.top()->getMovedTimes() << " times while it was here" << endl;
		delete parking_lot.top();
		parking_lot.pop();
	}
	outfs.close();
	infs.close();
	cout << "The result.txt is created, you can check it now!" << endl;

	return EXIT_SUCCESS;
}
