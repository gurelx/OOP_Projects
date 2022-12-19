/************************************************************
Final Project Milestone 4
Module: Motorcycle
Filename: Motorcycle.cpp
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
#include "Motorcycle.h"

using namespace std;

namespace sdds
{
	// Constructors
	Motorcycle::Motorcycle()
	{
		this->m_sidecar = false;
		this->setEmpty();
	}

	Motorcycle::Motorcycle(const char* plate, const char* model) : Vehicle(plate,model)
	{
		this->m_sidecar = false;
	}

	// Copy constructor
	Motorcycle::Motorcycle(const Motorcycle& src)
	{
		*this = src;
	}

	// Assignment operator
	void Motorcycle::operator = (const Motorcycle& src)
	{
		if (this != &src)
		{
			Vehicle::operator=(src); // Assign the attributes of the base class
			this->m_sidecar = src.m_sidecar;
		}
	}

	// Write the type of the class
	ostream& Motorcycle::writeType(ostream& os) const
	{
		if (this->isCsv()) os << "M,"; // Comma seperated mode
		else os << "Vehicle type: Motorcycle" << endl;

		return os;
	}

	// Read
	istream& Motorcycle::read(istream& in)
	{
		char prompt = 'c';
		string garbage;

		if (this->isCsv()) 
		{
			Vehicle::read(in); // call the base method
			in >> this->m_sidecar;
			in.ignore(1000, '\n');
		}
		else
		{
			cout << "\nMotorcycle information entry" << endl;
			Vehicle::read(in); // call the base method

			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

			do // Get the prompt for sidecar and validate 
			{
				in.get(prompt);
				getline(in, garbage); // Collect extra chars if user decides to use full words like "yes"

				if (!(prompt == 'Y' || prompt == 'y' || prompt == 'N' || prompt == 'n') || !garbage.empty())
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
			} while (!(prompt == 'Y' || prompt == 'y' || prompt == 'N' || prompt == 'n') || !garbage.empty());

			// Set the attribute
			if ((prompt == 'Y' || prompt == 'y')) this->m_sidecar = true;
			if ((prompt == 'N' || prompt == 'n')) this->m_sidecar = false;

		}
		return in;

	}
	
	// Write
	ostream& Motorcycle::write(ostream& os) const
	{
		// Check the validity of the car
		if (this->isEmpty())
		{
			cout << "Invalid Motorcycle Object" << endl;
		}
		else
		{
			Vehicle::write(os); // Write the base class
			// Comma seperated mode
			if (this->isCsv()) cout << this->m_sidecar << endl;
			// Not comma seperated mode
			else
			{
				if (this->m_sidecar) cout << "With Sidecar" << endl;
			}
		}
		return os;
	}


}