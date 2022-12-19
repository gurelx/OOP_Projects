/*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds
{
    class Mark
    {
        int m_mark;

    public:
        // Construction
        Mark(int mark = 0);

        // Type conversion Operators
        operator int() const;
        operator double() const;
        operator char() const;
        operator bool() const;

        // Comparison operator overloads
        bool operator==(const Mark& right) const;
        bool operator!=(const Mark& right) const;
        bool operator<(const Mark& right) const;
        bool operator>(const Mark& right) const;
        bool operator<=(const Mark& right) const;
        bool operator>=(const Mark& right) const;

        // Unary operators
        Mark& operator++();
        Mark operator++(int);
        Mark& operator--();
        Mark operator--(int);
        bool operator~();

        // Binary operators
        Mark& operator=(const int mark);
        Mark& operator+=(const int mark);
        Mark& operator-=(const int mark);
        Mark operator+(const int mark) const;
        Mark operator+(const Mark& right) const;
        Mark& operator<<(Mark& right);
        Mark& operator>>(Mark& right);
    };

    // Binary helpers
    int operator+=(int& val, const Mark& mark);
    int operator-=(int& val, const Mark& mark);
    int operator+(int& val, const Mark& mark);
}

#endif // SDDS_APARTMENT_H_