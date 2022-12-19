/************************************************************
Final Project Milestone 3
Module: Vehicle
Filename: Vehicle.cpp
Version 1.0
Author	Gurel Sezgin
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/18  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
************************************************************/

#include <iostream>
#include <string>
#include "Vehicle.h"

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
	std::string Vehicle::getLicensePlate() const
	{
		return this->m_plate;
	}

	std::string Vehicle::getMakeModel() const
	{
		return this->m_model;
	}

	int Vehicle::getParkingSpot() const
	{
		return this->m_parking;
	}

	// Set members
	void Vehicle::setMakeModel(std::string model)
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
	bool Vehicle::operator ==(const std::string plate) const
	{
		// Create temp strings 
		std::string objTemp = this->m_plate;
		std::string temp = plate;

		// Turn both of the temp strings into upper case
		for (size_t i = 0; i < objTemp.length(); i++) 
		{ 
			objTemp[i] = std::toupper(objTemp[i]);
		}
		for (size_t i = 0; i < temp.length(); i++)
		{
			temp[i] = std::toupper(temp[i]);
		}

		// Compare them
		return objTemp == temp;
	}

	bool Vehicle::operator ==(const Vehicle& vehicle) const
	{
		// Create temp strings 
		std::string obj1Temp = this->m_plate;
		std::string obj2Temp = vehicle.m_plate;

		// Turn both of the temp strings into upper case
		for (size_t i = 0; i < obj1Temp.length(); i++)
		{
			obj1Temp[i] = std::toupper(obj1Temp[i]);
		}
		for (size_t i = 0; i < obj2Temp.length(); i++)
		{
			obj2Temp[i] = std::toupper(obj2Temp[i]);
		}

		// Compare them
		return obj1Temp == obj2Temp;
	}

	// Read & Write methods
	std::istream& Vehicle::read(std::istream& in)
	{
		// If vehicle is set to comma seperated
		if (this->isCsv())
		{  
			// Read parking
			in >> this->m_parking;
			in.ignore(1, ',');

			// Read plate
			std::getline(in, this->m_plate, ',');

			// Read make and model
			std::getline(in, this->m_model, ',');
		}
		else
		{
			// Get input for plate and validate it
			std::cout << "Enter Licence Plate Number: ";
			do
			{
				std::getline(in, this->m_plate);
				if (this->m_plate.length() > 8)
				{
					std::cout << "Invalid Licence Plate, try again: ";
				}
			} while (this->m_plate.length() > 8);

			// Get input for make and model and validate it
			std::cout << "Enter Make and Model: ";
			do
			{
				std::getline(in, this->m_model);
				if (this->m_model.length() < 2 || this->m_model.length() > 60)
				{
					std::cout << "Invalid Make and model, try again: ";
				}
			} while (this->m_model.length() < 2 || this->m_model.length() > 60);
		}

		// Turn plate to upper case
		for (size_t i = 0; i < this->m_plate.length(); i++)
		{
			this->m_plate[i] = std::toupper(this->m_plate[i]);
		}

		// if istr fails set this to empty
		if (in.fail())
		{
			this->setEmpty();
		}

		return in;
	}

	std::ostream& Vehicle::write(std::ostream& os) const
	{
		if (this->isEmpty()) os << "Invalid Vehicle Object" << std::endl; // Invalid message
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

				if (this->m_parking == 0) os << "N/A" << std::endl;
				else os << this->m_parking << std::endl;

				os << "Licence Plate: " << this->m_plate << std::endl;

				os << "Make and Model: " << this->m_model << std::endl;
			}
		}
		return os;
	}
}

