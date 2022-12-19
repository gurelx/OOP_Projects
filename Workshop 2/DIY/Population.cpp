/*
*****************************************************************************
						  Workshop - #2 (P2)
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"


using namespace std;
namespace sdds {
	
	Data* report;
	int recNum;

	bool load(const char filename[])
	{
		int i = 0;

		if (openFile(filename))
		{
			recNum = noOfRecords();
			report = new Data[recNum];

			while (fscanf(fptr, "%[^,],%d\n", report[i].postalCode, &report[i].population) == 2)
			{
				i++;
			}

			if (i != recNum)
			{
				cout << "Error: incorrect number of records read; the data is possibly corrupted!<ENDL>" << endl;
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			cout << "Could not open data file: "<< filename << "<ENDL>" << endl;
			return false;
		}
	}

	void sort(Data* rep, int size)
	{
		Data temp;

		for (int i = 0; i < size - 1; i++)
		{
			for ( int j = 0; j < size - 1 - i; j++)
			{
				if (rep[j].population > rep[j + 1].population)
				{
					temp = rep[j];
					rep[j] = rep[j + 1];
					rep[j + 1] = temp;
				}
			}
		}
	}

	void display() 
	{
		int sum = 0;

		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;

		sort(report, recNum);

		for (int i = 0; i < recNum; i++)
		{
			cout << i + 1 << "- " << report[i].postalCode << ":  " << report[i].population << endl;
			sum += report[i].population;
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << sum << endl;
	}

	void deallocateMemory()
	{
		delete[] report;
		report = nullptr;
		closeFile(); // When this function is in the load function, it gives a memory leak, so I transferred it into deallocate()
	}
}