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
#include "Vehicle.h"

using namespace std;
namespace sdds
{
    //********* CONSTRUCTORS / DESTRUCTOR *********//

    Vehicle::Vehicle() {
        m_licensePlate = nullptr;
        m_makeModel = nullptr;
        m_parkingSpot = 0;
    }

    Vehicle::Vehicle(const char* licensePlate, const char* makeModel) {
        if (validLicensePlate(licensePlate) && validMakeModel(makeModel)) {
            setLicensePlate(licensePlate);
            setMakeModel(makeModel);
            m_parkingSpot = 0;
        }
        else {
            setEmpty();
        } 
    }

    Vehicle::Vehicle(const Vehicle& V) {   // copy constructor
        if (validLicensePlate(V.m_licensePlate) && validMakeModel(V.m_makeModel)) {
            setLicensePlate(V.m_licensePlate);
            setMakeModel(V.m_makeModel);
            setParkingSpot(V.m_parkingSpot);
        }
        else {
            setEmpty();
        }
    }

    Vehicle::~Vehicle() {
        delete[] m_licensePlate;
        m_licensePlate = nullptr;
        delete[] m_makeModel;
        m_makeModel = nullptr;
    }

    //********* OPERATORS *********//

    Vehicle& Vehicle::operator=(const Vehicle& V) {   // copy operator
        if (this != &V) { //check copy itself
            if (validLicensePlate(V.m_licensePlate) && validMakeModel(V.m_makeModel)) {
                delete[] m_licensePlate;
                delete[] m_makeModel;
                setLicensePlate(V.m_licensePlate);
                setMakeModel(V.m_makeModel);
                setParkingSpot(V.m_parkingSpot);
            }
            else {
                setEmpty();
            }
        }
        return *this; 
    }

    bool Vehicle::operator == (const char* licensePlate) const {
        bool flag = false;
        // char temp[LP_MAX_LEN] = {};
        if (strcmp(m_licensePlate, licensePlate) == 0) {
            flag = true;
        }
        else {
            flag = false;
        }
        return flag;
    }

    bool Vehicle::operator == (const Vehicle& V) const {
        bool flag = false;
        // char temp[LP_MAX_LEN] = {};
        if (strcmp(m_licensePlate, V.m_licensePlate) == 0) {
            flag = true;
        }
        else {
            flag = false;
        }
        return flag;
    }

   
    //********* SETTERS / GETTERS *********//

    void Vehicle::setEmpty() {
        delete[] m_licensePlate;
        m_licensePlate = nullptr;
        delete[] m_makeModel;
        m_makeModel = nullptr;
        m_parkingSpot = 0;
    }

    bool Vehicle::isEmpty() const {
        bool flag = false;
        if (m_licensePlate == nullptr && m_makeModel == nullptr && m_parkingSpot == 0) {
           flag = true;
        }
        else {
            flag = false;
        }
        return flag;
    }

    const char* Vehicle::getLicensePlate() const {
        return m_licensePlate;
    }

    void Vehicle::setLicensePlate(const char* licensePlate) {
        if (validLicensePlate(licensePlate)) {
            delete[] m_licensePlate;
            m_licensePlate = new char[strlen(licensePlate) + 1];         
            strcpy(m_licensePlate, licensePlate);
            upperCaseConverter(licensePlate);       
        }
        else {
            setEmpty();
        }
    }

    const char* Vehicle::getMakeModel() const {
        return m_makeModel;
    }

    void Vehicle::setMakeModel(const char* makeModel) {
        if (validMakeModel(makeModel)) {
            delete[] m_makeModel;
            m_makeModel = new char[strlen(makeModel) + 1];
            strcpy(m_makeModel, makeModel);          
        }
        else {
            setEmpty();
        }
    }
    
    int Vehicle::getParkingSpot() const {
        return m_parkingSpot;
    }

    void Vehicle::setParkingSpot(int parkingSpot) {
        if (parkingSpot >= 0) {
            m_parkingSpot = parkingSpot;
        }
        else {
            setEmpty();
        }
    }

