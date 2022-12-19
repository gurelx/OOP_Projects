/*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include <ostream>
namespace sdds {
   class Numbers {
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);
   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();

      // My methods
      Numbers(const Numbers&); // copy constructor
      Numbers& operator=(const Numbers&); // copy assignment operator
      Numbers& sort(bool ascending); // sorting method

      // Unary operators
      Numbers operator-()const;
      Numbers operator+()const;

      // file methods
      int numberCount();
      bool load();
      void save();

      Numbers& operator+=(double dbl); // += overload
      std::ostream& display(std::ostream& ostr = std::cout)const; // ostream overload

   };

   // Helper functions
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N); 
}
#endif // !SDDS_NUMBERS_H_

