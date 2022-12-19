/*****************************************************************************
                          Workshop - #8
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds
{
    class Rectangle :
        public LblShape
    {
    public:
        Rectangle();
        Rectangle(const char* label, const int width, const int height);

        void draw(std::ostream& os);
        void getSpecs(std::istream& in);
    private:
        int m_width;
        int m_height;
    };
}

#endif // !SDDS_RECTANGLE_H




