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
#include "Motorcycle.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	Motorcycle::Motorcycle() : Vehicle() {
		m_sidecar = false;
	}

	Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel) {}

	Motorcycle::Motorcycle(const Motorcycle& M) : Vehicle(M.getLicensePlate(), M.getMakeModel()) {
		this->setParkingSpot(M.getParkingSpot());
		this->setCsv(M.isCsv());
		this->m_sidecar = M.m_sidecar;
	}

	Motorcycle::~Motorcycle() {}

	Motorcycle& Motorcycle::operator = (const  Motorcycle& M) {
		if (this != &M) {
			this->setLicensePlate(M.getLicensePlate());
			this->setMakeModel(M.getMakeModel());
			this->setParkingSpot(M.getParkingSpot());
			this->setCsv(M.isCsv());
			this->m_sidecar = M.m_sidecar;
		}
		return *this;
	}

	std::ostream& Motorcycle::writeType(std::ostream& ostr)const {
		if (this->isCsv()) {
			ostr << "M,";
		}
		else {
			ostr << "Vehicle type: Motorcycle" << endl;
		}
		return ostr;
	}

	std::istream& Motorcycle::read(std::istream& istr) {
		if (this->isCsv()) {
			Vehicle::read(istr);
			istr >> m_sidecar;
			istr.clear();
			istr.ignore(1000, '\n');
		}
		else {
			string input;
			char answer{};
			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read();
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			answer = validAnswer(input);
			if (answer == 'Y' || answer == 'y') {
				this->m_sidecar = true;
			}
			else {
				this->m_sidecar = false;
			};
		}
		return istr;
	}

	std::ostream& Motorcycle::write(std::ostream& ostr)const {
		if (this->isEmpty()) {
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else {
			Vehicle::write(ostr);
			if (this->isCsv()) {
				ostr << m_sidecar << endl;
			}
			else {
				if (m_sidecar) {
					ostr << "With Sidecar" << endl;
				}
			}
		}
		return ostr;
	}
}