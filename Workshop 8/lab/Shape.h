/*****************************************************************************
						  Workshop - #8
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds 
{
	class Shape
	{
	public:
		Shape() = default;
		virtual void draw(std::ostream& os) = 0;
		virtual void getSpecs(std::istream& in) = 0;
		virtual ~Shape() = default;
	};
	// Helper methods
	std::istream& operator>>(std::istream& in, Shape& shape);
	std::ostream& operator<<(std::ostream& os,Shape& shape);
}

#endif // !SDDS_SHAPE_H


 