/*
*****************************************************************************
						  Workshop - #3 (P1)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

#include "CC.h"
#include "Utils.h"


using namespace std;
using namespace sdds;

// Validate input
bool sdds::CC::validate(const char* name,
	unsigned long long cardNo,
	short cvv,
	short expMon,
	short expYear) const 
{
	if((name != NULL && std::strlen(name) > 2) &&  // name check
		(cardNo >= 4000000000000000 && cardNo <= 4099999999999999) && // card no check
		(cvv <= 999 && cvv >= 100) && // cvv check
		(expMon >= 1 && expMon <= 12) && // month check
		(expYear >= 22 && expYear <= 32)) // year check
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Seperate credit card number
void sdds::CC::prnNumber()const
{
	long long int num = m_cardNo / 1000000000000;
	cout.width(4);
	cout.fill('0');

	printf("%04lld ", num); // first 4 digits

	num = ((m_cardNo / 100000000) * 100000000) - (num * 1000000000000);
	printf("%04lld ", num / 100000000); // second 4 digits

	num = ((m_cardNo / 10000) * 10000) - ((m_cardNo / 100000000) * 100000000);
	printf("%04lld ", num / 10000); // third 4 digits

	num = (m_cardNo - ((m_cardNo / 10000) * 10000));
	printf("%04lld", num); // last 4 digits

};

// Set all the members to a safe empty state (null for the pointer, 0 for the numbers)
void sdds::CC::set()
{
	m_name = nullptr;
	m_cardNo = 0;
	m_cvv = 0;
	m_expMon = 0;
	m_expYear = 0;
};

// Deallocate the memory for the pointer
void sdds::CC::cleanUp()
{
	delete[] m_name;
	sdds::CC::set();
};

// Check if the name pointer is null
bool sdds::CC::isEmpty() const
{
	if (m_name == nullptr)
	{
		return true;
	}
	else 
	{
		return false;
	}
};

// Set the parameters to the class members
void sdds::CC::set(const char* cc_name,
	unsigned long long cc_no,
	short m_cvv,
	short m_expMon,
	short m_expYear)
{
	sdds::CC::cleanUp();

	if (sdds::CC::validate(cc_name, cc_no, m_cvv, m_expMon, m_expYear)) // if validated
	{
		// Copy all the data to the class members
		m_name = new char[std::strlen(cc_name) + 1];
		std::strcpy(m_name, cc_name);
		m_cardNo = cc_no;
		this->m_cvv = m_cvv;
		this->m_expMon = m_expMon;
		this->m_expYear = m_expYear;
	}
	else
	{
		cout << "Invalid Credit Card Record" << endl;
	}
};

bool sdds::CC::read()
{
	char name[71];
	sdds::CC::cleanUp();

	unsigned long long no = 0;
	short cvv = 0;
	short mon = 0;
	short year = 0;

	// I couldn't find a better structure other than nested if's
	cout << "Card holder name: ";
	if (std::cin.getline(name, 70))
	{
		cout << "Credit card number: ";
		if (std::cin >> no)
		{
			cout << "Card Verification Value (CVV): ";
			if (cin >> cvv)
			{
				cout << "Expiry month and year (MM/YY): ";
				if (cin >> mon, cin.ignore(), year)
				{
					sdds::CC::set(name, no, cvv, mon, year);
				}
				else
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}
			else
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	else
	{
		cin.clear();
		cin.ignore(1000, '\n');
	}
	
	// Check if the input is wrong (empty in this case)
	if (sdds::CC::isEmpty())
	{
		return false;
	}
	else
	{
		return true;
	}
}

// Print the output based on row number
void sdds::CC::display(int row) const
{
	if (!(sdds::CC::isEmpty()))
	{
		if (row > 0) // Formatted print
		{
			printf("| %3d | %-30.30s | ", row, m_name);
			sdds::CC::prnNumber();
			printf(" | %3d | %2d/%d |\n", m_cvv, m_expMon, m_expYear);
		}
		else // Unformatted print
		{
			printf("Name: %s\n"
				"Creditcard No: ", m_name);
			sdds::CC::prnNumber();
			printf("\nCard Verification Value: %d\n"
				"Expiry Date: %d/%d\n", m_cvv, m_expMon, m_expYear);
		}
	}
};



