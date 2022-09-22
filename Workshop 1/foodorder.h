///*============================WORKSHOP 1 PART 2======================================
//Name: Rishita Rajendrakumar Patel
//id : 141921205
//section: OOP 345 NBB
//date: 22 jan 2022
////======================================================================================
//*/

#ifndef SDDS_FOODORDER_H__
#define SDDS_FOODORDER_H__

#include <iostream>
#include <cstring>

namespace sdds
{
	class FoodOrder 
	{
		char name[10];			//name of customer....
		std::string desc;		//description of food....
		double food_price;	
		bool bool_flag;
	
	public:
		FoodOrder();	//default construtor....
		std::istream& read(std::istream& istr);
		
		void display();		//displays the content of an Food Oredr....
	};
}
#endif // SDDS_FOODORDER_H__
