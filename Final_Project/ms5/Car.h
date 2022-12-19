/************************************************************
Final Project Milestone 5
Module: Car
Filename: Car.h
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

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
	public:
		// Constructors
		Car();
		Car(const char* plate, const char* model);

		// Rule of three
		Car(const Car& src);
		void operator=(const Car& src);
		~Car() = default; // I am using stings for the dynamic allocation

		// Read & Write
		std::ostream& writeType(std::ostream& os) const;
		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os) const;

	private:
		bool m_isWash;

	};
}
#endif // !SDDS_CAR_H
