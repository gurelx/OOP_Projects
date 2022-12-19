/*
Name: Gurel Sezgin
Email: gurel-sezgin@myseneca.ca
Student ID: 174331215
Data:
Section:
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper:public VehicleBasic
	{
	public:
		// Constructor
		Dumper(const char* plateNo = nullptr, const int year = 0, int capacity = 0, const char* address = nullptr);

		// Load/Unload Cargo
		bool loaddCargo(double cargo);
		bool unloadCargo();

		// File functions
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

	private:
		double m_capacity;
		double m_load;
	};
	// Helper functions
	std::ostream& operator <<(std::ostream& out, Dumper vehicle);
	std::istream& operator >>(std::istream& in, Dumper& vehicle);
}
#endif

