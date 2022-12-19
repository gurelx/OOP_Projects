/*****************************************************************************
						  Workshop - #8
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#include <iostream>
#include "Shape.h"

using namespace std;

namespace sdds
{
	// Insertion and extraction overloads
	istream& operator>>(istream& in, Shape& shape)
	{
		shape.getSpecs(in);
		return in;
	}

	ostream& operator<<(ostream& os, Shape& shape)
	{
		shape.draw(os);
		return os;
	}
}