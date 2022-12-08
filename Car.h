/*
*****************************************************************************
						  Milestone - #4
Full Name     : Ngoc Diem Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Nov 29, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
	class Car: public Vehicle
	{
		bool m_carwash;
	public:
		Car();
		Car(const char* licensePlate, const char* makeModel);
		Car(const Car& C);
		~Car();
		Car& operator=(const Car& C);
		std::ostream& writeType(std::ostream& ostr = std::cout)const;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;

	};
}

#endif