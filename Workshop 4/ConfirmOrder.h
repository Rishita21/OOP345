/*=============================================================
Name: Rishita Rajendrakumar Patel
Id: 141921205
Email: rrpatel42@myseneca.ca
Section: OOP 345 NBB
Date: 16 Feb 2022
================================================================*/

#ifndef SDDS_CONFIRM_ORDER_H
#define SDDS_CONFIRM_ORDER_H

#include "Toy.h"

namespace sdds
{
	class ConfirmOrder 
	{
	private:
		const Toy** toys{ nullptr };
		size_t m_num{ 0 };

	public:
		ConfirmOrder();
		~ConfirmOrder();

		ConfirmOrder& operator=(const ConfirmOrder& O);
		ConfirmOrder(const ConfirmOrder& O);
		ConfirmOrder& operator=(ConfirmOrder&& O);
		ConfirmOrder(ConfirmOrder&& O);

		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& O);
	};
}
#endif // !SDDS_CONFIRM_ORDER_H

