/************************************************************
Final Project Milestone 5
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author	Gurel Sezgin
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/22  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
************************************************************/

#include <iostream>
#include "ReadWritable.h"

namespace sdds
{
	// Constructor
	ReadWritable::ReadWritable()
	{
		this->m_flag = false;
	}

	// Set the flag
	bool ReadWritable::isCsv()const
	{
		return this->m_flag;
	}

	void ReadWritable::setCsv(bool value)
	{
		this->m_flag = value;
	}

	// Helper functions
	std::ostream& operator <<(std::ostream& out, ReadWritable& writable)
	{
		writable.write(out);
		return out;
	}
	std::istream& operator >>(std::istream& in, ReadWritable& readable)
	{
		readable.read(in);
		return in;
	}
}
