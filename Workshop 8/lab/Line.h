/*****************************************************************************
                          Workshop - #8
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds
{
    class Line :
        public LblShape
    {
    public:
        Line();
        Line(const char* label, const int length);

        void draw(std::ostream& os);
        void getSpecs(std::istream& in);
    private:
        int m_length;
    };
}

#endif // !SDDS_LINE_H




