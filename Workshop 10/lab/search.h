#include <iostream>
#include "Collection.h"
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_

namespace sdds {
	template<typename T>
	bool search(const T classArray[], int size, const char* key, Collection<T>& col)
	{
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			if (classArray[i] == key)
			{
				col.add(classArray[i]);
				flag = true;
			}
		}
		return flag;
	}
}

#endif