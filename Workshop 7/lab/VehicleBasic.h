/*
Name: Gurel Sezgin
Email: gurel-sezgin@myseneca.ca
Student ID: 174331215
Data:
Section:
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include <iostream>
#include <cstring>

namespace sdds
{
	const int PLATE_SIZE = 9;
	const int MAX_ADDRESS_SIZE = 64;

	class VehicleBasic
	{
	public:
		// Constructor
		VehicleBasic(const char* plateNo = nullptr, const int year = 0);
		void NewAddress(const char* address);

		// Stream functions
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

	private:
		char m_plateNum[PLATE_SIZE];
		char m_address[MAX_ADDRESS_SIZE];
		int m_year;
	};
	// Helper functions
	std::ostream& operator <<(std::ostream& out, VehicleBasic vehicle);
	std::istream& operator >>(std::istream& in, VehicleBasic& vehicle);
}

#endif

