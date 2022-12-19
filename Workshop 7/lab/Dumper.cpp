/*
Name: Gurel Sezgin
Email: gurel-sezgin@myseneca.ca
Student ID: 174331215
Data:
Section:
*/
#include <iostream>
#include <cstring>
#include "Dumper.h"
#include "VehicleBasic.h"

namespace sdds
{
	// Constructor
	Dumper::Dumper(const char* plateNo, const int year, int capacity, const char* address) : VehicleBasic(plateNo, year) // Call base constructor
	{
		this->m_load = 0;
		this->m_capacity = 0;

		if (address && std::strlen(address)) this->NewAddress(address); // Set the address if valid
		if (capacity > 0) this->m_capacity = capacity; // Set the capacity if valid.
	}
	
	/* Load/Unload Cargo */
	// Load cargo and return true if verified 
	bool Dumper::loaddCargo(double cargo)
	{
		if (this->m_load + cargo <= this->m_capacity)
		{
			this->m_load += cargo;
			return true;
		}
		else return false;
	}

	// Unload cargo and return true if verified 
	bool Dumper::unloadCargo()
	{
		if (this->m_load)
		{
			this->m_load = 0;
			return true;
		}
		else return false;
	}

	/* Stream Methods */
	// Inserts into os the content of the object in the format
	std::ostream& Dumper::write(std::ostream& os) const
	{
		this->VehicleBasic::write(os); // write year, plate, address 
		os << " | " << this->m_load << "/" << this->m_capacity; // cargo/capacity
		return os;
	}

	// Reads from the stream in the data for the current object
	std::istream& Dumper::read(std::istream& in)
	{
		this->VehicleBasic::read(in); // read year, plate, address

		// Capacity
		do
		{
			std::cout << "Capacity: ";
			in >> this->m_capacity;
			in.clear();
			in.ignore(1000, '\n');
		} while (!this->m_capacity);

		// Cargo
		do
		{
			std::cout << "Cargo: ";
			in >> this->m_load;
			in.clear();
			in.ignore(1000, '\n');
		} while (this->m_load < 0);

		return in;
	}

	/* Helper Methods */
	// Extract a VehicleBasic from a stream
	std::ostream& operator <<(std::ostream& out, Dumper vehicle)
	{
		vehicle.write(out);
		return out;
	}

	// Insert a VehicleBasic into a stream
	std::istream& operator >>(std::istream& in, Dumper& vehicle)
	{
		vehicle.read(in);
		return in;
	}
}

