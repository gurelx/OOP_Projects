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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Parking.h"
#include "Menu.h"

namespace sdds
{
	// Constructor
	Parking::Parking(const char* filename)
	{
		// Set invalid empty state
		this->m_filename = nullptr;
		this->m_mainMenu.clear();
		this->m_vehicleSelect.clear();

		if (filename != nullptr && std::strlen(filename))
		{
			// Filename
			this->m_filename = new char[std::strlen(filename) + 1];
			std::strcpy(this->m_filename, filename);
		}

		// Populate
		if (!this->load())	std::cout << "Error in data file" << std::endl;
		else
		{
			// Main meniu population
			this->m_mainMenu = "Parking Menu, select an action:";
			this->m_mainMenu.setMenuIndent(0); //Used such a function since I couldn't make Menu constructor work
			this->m_mainMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";

			// Vehicle selection population
			this->m_vehicleSelect = "Select type of the vehicle:";
			this->m_vehicleSelect.setMenuIndent(1);
			this->m_vehicleSelect << "Car" << "Motorcycle" << "Cancel";
		}
	}

	// Destructor
	Parking::~Parking()
	{
		this->save();
		delete[] this->m_filename;
		this->m_filename = nullptr;
	}

	bool Parking::isEmpty() const
	{
		return this->m_filename == nullptr;
	}

	void Parking::status() const
	{
		std::cout << "****** Valet Parking ******" << std::endl;
	}


	/*** Mock Up Methods ****/
	void Parking::parkVehicle() const
	{
		int selection = 0;

		selection = this->m_vehicleSelect.run();
		switch (selection)
		{
		case 1:
			std::cout << "---------------------------------" << std::endl;
			std::cout << "Parking Car" << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "---------------------------------" << std::endl;
			std::cout << "Parking Motorcycle" << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "---------------------------------" << std::endl;
			std::cout << "Cancelled parking" << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cout << std::endl;
			break;
		}
	}

	void Parking::returnVehicle() const
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Returning Vehicle" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << std::endl;
	}

	void Parking::listVehicles() const
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Listing Parked Vehicles" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << std::endl;
	}

	void Parking::findVehicles() const
	{
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Finding a Vehicle" << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << std::endl;
	}


	// Close the parking
	bool Parking::closeParking() const
	{
		char selection;
		std::cout << "This will close the parking; All the vehicles will be removed!" << std::endl;
		std::cout << "Are you sure? (Y)es/(N)o: ";
		
		std::cin >> selection;
		while (selection != 'y' && selection != 'Y' && selection != 'n' && selection != 'N')
		{
			std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> selection;
		}
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		if (selection == 'y' || selection == 'Y') std::cout << "Ending application!" << std::endl;
			 
		return (selection == 'y' || selection == 'Y' ? 1 : 0);
	}

	// Exit directly
	bool Parking::exit() const
	{
		char selection;
		std::cout << "This will terminate the application and save the data!" << std::endl;
		std::cout << "Are you sure? (Y)es/(N)o: ";

		std::cin >> selection;
		while (selection != 'y' && selection != 'Y' && selection != 'n' && selection != 'N')
		{
			std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> selection;
		}
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		if (selection == 'y' || selection == 'Y') std::cout << "Exiting application!" << std::endl;

		return (selection == 'y' || selection == 'Y' ? 1 : 0);
	}

	 
	/**** File Methods ****/
	bool Parking::load() const
	{
		if (!this->isEmpty())
		{
			std::cout << "---------------------------------" << std::endl;
			std::cout << "loading data from " << this->m_filename << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cout << std::endl;
			return true;
		}
		else return false;
	}

	void Parking::save() const
	{
		if (!this->isEmpty())
		{
			std::cout << "---------------------------------" << std::endl;
			std::cout << "Saving data into " << this->m_filename << std::endl;
			std::cout << "---------------------------------" << std::endl;
			std::cout << std::endl;
		}
	}


	// Running the class will display the menu and mock up methods 
	int Parking::run()
	{
		if (!this->isEmpty())
		{
			bool willExit = false;
			int selection = 0;
			do
			{
				// The Menu
				this->status();
				selection = this->m_mainMenu.run();
				switch (selection)
				{
				case 1:
					this->parkVehicle();
					break;
				case 2:
					this->returnVehicle();
					break;
				case 3:
					this->listVehicles();
					break;
				case 4:
					this->findVehicles();
					break;
				case 5:
					willExit = this->closeParking();
					 break;
				case 6:
					willExit = this->exit();
					if (willExit) break;
				}
			} while (!willExit);

			return 1;
		}
		else
		{
			return 0;
		}
	}

}

