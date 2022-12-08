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
#include <iostream>
#include "ReadWritable.h"

using namespace std;
namespace sdds
{

	ReadWritable::ReadWritable() {
		flag = false;
	};

	ReadWritable::~ReadWritable() {
		//empty body
	}

	bool ReadWritable::isCsv() const {
		return flag;
	};

	void ReadWritable::setCsv(bool value) {
		flag = value;
	};

	std::ostream& operator<<(std::ostream& os, ReadWritable& w) {
		return w.write(os);
	}
	std::istream& operator>>(std::istream& is, ReadWritable& r) {
		return r.read(is);
	}

}