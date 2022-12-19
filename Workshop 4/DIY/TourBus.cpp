/*
*****************************************************************************
						  Workshop - #4 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TourBus.h"

using namespace std;
using namespace sdds;

// Constructor for safe empty state
sdds::TourBus::TourBus()
{
	this->passengers = nullptr;
	this->passengerNum = 0;
}

// If the tour bus is created 4, 16 or 22 allocate dynamic memory for passengers
sdds::TourBus::TourBus(int num)
{
	if (num == 4 || num == 16 || num == 22)
	{
		passengers = new TourTicket[num];
		passengerNum = num;
	}
	else // else nullify the members
	{
		passengers = nullptr;
		passengerNum = 0;
	}
}

// Check the validity of the tour bus based on the value inside passengers
bool sdds::TourBus::validTour() const
{
	return bool(passengers != nullptr);
}

// Deconstructor just to be safe...
sdds::TourBus::~TourBus()
{
	delete[] passengers;
	passengers = nullptr;
}

// Board the passengers by issuing their tickets
TourBus& sdds::TourBus::board() 
{
	char name[100];
	cout << "Boarding " << passengerNum << " Passengers:" << endl;
	for (int i = 0; i < passengerNum; i++)
	{
		cout << i + 1 << "/" << passengerNum << "- Passenger Name: ";
		cin.getline(name, 100);
		passengers[i].issue(name);
	}
	return *this;
}

// If tour is valid, check if the board is full, then display each passenger info 
void sdds::TourBus::startTheTour() const
{
	if (validTour())
	{
		if (passengers[passengerNum-1].valid()) // checking if the board is full by the validity of the last element
		{
			cout << "Starting the tour...." << endl;
			cout << "Passenger List:" << endl;
			cout << "|Row | Passenger Name                           | Num |" << endl;
			cout << "+----+------------------------------------------+-----+" << endl;
			for (int i = 0; i < passengerNum; i++)
			{
				cout << "|  " << i + 1 << " ";
				passengers[i].display() << endl;
			}
			cout << "+----+------------------------------------------+-----+" << endl;
		}
		else
		{
			cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
		}
	}
}