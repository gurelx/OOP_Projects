/************************************************************
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author	Gurel Sezgin
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/8  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
************************************************************/

#include "Menu.h"

namespace sdds
{
	class Parking
	{
	public:
		Parking(const char* filename = nullptr);
		~Parking();
		int run();

	private:
		char* m_filename;
		Menu m_mainMenu;
		Menu m_vehicleSelect;

		// Copy preventation
		Parking(const Parking&) = delete;
		void operator=(const Parking&) = delete;

		// Status Methods
		bool isEmpty() const;
		void status() const;

		// Vehicle methods
		void parkVehicle() const;
		void returnVehicle() const;
		void listVehicles() const;
		void findVehicles() const;

		// Exit methods
		bool closeParking() const;
		bool exit() const;

		// File Methods
		bool load() const;
		void save() const;
	};
}