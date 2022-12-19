/************************************************************
Final Project Milestone 5
Module: Car
Filename: Car.cpp
Version 1.0
Author	Gurel Sezgin
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/22  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
************************************************************/

#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

namespace sdds
{
	// Constructors
	Car::Car()
	{
		this->m_isWash = false;
		this->setEmpty();
	}

	Car::Car(const char* plate, const char* model) : Vehicle(plate, model)
	{
		this->m_isWash = false;
	}

	// Copy constructor
	Car::Car(const Car& src)
	{
		*this = src;
	}

	// Assignment operator
	void Car::operator=(const Car& src)
	{
		if (this != &src)
		{
			Vehicle::operator=(src); // Assign the attributes of the base class
			this->m_isWash = src.m_isWash;
		}
	}

	// Write the type of the class
	ostream& Car::writeType(ostream& os) const
	{
		if (this->isCsv()) os << "C,"; // Comma seperated mode
		else os << "Vehicle type: Car" << endl;

		return os;
	}

	// Read
	istream& Car::read(istream& in)
	{
		char prompt = 'c';
		string garbage;

		// If the car is in comma seperated mode
		if (this->isCsv())
		{
			Vehicle::read(in); // call the base method
			in >> this->m_isWash;
			in.ignore(1000, '\n');
		}
		else
		{
			cout << "\nCar information entry" << endl; // Newline character in beginnig not mentioned in document?
			Vehicle::read(in); // call the base method

			cout << "Carwash while parked? (Y)es/(N)o: ";

			do // Get the prompt for car wash and validate 
			{
				in.get(prompt);
				getline(in, garbage); // Collect extra chars if user decides to use full words like "yes"

				if (!(prompt == 'Y' || prompt == 'y' || prompt == 'N' || prompt == 'n') || !garbage.empty())
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
			} while (!(prompt == 'Y' || prompt == 'y' || prompt == 'N' || prompt == 'n') || !garbage.empty());

			// Set the attribute
			if ((prompt == 'Y' || prompt == 'y')) this->m_isWash = true;
			if ((prompt == 'N' || prompt == 'n')) this->m_isWash = false;

		}
		return in;
	}

	// Write 
	ostream& Car::write(ostream& os) const
	{
		// Check the validity of the car
		if (this->isEmpty())
		{
			os << "Invalid Car Object" << endl;
		}
		else
		{
			Vehicle::write(os); // Write the base class
			// Comma seperated mode
			if (this->isCsv()) os << this->m_isWash << endl;
			// Not comma seperated mode
			else
			{
				if (this->m_isWash) os << "With Carwash" << endl;
				else  os << "Without Carwash" << endl;
			}
		}
		return os;
	}
}