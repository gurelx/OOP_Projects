/*****************************************************************************
                          Workshop - #5 (P1)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   Apartment::Apartment(int number, double balance)
   {

      if (number >= 1000 && number <= 9999
         && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }

   // Type conversion operators 
   Apartment::operator bool() const
   {
       return bool(this->m_number >= 1000 && this->m_number <= 9999 && this->m_balance >= 0);
   }

   Apartment::operator int() const
   {
       return m_number;
   }

   Apartment::operator double() const
   {
       return m_balance;
   }

   // Unary member operator
   bool Apartment::operator~() const
   {
       return bool(m_balance < 0.00001);
   }

   //Binary member operators
   Apartment& Apartment::operator=(int integer)
   {
       if (integer >= 1000 && integer <= 9999)
       {
           this->m_number = integer;
       }
       else
       {
           this->m_number = -1;
           this->m_balance = 0;
       }

       return *this;
   }

   Apartment& Apartment::operator=(Apartment& B)
   {
       int tempNumber;
       double tempBalance;

       tempBalance = this->m_balance;
       this->m_balance = B.m_balance;
       B.m_balance = tempBalance;

       tempNumber = this->m_number;
       this->m_number = B.m_number;
       B.m_number = tempNumber;
           
       return *this;
   }

   Apartment& Apartment::operator+=(double dbl)
   {
       if (bool(this) && // valid apartment
           dbl > 0) //valid double
       {
           this->m_balance += dbl;
       }

       return *this;
   }

   Apartment& Apartment::operator-=(double dbl)
   {
       if (bool(this) && // valid apartment
           dbl > 0 // valid double 
           && this->m_balance >= dbl) // enough apartment funds 
       {
           this->m_balance -= dbl;
       }

       return *this;
   }

   Apartment& Apartment::operator<<(Apartment& B)
   {
       if (bool(this) && bool(B) && (this->m_balance != B.m_balance))
       {
           this->m_balance += B.m_balance;
           B.m_balance = 0;
       }
       return *this;
   }

   Apartment& Apartment::operator>>(Apartment& B)
   {
       if (bool(this) && bool(B) && (this->m_balance != B.m_balance))
       {
           B.m_balance += this->m_balance;
           this->m_balance = 0;
       }
       return *this;
   }

   //Binary helper operators
   double operator+(const Apartment& A, const Apartment& B)
   {
       if (bool(A) && bool(B))
       {
           return  double(A) + double(B);
       }
       else
       {
           return 0;
       }
   }

   double operator+=(double& dbl, const Apartment& B)
   {
       if (bool(B))
       {
           dbl += double(B);
       }
       return dbl;
   }
}