/*=============================================================
Name: Rishita Rajendrakumar Patel
Id: 141921205
Email: rrpatel42@myseneca.ca
Section: OOP 345 NBB
Date: 16 Feb 2022
================================================================*/

#include "Child.h"
using namespace std;
namespace sdds {
	Child::Child()
	{
		delete[] toy;
		toy = nullptr;

		num = 0;
		child_name = "";
		child_age = 0;
	}

	Child& Child::operator=(const Child& C)
	{
		if (this != &C)
		{
			num = C.num;
			child_name = C.child_name;
			child_age = C.child_age;

			delete[] toy;
			toy = new Toy[num];

		 size_t i = 0;
		 while (i < num)
		 {
			 toy[i] = C.toy[i];
			 i++;
		 }
		}

		return *this;
	}

	Child::Child(const Child& C)
	{
		*this = C;
	}

	Child::Child(Child&& C) 
	{
		*this = move(C);
	}

	Child& Child::operator=(Child&& C)
	{
		if (this != &C)
		{
			num = C.num;
			child_name = C.child_name;
			child_age = C.child_age;

			delete[] toy;
			toy = C.toy;

			C.toy = nullptr;
			C.num = 0;
			C.child_name = "";
			C.child_age = 0;

		}

		return *this;
	}

	Child::~Child()
	{
		delete[] toy;
		toy = nullptr;
	}

	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		toy = new Toy[count];
		child_name = name;
		child_age = age;
		num = count;

		size_t i = 0;
		while (i < count)
		{
			toy[i] = *toys[i];
			i++;
		}
	}

	size_t Child::size() const
	{
		return num;
	}

	ostream& operator<<(ostream& ostr, const Child& C)
	{
		static size_t cntt;
		++cntt;
		ostr << "--------------------------\n"
			<< "Child " << cntt << ": " << C.child_name 
			<< " " << C.child_age << " years old:\n";
		ostr << "--------------------------\n";

		if (C.num != 0) 
		{
			for (size_t i = 0; i < C.num; i++) 
			{
				ostr << C.toy[i];
			}
		}
		else 
		{
			ostr << "This child has no toys!\n";
		}
		ostr << "--------------------------\n";
		return ostr;
	}
}

