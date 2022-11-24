/*=============================================================
Name: Rishita Rajendrakumar Patel
Id: 141921205
Email: rrpatel42@myseneca.ca
Section: OOP 345 NBB
Date: 16 Feb 2022
================================================================*/

#include "ConfirmOrder.h"
#include <iostream>

using namespace std;
namespace sdds 
{
	ConfirmOrder::ConfirmOrder() {

	}

	ConfirmOrder::~ConfirmOrder()
	{
		delete[] toys;
		toys = nullptr;
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& O)
	{
		if (this != &O)
		{
			m_num = O.m_num;
			delete[] toys;
			toys = new const Toy * [m_num];

			for (size_t i = 0; i < m_num; i++)
			{
				toys[i] = O.toys[i];
			}
		}

		return *this;
	}

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& O)
	{
		*this = O;
	}

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& O)
	{
		if (this != &O)
		{
			m_num = O.m_num;
			delete[] toys;
			toys = O.toys;

			O.toys = nullptr;
			O.m_num = 0;

		}

		return *this;
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder&& O)
	{
		*this = move(O);
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
		//adds the toy toy to the array by adding its address....
	{
		bool decider = false;

		for (size_t i = 0; i < m_num; i++) 
		{
			if (toys[i] == &toy) 
			{
				decider = true;
			}
			else
			{
				decider = false;
			}
		}

		if (!decider)
		{
			const Toy** toyy = nullptr;
			toyy = new const Toy * [m_num + 1];

			size_t i = 0;
				while (i < m_num)
				{
					toyy[i] = toys[i];
					i++;
				}

			toyy[m_num] = &toy;
			m_num++;
			delete[] toys;
			toys = toyy;
		}
		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		bool decider = false;

		for (size_t i = 0; i < m_num; i++) 
		{
			if (toys[i] == &toy) 
			{
				decider = true;
			}
		}

		if (decider)
		{
			for (size_t i = 0; i < m_num; i++)
			{
				if (toys[i] == &toy)
				{
					toys[i] = nullptr;
				}
			}
			m_num--;
		}

		return *this;
	}

	ostream& operator<<(ostream& ostr, const ConfirmOrder& O)
	{
		ostr << "--------------------------\n";
		ostr << "Confirmations to Send\n";
		ostr << "--------------------------\n";
		if (O.m_num == 0) 
		{
			ostr << "There are no confirmations to send!\n";
		}
		else {
			for (size_t i = 0; i < O.m_num; i++) {
				if (O.toys[i] != nullptr) {
					ostr << *O.toys[i];
				}
			}
		}
		ostr << "--------------------------\n";

		return ostr;
	}
}
