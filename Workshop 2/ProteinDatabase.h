/* ==================================WORKSHOP 2 PART 2=================================
NAME: RISHITA RAJENDRAKUMAR PATEL
ID: 141921205
MAIL: rrpatel42@myseneca.ca
SECTION: OOP 345 NBB
DATE: 31 JANUARY 2022
=======================================================================================*/
#include <iostream>
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_

namespace sdds
{
	class ProteinDatabase
	{
	public:
		unsigned int current_strings = 0;		//keeps track of the number of strings currently stored....
		std::string* arrayy = nullptr;		//a dynamically allocated array of elements of type std::string....

		ProteinDatabase();
		ProteinDatabase(char* fileename);
		size_t size();
		std::string operator[](size_t);

		ProteinDatabase(ProteinDatabase&& prev);
		ProteinDatabase(const ProteinDatabase& prev);
		ProteinDatabase& operator=(const ProteinDatabase& prev);
		ProteinDatabase& operator=(ProteinDatabase&& prev);


		~ProteinDatabase();
	};

}
#endif
