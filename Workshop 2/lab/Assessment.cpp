/*
*****************************************************************************
						  Workshop - #2 (P1)
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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assessment.h"

using namespace std;
using namespace sdds;

bool sdds::read(int& value, FILE* fptr)
{
	if (fscanf(fptr, "%d\n", &value) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool sdds::read(double& value, FILE* fptr)
{
	if (fscanf(fptr, "%lf", &value) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool sdds::read(char* cstr, FILE* fptr)
{
	if (fscanf(fptr, ",%60[^\n]\n", cstr) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool sdds::read(Assessment& asmnt, FILE* fptr)
{
	double mark;
	char title[61];
	int num;

	if(read(mark, fptr) && read(title, fptr))
	{
		num = strlen(title);

		asmnt.m_mark = new double;
		asmnt.m_title = new char[num + 1];

		*asmnt.m_mark = mark;
		strcpy(asmnt.m_title, title);
		
		return true;
	}
	else
	{
		return false;
	}
}
void sdds::freeMem(Assessment*& aptr, int size)
{
	if (aptr) {
		for (int i = 0; i < size; i++)
		{
			delete aptr[i].m_mark;
			delete [] aptr[i].m_title;
		}
		delete [] aptr;
	}

	aptr = nullptr;
}
int sdds::read(Assessment*& aptr, FILE* fptr)
{
	int i;
	int entryNum;
	read(entryNum, fptr);

	aptr = new Assessment[entryNum];

	for (i = 0; i < entryNum; i++)
	{
		if (!(read(aptr[i], fptr)))
			break;
	}

	if (i != entryNum) 
	{
		freeMem(aptr, i);
		return 0;
	}
	else
	{
		return entryNum;
	}

}

