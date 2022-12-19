/************************************************************
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 1.1
Author	Gurel Sezgin
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/8  Preliminary release
2020/12/5  Adjusted for ms5
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
************************************************************/

#include "Menu.h"
#include "Vehicle.h"

namespace sdds
{
	const int MAX_PARK_SPOTS = 100;

	class Parking
	{
	public:
		Parking(const char* filename = nullptr, int noOfSpots = 0);
		~Parking();
		int run();

	private:
		char* m_filename;
		Menu m_mainMenu;
		Menu m_vehicleSelect;

		// Added members for ms5
		int m_noOfSpots;
		Vehicle* m_parkSpots[MAX_PARK_SPOTS];
		int m_parkedVehicles;

		// Copy preventation
		Parking(const Parking&) = delete;
		void operator=(const Parking&) = delete;

		// Status Methods
		bool isEmpty() const;
		void status() const;

		// Vehicle methods
		void parkVehicle();
		void returnVehicle();
		void listVehicles() const;
		void findVehicles();

		// Exit methods
		bool closeParking();
		bool exit() const;

		// File Methods
		bool load();
		void save() const;
	};
}