/*****************************************************************************
                          Workshop - #6 (P1)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {


   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   } 

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         deallocate();
         setEmpty();
         m_isOriginal = false; 
      }
   }

   Numbers::~Numbers() {
      save();
      deallocate();
   }

   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   void Numbers::deallocate() {
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

  

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if(!isEmpty()) {
         maxVal = m_numbers[0];
         for(int i = 1; i < m_numCount; i++)
            if(maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
  
   // My functions

   // copy constructor
   Numbers::Numbers(const Numbers& src)
   {
       // Sets the object to the safe empty state
       deallocate();
       setEmpty();
       // Sets the object NOT to be original 
       this->m_isOriginal = false;
       // Assigns the current object to the Numbers object that is being copied.
       *this = src;
   }

   // copy assignment operator
   Numbers& Numbers::operator=(const Numbers& src)
   {
       if (this != &src)
       {
           // deletes the current collection of the double values
           // Sets the object to the safe empty state
           deallocate();
           setEmpty();
           // Sets the object NOT to be original 
           this->m_isOriginal = false;
           // Allocates new memory pointed by m_numbers to the number of the values in the object that is being copied.
           if (src.m_numbers != nullptr)
           {
               this->m_numbers = new double[src.m_numCount];
               // Copies all the double values in the object that is being copied into the newly allocated memory.
               for (int i = 0; i < src.m_numCount; i++)
               {
                   this->m_numbers[i] = src.m_numbers[i];
               }
               this->m_numCount = src.m_numCount;
           }
       }
       return *this;
   }

   // sorting method
   // Sort the numbers based on bool argument
   Numbers& Numbers::sort(bool ascending)
   {
       double temp = 0;

       if (ascending) // sort in ascending order
       {
           for (int i = this->m_numCount - 1; i > 0; i--)
           {
               for (int j = 0; j < i; j++)
               {
                   if (this->m_numbers[j] > this->m_numbers[j + 1])
                   {
                       temp = this->m_numbers[j];
                       this->m_numbers[j] = this->m_numbers[j + 1];
                       this->m_numbers[j + 1] = temp;
                   }
               }
           }
       }
       else // sort in descending order
       {
           for (int i = 0; i < this->m_numCount; i++) {
               for (int j = 0; j < this->m_numCount - i - 1; ++j) {
                   if (this->m_numbers[j] < this->m_numbers[j + 1]) {
                       temp = this->m_numbers[j];
                       this->m_numbers[j] = this->m_numbers[j + 1];
                       this->m_numbers[j + 1] = temp;
                   }
               }
           }
       }
       return *this;
   }

   // Unary operators
   // will return a descending sorted copy of the Numbers object.
   Numbers Numbers::operator-() const
   {
       Numbers copy;
       copy = *this;
       copy.sort(false);
       return copy;
   }
   // will return an ascending sorted copy of the Numbers object.
   Numbers Numbers::operator+()const
   {
       Numbers copy;
       copy = *this;
       copy.sort(true);
       return copy;
   }

   // file methods
   // Count and return the number of newline chars in a file
   int Numbers::numberCount()
   {
       ifstream file(m_filename);
       int newlineCount = 0;
       double buffer = 0;
       while (file)
       {
           file >> buffer; // get the number
           if (file.get() == '\n') // get the newline char
           {
               newlineCount++;
           }
       }
       return newlineCount;
   }

   // Returns true if all the double values are read from the data file and stored in a dynamically allocated memory pointed by m_numbers.
   bool Numbers::load()
   {
       int i = 0;
       if (m_numCount > 0) 
       {
           ifstream file(m_filename);
           m_numbers = new double[m_numCount];
           
           while (i <= m_numCount)
           {
               file >> m_numbers[i]; // get the number
               file.ignore(); // ignore newline
               i++;
           }
       }
       return bool(m_numCount == i - 1);
   }

   // Write to an original and empty object
   void Numbers::save()
   {
       int i = 0;
       if (m_isOriginal == true && !isEmpty())
       {
           ofstream file(m_filename);

           if (file)
           {
               file.setf(ios::fixed);
               file.precision(2); // write with precision
               for (i = 0; i < m_numCount; i++)
               {
                   file << m_numbers[i] << endl;
               }
           }
       }
   }

   // Overload the += operator to add a single double value to the list of numbers in the array and then return the reference of the current object.
   Numbers& Numbers::operator+=(double dbl)
   {
       double* tmpPtr = new double[m_numCount + 1]; // temp with a bigger memory

       for (int i = 0; i < m_numCount; i++)
       {
           tmpPtr[i] = m_numbers[i]; // append this->numbers to temp
       }

       tmpPtr[m_numCount] = dbl; // append dbl to extra memory
       m_numCount++; // numcount has increased
       delete[] m_numbers;
       m_numbers = tmpPtr; // this should point to temp

       return *this;
   }

   // Displays the Numbers object on the screen. 
   std::ostream& Numbers::display(std::ostream& ostr) const
   {
       if (isEmpty())
       {
           ostr << "Empty list";
       }
       else
       {
           // Decide if it is copy or the original file
           ostr << "=========================" << endl;
           if (m_isOriginal)
           {
               ostr << m_filename << endl;
           }
           else
           {
               ostr << "*** COPY ***" << endl;
           }

           // format display
           ostr.setf(ios::fixed, ios::floatfield);
           ostr.precision(2);

           // display values
           for (int i = 0; i < m_numCount; i++)
           {
               if (i != m_numCount - 1)
               {
                   ostr << m_numbers[i] << ", ";
               }
               else
               {
                   ostr << m_numbers[i];
               }
           }
           ostr << endl;

           // display total, max, average
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average:         " << average() << endl;
           ostr << "=========================";
           ostr.unsetf(ios::fixed);
       }
       return ostr;
   }

   // Helper functions
   // Overload the insertion operator to display the Numbers object using istream.
   std::ostream& operator<<(std::ostream& os, const Numbers& N)
   {
       return N.display(os);
   }

   // Overload the extraction operator to read the Numbers object using istream.
   std::istream& operator>>(std::istream& istr, Numbers& N)
   {
       double dbl = 0;
       istr >> dbl;
       if (dbl)
       {
           N += dbl;
       }
       return istr;
   }
}
