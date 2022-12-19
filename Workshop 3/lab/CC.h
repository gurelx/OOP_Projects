/*
*****************************************************************************
						  Workshop - #3 (P1)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef CC_H
#define CC_H

extern FILE* fptr;

namespace sdds
{
	class CC
	{
	private: // private members
		char* m_name;
		unsigned long long m_cardNo;
		short m_cvv;
		short m_expMon;
		short m_expYear;

	private: // private methods
		bool validate(const char* name,
			unsigned long long cardNo,
			short cvv,
			short expMon,
			short expYear)const;
		void prnNumber()const;

	public: // public methods
		void set();
		void cleanUp();
		bool isEmpty() const;
		void set(const char* cc_name,
			unsigned long long cc_no,
			short m_cvv,
			short m_expMon,
			short m_expYear);
		bool read();
		void display(int row = 0) const;
	};
}

#endif