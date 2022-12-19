/************************************************************
Final Project Milestone 3
Module: Vehicle
Filename: Vehicle.h
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

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include <string>
#include "ReadWritable.h"

namespace sdds
{
	class Vehicle : public ReadWritable
	{
	public:
		// Constructors
		Vehicle();
		Vehicle(const char* plate, const char* model);

		// Copy Constructor & Assignment
		Vehicle(const Vehicle& vehicle);
		void operator=(const Vehicle& vehicle);

		// Empty methods
		void setEmpty();
		bool isEmpty() const;

		// Get members
		std::string getLicensePlate() const;
		std::string getMakeModel() const;
		int getParkingSpot() const;

		// Set members
		void setMakeModel(std::string model);
		void setParkingSpot(int parking);

		// == overloads
		bool operator ==(const std::string plate) const;
		bool operator ==(const Vehicle& vehicle) const;

		// Read & Write methods
		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os) const;
		virtual std::ostream& writeType(std::ostream& os) const = 0;

	private:
		std::string m_plate;
		std::string m_model;
		int m_parking;
	};
}

#endif // !SDDS_VEHICLE_H
