/************************************************************
Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.cpp
Version 1.0
Author	Gurel Sezgin
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/18  Preliminary release
2020/11/22  Added set m_flag part to = operator overload
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
************************************************************/

#include <iostream>
#include <string>
#include "Vehicle.h"

using namespace std;

namespace sdds
{
	// Constructors
	Vehicle::Vehicle()
	{
		// Invalid empty state
		this->setEmpty();
	}

	Vehicle::Vehicle(const char* plate, const char* model)
	{
		// Assign the parameters if they are valid
		if (plate != nullptr && plate[0] != '\0') this->m_plate = plate;
		if (model != nullptr && model[0] != '\0') this->m_model = model;
		this->m_parking = 0;
	}

	// Copy constructor & assignment
	Vehicle::Vehicle(const Vehicle& vehicle)
	{
		*this = vehicle;
	}

	void Vehicle::operator=(const Vehicle& vehicle)
	{
		// If vehicle is not self and is valid, copy
		if (this != &vehicle && !vehicle.isEmpty())
		{
			this->setCsv(vehicle.isCsv()); // set the m_flag first
			this->m_plate = vehicle.m_plate;
			this->m_model = vehicle.m_model;
			this->m_parking = vehicle.m_parking;
		}
		// Else set object empty
		else this->setEmpty();
	}

	// Empty methods
	void Vehicle::setEmpty()
	{
		// Invalid empty state
		this->m_plate.clear();
		this->m_model.clear();
		this->m_parking = 0;
	}

	bool Vehicle::isEmpty() const
	{
		return this->m_plate.empty() // If plate is empty
			|| this->m_plate.length() > 8 // If plate is longer than 8 chars
			|| this->m_model.empty() // If model is empty
			|| this->m_model.length() < 2; // If model is shorter than 2 chars
	}

	// Get members
	string Vehicle::getLicensePlate() const
	{
		return this->m_plate;
	}

	string Vehicle::getMakeModel() const
	{
		return this->m_model;
	}

	int Vehicle::getParkingSpot() const
	{
		return this->m_parking;
	}

	// Set members
	void Vehicle::setMakeModel(string model)
	{
		// If the model is not empty set it to member
		if (!model.empty()) this->m_model = model;
		// Else set object empty
		else this->setEmpty();
	}

	void Vehicle::setParkingSpot(int parking)
	{
		// If the parking is valid set it to member
		if (parking >= 0) this->m_parking = parking;
		// Else set object empty
		else this->setEmpty();
	}

	// == overloads
	bool Vehicle::operator ==(const string plate) const
	{
		// Create temp strings 
		string objTemp = this->m_plate;
		string temp = plate;

		// Turn both of the temp strings into upper case
		for (size_t i = 0; i < objTemp.length(); i++)
		{
			objTemp[i] = toupper(objTemp[i]);
		}
		for (size_t i = 0; i < temp.length(); i++)
		{
			temp[i] = toupper(temp[i]);
		}

		// Compare them
		return objTemp == temp;
	}

	bool Vehicle::operator ==(const Vehicle& vehicle) const
	{
		// Create temp strings 
		string obj1Temp = this->m_plate;
		string obj2Temp = vehicle.m_plate;

		// Turn both of the temp strings into upper case
		for (size_t i = 0; i < obj1Temp.length(); i++)
		{
			obj1Temp[i] = toupper(obj1Temp[i]);
		}
		for (size_t i = 0; i < obj2Temp.length(); i++)
		{
			obj2Temp[i] = toupper(obj2Temp[i]);
		}

		// Compare them
		return obj1Temp == obj2Temp;
	}

	// Read & Write methods
	istream& Vehicle::read(istream& in)
	{
		// If vehicle is set to comma seperated
		if (this->isCsv())
		{
			// Read parking
			in >> this->m_parking;
			in.ignore(1, ',');

			// Read plate
			getline(in, this->m_plate, ',');

			// Read make and model
			getline(in, this->m_model, ',');
		}
		else
		{
			// Get input for plate and validate it
			cout << "Enter License Plate Number: ";
			do
			{
				getline(in, this->m_plate);
				if (this->m_plate.length() > 8)
				{
					cout << "Invalid License Plate, try again: ";
				}
			} while (this->m_plate.length() > 8);

			// Get input for make and model and validate it
			cout << "Enter Make and Model: ";
			do
			{
				getline(in, this->m_model);
				if (this->m_model.length() < 2 || this->m_model.length() > 60)
				{
					cout << "Invalid Make and model, try again: ";
				}
			} while (this->m_model.length() < 2 || this->m_model.length() > 60);
		}

		// Turn plate to upper case
		for (size_t i = 0; i < this->m_plate.length(); i++)
		{
			this->m_plate[i] = toupper(this->m_plate[i]);
		}

		// if istr fails set this to empty
		if (in.fail())
		{
			this->setEmpty();
		}

		return in;
	}

	ostream& Vehicle::write(ostream& os) const
	{
		if (this->isEmpty()) os << "Invalid Vehicle Object" << endl; // Invalid message
		else
		{
			this->writeType(os);

			// If comma seperated mode on
			if (this->isCsv())
			{
				os << this->m_parking << ',' << this->m_plate << ',' << this->m_model << ',';
			}
			else
			{
				os << "Parking Spot Number: ";

				if (this->m_parking == 0) os << "N/A" << endl;
				else os << this->m_parking << endl;

				os << "License Plate: " << this->m_plate << endl;

				os << "Make and Model: " << this->m_model << endl;
			}
		}
		return os;
	}
}

