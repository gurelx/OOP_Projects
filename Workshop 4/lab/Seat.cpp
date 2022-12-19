#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

#include "Seat.h"


using namespace sdds;
using namespace std;

	// Returns true if the row number and the seating letter, together correctly address a seat in the airplane.
	bool sdds::Seat::validate(int row, char letter)const
	{
		bool isValid = false;

		if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')
		{
			if ((row >= 20 && row <= 38) || (row >= 7 && row <= 15))
			{
				isValid = true;
			}
			else if ((row <= 4 && row >= 1) && !(letter == 'C' || letter == 'D'))
			{
				isValid = true;
			}
		}

		return isValid;
	}

	// Allocates memory for passenger name and copy the value into the allocated memory.
	Seat& sdds::Seat::alAndCp(const char* str)
	{
		this->name = nullptr;

		if (str != NULL && std::strlen(str) != 0) // validate str is not null and not empty
		{
			this->name = new char[std::strlen(str) + 1]; // allocate memory
			std::strcpy(this->name, str); // copy the content
		}

		return *this;
	}

	// Resets the object into a safe empty state.
	Seat& sdds::Seat::reset()
	{
		delete[]this->name;
		this->name = nullptr;
		this->rowNum = 0;
		this->seatLetter = 0;

		return *this;
	}
	
	// Returns true if the passenger name pointer attribute is nullptr.
	bool sdds::Seat::isEmpty() const
	{
		if (this->name == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Returns true if the seats are assigned and valid by returning the validate method call result.
	bool sdds::Seat::assigned() const
	{
		if (validate(this->rowNum, this->seatLetter))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Sets the object to the safe empty state.
	sdds::Seat::Seat()
	{
		this->name = nullptr;
		this->rowNum = 0;
		this->seatLetter = 0;
	}

	// If argument is a valid and non-empty, allocates memory for passenger name and copies the content. Then sets the seat row and letter to zero.
	sdds::Seat::Seat(const char* passengerName)
	{
		alAndCp(passengerName);
		this->rowNum = 0;
		this->seatLetter = 0;
	}

	// If arguments are valid sets the row number and the letter alongside passenger name.
	sdds::Seat::Seat(const char* passengerName, int row, char letter)
	{
		alAndCp(passengerName); // set the name
		set(row, letter); // set the row / letter
	}

	// Deallocates the memory pointed by the passenger name pointer attribute.
	sdds::Seat::~Seat()
	{
		delete[]this->name;
		this->name = nullptr;
	}

	// Validate the row and letter, if they are valid set to the attributes. If not, the attributes will be set to zero.
	Seat& sdds::Seat::set(int row, char letter)
	{
		if (validate(row, letter))
		{
			this->rowNum = row;
			this->seatLetter = letter;
		}
		else 
		{
			this->rowNum = 0;
			this->seatLetter = 0;
		}

		return *this;
	}

	// Returns the row attribute value.
	int sdds::Seat::row() const
	{
		return this->rowNum;
	}

	// Returns the row attribute value.
	char sdds::Seat::letter() const
	{
		return this->seatLetter;
	}

	// Returns the value of the passenger name pointer attribute.
	const char* sdds::Seat::passenger() const
	{
		return this->name;
	}

	// Prints passenger name and seat number.
	std::ostream& sdds::Seat::display(std::ostream& coutRef) const
	{
		char local[41] = {' '};

		if (isEmpty())
		{
			coutRef << "Invalid Seat!";
		}
		else
		{
			std::strncpy(local, name, 40); // Copy the name to local string
			
			// Print passenger name
			coutRef.width(40);
			cout.fill('.');
			coutRef << std::left << local;

			// Reset cout buffer
			cout.unsetf(iostream::left);
			cout.fill(' ');

			if (!(rowNum)) // Invalid seat number checker
			{
				coutRef << " ___";
			}
			else
			{
				coutRef << " " << rowNum << seatLetter; // Print the seat number
			}
		}
		return coutRef;
	}


	std::istream& sdds::Seat::read(std::istream& cinRef)
	{
		char localName[71];
		int localNum;
		char localLetter;
		reset(); // safe empty state

		cinRef.getline(localName, 70, ','); // passenger name
		cinRef >> localNum >> localLetter; // seat info
		cinRef.get(); // for the \n character

		if (cinRef)
		{
			alAndCp(localName);
			if (name)
			{
				set(localNum, localLetter);
			}
		}

		return cinRef;
	}
