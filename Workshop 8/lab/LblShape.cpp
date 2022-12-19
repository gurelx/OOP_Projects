/*****************************************************************************
						  Workshop - #8
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds
{
	// Constructors & Destructor
	LblShape::LblShape()
	{
		this->m_label = nullptr;
	}

	LblShape::LblShape(const char* label)
	{
		this->m_label = nullptr;
		// Validate argument
		if (label != nullptr && label[0])
		{
			this->m_label = new char[strlen(label) + 1];
			strcpy(this->m_label, label);
		}
	}
	LblShape::~LblShape()
	{
		delete[] this->m_label;
		this->m_label = nullptr;
	}

	// Protected method
	char* LblShape::label() const
	{
		return this->m_label;
	}

	// Pure Virtual Method
	void LblShape::getSpecs(istream& in)
	{
		// Read the label
		string label;
		getline(in, label, ',');

		// Validate it and assign it to member
		if (!label.empty())
		{
			delete[] this->m_label;
			this->m_label = new char[label.length() + 1];
			strcpy(this->m_label, label.c_str());
		}
	}
}
