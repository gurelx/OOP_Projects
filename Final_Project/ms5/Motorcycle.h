/************************************************************
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.h
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

#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Motorcycle : public Vehicle
	{
	public:
		// Constructors
		Motorcycle();
		Motorcycle(const char* plate, const char* model);

		// Rule of three
		Motorcycle(const Motorcycle& src);
		void operator = (const Motorcycle& src);
		~Motorcycle() = default;

		// Read & Write
		std::ostream& writeType(std::ostream& os) const;
		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os) const;

	private:
		bool m_sidecar;
	};
}
#endif // !SDDS_MOTORCYCLE_H