/************************************************************
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.h
Version 1.0
Author	Gurel Sezgin
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/18  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
************************************************************/


#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>

namespace sdds
{
	class ReadWritable
	{
	public:
		// Constructor/Deconstructor
		ReadWritable();
		virtual ~ReadWritable() = default;

		// Set the flag
		bool isCsv()const;
		void setCsv(bool value);

		// Read/write
		virtual std::ostream& write(std::ostream& os) const = 0; 
		virtual std::istream& read(std::istream& in) = 0;

	private:
		bool m_flag;
	};

	// Helper functions
	std::ostream& operator <<(std::ostream& out, ReadWritable& writable);
	std::istream& operator >>(std::istream& in, ReadWritable& readable);
}

#endif // !SDDS_READWRITABLE_H

