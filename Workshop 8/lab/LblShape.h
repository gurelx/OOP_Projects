/*****************************************************************************
						  Workshop - #8
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>
#include "Shape.h"

namespace sdds 
{
	class LblShape :
		public Shape
	{
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();

		LblShape(const LblShape& shape) = delete;
		void operator=(const LblShape& shape) = delete;

		void getSpecs(std::istream& in);
	private:
		char* m_label;
	protected:
		char* label() const;
	};
}

#endif // !SDDS_LBLSHAPE_H
