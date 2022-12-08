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

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include "ReadWritable.h"

namespace sdds
{   
    const int LP_MAX_LEN = 9;
    const int MM_MAX_LEN = 61;
    const int MINIMUM_VALUE = 1;

    class Vehicle : public ReadWritable
    {
        char* m_licensePlate = nullptr;
        char* m_makeModel = nullptr;
        int m_parkingSpot = 0;
    protected:
        void setEmpty();
        bool isEmpty() const;
        const char* getLicensePlate() const;
        const char* getMakeModel() const;
        void setMakeModel(const char* makeModel);

    public:
        Vehicle();
        Vehicle(const char* licensePlate, const char* makeModel);
        Vehicle(const Vehicle& V); //copy from src -> this object
        Vehicle& operator=(const Vehicle& V);
        ~Vehicle();   
        void setLicensePlate(const char* licensePlate);    
        int getParkingSpot() const;
        void setParkingSpot(int parkingSpot);
        bool operator == (const char* licensePlate) const;
        bool operator == (const Vehicle& V) const;
        std::istream& read(std::istream& istr = std::cin); //modify object -> cannot push const here
        std::ostream& write(std::ostream& ostr = std::cout)const; //read value and display-> push const here
        virtual std::ostream& writeType(std::ostream& ostr = std::cout)const = 0;
        bool validLicensePlate(const char* licensePlate);
        bool validMakeModel(const char* licensePlate);
        void upperCaseConverter (const char* licensePlate);
       
    };
}

#endif // !SDDS_VEHICLE_H
