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

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string.h>
#include "Car.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	Car::Car(): Vehicle() {
		m_carwash = false;
	}

	Car::Car(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel) {}

	Car::Car(const Car& C): Vehicle (C.getLicensePlate(), C.getMakeModel()) {
		this->setParkingSpot(C.getParkingSpot());
		this->setCsv(C.isCsv());
		this->m_carwash = C.m_carwash;
	}

	Car::~Car() {}

	Car& Car::operator = (const Car& C) {
		if (this != &C) {
				this->setLicensePlate(C.getLicensePlate());
				this->setMakeModel(C.getMakeModel());
				this->setMakeModel(C.getMakeModel());
				this->setParkingSpot(C.getParkingSpot());
				this->setCsv(C.isCsv());
				this->m_carwash = C.m_carwash;			
		}
		return *this;		
	}

	std::ostream& Car::writeType(std::ostream& ostr)const {
		if (this->isCsv()) {
			ostr << "C,";
		}
		else {
			ostr << "Vehicle type: Car" << endl;
		}
		return ostr;
	}

	std::istream& Car::read(std::istream& istr) {
		if (this->isCsv()) {
			Vehicle::read(istr);
			istr >> m_carwash;
			istr.clear();
			istr.ignore(1000, '\n');
		}
		else {		
			string input;
			char answer{};
			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read();
			cout << "Carwash while parked? (Y)es/(N)o: ";
			answer = validAnswer(input);
			if (answer == 'Y' || answer == 'y') {
				this->m_carwash = true;
			}
			else {
				this->m_carwash = false;
			};
		}
		return istr;
	}

	std::ostream& Car::write(std::ostream& ostr)const {
		if (this->isEmpty()) {
			ostr << "Invalid Car Object" << endl;
			return ostr;
		}
		else {
			Vehicle::write(ostr);
			if (this->isCsv()) {
				ostr << m_carwash << endl;
			}
			else {
				if (m_carwash) {
					ostr << "With Carwash" <<endl;
				}
				else {
					ostr << "Without Carwash" <<endl;
				}
			}
		}
		return ostr;
	}



}