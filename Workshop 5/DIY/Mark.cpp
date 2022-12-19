/*****************************************************************************
                          Workshop - #5 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#include <iostream>
#include "Mark.h"

namespace sdds
{
    // Construction 
    // If one argument is a valid int set the mark, if the value is not provided set 0, if the argument is not valid, set to -1
    Mark::Mark(int mark)
    {
        if (0 <= mark && mark <= 100)
        {
            m_mark = mark;
        }
        else
        {
            m_mark = -1;
        }
    }

    // Type conversion Operators

    //The object can be casted to an integer; the result would be the value of the mark or zero if the mark is in an invalid state.
    Mark::operator int() const
    {
        if (bool(*this))
        {
            return m_mark;
        }
        else
        {
            return 0;
        }
    }

    // Map the result would to the GPA equivalent of the integer value or zero if the mark is in an invalid state.
    Mark::operator double() const
    {
        double gpa;

        if (0 <= m_mark && m_mark < 50)
        {
            gpa = 0;
        }
        else if (50 <= m_mark && m_mark < 60)
        {
            gpa = 1;
        }
        else if (60 <= m_mark && m_mark < 70)
        {
            gpa = 2;
        }
        else if (70 <= m_mark && m_mark < 80)
        {
            gpa = 3;
        }
        else if (80 <= m_mark && m_mark <= 100)
        {
            gpa = 4;
        }
        else
        {
            gpa = 0;
        }
        return gpa;
    }

    // Map the result would to the grade equivalent of the integer value or X if the mark is in an invalid state.
    Mark::operator char() const
    {
        char grade;

        if (0 <= m_mark && m_mark < 50)
        {
            grade = 'F';
        }
        else if (50 <= m_mark && m_mark < 60)
        {
            grade = 'D';
        }
        else if (60 <= m_mark && m_mark < 70)
        {
            grade = 'C';
        }
        else if (70 <= m_mark && m_mark < 80)
        {
            grade = 'B';
        }
        else if (80 <= m_mark && m_mark <= 100)
        {
            grade = 'A';
        }
        else
        {
            grade = 'X';
        }
        return grade;
    }

    // Is mark in a valid state or not
    Mark::operator bool() const
    {
        return bool(0 <= m_mark && m_mark <= 100);
    }

    // Comparison operator overloads

    // Is *this == right?
    bool Mark::operator==(const Mark& right) const
    {
        return bool(this->m_mark == right.m_mark);
    }

    // Is *this != right?
    bool Mark::operator!=(const Mark& right) const
    {
        return bool(!(*this == right));
    }

    // Is *this < right?
    bool Mark::operator<(const Mark& right) const
    {
        return bool(this->m_mark < right.m_mark);
    }

    // Is *this > right?
    bool Mark::operator>(const Mark& right) const
    {
        return bool(!((*this < right) || (*this == right)));
    }

    // Is *this <= right?
    bool Mark::operator<=(const Mark& right) const
    {
        return bool(!(*this > right));
    }

    // Is *this >= right?
    bool Mark::operator>=(const Mark& right) const
    {
        return bool(!(*this < right));
    }

    // Unary operators

    // Increment the mark, do nothing if mark is not valid (m++)
    Mark& Mark::operator++()
    {
        if (bool(*this))
        {
            this->m_mark++;
        }
        return *this;
    }

    // Increment the mark, do nothing if mark is not valid (++m)
    Mark Mark::operator++(int)
    {
        Mark mark = *this;
        ++(*this);
        return mark;
    }

    // Decrement the mark, do nothing if mark is not valid (m--)
    Mark& Mark::operator--()
    {
        if (bool(*this))
        {
            this->m_mark--;
        }
        return *this;
    }

    // Decrement the mark, do nothing if mark is not valid (--m)
    Mark Mark::operator--(int)
    {
        Mark mark = *this;
        --(*this);
        return mark;
    }

    // Return true if mark is a "pass"
    bool Mark::operator~()
    {
        return bool(50 <= this->m_mark && this->m_mark <= 100);
    }

    // Binary operators

    // Set mark to an int, even mark is invalid
    Mark& Mark::operator=(const int mark)
    {
        this->m_mark = mark;
        return *this;
    }

    // Add an int value to a mark, if mark is invalid, do nothing
    Mark& Mark::operator+=(const int mark)
    {
        if (bool(*this))
        {
            this->m_mark += mark;
        }
        return *this;
    }

    // Subtract an int value from a mark, if mark is invalid, do nothing
    Mark& Mark::operator-=(const int mark)
    {
        if (bool(*this))
        {
            this->m_mark -= mark;
        }
        return *this;
    }

    // The sum of a Mark and an integer
    Mark Mark::operator+(const int mark) const //THIS IS THE OPERATOR TO CHECK !!!!
    {
        Mark sum;
        sum.m_mark = this->m_mark + mark;

        return sum;
    }

    // The sum of a Mark and another Mark 
    Mark Mark::operator+(const Mark& right) const //THIS IS THE OPERATOR TO CHECK !!!!
    {
        Mark local;
        local = this->m_mark + right.m_mark;

        return local;
    }

    // Move the value from left to this, leave right with zero
    Mark& Mark::operator<<(Mark& right)
    {
        *this += right;
        right.m_mark = 0;

        return *this;
    }

    // Move the value from this to right, leave this with zero
    Mark& Mark::operator>>(Mark& right)
    {
        right += *this;
        this->m_mark = 0;

        return *this;
    }

    // Binary helpers

    // Add a mark value to an int, if mark is invalid, do nothing
    int operator+=(int& val, const Mark& mark)
    {
        if (bool(mark))
        {
            val += int(mark);
        }
        return val;
    }

    // Subtract a mark value from an int, if mark is invalid, do nothing
    int operator-=(int& val, const Mark& mark)
    {
        if (bool(mark))
        {
            val -= int(mark);
        }
        return val;
    }

    // The sum of an integer and a Mark 
    int operator+(int& val, const Mark& mark)
    {
        Mark local;
        local = mark + val;

        return local;
    }
}
