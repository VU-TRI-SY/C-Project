/*
*****************************************************************************
						  Milestone - #2
Full Name     : Ngoc Diem Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Nov 13, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include <cstring>
#include "Menu.h"

using namespace std;
namespace sdds
{
	//********* MENUITEM FUNCTIONS *********// 

	MenuItem::MenuItem() {
		m_content[0] = '\0';
	}

	MenuItem::MenuItem(const char* title) {
		if (&Menu::titleValid) {
			strncpy(m_content, title, MAX_NAME_LEN);
		}
		else {
			m_content[0] = '\0';
		}
	}

	std::ostream& MenuItem::display(std::ostream& os) const {
		os << m_content << endl;
		return os;
	}

	//********* MENU FUNCTIONS *********// 

	Menu::Menu() {
		setEmpty();
	}

	Menu::Menu(const char* title, int indent) {
		if (&Menu::titleValid) {
			strncpy(m_title, title, MAX_NAME_LEN);
			m_indent = indent;
			m_num = 0;
		}
		else {
			setEmpty();
		}
	}

	Menu& Menu::operator=(const char* title) {
		if (title != nullptr)
		{
			if (title[0] == '\0') {
				m_title[0] = '\0';
			}
			else {
				strncpy(m_title, title, MAX_NAME_LEN);
			}
		}
		else
		{
			setEmpty();
		}
		return *this;
	}
	void Menu::add(const char* title) {
		if (!isEmpty() && m_num < MAX_NO_OF_ITEMS) {
			if (title != nullptr) {
				strncpy(m_item[m_num].m_content, title, MAX_NAME_LEN);
				m_num++;
			}
			else {
				setEmpty();
			}
		}
		else {
			setEmpty();
		}
	}

	Menu& Menu::operator<<(const char* title) {
		add(title);
		return *this;
	}

	void Menu::display() const {
		if (isEmpty())
		{
			cout << "Invalid Menu!" << endl;
		}
		else {
			if (m_num != 0) {
				cout << string(m_indent * 4, ' ') << m_title << endl;
				for (int i = 0; i < m_num; i++) {
					cout << string(m_indent * 4, ' ') << i + 1 << "- " <<
						m_item[i].m_content << endl;
				}
				cout << string(m_indent * 4, ' ') << "> ";
			}
			else {
				cout << this->m_title << endl;
				cout << "No Items to display!" << endl;
				return;
			}
		}
	}
	Menu::operator bool() const {
		return (!isEmpty());
	}

	Menu::operator int() const {
		return run();
	}

	void Menu::setEmpty() {
		m_title[0] = '\0';
		m_indent = 0;
		m_num = 0;
	}
	bool Menu::isEmpty() const {
		return m_title[0] == '\0';
	}
	int Menu::run() const {
		display();
		int choice;
		if (m_num != 0) {
			while (1) {
				cin >> choice;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid Integer, try again: ";
				}
				else {
					if (choice < 1 || choice > m_num) {
						cout << "Invalid selection, try again: ";
					}
					else {
						cin.ignore(1000, '\n');
						return choice;
					}
				}
			};
		}
		else {
			return 0;
		}
	}

	void Menu::clear() {
		setEmpty();
	}
	bool Menu::titleValid(const char* title) const {
		if (title != nullptr && title[0] != '\0') {
			return true;
		}
		return false;
	}
}