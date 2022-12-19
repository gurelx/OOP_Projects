/*
Name: Gurel Sezgin
Email: gurel-sezgin@myseneca.ca
Student ID: 174331215
Data: 
Section: 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

namespace sdds
{
	// Constructor
	VehicleBasic::VehicleBasic(const char* plateNo, const int year)
	{
		// Initializing values
		this->m_plateNum[0] = '\0';
		this->m_address[0] = '\0';
		this->m_year = 0;

		// Passing arguments & defaults
		if (plateNo && std::strlen(plateNo)) std::strncpy(this->m_plateNum, plateNo, PLATE_SIZE);
		if (year) this->m_year = year;
		strcpy(this->m_address, "Factory");
	}

	// Moves the vehicle to the new address if the new address is different from the current address.
	void VehicleBasic::NewAddress(const char* address)
	{
		if (std::strcmp(this->m_address, address)) // if addresses are not the same
		{
			std::cout.setf(std::ios::right);
			std::cout << "|" << std::setw(8) << this->m_plateNum << "| "; // plate num
			std::cout << "|" << std::setw(20) << this->m_address << " ---> "; // old address
			std::cout.unsetf(std::ios::right);

			strcpy(this->m_address, address); // copy the new address

			std::cout.setf(std::ios::left);
			std::cout << std::setw(20) << this->m_address << "|" << std::endl; // new address
			std::cout.unsetf(std::ios::left);
		}
	}

	/* Stream Methods */
	// Inserts into os the content of the object in the format
	std::ostream& VehicleBasic::write(std::ostream& os) const
	{
		os << "| " << this->m_year << " | " << this->m_plateNum << " | " << this->m_address;
		return os;
	}

	// Reads from the stream in the data for the current object
	std::istream& VehicleBasic::read(std::istream& in)
	{
		// Year
		do
		{
			std::cout << "Built year: ";
			in >> this->m_year;
			in.clear();
			in.ignore(1000, '\n');
		} while (!this->m_year);

		// Licence Plate
		do
		{
			std::cout << "License plate: ";
			in >> this->m_plateNum;
			in.clear();
			in.ignore(1000, '\n');
		} while (!this->m_plateNum);

		// address
		do
		{
			std::cout << "Current location: ";
			in >> this->m_address;
			in.clear();
			in.ignore(1000, '\n');
		} while (!this->m_address);

		return in;
	}

	/* Helper Methods */
	// Extract a VehicleBasic from a stream
	std::ostream& operator <<(std::ostream& out, VehicleBasic vehicle)
	{
		vehicle.write(out);
		return out;
	}

	// Insert a VehicleBasic into a stream
	std::istream& operator >>(std::istream& in, VehicleBasic& vehicle)
	{
		vehicle.read(in);
		return in;
	}
}
