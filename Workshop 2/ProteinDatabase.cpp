/* ==================================WORKSHOP 2 PART 2=================================
NAME: RISHITA RAJENDRAKUMAR PATEL
ID: 141921205
MAIL: rrpatel42@myseneca.ca
SECTION: OOP 345 NBB
DATE: 31 JANUARY 2022
=======================================================================================*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include<string>
using namespace std;

#include "ProteinDatabase.h"

namespace sdds {

	ProteinDatabase::ProteinDatabase() 
	{
		// no arg default contructor....
	}

	ProteinDatabase::ProteinDatabase(char* fileename) 
	{
		ifstream file(fileename);

		current_strings = 0;
		arrayy = nullptr;

		if (!file)
			return;

		std::string line_start, name;

		while (std::getline(file, line_start).good()) 
		{
			if (line_start[0] == '>') 
			{
				current_strings++;
			}
			else
			{ }
		}


		file.clear();
		file.seekg(std::ios::beg);


		arrayy = new string[current_strings];
		line_start.clear();
		
		int i = -1;

		do
		{
			if (line_start[0] == '>') 
			{
				++i;
				name = line_start.substr(1);

			}
			else if (!name.empty()) 
			{
				arrayy[i] += line_start;
			}
		} while (getline(file, line_start).good());

	}

	size_t ProteinDatabase::size()		//a query that returns the number of protein sequences stored in the current object....
	{
		return current_strings;
	}

	std::string ProteinDatabase::operator[](size_t indx)		// a query that returns a copy of the protein sequence at the index received as the function parameter....
	{
		if (indx < current_strings)
		{
			return arrayy[indx];
		} 
		else         //If the index is invalid, this function should return an empty string....
		{
			return "";
		} 
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& prev)
	{
		*this = std::move(prev);
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& prev) 
	{
		*this = prev;
	}
	
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& prev) 
	{
		if (this != &prev) 
{
			delete[] arrayy;
			current_strings = prev.current_strings;
			arrayy = new string[current_strings]{
			};
			
			for (unsigned int i = 0; i < current_strings; i++) 
			{
				arrayy[i] = prev.arrayy[i];
			}
		}
		return *this;
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& prev)
	{
		if (this != &prev)
		{
			delete[] arrayy;
			arrayy = prev.arrayy;

			prev.arrayy = nullptr;
			current_strings = prev.current_strings;

			prev.current_strings = 0;
		}
		return *this;
	}

	ProteinDatabase::~ProteinDatabase()
	{
		delete[] arrayy;
	}

}