    //********* READ / WRITE FUNCTION *********//
  
    std::istream& Vehicle::read(std::istream& istr) {
        char licensePlate[LP_MAX_LEN], makeModel[MM_MAX_LEN];
        if (isCsv()) {
            istr >> m_parkingSpot;
            istr.ignore(); //ignore the comma
            istr.getline(licensePlate, LP_MAX_LEN, ',');
            if (istr.fail()) {
                setEmpty();
                istr.clear();
                return istr;
            }
            setLicensePlate(licensePlate);
            upperCaseConverter(licensePlate);
            istr.getline(makeModel, MM_MAX_LEN, ',');
            if (istr.fail()) {
                setEmpty();
                istr.clear();
                return istr;
            }
            setMakeModel(makeModel);
        }  
       else {
            bool flag = true;
            cout << "Enter License Plate Number: ";
            do {
                istr.getline(licensePlate, LP_MAX_LEN, '\n');
                if (istr.fail()){
                    setEmpty();
                    istr.clear();
                    istr.ignore(1000, '\n');
                    cout << "Invalid License Plate, try again: ";
                     flag = false;
                }
                else {       
                    if (validLicensePlate(licensePlate)) {
                        setLicensePlate(licensePlate);
                        flag = true;
                    } 
                    else {
                        flag = false;
                    }
                }
            } while (flag == false);
            cout << "Enter Make and Model: ";
            do {
                istr.getline(makeModel, MM_MAX_LEN + 1, '\n');
                if (istr.fail()) {
                    setEmpty();
                    istr.clear();
                    flag = false;
                }
                else if (validMakeModel(makeModel)) {
                    setMakeModel(makeModel);
                    flag = true;
                }
                else {
                    cout << "Invalid Make and model, try again: ";
                    flag = false;
                }
            } while (flag == false);
            m_parkingSpot = 0;
       }
        return istr;
    }

    std::ostream& Vehicle::write(std::ostream& ostr) const {
        if (m_licensePlate == nullptr && m_makeModel == nullptr && m_parkingSpot == 0) {
            ostr << "Invalid Vehicle Object" << endl;
        }
        else {
            writeType(ostr);
            if (isCsv()) {
                ostr << m_parkingSpot << "," << m_licensePlate << "," << m_makeModel << ",";
            }
            else {
                ostr << "Parking Spot Number: ";
                if (m_parkingSpot == 0) {
                    ostr << "N/A";
                }
                else {
                    ostr << m_parkingSpot;
                }
                ostr << endl;
                ostr << "License Plate: " << m_licensePlate << endl;
                ostr << "Make and Model: " << m_makeModel << endl;
            }
        }
        return ostr;
    }

    //********* ADD-ON FUNCTIONS *********//

    bool Vehicle::validLicensePlate(const char* licensePlate) {
        bool flag = false;
        if ((licensePlate == nullptr || licensePlate[0] == '\0')) {
            flag = false;
        }
        else {
            if ((strlen(licensePlate) >= MINIMUM_VALUE) && (strlen(licensePlate) <= (LP_MAX_LEN - 1))) {
                flag = true;
            }
            else {
                flag = false;
            }
        }
        return flag;
    }

    bool Vehicle::validMakeModel(const char* makeModel) {
        bool flag = false;
        if ((makeModel == nullptr || makeModel[0] == '\0')) {
            flag = false;
        }
        else {
            if ((strlen(makeModel) > MINIMUM_VALUE) && (strlen(makeModel) <= (MM_MAX_LEN - 1))) {
                flag = true;
            }
            else {
                flag = false;
            }
        }
        return flag;
    }

    void Vehicle::upperCaseConverter(const char* licensePlate) {
        int i;
        for (i = 0; i < (int)strlen(licensePlate); i++) {
            this->m_licensePlate[i] = toupper(licensePlate[i]);
        };
    }

}




