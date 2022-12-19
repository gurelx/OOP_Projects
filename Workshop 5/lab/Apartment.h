/*****************************************************************************
                          Workshop - #5 (P1)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. 
*****************************************************************************/

#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
      Apartment(int number, double balance);
      std::ostream& display()const;
      
      // Type conversion operators 
      operator bool() const;
      operator int() const;
      operator double() const;

      // Unary member operator
      bool operator~() const;

      //Binary member operators
      Apartment& operator=(int integer); // Set to an integer
      Apartment& operator=(Apartment& B); // Assign to each other
      Apartment& operator+=(double dbl); // Add a double value to an apartment
      Apartment& operator-=(double dbl); // Subtract a double value from an apartment
      Apartment& operator<<(Apartment& B); // Move the balance from the right apartment to the left apartment.  
      Apartment& operator>>(Apartment& B); // Move the balance from the left apartment to the right apartment.  
   };
      //Binary helper operators
      double operator+(const Apartment& A, const Apartment& B); // Find the sum
      double operator+=(double& dbl, const Apartment& B); // Adds a double value
}
      

#endif // SDDS_APARTMENT_H_