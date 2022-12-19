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
#include <iomanip>
#include "Rectangle.h"

using namespace std;

namespace sdds
{
    // Constructors
    Rectangle::Rectangle()
    {
        this->m_height = 0;
        this->m_width = 0;
    }
    Rectangle::Rectangle(const char* label, const int width, const int height): LblShape(label)
    {
        // Set the values
        this->m_width = width;
        this->m_height = height;

        // If the values are not valid set empty
        if ((height < 3) && (width < (int)(strlen(this->label()) + 1))) // Casted int for gcc
        {
            this->m_height = 0;
            this->m_width = 0;
        }
    }

    // Overloaded functions
    void Rectangle::draw(std::ostream& os)
    {
        // Needed to validate width and heigth again for the string method 
        if (this->m_width > 2 && this->m_height > 3)
        {
            // Formatted output
            os << '+' << string(this->m_width - 2, '-') << '+' << endl;
            os.setf(ios::left);
            os << '|' << setw(this->m_width - 2) << this->label() << '|' << endl;
            for (int i = 0; i < this->m_height - 3; i++)
            {
                os << '|' << string(this->m_width - 2, ' ') <<  '|' << endl;
            }
            os << '+' << string(this->m_width - 2, '-') << '+';
            os.unsetf(ios::left);
        }
    }

    void Rectangle::getSpecs(std::istream& in)
    {
        // Call the base function
        this->LblShape::getSpecs(in);

        // Read width and height 
        in >> this->m_width;
        in.get();
        in >> this->m_height;
        in.ignore(1000, '\n');
    }
}
