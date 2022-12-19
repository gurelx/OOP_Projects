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
#include <iomanip>
#include <cstring>

#include "Line.h"

using namespace std;

namespace sdds
{
    // Constructor
    Line::Line()
    {
        this->m_length = 0;
    }

    Line::Line(const char* label, const int length) : LblShape(label)
    {
        this->m_length = length;
    }

    // Override methods
    void Line::draw(std::ostream& os)
    {
        //If the length and label exists
        if (this->m_length > 0 && this->label())
        {
            // Print label in a formatted way
            os.setf(ios::left);
            os << setw(this->m_length) << setfill('=') << this->label() << setfill(' ');
            os.unsetf(ios::left);
        }
    }
    void Line::getSpecs(std::istream& in)
    {   
        // Call the base method
        this->LblShape::getSpecs(in);

        // Read the length
        in >> this->m_length;
        in.ignore(1000, '\n');
    }
}
