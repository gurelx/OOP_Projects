/*
*****************************************************************************
						  Workshop - #4 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include <iostream>
#include "TourTicket.h"

namespace sdds 
{
	class TourBus
	{
	private:
		TourTicket* passengers;
		int passengerNum;
		TourBus();

	public:
		TourBus(int num);
		bool validTour() const;
		TourBus& board();
		void startTheTour() const;
		~TourBus();
	};
}

#endif