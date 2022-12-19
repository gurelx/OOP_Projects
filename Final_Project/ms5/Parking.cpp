/************************************************************
Final Project Milestone 5
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
#include <iomanip>
#include <fstream>
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Menu.h"

using namespace std;

namespace sdds
{
	// Constructor
	Parking::Parking(const char* filename, int noOfSpots)
	{
		this->m_parkedVehicles = 0;

		if (filename != nullptr && strlen(filename) && !(noOfSpots < 10 || noOfSpots > MAX_PARK_SPOTS))
		{
			// Filename
			this->m_filename = new char[strlen(filename) + 1];
			strcpy(this->m_filename, filename);

			// Parking spots
			this->m_noOfSpots = noOfSpots;
		}
		else
		{
			// Set invalid empty state
			this->m_filename = nullptr;
			this->m_mainMenu.clear();
			this->m_vehicleSelect.clear();
			this->m_noOfSpots = 0;
		}

		// Set all parking spots to null
		for (int i = 0; i < MAX_PARK_SPOTS; i++)
		{
			this->m_parkSpots[i] = nullptr;
		}

		// Populate
		if (!this->load())	cout << "Error in data file" << endl;
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
		this->save(); // save the file
		delete[] this->m_filename; // Delete the filename

		// Delete park spots
		for (int i = 0; i < MAX_PARK_SPOTS; i++)
		{
			if (this->m_parkSpots[i] != nullptr)
			{
				delete this->m_parkSpots[i];
			}
		}
	}

	// Is parking empty
	bool Parking::isEmpty() const
	{
		return this->m_filename == nullptr;
	}

	// Print the status of the park
	void Parking::status() const
	{
		cout << "****** Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.setf(ios::left);
		cout << setw(4) << (this->m_noOfSpots - this->m_parkedVehicles) << " *****" << endl;
		cout.unsetf(ios::left);
	}

	/* Vehicle Methods */

	// Park a vehicle
	void Parking::parkVehicle()
	{
		// If there are no parking spots
		if (this->m_parkedVehicles == this->m_noOfSpots)
		{
			cout << "Parking is full";
		}
		else
		{
			// Pointer to hold the vehicle
			Vehicle* vehicle = nullptr;
			// User prompt
			int selection = 0;
			// Is the vehicle parked
			bool isSet = false;

			// Invoke the menu
			selection = this->m_vehicleSelect.run();
			switch (selection)
			{
			// Car is selected
			case 1:
				vehicle = new Car;
				break;
			// Mc is selected
			case 2:
				vehicle = new Motorcycle;
				break;
			// Parking cancelled
			case 3:
				cout << "Parking Cancelled" << endl;
				break;
			}

			// If parking not cancelled
			if (selection != 3)
			{
				// Disable comma separated mode and read the vehicle
				vehicle->setCsv(0);
				vehicle->read(cin);

				// Search for a parking spot
				for (int i = 0; i < this->m_noOfSpots; i++)
				{
					if (this->m_parkSpots[i] == nullptr && !isSet)
					{
						// Assign the vehicle and its parking spot
						this->m_parkSpots[i] = vehicle;
						this->m_parkSpots[i]->setParkingSpot(i + 1);
						// Vehicle is parked
						isSet = true;
						// One more vehicle is parked
						this->m_parkedVehicles++;
					}
				}

				// Ticket generation
				cout << endl;
				cout << "Parking Ticket" << endl;
				if (vehicle != nullptr)
				{
					vehicle->write(cout);
					cout << endl;
				}
				else
				{
					// Deallocate vehicle
					delete vehicle;
				}
			}
		}
	}

	// Return a vehicle
	void Parking::returnVehicle()
	{
		cout << "Return Vehicle" << endl;

		char plate[9];
		bool flag = false;

		// Prompt for licence plate
		cout << "Enter License Plate Number: ";
		do
		{
			cin.getline(plate, '\n'); // get input
			cout << endl;

			// if garbage value exists
			if (strlen(plate) < 1 || strlen(plate) > 8)
			{
				cout << "Invalid License Plate, try again: ";
			}
		} while (strlen(plate) < 1 || strlen(plate) > 8);

		// Go through all the spots
		for (int i = 0; i < this->m_noOfSpots; i++)
		{
			// If found a vehicle that matches input, return it
			if (this->m_parkSpots[i] != nullptr && *m_parkSpots[i] == plate)
			{
				cout << "Returning:" << endl;
				this->m_parkSpots[i]->setCsv(0);
				this->m_parkSpots[i]->write(cout);
				cout << endl;

				// Delete the vehicle
				delete this->m_parkSpots[i];
				this->m_parkSpots[i] = nullptr;
				// One less parked vehicle
				this->m_parkedVehicles--;
				
				flag = true;
			}
		}

		// If the plate not found
		if (!flag)
		{
			for (size_t n = 0; n < strlen(plate); n++) plate[n] = toupper(plate[n]);

			cout << "License plate " << plate << " Not found" << endl;
			cout << endl;
		}
	}

	// List all vehicles parked
	void Parking::listVehicles() const
	{
		cout << "*** List of parked vehicles ***" << endl;

		// Go through all the spots
		for (int i = 0; i < this->m_noOfSpots; i++)
		{	
			// If found a vehicle, print it
			if (this->m_parkSpots[i] != nullptr)
			{
				this->m_parkSpots[i]->setCsv(0);
				this->m_parkSpots[i]->write(cout);
				cout << "-------------------------------" << endl;
			}
		}
	}

	// Find a vehicle
	void Parking::findVehicles()
	{
		char plate[9];
		bool flag = false;
		cout << "Vehicle Search" << endl;

		// Prompt for licence plate
		cout << "Enter Licence Plate Number: ";
		do
		{
			cin.getline(plate, '\n'); // get input
			cout << endl;

			// if garbage value exists
			if (strlen(plate) < 1 || strlen(plate) > 8)
			{
				cout << "Invalid Licence Plate, try again: ";
			}
		} while (strlen(plate) < 1 || strlen(plate) > 8);

		// Go through all the spots
		for (int i = 0; i < this->m_noOfSpots; i++)
		{
			// If found a vehicle that matches input, print it
			if (this->m_parkSpots[i] !=  nullptr && *m_parkSpots[i] == plate)
			{
				cout << "Vehicle found:" << endl;
				this->m_parkSpots[i]->setCsv(0);
				this->m_parkSpots[i]->write(cout);
				cout << endl;
				flag = true;
			}
		}

		// If the plate not found
		if (!flag)
		{
			for (size_t n = 0; n < strlen(plate); n++) plate[n] = toupper(plate[n]);

			cout << "License plate " << plate << " Not found" << endl;
			cout << endl;
		}
	}


	// Close the parking
	bool Parking::closeParking()
	{
		// If there are no cars parked
		if (this->isEmpty())
		{
			cout << "Closing Parking" << endl;
			return true;
		}
		else 
		{
			char selection;
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";

			// Input validation
			cin >> selection;
			while (selection != 'y' && selection != 'Y' && selection != 'n' && selection != 'N')
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> selection;
			}
			cin.clear();
			cin.ignore(1000, '\n');

			// If selected yes
			if (selection == 'y' || selection == 'Y')
			{
				cout << "Closing Parking" << endl;
				cout << endl;
				
				// Tow all parked cars one by one
				for (int i = 0; i < this->m_noOfSpots; i++)
				{
					if (this->m_parkSpots[i] != nullptr)
					{
						cout << "Towing request" << endl;
						cout << "*********************" << endl;
						this->m_parkSpots[i]->setCsv(0);
						this->m_parkSpots[i]->write(cout);
						
						if (i < this->m_noOfSpots - 1) cout << endl;

						delete this->m_parkSpots[i];
						this->m_parkSpots[i] = nullptr;
					}
				}

				// There are no parked vehicles anymore
				this->m_parkedVehicles = 0;
			}
			return (selection == 'y' || selection == 'Y' ? 1 : 0);
		}
	}

	// Exit directly
	bool Parking::exit() const
	{
		char selection;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		cin >> selection;
		while (selection != 'y' && selection != 'Y' && selection != 'n' && selection != 'N')
		{
			cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> selection;
		}
		cin.clear();
		cin.ignore(1000, '\n');

		if (selection == 'y' || selection == 'Y') cout << "Exiting program!" << endl;

		return (selection == 'y' || selection == 'Y' ? 1 : 0);
	}


	/**** File Methods ****/
	bool Parking::load()
	{
		// Vehicle pointer to hold the vehicle
		Vehicle* vehicle = nullptr;
		// Number of records read
		int noOfRecords = 0;
		// Return flag
		bool flag = false;

		// If not in empty state
		if (!this->isEmpty())
		{
			// Open the file
			ifstream ifs;
			ifs.open(this->m_filename);
			
			// If able to open the file
			if (ifs.is_open())
			{
				// While the number of records read is less than the number of elements of the array
				do
				{
					// Get the first char
					char c = ifs.get();

					// If reading fails, break
					if (ifs.fail()) break;
					else
					{
						// Evaluate the char, create proper vehicle, store the address to pointer
						if (c == 'M')
						{
							vehicle = new Motorcycle;
						}
						else if (c == 'C')
						{
							vehicle = new Car;
						}
						// Else ignore the rest of the line
						else ifs.ignore(1000, '\n');
					}

					// If proper vehicle is stored
					if (vehicle)
					{
						ifs.get(); // get the comma after vehicle type
						vehicle->setCsv(1); // Open comma-seperated mode
						vehicle->read(ifs); // Read the file

						// If reading the file not failed (which also means parking spot is read from file)
						if (0 < vehicle->getParkingSpot() && vehicle->getParkingSpot() <= this->m_noOfSpots)
						{
							// Assign the vehicle at the spot indicated in file
							this->m_parkSpots[vehicle->getParkingSpot() - 1] = vehicle;

							// Increase the number of parked vehicles
							this->m_parkedVehicles++;
							// Increase the number of records read and assigned
							noOfRecords++;
							flag = true;

						}
						else {
							// deallocate vehicle
							delete vehicle;
							vehicle = nullptr;
							break;
						}
					}
				} while (noOfRecords < this->m_noOfSpots);
			} 
			ifs.close();

		}
		// If parking is empty state or not able to open the file return true
		else flag = true;

		return flag;
	}

	void Parking::save() const
	{
		// If this is not empty
		if (!this->isEmpty())
		{	
			// Open the file
			ofstream ofs;
			ofs.open(this->m_filename);

			// If file opened correctly
			if (ofs.is_open())
			{
				for (int i = 0; i < this->m_noOfSpots; i++)
				{
					if (this->m_parkSpots[i] != nullptr)
					{
						this->m_parkSpots[i]->setCsv(1);
						this->m_parkSpots[i]->write(ofs);
					}
				}
			}
			ofs.close();
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

				if (selection != 5 && selection != 6)
				{
					cout << "Press <ENTER> to continue....";
					cin.ignore();
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

