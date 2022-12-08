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
#include<string>

using namespace std;
namespace sdds
{
	char validAnswer(std::string input) {
		bool ok = true;
		char answer;
		do {
			cin >> input;
			if (input.size() == 1) {
				answer = input[0];
				if (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					ok = false;
				}
				else {
					ok = true;
				}
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				ok = false;
			}
		} while (ok == false);
		return answer;
	}
}