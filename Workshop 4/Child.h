/*=============================================================
Name: Rishita Rajendrakumar Patel
Id: 141921205
Email: rrpatel42@myseneca.ca
Section: OOP 345 NBB
Date: 16 Feb 2022
================================================================*/

#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H

#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {
	class Child
	{
	private:
		Toy* toy{};
		size_t num;

		std::string child_name;
		int child_age;
	public:
		Child();
		Child& operator=(const Child& C);
		Child(const Child& C);
		Child(Child&& C);
		Child& operator=(Child&& C);
		~Child();

		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& ostr, const Child& child);
	};
}
#endif // !SDDS_CHILD_H
