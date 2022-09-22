///*============================WORKSHOP 1 PART 2======================================
//Name: Rishita Rajendrakumar Patel
//id : 141921205
//section: OOP 345 NBB
//date: 22 jan 2022
////======================================================================================
//*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "foodorder.h"
using namespace std;

//two global variables....
double g_taxrate;
double g_dailydiscount;

namespace sdds 
{
	FoodOrder::FoodOrder() 
	{
		//Default constructor

		/*desc = nullptr;
		name[0] = '\0';
		food_price = -1;
		bool_flag = false;*/

	}

	istream& FoodOrder::read(istream& istr)
	{
		char temp = ' ';

		if (!istr.fail()) 
		{
			istr.get(name, 10, ',');
			istr.ignore();
			
			getline(istr, desc, ',');
			istr >> food_price;
			
			istr.ignore();
			istr >> temp;

			if (temp == 'Y') 
			{
				bool_flag = true;
			}
			else 
			{
				bool_flag = false;
			}
		}
		return istr;
	}

	void FoodOrder::display() 
	{
		static int num_times = 1;		// will remain in memory for the lifetime of program.
		
		double price_tot = food_price * g_taxrate + food_price;
		
		if (name[0] != '\0') 
		{
			cout.width(2);
			cout.setf(ios::left);
			cout << num_times;
			cout << ". ";

			cout.width(10);
			cout << name;
			cout << "|";

			cout.width(25);
			cout << desc;
			cout << "|";

			cout.width(12);
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << price_tot;
			cout.unsetf(ios::fixed);
			cout << "|";
			cout.unsetf(ios::left);
			
			cout.setf(ios::right);
			cout.width(13);
		
			if (bool_flag)
			{
				cout.precision(2);
				cout.setf(ios::fixed);
				cout << price_tot - g_dailydiscount;
				cout << endl;
				cout.unsetf(ios::fixed);
			}
			else 
			{
				cout.fill(' ');
				cout << endl;
			}
			cout.unsetf(ios::right);
		}
		else 
		{
			cout.width(2);
			cout.setf(ios::left);
			cout << num_times << ". No Order";
			cout << endl;
		}

		num_times++;
	}
}
